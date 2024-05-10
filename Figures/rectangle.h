#pragma once
#include "Abs.h"
#include <iostream>
class Rectangle : public Geometric_Figure {

public:
	Rectangle(double w, double h) : width(w),
		height(h){}
	double calc_area() override;
	double calc_perimetr() override;
	void name() override;
	Rectangle(double x1, double y1, double x2, double y2,
		double x3, double y3, double x4, double y4);
private:
	double width;
	double height;
};