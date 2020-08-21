#include <string>

class Animal
{
    protected:   
	std::string m_name;
	const char* m_speak;

	Animal(std::string name, const char* speak)
		: m_name(name), m_speak(speak)
	{}

    public:
	std::string getName() { return m_name;}
	const char* speak()   { return m_speak;}

};


class Cat : public Animal
{
	public:
	Cat(std::string name)
		: Animal(name, "Meow")
	{}

};


class Dog : public Animal
{
	public:
	Dog(std::string name)
		: Animal(name, "Woof")
	{}

};

