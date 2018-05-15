#include <iomanip> 
#include <vector> 
#include "CustomerOrder.h"
#include "CustomerItem.h"
#include "Item.h"
#include "Utilities.h"

size_t CustomerOrder::field_width;

CustomerOrder::CustomerOrder(const std::string& record)
{
	nOrders = 0;
	order = nullptr;

	Utilities util;

	bool more = true;
	size_t next_pos = 0;
	std::string token;
	int token_qty = 0;

	std::vector<std::string> items;

	// while more tokens are available for extraction
	while (more)
	{
		try
		{
			token = util.nextToken(record, next_pos, more);

			if (token_qty == 0 && token !="Empty")
			{
				name = token;
				token_qty++;
			}

			else
			{
				if (token_qty == 1)
				{
					product = token;
					token_qty++;
				}

				else
				{
					if (more)
					{
						items.push_back(token);
						nOrders++;
						token_qty++;
					}
				}

			}
		}

		catch (const std::string& msg)
		{
			std::cout << msg << "<-- *** no token found before the delimiter ***" << std::endl;
		}

	}
	
	
	order = new CustomerItem[nOrders];

	for (size_t i=0; i<items.size(); i++) 
	{
		
		order[i] = items[i];
	}

	if (field_width < util.getFieldWidth()) field_width = util.getFieldWidth();

}

CustomerOrder::CustomerOrder(const CustomerOrder& other) 
{ 

	throw "*** Error: copy constructor not available ***"; 
}

CustomerOrder::CustomerOrder(CustomerOrder&& other) NOEXCEPT 
{
	order = nullptr;
	*this = std::move(other);
	
}

CustomerOrder&& CustomerOrder::operator=(CustomerOrder&& other) NOEXCEPT 
{
	if (this != &other) 
	{
		// deallocate memory
		delete[] order;

		// assign the values
		name = other.name;
		product = other.product;
		order = other.order;
		nOrders = other.nOrders;

		// reset the values
		other.name = char(0);
		other.product = char(0);
		other.order = nullptr;
		other.nOrders = 0;
	}
	return std::move(*this);
}

CustomerOrder::~CustomerOrder() 
{
	delete[] order;
	order = nullptr;
}

bool CustomerOrder::empty() const 
{	
	if (name.empty() && product.empty() && nOrders == 0) return true;
	else return false;
}

size_t CustomerOrder::noOrders() const 
{ 
	return nOrders; 
}

const std::string& CustomerOrder::operator[](unsigned int i) const 
{
	if (i >= nOrders) throw "index out of bounds";

	return order[i].getName();
}

void CustomerOrder::fill(Item& item) 
{
	for (size_t i = 0; i < nOrders; i++) {
		if (order[i].asksFor(item) && order[i].isFilled() == false) 
		{
			order[i].fill(item.getCode());
			item++;
		}
	}
}

void CustomerOrder::remove(Item& item) 
{
	for (size_t i = 0; i < nOrders; i++) 
	{
		if (order[i].asksFor(item) && order[i].isFilled()) 
		{
			order[i].clear();
		}
	}
}

void CustomerOrder::display(std::ostream& os) const 
{
	os << std::left << std::setw(field_width);
	os << name;
	os << std::right << std::setw(0);
	os << " : " << product << std::endl;

	// loop thourgh the CustomerItems object, fillind the ostream object
	for (size_t i = 0; i < nOrders; i++) 
	{
		order[i].display(os);
	}
}