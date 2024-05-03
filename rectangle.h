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
	
private:
	double width;
	double height;
};