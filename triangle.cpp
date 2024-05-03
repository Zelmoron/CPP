#include "triangle.h"

double Triangle::calc_perimetr()
{
	double perimetr;
	perimetr = width1 + width2 + width3;
	return perimetr;
}

double Triangle::calc_area()
{
	double Geron;
	double pol_p = calc_perimetr() / 2;
	Geron = sqrt(pol_p * (pol_p - width1) * (pol_p - width2) * (pol_p - width3));
	return Geron;
}

void Triangle::name()
{
	std::cout << "Triangle\n";

}
