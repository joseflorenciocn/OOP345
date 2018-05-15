#include <iostream>
#include <cstring>
#include "CString.h"

namespace w1
{
	
	static int local = 0;

	CString::CString(char* str)
	{
		if (str == NULL) this->m_string[0] = '\0';
		else
		{
			strncpy (m_string, str, (MAX-1));
			m_string[MAX-1] = '\0';
		}
	}

	std::ostream& CString::display(std::ostream& out) const
	{
		out << local << ": ";
		out << m_string << std::endl;
		local++;

		return out;
	}

	std::ostream& operator <<(std::ostream& out, const CString& tmp)
	{
	
	return tmp.display(out);
		
	}
	
	
}
