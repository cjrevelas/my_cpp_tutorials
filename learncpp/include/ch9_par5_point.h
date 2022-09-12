class Point 
{
	private:
		double m_x;
		double m_y;
		double m_z;

	public:

	//constructor
	Point (double x = 0.0, double y = 0.0, double z = 0.0)
		: m_x(x), m_y(y), m_z(z)
	{
	}

	//Convert the point to its negative equivalent
	Point operator-();  //maybe the "const" keyword must be added after the parenthesis

	//Convert the point to its positive equivalent
	Point operator+();  //maybe the "const" keyword must be added after the parenthesis

	//Return true if the point is set at the origin
	bool operator!();   //maybe the "const" keyword must be added after the parenthesis

	double getX() { return m_x; }
	double getY() { return m_y; }
	double getZ() { return m_z; }
};

//define function bodies
Point Point::operator-()
{
	return Point(-m_x, -m_y, -m_z);
}

Point Point::operator+()
{
	return Point(+m_x, +m_y, +m_z);
	// return *this; ---> This would also work because we are returning exactly the same thing we are operating on
}

bool Point::operator!()
{
	return (m_x == 0.0 && m_y == 0.0 && m_z == 0.0);
}