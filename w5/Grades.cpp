#include <iostream>
#include <fstream>
#include <string>
#include "Grades.h"




Grades::Grades()
{
	mp_id = nullptr;
	mp_grade = nullptr;
	m_size = 0;	
}


Grades::Grades(const char* filename)
{
	m_size = 0;
	char delimiter = '\n';

	std::ifstream file;
	file.open(filename);

	try
	{


		if (file.is_open())
		{
			//count the number of records in the file
			do
			{

				getline(file, m_student);// , delimiter);

				if (!m_student.empty())	m_size++;

			} while (file);


			//allocate memory for student info's array
			mp_id = new int[m_size];
			mp_grade = new double[m_size];
			int flag = 0;

			// rewind
			file.clear();
			file.seekg(0, file.beg);

			// fills the array with student info
			while (file.good())
			{
				file >> mp_id[flag];
				file >> mp_grade[flag];
				flag++;
			}

			file.close();
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

Grades::~Grades() 
{
	// deallocates memory
	delete[] mp_id;
	delete[] mp_grade;
}

void Grades::displayGrades(std::ostream& out, std::string(*letterfunc)(double)) const
{

	// for each element, print one record
	for (int i = 0; i < m_size; i++) 
	{
		if (letterfunc(mp_grade[i]) == "Z") throw mp_id[i];
		else out << mp_id[i] << ' ' << mp_grade[i] << ' ' << letterfunc(mp_grade[i]) << std::endl;
	}
}



		
