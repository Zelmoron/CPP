#pragma once
#include <vector>
#include "Map.h"
class Game { // класс для игры в 15
public:
	void Play();

	const std::vector<std::vector<int>>& GetMap();

	void ShowMap();


private:

	void RequestAndStep();
	Map map_;

};