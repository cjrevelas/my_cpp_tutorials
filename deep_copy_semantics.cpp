#include <iostream>

template<class T>
class Auto_ptr3{
    T* m_ptr;

public:
    Auto_ptr3(T* ptr = nullptr)
             :m_ptr(ptr){}


    ~Auto_ptr3(){
        delete m_ptr;
    }

    //copy constructor: do deep copy of a.m_ptr to m_ptr
    Auto_ptr3(const Auto_ptr3& a){
        m_ptr = new T;        //this translates to m_ptr = new Resource
        *m_ptr = *a.m_ptr;
    }

    //copy assignment: do deep copy of a.m_ptr to m_ptr
    Auto_ptr3& operator=(const Auto_ptr3& a){
        //self-assignment detection
        if (&a == this)
            return *this;

        //release any resource we're holding
        delete m_ptr;

        //copy the resource
        m_ptr  = new T;
        *m_ptr = *a.m_ptr;

        return *this;
    }

    T& operator*() const { return *m_ptr; }
    T* operator->() const { return m_ptr; }

    bool isNull() const { return m_ptr == nullptr; }
};

class Resource{
public:
    Resource() { std::cout << "Resource acquired\n"; }
    ~Resource() { std::cout << "Resource destroyed\n"; }
};

Auto_ptr3<Resource> generateResource(){
    Auto_ptr3<Resource> res(new Resource);  //this invokes the normal constructor of Auto_ptr3 and the constructor of Resource
    return res;                             //this return value will invoke the copy constructor of Auto_ptr3 and res is copy constructed to a temp object
}                                           //res goes out of scope, so the destructor of Resource and Auto_ptr3 are invoked

int main(){

    Auto_ptr3<Resource> mainres;
    mainres = generateResource(); // the temp object is assigned to mainres and the copy assignment is invoked leading to resource allocation again
                                  //the temp object goes out of (expression) scope here so the destructor is invoked once again
    return 0;
}                                 // mainres object goes out of scope and the destructor is invoked once again
