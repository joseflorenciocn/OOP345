#ifndef GRADES_H
#define GRADES_H

#include <iostream>
#include <string>

class Grades
{
public:
	Grades();
	Grades(const char* filename);
	~Grades();
	void displayGrades(std::ostream& out, std::string(*letterfunc)(double)) const;


private:
	int* mp_id;
	double* mp_grade;
	std::string m_student;
	int	m_size;


};


#endif
