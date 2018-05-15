#include<string>
#include <fstream>
#include"Message.h"



namespace w5
{
	Message::Message()
	{
		m_message = '\0';
		m_user = '\0';
		m_reply = '\0';
		m_msg = '\0';
		m_size = 0;
	}

	Message::~Message()
	{

	}

	Message::Message(std::ifstream& in, char c)
	{
		this->m_size = 0;

		
		if (in.is_open())
		{

			getline(in, m_message, c);


			for (int i = 0; i < m_message.length(); i++)
			{
				if (m_message[i] == ' ') 
				{
					m_size++;
				}

			}

			m_size++;

			if (m_size <= 1)
			{
				m_user = '\0';
				m_reply = '\0';
				m_msg = '\0';
			}

			else
			{

				std::string* word_tmp = new std::string[this->m_size];
				int flag = 0;

				for (int i = 0; i < m_message.length(); i++)
				{
					if (m_message[i] == ' ') 
					{
						flag++;
					}

					else word_tmp[flag] = word_tmp[flag] + m_message[i];

				}

				m_user = word_tmp[0];


				if (word_tmp[1][0] == '@')
				{

					word_tmp[1].erase(0,1);
					m_reply = word_tmp[1];

					for (int j = 2; j < m_size; j++)
					{
						m_msg.append(word_tmp[j] + ' ');
					}

				}

				else
				{
					m_reply = '\0';

					for (int j = 1; j < m_size; j++)
					{
						m_msg.append(word_tmp[j] + ' ');
					}
				}

				delete[] word_tmp;

			}
		}

		else
		{
			m_message = '\0';
			m_user = '\0';
			m_reply = '\0';
			m_msg = '\0';
			m_size = 0;
		}
	}

	bool Message::empty() const
	{
		if (m_user[0] == '\0' || m_msg[0] == '\0') return 1;
		else return 0;
	}

	void Message::display(std::ostream& out) const
	{	
			if (m_reply[0]=='\0')
			{
				out << "Message" << std::endl;
				out << " User  : " << m_user << std::endl;
				out << " Tweet : " << m_msg << std::endl;
			}

			else
			{
				out << "Message" << std::endl;
				out << " User  : " << m_user << std::endl;
				out << " Reply : " << m_reply << std::endl;
				out << " Tweet : " << m_msg << std::endl;
			}

	}
	
}










