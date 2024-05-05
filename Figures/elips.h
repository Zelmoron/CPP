#pragma once
#include "Abs.h"
#include <iostream>

class Elips :public Geometric_Figure {
public:

	Elips(int x,int y,double r,double r2):x(x),
		y(y),
		radius1(r),
		radius2(r2){}
	double calc_area() override;
	double calc_perimetr() override;
	void name() override;
private:
	int x, y;
	double radius1, radius2;
};