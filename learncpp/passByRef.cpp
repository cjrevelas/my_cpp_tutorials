#include <iostream>

using namespace std;

void passByValue(int x);
void passByReference(int *x);

int main()
{
	int a = 13;
	int b = 13;

	passByValue(a);
	passByReference(&b);

	cout << "variable a is now:" << a  << endl;
	cout << "variable b is now:" << b  << endl;

}

void passByValue(int x)
{
	x = 99;             //access to the "copy" of variable a, not a itself.
}

void passByReference(int *x)
{
	*x = 66;            //direct accest to variable b through its memory address given by the pointer.
}