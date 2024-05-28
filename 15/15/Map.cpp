#include "Map.h"
#include <iostream>

Map::Map() : map_(MAP_SIZE, std::vector<int>(MAP_SIZE))
{
	std::vector<int> random_numbers; //создал вектор для рандомных чисел
	for (int i = 0; i <= 15; i++) {
		random_numbers.push_back(i); //0..15
	}
	srand(time(0));
	for (int j = 0; j < 10; j++) { // для рандомных чисел 
		for (int i = 0; i < random_numbers.size(); ++i)
			std::swap(random_numbers[i], random_numbers[std::rand() % random_numbers.size()]); //0..15
	}
	for (int i = 0; i < MAP_SIZE; i++) {
		for (int j = 0; j < MAP_SIZE; j++) {
			map_[i][j] = random_numbers.back(); // в вектор(игровое поле) закидываем случайные числа
			random_numbers.pop_back(); //чтобы не было повторений чистим вектор
		}
	}

	//map_ = {
	//	{1,2,3,4},
	//	{5,6,7,8},								// для быстрой победы
	//	{9,10,11,12},
	//	{13,14,0,15}
	//};

	//map_ = {
	//	{4,15,1,12},
	//	{3,6,13,9},								// Пример с картинки
	//	{5,10,7,8},
	//	{2,14,11,0}
	//};

	ScanPos(); // ищем 0
	ScanPosNumber();
}

const std::vector<std::vector<int>>& Map::GetMap()
{
	return map_;
}

void Map::Move(int direction)
{ //функция для перемещения нолика(пустой клетки)

	//      0
	//		|
	//	3-------1
	//		|
	//		2
	int x = current_pos_0_[0];
	int y = current_pos_0_[1];
	try { // если у нас не валидная клавиша, то просто ничего не делаем

		if (direction == 0) {
			std::swap(map_.at(x - 1).at(y), map_.at(x).at(y)); // меняем местами координту 0 и верхней ячейки
			current_pos_0_ = { x - 1,y };// через at обрабатываем ошибку для выходв за пределы вектора
		}


		if (direction == 2) {											// по аналогии вниз вправо влево
			std::swap(map_.at(x + 1).at(y), map_.at(x).at(y));
			current_pos_0_ = { x + 1,y };
		}


		if (direction == 1) {
			std::swap(map_.at(x).at(y - 1), map_.at(x).at(y));
			current_pos_0_ = { x,y - 1 };
		}



		if (direction == 3) {
			std::swap(map_.at(x).at(y + 1), map_.at(x).at(y));
			current_pos_0_ = { x,y + 1 };
		}



	}
	catch (...) {}// ловим ошибку на нажатие неправиоьно клавишп


}

void Map::PrintMap()
{ //вывод в консоль

	for (int i = 0; i < MAP_SIZE; i++) {
		for (int j = 0; j < MAP_SIZE; j++) {
			if (map_[i][j] / 10 == 1) { // просто для красоты
				std::cout << " " << map_[i][j] << " | ";
			}
			else {
				std::cout << "  " << map_[i][j] << " | ";
			}

		}
		std::cout << std::endl << std::string(20, '-') << std::endl;
	}
}

void Map::ScanPos()
{// функция, для первого определения координаты нуля
	for (int i = 0; i < MAP_SIZE; i++) {
		for (int j = 0; j < MAP_SIZE; j++) {
			if (map_[i][j] == 0) {
				current_pos_0_ = { i,j };
			}
		}
	}
}

bool Map::CheckWin()
{ // проверка на победу
	bool is_win = true;
	for (int i = 0; i < MAP_SIZE; i++) {
		for (int j = 1; j <= MAP_SIZE; j++) {
			if (map_[i][j - 1] != i * MAP_SIZE + j
				&& !(i == MAP_SIZE - 1 && j == MAP_SIZE)) { //если клетка не равна последней
				is_win = false;
			}
		}
	}
	return is_win;
}

void Map::ScanPosNumber()
{
	for (int i = 0; i < MAP_SIZE; i++) {
		for (int j = 0; j < MAP_SIZE; j++) {
			if (map_[i][j] == 1) {
				current_pos_n_ = { i,j };
			}
		}
	}
}

std::pair<int,int> Map::GetZeroPos()
{
	int x = current_pos_0_[0];
	int y = current_pos_0_[1];
	std::pair <int,int> p1(x,y);
	return p1;
}


std::pair<int, int> Map::GetNumberPos() 
{
	int x2 = current_pos_n_[0];
	int y2 = current_pos_n_[1];
	std::pair <int, int> p2(x2, y2);
	return p2;
}

