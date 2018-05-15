#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "Sale.h"



namespace w7
{

	Sale::Sale(const char* filename)
	{

		std::ifstream file;
		file.open(filename);

		try
		{
			if (file.is_open())
			{
				do
				{
					
					iProduct* tmp = readProduct(file);
					prod.push_back(tmp);

				} while (file);
			}
			else
			{
				throw "File doesn't open";
			}
		}
		catch (const char* message)
		{
			std::cout << "Error in: " << message << std::endl;
		}

	}
	
	void Sale::display(std::ostream& out) const
	{
		
		out << "Product No      Cost Taxable" << std::endl;
		out.width(10);

		for (int i = 0; i < prod.size(); i++)
		{
			prod[i]->display(out);
		}
		
		out.setf(std::ios::right);
		out.width(10);
		out << "Total:";
		double total = 0;
		
		for (int i = 0; i < prod.size(); i++)
		{
			
			total += prod[i]->getCharge();
		}
		
	//	total = round (total);
		
		out.setf(std::ios::left);
		out.width(10);
		out << std::fixed << std::setprecision(2) << total << std::endl;
	}
	
	
	
iProduct* readProduct(std::ifstream& file)
{

	iProduct* tmp;


	try
	{
		if (file.is_open())
		{
			int id_tmp = 0;
			double price_tmp = 0;
			std::string msg;

			file >> id_tmp;
			file >> price_tmp;
			getline(file, msg);

			tmp = new TaxableProduct(id_tmp, price_tmp, msg);

		}

		else
		{
			throw "File doesn't open";
		}
	}

	catch (const char* message)
	{
		std::cout << "Error in: " << message << std::endl;
	}


	return tmp;

}
	


}


