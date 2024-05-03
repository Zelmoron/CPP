#include "rectangle.h"

double Rectangle::calc_area()
{
	double area;
	area = width * height;
	return area;

}

double Rectangle::calc_perimetr()
{
	double perimetr = 2 * (width + height);
	return perimetr;
}

void Rectangle::name()
{
	std::cout << "Rectangle\n";
}
