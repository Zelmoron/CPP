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

Rectangle::Rectangle(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
{
	width = sqrt((pow((x2 - x1), 2) + pow((y2 - y1), 2)));
	height = sqrt((pow((x2 - x3), 2) + pow((y2 - y3), 2)));
}
