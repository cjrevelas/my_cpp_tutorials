#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

class Person{
protected:
    std::string m_name;
    int m_age;

public:
    Person(){}

    virtual void getdata(){}
    virtual void putdata(){}

    virtual ~Person(){}
};


class Student : public Person{
private:
    int m_id;
    static int idGen;
    std::vector<int> m_marks;

public:
    Student(){
        Person();
        m_id = ++idGen;
    }

    virtual void getdata(){
        std::cin >> m_name >> m_age;
        int temp;
        for (int ii=0; ii<6; ++ii){
            std::cin >> temp;
            m_marks.push_back(temp);
        }
        std::cin.ignore(11000,'\n');
    }

    virtual void putdata(){
        int sum = 0;
        for (int ii = 0; ii<m_marks.size(); ++ii){
            sum += m_marks[ii];
        }
        std::cout << m_name << ' ' << m_age << ' ' << sum << ' ' << m_id << std::endl;
    }

    virtual ~Student(){}
};


class Professor : public Person{
private:
    int m_pubs, m_id;
    static int idGen;

public:
    Professor(){
        Person();
        m_id = ++idGen;
    }

    virtual void getdata(){
        std::cin >> m_name >> m_age >> m_pubs;
        std::cin.ignore(11000,'\n');
    }

    virtual void putdata(){
        std::cout << m_name << ' ' << m_age << ' ' << m_pubs << ' ' << m_id << std::endl;
    }

    virtual ~Professor(){}
};

int Professor::idGen=0;
int Student::idGen=0;

int main(){
    int n, val;
    std::cin>>n;
    Person *per[n];

    for(int i = 0;i < n;i++){

        std::cin>>val;
        if(val == 1){
            per[i] = new Professor;
        }
        else per[i] = new Student;

        per[i]->getdata();
    }

    for(int i=0;i<n;i++)
        per[i]->putdata();

    return 0;
}
