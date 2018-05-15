#include <iomanip> 
#include "Item.h"
#include "Utilities.h" 

size_t Item::field_width;


Item::Item(const std::string& record)
{	
	
	//description = "no detailed description";
	Utilities util;

	bool more = true;
	size_t next_pos = 0;
	std::string token;
	int token_qty = 0;

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
					filler = token;
					token_qty++;
				}

				else
				{
					if (token_qty == 2)
					{
						remover = token;
						token_qty++;
					}

					else
					{
						if (token_qty == 3)
						{
							//declare a placeholder to convert
							std::string::size_type size;
							// convert it to integer
							code = std::stoi(token, &size);
							token_qty++;
						}

						else
						{
							if (token_qty == 4)
							{
								if (!(token[0] == ' ') && !token.empty())
								{
								description = token;
								token_qty++;
								}
								
								else
								{
								description = "no detailed description";
								token_qty++;
								}
								
							}
						}
					}

				}

			}
		}

		catch (const std::string& msg)
		{
			std::cout << msg << "<-- *** no token found before the delimiter ***" << std::endl;
		}

	}

	if (field_width < util.getFieldWidth()) field_width = util.getFieldWidth();

}

bool Item::empty() const 
{ 
	return name.empty(); 
}

Item& Item::operator++(int c) 
{
  code++;
	return *this;
}

const std::string& Item::getName() const 
{ 
	return name; 
}

const std::string& Item::getFiller() const 
{ 
	return filler; 
}

const std::string& Item::getRemover() const 
{ 
	return remover; 
}

size_t Item::getCode() const 
{ 
	return code; 
}

void Item::display(std::ostream& os, bool full) const {
	os << std::left << std::setw(field_width) << std::setfill(' ');
	os << name << " [";
	os << std::right << std::setw(CODE_WIDTH) << std::setfill('0');
	os << code;
	os << std::setfill(' ') << "] ";

	// if the full flag is true, this function includes a complete description of the item
	if (full) 
	{
		os << "From ";
		os << std::left << std::setw(field_width);
		os << name << " To " << remover << std::endl;
		os << std::right << std::setw(field_width + CODE_WIDTH + 4);
		os << "  : " << description;
	}
	os << std::endl;
}