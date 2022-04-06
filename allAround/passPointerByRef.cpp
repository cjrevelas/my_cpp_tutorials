#include <iostream>

/* If a pointer is passed to a function as a parameter, then any change
 * to the pointer will not influence the code outside the function. This
 * happens because when passing a parameter by address, only a copy of the
 * pointer is passed to the function, which just points to the same address
 * as the original pointer.
 */

// Let's define a global variable here:
int gVar(2);

// ...and a function whose parameter is passed by address
void passByAdress(int *ptrToVar) {
  ptrToVar = &gVar;
}

void passPointerByAddress(int **ptrToVar, int *newAddress) { // This is allowed in both C and C++
  *ptrToVar = newAddress;
}

void passPointerByRef(int *&ptrToVar) {  // This is allowed only in C++
 ptrToVar = &gVar;
}

int main() {
  int lVar(5); //local variable of the main function

  int *ptr = &lVar;

  std::cout << "Global variable is in address " << &gVar << " and has value " << gVar << '\n';
  std::cout << "Local variable is in address " << &lVar << " and has value " << lVar << '\n';
  std::cout << "Pointer points to " << ptr << " where the value " << *ptr << " is stored" << '\n';

  std::cout << '\n' << "Calling function passByAdress, where the pointer is passed by value\n";
  passByAdress(ptr);
  std::cout << "Pointer points to " << ptr << " where the value " << *ptr << " is stored" << '\n';

  std::cout << '\n' << "Calling function passPointerByRef, where the pointer is passed by reference\n";
  passPointerByRef(ptr);
  std::cout << "Pointer points to " << ptr << " where the value " << *ptr << " is stored" << '\n';

  // Now we want to switch back to pointing to lVar, but using function passPointerByAdress
  std::cout << '\n' << "Calling function passPointerByAdress, where the pointer is passed by address\n";
  passPointerByAddress(&ptr, &lVar);
  std::cout << "Pointer points to " << ptr << " where the value " << *ptr << " is stored" << '\n';
}
