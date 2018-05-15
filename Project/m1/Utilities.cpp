// Milestone 1 - Task Manager
// Utilities.cpp
// Jose Florencio
// v1.0 - 19/03/2018

#include "Utilities.h"
#include <string>
#include <iostream>
#include <fstream>

char Utilities::delimiter = '|';
std::ofstream Utilities::logFile;

Utilities::Utilities()
{

	field_width = 1;

}

//Not used in the program
/*
void Utilities::setFieldWidth(size_t fw)
{



}
*/


size_t Utilities::getFieldWidth() const
{

	return this->field_width;

}


const std::string Utilities::nextToken(const std::string& str, size_t& next_pos, bool& more)
{
	int token_qty = 1;


	std::string token;

	for (size_t i = next_pos; i < str.length(); i++)
	{
		if (str[i] == delimiter)
		{
			token_qty++;
		}

	}

		std::string* word_tmp = new std::string[token_qty];
		int* position = new int[token_qty];
		int flag = 0;
		position[0] = 0;

		for (size_t j = next_pos; j < str.length(); j++)
		{
			if (str[j] == delimiter)
			{
				position[flag] = j;
				flag++;			
			}

			else word_tmp[flag] = word_tmp[flag] + str[j];
		}

		token = word_tmp[0];
		if (position[0] != 0)
		{
			next_pos = (position[0] + 1);
			more = true;
		}

		else
		{
			next_pos = str.length();
			more = false;
		}

		delete[] word_tmp;
		delete[] position;


	if (field_width < token.length())
	{
		field_width = token.length();
	}

	//Code to trim the whitespaces
	if (token.length() > 1) 
	{
		unsigned fPos = token.find_first_not_of(" \a\b\f\n\r\t\v");
		unsigned lPos = token.find_last_not_of(" \a\b\f\n\r\t\v");
		if (fPos != std::string::npos)
			token = std::string(token, fPos, lPos - fPos + 1);
	}

	
	if (token.empty())
	{
		more = 0;
		
		//Code to save the record from the task and pass as an throw exception
		//I made this code because i have a lot of problemns 
		//in the linux compilation that cant concatenate the strings
		/////////////////////////////////////////////////////////////
		std::string record;
		for (size_t i=0; i<(str.length()-1); i++)
		{
		record += str[i];
		}
		///////////////////////////////////////////////////////////////
		//If you are using visual studio environment comment this code above
		// and remove the comment before the throw execution
		
		
		//std::string record = str;
		throw std::string(record);
	}

	return token;

}

void Utilities::setDelimiter(const char del)
{
	delimiter = del;
}

void Utilities::setLogFile(const char* logfile)
{
	std::ofstream file;
	file.open(logfile);
}

std::ofstream& Utilities::getLogFile()
{

	return logFile;

}
