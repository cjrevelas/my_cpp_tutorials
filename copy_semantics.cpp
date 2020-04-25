#include <iostream>

template<class T>
class Auto_ptr1{
    T* m_ptr;

public:
    //pass in a pointer to "own" via the constructor
    Auto_ptr1(T* ptr=nullptr)
    :m_ptr(ptr) {}


    //the destructor will make sure it gets deallocated
    ~Auto_ptr1(){
    delete m_ptr;
    }

    //overload dereference and operator-> so we can use Auto_ptr1 like m_ptr
    T& operator*() const { return *m_ptr; }
    T* operator->() const { return m_ptr; }
};

class Resource{

public:
    Resource() { std::cout << "Resource acquired\n"; }
    ~Resource() { std::cout << "Resource destroyed\n"; }
};

int main(){

    Auto_ptr1<Resource> res(new Resource); // this is like saying: m_ptr = new Resource, thus m_ptr = res owns the allocated Resource object

    //no explicit delete needed here
    //the Resource in angled braces doesn't need a * symbol, since that's supplied by the template

    return 0;
}   //res goes out of scope here, and destroys the allocated Resource for us
