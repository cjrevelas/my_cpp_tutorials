#include <iostream>
#include <string>

class Ball
{
private:
	std::string  m_color;
	double       m_radius;

public:
	//Constructor #1
	Ball(const std::string &color = "black", double radius = 10.0)
	{
       m_color  = color; 
	   m_radius = radius;
	}

	//Constructor #2
	//the default values must lie in the right-most possible place in function parameters
	Ball(double radius)
	{
	    m_color  = "black";
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

	Ball twenty(20.0);            //the default values must lie in the right-most possible place in function parameters
	twenty.print();

	Ball blueTwenty("blue", 20.0);
	blueTwenty.print();

	return 0;
}