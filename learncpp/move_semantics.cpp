#include <iostream>

template<class T>
class Auto_ptr4{
    T* m_ptr;

public:
    Auto_ptr4(T* ptr = nullptr)
    :m_ptr(ptr){}

    ~Auto_ptr4(){
        delete m_ptr;
    }

    //move constructor: transfer ownership of a.m_ptr to m_ptr
    Auto_ptr4(Auto_ptr4&& a)
    :m_ptr(a.m_ptr){
        a.m_ptr = nullptr;
    }

    //move assignment operator: transfer ownership of a.m_ptr to m_ptr
    Auto_ptr4& operator=(Auto_ptr4&& a){
        //self-assignment detection
        if (&a == this)
            return *this;

        //release any resource we're holding
        delete m_ptr;

        //transfer ownership of a.m_ptr to m_ptr
        m_ptr = a.m_ptr;
        a.m_ptr = nullptr;

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


Auto_ptr4<Resource> generateResource(){
    Auto_ptr4<Resource> res(new Resource); //this invokes the normal constructor of Auto_ptr4 and the constructor of Resource
        return res;                        //this return value will invoke the move constructor because res is used as an r-value here
                                           //its dynamically allocated Resource object is transferred to the temp object
}                                          //res goes out of scope here. Because res no longer manages a pointer (it was moved to the temp object), nothing interesting happens here


int main(){
    Auto_ptr4<Resource> mainres;
    mainres = generateResource(); //this assignment will invoke the move assignment operator
                                  //the temp object is move assigned to mainres object. this transfers the dynamically allocated Resource object (stored in the temp object) to the mainres Auto_ptr4 object.
                                  //the temp object goes out of expression scope here, but since it no longer manages a pointer (it was moved to mainres object), nothing interesting happens here either.
    return 0;
}                                 //mainres object goes out of scope here and because it does manage a Res object, the Res destructor is invoked and then the Auto_ptr4 destructor frees the allocated memory.
