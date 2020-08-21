#include <iostream>

class IntPair
{
 public:
	 int m_int1;
	 int m_int2;

	 void set(int x, int y)
	 {
		 m_int1 = x;
		 m_int2 = y;
	 }

	 void print()
	 {
		 std::cout << "Pair(" << m_int1 << "," << m_int2 << ")" << std::endl;
	 }
};

int main()
{
    IntPair p1;
	p1.set(1,1); //set p1 values to (1,1)

	IntPair p2 = {2,2}; //initialize p2 values to (2,2)

	p1.print();
	p2.print();

    return 0;
}