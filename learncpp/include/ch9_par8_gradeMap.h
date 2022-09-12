#include <vector>
#include "studentGrade.h"

class GradeMap
{
	private:
		std::vector<StudentGrade> m_map;

	public:
		GradeMap() {} //constructor does not do anything

		char& operator[] (const std::string &student_name); //overload the subscript operator
};

char& GradeMap::operator[] (const std::string &student_name)
{
	//check if the name already exists in the vector
	for (unsigned int i=0; i<m_map.size(); ++i)     //or else a signed/unsigned mismatch compiler warning will occur from the operator <.
	{
		if( student_name == m_map[i].name )
			return m_map[i].grade;
	}

	//if it does not exist, add a new StudentGrade for the new student
	StudentGrade temp = {student_name, ' '};

	//add this StudentGrade to the vector
	m_map.push_back(temp);

	//return the grade component of the added (last) element
	return m_map.back().grade;
}