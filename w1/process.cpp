#include <iostream>
#include "CString.h"
#include "process.h"

/*
! Function "process" implementation
*/

void process(char* str)
{

	w1::CString string_tmp(str);
	
	std::cout << string_tmp;

}


