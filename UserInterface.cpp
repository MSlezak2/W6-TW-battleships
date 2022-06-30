#pragma once
#include "UserInterface.h"
#include "Player.h"
#include <iostream>
#include "GameHandler.h"

void UserInterface::displayCurrentPlayerBoard(Player player) {

	// stworz sobie tablice 2D "board" wypelniona zerami
	char tempBoard[5][5];
	for (int i = 0; i < sizeof tempBoard / sizeof tempBoard[0]; i++) {
		for (int j = 0; j < sizeof tempBoard[0] / sizeof tempBoard[0][0]; j++) {
			tempBoard[i][j] = '0';
		}
	}

	// dla kazdego elementu wektora ships, wypelnij odpowiednie komorki tablicy "board" iksami tam gdzie jest statek
	for (int i = 0;  i < player.getShips().size();  i++) {
		Ship ship = player.getShips()[i];
		int tempX = ship.getX();
		int tempY = ship.getY();
		for (int j = 0; j < ship.getSize(); j++) {
			tempBoard[tempY][tempX] = 'X';
			if (ship.getIsVertical()){
				tempY++;
			} else {
				tempX++;
			}
		}
	}

	// wyswietlenie planszy (na podstawie pomocniczej tablicy "tempBoard"
	std::cout << "  ";
	for (int i = 1; i <= 5; i++)
	{
		std::cout << i;
	}
	std::cout << std::endl;
	for (int i = 0; i < sizeof tempBoard / sizeof tempBoard[0]; i++) {
		std::cout << (char)(65 + i) << " ";
		for (int j = 0; j < sizeof tempBoard[0] / sizeof tempBoard[0][0]; j++) {
			std::cout << tempBoard[i][j];
		}
		std::cout << std::endl;
	}
}



void UserInterface::displayRivalsBoard(Player rivalPlayer) {

	// stworz sobie tablice 2D "board" wypelniona zerami
	char tempBoard[5][5];
	for (int i = 0; i < sizeof tempBoard / sizeof tempBoard[0]; i++) {
		for (int j = 0; j < sizeof tempBoard[0] / sizeof tempBoard[0][0]; j++) {
			tempBoard[i][j] = '0';
		}
	}

	// wez tablice shotsHistory (atrybut obiektu reprezentujacego przeciwnego gracza) i tam gdzie ma jedynke
	// wpisz jedynke do tablicy "board" (jedynka bedzie reprezentowac nietrafienie (MISS))
	for (int i = 0; i < sizeof tempBoard / sizeof tempBoard[0]; i++) {
		for (int j = 0; j < sizeof tempBoard[0] / sizeof tempBoard[0][0]; j++) {
			if (rivalPlayer.shotsHistory[i][j] == true)
			{
				tempBoard[i][j] = 'M';
			}
		}
	}

	// dla kazdego elementu wektora ships (przeciwnik) poszukaj pol ktore zostaly trafione i do tablicy "board"
	// w tych miejscach
	for (int i = 0; i < rivalPlayer.getShips().size(); i++) {
		Ship ship = rivalPlayer.getShips()[i];
		int tempX = ship.getX();
		int tempY = ship.getY();
		bool* isHitPointer = ship.getIsHit();
		for (int j = 0; j < ship.getSize(); j++) {
			if (*isHitPointer == true) {
				if (ship.getIsSunk()) {
					tempBoard[tempY][tempX] = 'S';
				} else {
					tempBoard[tempY][tempX] = 'H';	
				}
			}
			isHitPointer++;
			if (ship.getIsVertical()) {
				tempY++;
			}
			else {
				tempX++;
			}
		}
	}

	// wyswietlenie planszy (na podstawie pomocniczej tablicy "tempBoard"
	std::cout << "  ";
	for (int i = 1; i <= 5; i++)
	{
		std::cout << i;
	}
	std::cout << std::endl;
	for (int i = 0; i < sizeof tempBoard / sizeof tempBoard[0]; i++) {
		std::cout << (char)(65 + i) << " ";
		for (int j = 0; j < sizeof tempBoard[0] / sizeof tempBoard[0][0]; j++) {
			std::cout << tempBoard[i][j];
		}
		std::cout << std::endl;
	}
}

void UserInterface::askForCoordinates() { // od razu waliduje czy podany input jest wspolrzedna, i czy nie wykracza poza ramy

	char columns;
	bool co = false;
	bool ro = false;

	while (co == false)
	{
		std::cout << "select row " << std::endl;
		std::cin >> columns;
		if (columns != 'a' && columns != 'b' && columns != 'c' && columns != 'd' && columns != 'e' && columns != 'A' && columns != 'B' && columns != 'C' && columns != 'D' && columns != 'E') {
			std::cout << "there is no such row" << std::endl;
			//system("cls");
		}
		else co = true;
		//system("cls");
	}
	while (ro == false)
	{
		std::cout << "select column " << std::endl;
		std::cin >> x;
		if (x != 1 && x != 2 && x != 3 && x != 4 && x != 5) {
			std::cout << "there is no such column" << std::endl;
			//system("cls");
		} else {
			ro = true;
			x -= 1;
		}
		//system("cls");
	}
	if (columns == 'a' || columns == 'A')y = 0;
	else if (columns == 'b' || columns == 'B')y = 1;
	else if (columns == 'c' || columns == 'C')y = 2;
	else if (columns == 'd' || columns == 'D')y = 3;
	else if (columns == 'e' || columns == 'E')y = 4;

}

int UserInterface::getX()
{
	return x;
}

int UserInterface::getY()
{
	return y;
}

int UserInterface::getIsVertical()
{
	return isVertical;
}
