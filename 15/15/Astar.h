#pragma once
#include <cmath>
class A {
public:
	void AutoGame() {
		Map a,b;
		std::pair<int,int> p1 = a.GetZeroPos();
		std::cout << p1.first<<" "<<p1.second<<std::endl;
		std::pair<int, int>p2 = b.GetNumberPos();
		std::cout << p2.first << " " << p2.second;

	}

	float GetLength(int x1, int y1, int x2, int y2) {
		return sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
	}

	int GetLengthLine(int x1, int y1, int x2, int y2) {
		return abs(x1 - x2) + abs(y1 - y2);
	}

	
};