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
Triangle::Triangle(double x1, double y1, double x2, double y2, double x3, double y3)
{
	width1 = sqrt((pow((x2 - x1), 2) + pow((y2 - y1), 2)));
	width2 = sqrt((pow((x3 - x1), 2) + pow((y3 - y1), 2)));
	width3 = sqrt((pow((x3 - x2), 2) + pow((y3 - y2), 2)));
}

void Triangle::name()
{
	std::cout << "Triangle\n";

}
