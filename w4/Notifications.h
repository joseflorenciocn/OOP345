#ifndef W5_NOTIFICATIONS_H
#define W5_NOTIFICATIONS_H



namespace w5 {

	class Message;
	const int max=10;
	
	class Notifications
	{

	public:

		Notifications(); //- default constructor - empty
		Notifications(const Notifications&); //- copy constructor
		Notifications& operator=(const Notifications&); //-copy assignment operator
		Notifications(Notifications&&); //- move constructor
		Notifications&& operator=(Notifications&&); //-move assignment operator
		~Notifications(); //- destructor
		void operator+=(const Message& mesg); //- adds msg to the set
		void display(std::ostream& os) const; //- inserts the Message objects to the os output stream
		int getSize() const;

	private:

		Message* msg[max];
		int m_size;

	};


}




#endif 
