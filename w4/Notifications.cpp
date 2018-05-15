#include <string>
#include <fstream>
#include "Message.h"
#include "Notifications.h"


namespace w5
{
	Notifications::Notifications()//- default constructor - empty
	{
		for (int i = 0; i<max; i++)	msg[i] = nullptr;
		m_size = 0;
	}

	Notifications::Notifications(const Notifications& other) //- copy constructor
	{

		for (int i = 0; i<max; i++)	msg[i] = nullptr;
		m_size = 0;
		*this = other;

	}

	Notifications& Notifications::operator=(const Notifications& other) //-copy assignment operator
	{
		if (this != &other)
		{
				for (int i = 0; i < m_size; i++)
				{ 
					delete msg[i];
				}


			for (int i = 0; i<other.m_size; i++)	
			{
				msg[i] = new Message;
				msg[i] = other.msg[i];
			}

			this->m_size = other.m_size;

		}
		return *this;
	}

	Notifications::Notifications(Notifications&& other) //- move constructor
	{
		for (int i = 0; i<other.m_size; i++)	
		{  
			this->msg[i] = other.msg[i];
		}
		
		this->m_size = other.m_size;
	}

	Notifications&& Notifications::operator=(Notifications&& other) //-move assignment operator
	{
		if (this != &other)
		{

				for (int i = 0; i < m_size; i++)
				{ 
					delete msg[i];
				}
			
			for (int i = 0; i<other.m_size; i++)	
			{  
			this->msg[i] = other.msg[i];
			}
			
			this->m_size = other.m_size;

			for (int i = 0; i<max; i++)	msg[i] = nullptr;
			other.m_size = 0;
		}

		return std::move(*this);

	}

	Notifications::~Notifications() //- destructor
	{
		for (int i = 0; i < m_size; i++)
		{ 
		delete msg[i];
		}
	}

	void Notifications::operator+=(const Message& mesg) //- adds msg to the set
	{
		if(m_size<max) 
		{
			msg[this->m_size] = new Message (mesg);
			m_size++;
		}
	}


	void Notifications::display(std::ostream& os) const //- inserts the Message objects to the os output stream
	{

		for (int i = 0; i < m_size; i++)
		{
			msg[i]->display(os);
		}


	}

	int Notifications::getSize() const
	{
		return m_size;
	}

}

