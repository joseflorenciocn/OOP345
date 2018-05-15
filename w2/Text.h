#ifndef W3_TEXT_H
#define W3_TEXT_H

#include <string>

namespace w3
{

	class Text
	{
	public:
		Text(const char* str = "empty");
		~Text();
		Text(const Text&);
		Text& operator=(const Text&);
		Text(Text&&);
		Text& operator=(Text&&);
		void display() const;
		size_t size() const;

	private:

		std::string* m_ptext;
		int m_size;

	};


}


#endif
