#include <iomanip> 
#include "CustomerItem.h"
#include "Item.h"


CustomerItem::CustomerItem(const std::string& customerItem)
{	
	if (!customerItem.empty()) 
	{
		name = customerItem;
		filled = false;
		code = 0;
	}

	else
	{
		name = char(0);
		filled = false;
		code = 0;
	}

}

bool CustomerItem::asksFor(const Item& item) const 
{ 
	if (name == item.getName())	return true;
	else return false;
}

bool CustomerItem::isFilled() const 
{ 
	return filled; 
}

void CustomerItem::fill(const unsigned int c) 
{
	code = c;
	filled = true;
}

void CustomerItem::clear() 
{
	code = 0;
	filled = false;
}

const std::string& CustomerItem::getName() const 
{ 
	return name; 
}

void CustomerItem::display(std::ostream& os) const 
{

	std::string init;

	if (filled)	init = " + [";
	else init = " - [";

	os << init;
	os << std::setw(CODE_WIDTH) << std::setfill('0');
	os << code << "] ";
	os << std::setfill(' ');
	os << name << std::endl;
	
}