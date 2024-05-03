#include "circl.h"

double Circl::calc_area()
{
	double area = 3.14 * radius * radius;
	return area;
}

double Circl::calc_perimetr()
{
	double perimetr = 2 * 3.14 * radius;
	return perimetr;
}

void Circl::name()
{
	std::cout << "Circl\n";
}