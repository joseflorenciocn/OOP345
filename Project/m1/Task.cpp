
// Milestone 1 - Task Manager
// Task.cpp
// Jose Florencio
// v1.0 - 19/03/2018

#include <string>
#include "Task.h"
#include "Utilities.h"

size_t Task::field_width = 0;

Task::Task(const std::string& record)
{
         
	this->slots="1";        
	this->pNextTask[0] = nullptr;
	this->pNextTask[1] = nullptr;

	Utilities util;

	bool more=true;
	size_t next_pos = 0;
	std::string token;
	int token_qty = 0;

	// while more tokens are available for extraction
	while (more)
	{
		try 
		{
			token = util.nextToken(record, next_pos, more);
			
			if (token_qty == 0)
			{
				name = token;
				token_qty++;
			}

			else
			{
				if (token_qty == 1)
				{
					slots = token;
					token_qty++;
				}

				else
				{
					if (token_qty == 2)
					{
						nextTask[passed] = token;
						token_qty++;
					}

					else
					{
						if (token_qty == 3)
						{
							nextTask[redirect] = token;
							token_qty++;
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

	if (field_width < util.getFieldWidth()) 
	{
		field_width = util.getFieldWidth();
	}

	
}

const std::string& Task::getName() const
{
	return this->name;
}

//Product slots in the token (converted from a string to an unsigned integer)
unsigned int Task::getSlots() const
{
	unsigned int val = atoi(slots.c_str()); 
	return val;

}

bool Task::validate(const Task& task) 
{
	bool valid = true;
	for (int i = 0; i < 2; i++) 
	{
		if (!nextTask[i].empty() && nextTask[i] == task.getName()) pNextTask[i] = &task;
		if (!nextTask[i].empty() && !pNextTask[i]) valid = false;
	}
	return valid;

}
const Task* Task::getNextTask(Quality quantity) const
{	
	if (!nextTask[quantity].empty() && !pNextTask[quantity])
	{
		throw std::string("*** Validate [" + nextTask[quantity] + "] @ [" + name + "] ***");
	}

	return pNextTask[quantity];
}

void Task::display(std::ostream& out) const
{

	out.setf(std::ios::left);
	out << "Task Name    : ";
	out.width(field_width + 2);
	out << "[" + name + "]" << " [" + slots + "]" << std::endl;

		if (!nextTask[passed].empty()) 
		{
			out << " Continue to : ";
			out.width(field_width + 2);
			out << "[" + nextTask[passed] + "]";

			if (!pNextTask[passed]) 
			{
				out << " *** to be validated ***";
			}
			out << std::endl;
		}

		if (!nextTask[redirect].empty())
		{
			out << " Redirect to : ";
			out.width(field_width + 2);
			out << "[" + nextTask[redirect] + "]";

			if (!pNextTask[redirect])
			{
				out << " *** to be validated ***";
			}
			out << std::endl;
		}



}

size_t Task::getFieldWidth()
{

	return field_width;

}

bool operator==(const Task& first, const Task& second) 
{ 
	if (first.getName() == second.getName()) return true;
	else return false;
}