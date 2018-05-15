/*
!Header guard against repeted use
*/
#ifndef W1_CSTRING_H
#define W1_CSTRING_H


namespace w1
{

/*
!Number of characters stored by the object
*/
	const int MAX = 4;

	class CString
	{
	
	public:

	/*
	!Constructor function that receives the address of a C-style null-terminated string and stores the first MAX characters of the string.
	*/
		CString(char*);
		
	/*
	!	Query that receives a reference to an ostream object and displays the string stored in the CString object
	*/
		std::ostream& display(std::ostream&) const;

	private:

	/*
	!	Object member to store the string
	*/
		char m_string[MAX];

	};
	/*
	! Helper operator that inserts the stored string into the left ostream operand
	*/
	std::ostream& operator <<(std::ostream&, const CString&);

}


#endif
