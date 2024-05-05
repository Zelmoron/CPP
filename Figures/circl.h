#pragma once
#include "Abs.h"
#include <iostream>

class Circl :public Geometric_Figure {
public:
	Circl(int x,int y,double r):x(x),
		y(y),
		radius(r){}
	double calc_area() override;
	double calc_perimetr() override;
	void name() override;
private:
	int x, y;
	double radius;

};