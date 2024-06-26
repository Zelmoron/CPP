#pragma once
#include <vector>
const int MAP_SIZE = 4; //размер игрового поля
class Map { //класс игрового поля
public:


	Map(); //КОнструктор
	const std::vector<std::vector<int>>& GetMap(); //обвертка для карты
	void Move(int direction); //Функция отвечающая за ходы
	void PrintMap(); //вывод карты в консоль
	void ScanPos(); //сканировнаие позиции пустой клетки(0)
	bool CheckWin(); //обработка победы
	void ScanPosNumber(); 
	std::pair<int,int> GetZeroPos(); // для получения координат 0
	std::pair <int, int>GetNumberPos(); // для получения коорднат числа(пока что только единицы)
private:

	std::vector<std::vector<int>> map_; //двумерный массив для поля
	std::vector<int>current_pos_0_ = { 0,0 }; //массив координат нуля
	std::vector<int>current_pos_n_ = { 0,0 }; //массив координат нуля
};