#pragma once
#include "Abs.h"
#include <cmath>
#include <iostream>
class Triangle :public Geometric_Figure {
public:
	Triangle(double w1, double w2, double w3) :width1(w1),
		width2(w2),
		width3(w3) {}
	double calc_perimetr() override;
	double calc_area() override;
	void name() override;
	Triangle(double x1, double y1, double x2, double y2,
		double x3, double y3);
private:
	double width1;
	double width2;
	double width3;
};