#pragma once
#include <cmath>
class A {
	float GetLength(int x1, int y1, int x2, int y2) {
		return sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
	}

	int GetLengthLine(int x1, int y1, int x2, int y2) {
		return abs(x1 - x2) + abs(y1 - y2);
	}
};