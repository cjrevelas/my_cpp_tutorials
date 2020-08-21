#include "Point3d.h"
#include "Vector3d.h"
#include <iostream>

void Point3d::print()
{
	std::cout << "Point(" << m_x << " , " << m_y << " , " << m_z << ")\n";
}

void Point3d::moveByVector(const Vector3d &v)
{
	m_x += v.m_x;
	m_y += v.m_y;
	m_z += v.m_z;
}

//Point3d::moveByVector() can also be defined above main() in main.cpp
//In this case, we do not have to include Vector3d.h here (only in main.cpp)