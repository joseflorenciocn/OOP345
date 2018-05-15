#ifndef W5_MESSAGE_H
#define W5_MESSAGE_H

namespace w5 
{

	class Message
	{
	public:
		Message();
		~Message();
		Message(std::ifstream& in, char c);
		bool empty() const;
		void display(std::ostream&) const;


	private:

		std::string  m_message;
		std::string  m_user;
		std::string  m_reply;
		std::string  m_msg;
		int m_size;


	};

	


}


#endif 
