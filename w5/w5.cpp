// Workshop 6 - Lambda Expression
// w6.cpp

#include <iostream>
#include <math.h>
#include "Grades.h"

int main(int argc, char* argv[]) {
	if (argc != 2) {
		std::cerr << argv[0] <<
			": incorrect number of arguments\n";
		std::cerr << "Usage: " << argv[0] << " file_name\n";
		return 1;
	}


	Grades grades(argv[1]);
	// define the lambda expression for letter

	// lambda expression to calculate the letter grade
	auto letter = [](double grade) {
		std::string result;

		// round the grade
		grade = round(grade);

		// calculate the letter value for the grade
		if (grade >= 90 && grade <= 100) result = "A+";
		else if (grade >= 80 && grade <= 89) result = "A";
		else if (grade >= 75 && grade <= 79) result = "B+";
		else if (grade >= 70 && grade <= 74) result = "B";
		else if (grade >= 65 && grade <= 69) result = "C+";
		else if (grade >= 60 && grade <= 64) result = "C";
		else if (grade >= 55 && grade <= 59) result = "D+";
		else if (grade >= 50 && grade <= 54) result = "D";
		else if (grade >= 0 && grade <= 49) result = "F";
		else                                result = "Z"; // not a grade ~ error

		return result;
	};


	try
	{
		grades.displayGrades(std::cout, letter);
	}
	catch (const int& id)
	{
		std::cout << "Grade of " << id << " not allowed" << std::endl;
	}



	std::cout << "Press any key to continue ... ";
	std::cin.get();
}
