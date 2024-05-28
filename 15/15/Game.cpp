#include "Game.h"
#include <iostream>
#include <conio.h>
void Game::Play()
{
	RequestAndStep(); // запрос на ход
	std::cout << "You Win!";
}

const std::vector<std::vector<int>>& Game::GetMap()
{
	return map_.GetMap();
}

void Game::ShowMap()
{
	system("cls"); //чистим консоль
	map_.PrintMap();
}

void Game::RequestAndStep()
{
	//сделать норм ввод - ВЫПОЛНЕНО
	system("cls");
	map_.PrintMap(); // выводим в консоль карту
	std::cout << "Делай Ход\n";

	int e = 0;
	int flag = 1, r; // При повторном запуске программы можеть быть ошибка, ТАкже необходимо использовать капслок, РУССКИЕ БУКВЫ НЕ ВАЛИДНЫ
	while (flag)
	{
		r = _getch();

		if (r == 65) {// A
			flag = 0;
			map_.Move(1);

		}



		if (r == 68) {
			flag = 0;
			map_.Move(3);

		} //  D


		if (r == 87) {
			flag = 0;
			map_.Move(0);

		} // W


		if (r == 83) {
			flag = 0;
			map_.Move(2);
		} // S


	}
	/*if (mv == 0xE0)
		mv = _getch();
		map_.Move(2);
	if (mv == 0xE0)
		mv = _getch();
		map_.Move();
	if (mv == 0xE0)
		mv = _getch();
		map_.Move(3);*/
		//map_.Move(dir); // кидаем этот ход в класс директория

	if (map_.CheckWin()) {
		return;
	}

	RequestAndStep(); //рекурсия
}