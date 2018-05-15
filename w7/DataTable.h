#ifndef DATATABLE_H
#define DATATABLE_H

#include <algorithm>
#include <functional>
#include <iostream>
#include <cstring>
#include <vector>
#include <numeric>

namespace w8
{

	template <typename T>
	class DataTable
	{
	public:
		DataTable(std::ifstream& in, int FW, int ND) //Constructor
		{
		
				T x_tmp, y_tmp;

				if (in.is_open())
				{
					while (!in.eof())
					{
					in >> x_tmp >> y_tmp;
					x.push_back(x_tmp);
					y.push_back(y_tmp);
				}
		}

		fw = FW;
		nd = ND;
		
		}
		
		T mean() const // returns the mean value of the dependent coordinate
		{
		
		T num = y.size();

		std::vector<T> elem(y.size());
		std::transform(y.begin(), y.end(), elem.begin(), [num](T a) {
			return a / num;
		});

		T sum = std::accumulate(elem.begin(), elem.end(), (T)0);

		return (T)sum;
		
		}
		
		T sigma() const //returns the standard deviation of the dependent coordinates
		{
		
		T mn = mean();

		std::vector<T> elem(y.size());
		std::transform(y.begin(), y.end(), elem.begin(), [mn](T a) {
			return  a - mn;
		});

		T total = std::inner_product(elem.begin(), elem.end(), elem.begin(), (T)0);

		return (T)sqrt(total / (y.size() - 1));
			
		}
		
		T median() const //returns the median value of the dependent coordinate
		{
		
		std::vector<T> elem = this->y;
		std::nth_element(elem.begin(), elem.begin() + elem.size() / 2, elem.end());

		return elem[elem.size() / 2];
		
		}
		
		void regression(T& slope, T& y_intercept) const //returns the slope and intercept for the data set
		{
		
		T n = (T)y.size();

		T Exy = std::inner_product(x.begin(), x.end(), y.begin(), (T)0);
		T Ex2 = std::inner_product(x.begin(), x.end(), x.begin(), (T)0);

		T Ex = std::accumulate(x.begin(), x.end(), (T)0);
		T Ey = std::accumulate(y.begin(), y.end(), (T)0);

		slope = (n*Exy - Ex * Ey) / (n*Ex2 - Ex * Ex);
		y_intercept = (Ey - slope * Ex) / n;

		
		}
		
		void display(std::ostream& out) const //displays the data pairs as shown below
		{
		
		for (int i = 0; i < x.size(); i++)
		{
			
			out << std::fixed << std::setprecision(2) << x[i] << "   " << y[i] << std::endl;
		}
		
		}

	private:
		std::vector<T> x;
		std::vector<T> y;
		int fw;
		int nd;

	};

}

template <typename T> std::ostream& operator<<(std::ostream& out, const w8::DataTable<T>& dat)
{
	
		dat.display(out);

		return out;
	
	
}


#endif



