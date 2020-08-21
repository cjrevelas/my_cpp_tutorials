#include <iostream>
#include <algorithm>
#include "include/student.h"

Student sortStud(Student *stud, const int& length);

int main(){

    int numStudents;
    std::cout << "Enter the number of students: ";
    std::cin  >> numStudents;

    Student *stud = new Student[numStudents];

    for (int ii=0; ii<numStudents; ++ii){
        std::cin >> stud[ii].name;
        std::cin >> stud[ii].grade;
    }

    //std::cout << stud[0].name << " " << stud[0].grade << std::endl;
    //std::cout << stud[1].name << " " << stud[1].grade << std::endl;

    sortStud(stud, numStudents);

    for (int ii = 0; ii<numStudents; ++ii){
         std::cout << stud[ii].name << " got a grade of " << stud[ii].grade << std::endl;
    }

    delete[] stud;
    stud = nullptr;

    return 0;
}

Student sortStud(Student *stud, const int& length){

    for (int startIndex = 0; startIndex < length-1; ++startIndex){

        //largestIndex is the index of the largest element we’ve encountered this iteration
        //start by assuming the largest element is the first element of this iteration
        int largestIndex = startIndex;

        //then look for a larger element in the rest of the array
        for (int currentIndex = startIndex + 1; currentIndex < length; ++currentIndex){

                  //if we've found an element that is larger than our previously found largest
                  if (stud[currentIndex].grade > stud[largestIndex].grade)
                        //then keep track of it
                        largestIndex = currentIndex;
        }

        //largestIndex is now the largest element in the remaining array
        //swap our start element with our largest element (this sorts it into the correct place)
        std::swap(stud[startIndex], stud[largestIndex]);
     }

    return *stud;
}
