#include <iostream>
#include <string>

class Ball
{
private:
	std::string  m_color;
	double       m_radius;

public:
	//Constructor #1
	Ball()
	{
		//default values for private members of class ball
		m_color  = "black";
		m_radius = 10.0;
	}

	//Constructor #2
	Ball(const std::string &color)         // it must be const, because we wish to pass by ref an r-value (else pass by value without const)
	{
		m_color  = color;
		m_radius = 10.0;
	}

	//Constructor #3
	Ball(double radius)
	{
		m_color  = "black";
		m_radius = radius;
	}

	//Constructor #4
	Ball(const std::string &color, double radius)
	{
		m_color  = color;
		m_radius = radius;
	}

	//Printing function
    void print()
	{
		std::cout << "color: " << m_color << ", radius: " << m_radius << "\n";
	}
};


int main()
{
	Ball def;
	def.print();

	Ball blue("blue");
	blue.print();

	Ball twenty(20.0);
	twenty.print();

	Ball blueTwenty("blue", 20.0);
	blueTwenty.print();

	return 0;
}