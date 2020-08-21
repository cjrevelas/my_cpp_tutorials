//*********************************************************************************************************//
#include <iostream>
#include <string>
//*********************************************************************************************************//
class Fruit
{
	private:
		std::string  m_name;
		std::string  m_color;


	public:
		Fruit(std::string name, std::string color)
		     : m_name(name), m_color(color)
	    {
	    }

		const std::string& getName() const { return m_name; }
		const std::string& getColor() const { return m_color; }
};
//*********************************************************************************************************//
class Apple : public Fruit
{
    private:
		double m_fiber;

	public:		
		Apple(std::string name, std::string color, double fiber)
			: Fruit(name, color), m_fiber(fiber)
		{
		}

		double getFiber() const { return m_fiber; }

		friend std::ostream& operator<<(std::ostream &out, const Apple &a)
		{
			out << "Apple (" << a.getName() << ", " << a.getColor() << ", " << a.getFiber() << ")\n";

			return out;
		}
		
};
//*********************************************************************************************************//
class Banana : public Fruit
{
	public:
		Banana(std::string name, std::string color)
			  : Fruit(name, color)
		{
		}

		friend std::ostream& operator<<(std::ostream &out, const Banana &b)
		{
			out << "Banana (" << b.getName() << ", " << b.getColor() << ")\n";

			return out;
		}
};
//*********************************************************************************************************//
int main()
{
	const Apple a("Red delicious", "Red", 4.2);
	std::cout << a;

	const Banana b("Cavendish", "Yellow");
	std::cout << b;

	return 0;
}
//*********************************************************************************************************//

