#include <iostream>
#include <string>
#include <cassert>

class Mystring
{
	private:
		std::string m_string;

	public:
		Mystring(const std::string string)
			: m_string(string)
		{}

		std::string operator()(int begin, int length);		
};

std::string Mystring::operator()(int begin, int length)
{
	assert(begin + length <= m_string.length() && "Mystring operator()(int,int): Substring is out of range.");

	std::string output;

	for (int count=0; count < length; ++count)
		output += m_string[begin + count];

	return output;
}

int main()
{
	Mystring string("Hello, world!");
	std::cout << string(7,5) << std::endl; //start at the 7th character and print 5 characters


	return 0;
}