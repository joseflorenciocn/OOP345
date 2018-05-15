#include <iostream>
#include <string>
#include "TaxableProduct.h"

namespace w7 
{

	TaxableProduct::TaxableProduct(int id, double price, std::string msg) : Product(id, price)
	{
		

		if (msg[1] == 'P')
		{
			m_tax = "PST";
		}

		else
		{
			if (msg[1] == 'H')
			{
				m_tax = "HST";
			}

			else
			{
				m_tax = " ";
			}
		}
		
	}


	double TaxableProduct::getCharge() const
	{
		
		if (m_tax == "PST")
		{
			return (Product::getCharge()*1.08);
		}
		else
		{
			if (m_tax == "HST") 
			{
				return (Product::getCharge()*1.13);
			}
			
			else
			{
				return Product::getCharge();	
			}
		} 
		

	}

	void TaxableProduct::display(std::ostream& out) const
	{
		Product::display(out);
		
		out.setf(std::ios::left);
		out << " " << m_tax << std::endl;

	}

}