#include <iostream>
#include <cstring>
#include <fstream>
#include "Text.h"

namespace w3
{
/*!Default Constructor */
	Text::Text(const char* str)
	{
		if (!strcmp(str, "empty"))
		{
			m_ptext = nullptr;
			m_size = 0;
	
		}
		else
		{
			int size_file;
			char* textfile;
			std:: string num_lines;
			m_size = 0;
			
			//Simple code to add .txt at the end of file
			size_file = strlen(str);

			textfile = new char[size_file+5];
			strcpy(textfile, str);
			strcat(textfile, ".txt");
			
			//Open the file
			std::ifstream is;
			is.open(textfile);

			if (is.is_open())
			{
				
				//count the number of lines
				while (getline(is, num_lines, '\n')) 
							 {++m_size;} 
				
				//create a string with the file's number of lines
				m_ptext = new std::string[m_size +1];
				
				//Rewind the file
				is.clear();
				is.seekg(0);
				
				//insert the data inside the object
				for (int t = 0; t < m_size; t++)
				{
					getline(is,m_ptext[t],'\n');
				}

				m_ptext[m_size] = '\0';

				is.close();
			}

			else m_ptext = nullptr;			
	
			delete[] textfile;

		}
	}

	/*!Default Destructor */
	Text::~Text()
	{

		delete[] m_ptext;

	}
	
	/*!Display function to show whats is inside the member */
	void Text::display() const
	{
		for (int i=0; i<m_size; i++)
		{
			std::cout << m_ptext[i] << std::endl;
		}
	}

	/*!Copy constructor */
	Text::Text(const Text& other)
	{
		this->m_ptext = nullptr;
		this->m_size = 0;
		*this = other;
	}

	/*!Copy assignment */
	Text& Text::operator=(const Text& other)
	{

		if (this != &other)
		{
			delete[] this->m_ptext;


				this->m_ptext = new std::string[other.m_size +1];
				for (int i = 0; i <= other.m_size; ++i)
				{
					this->m_ptext[i] = other.m_ptext[i];
				}
				this->m_size = other.m_size;
			
		}
		return *this;

	}

	/*!Move constructor */
	Text::Text (Text&& other)
	{
	
		this->m_ptext = other.m_ptext;
		this->m_size = other.m_size;

		other.m_ptext = nullptr;
		other.m_size = 0;
	
	}

	/*!Move assignment */
	Text& Text::operator=(Text&& other)
	{
		if (this != &other)
		{

			delete[] this->m_ptext;

			this->m_ptext = other.m_ptext;
			this->m_size = other.m_size;

			other.m_ptext = nullptr;
			other.m_size = 0;
		}

		return *this;
	}

	/*!Display Size of member */
	size_t Text::size() const
	{
		return m_size;
	}

}
	

