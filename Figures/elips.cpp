#include "elips.h"

double Elips::calc_area()
{
	double area = radius1 * radius2 * 3.14;
	return area;
}

double Elips::calc_perimetr()
{

	double perimetr = 4 * ((3.14 * radius1 * radius2 + (radius1 - radius2)) / (radius1 + radius2));
	return perimetr;
}

void Elips::name()
{
	std::cout << "Elips\n";
}
