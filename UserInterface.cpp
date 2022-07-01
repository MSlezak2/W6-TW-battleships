#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include "UserInterface.h"
#include "GameHandler.h"
#include "Player.h"


void UserInterface::displayWelcomeSign() {

	std::cout << std::endl;
	std::cout <<"  ______       _____     ______    ______    __         ______      ______     __  __     __     ______  \n";
	std::cout <<" /\\  == \\    /\\  __ \\   /\\__  _\\  /\\__  _\\  /\\ \\       /\\   ___\\   /\\  ___\\   /\\ \\_\\ \\   /\\ \\   /\\  == \\  \n";
	std::cout <<" \\ \\  __ <   \\ \\  __ \\  \\/_/\\ \\/  \\/_/\\ \\/  \\ \\ \\____  \\ \\   __\\   \\ \\___ \\   \\ \\  __ \\  \\ \\ \\  \\ \\   _/   \n";
	std::cout <<"  \\ \\ _____\\  \\ \\_\\ \\_\\    \\ \\_\\     \\ \\_\\   \\ \\_____\\  \\ \\______\\  \\/\\_____\\  \\ \\_\\ \\_\\  \\ \\_\\  \\ \\_\\     \n";
	std::cout <<"   \\/______/   \\/_/\\/_/     \\/_/      \\/_/    \\/_____/   \\/______/   \\/_____/   \\/_/\\/_/   \\/_/   \\/_/    \n";
}

void UserInterface::displayEndGameSign() {

	system("cls");
	std::cout << "  ______      _____     __   __     ______        ______       _   _     ______      ______    \n";
	std::cout << " /\\ ____\\   /\\  __ \\   /\\  \\/  \\   /\\  ____\\     /\\   __ \\   /\\ \\ \\ \\   /\\   ___\\   /\\  _  \\     \n";
	std::cout << " \\ \\  ____  \\ \\  __ \\  \\ \\  __  \\  \\ \\   __\\     \\ \\  \\_\\ \\  \\ \\ \\ \\ \\  \\ \\   __\\   \\ \\   _/        \n";
	std::cout << "  \\ \\ ____\\\  \\ \\_\\ \\_\\  \\ \\_\\ \\ _\\  \\  \\_____\\    \\ \\______\\  \\ \\_\\_\\ \\  \\ \\______\\  \\_\\_\\ _\\      \n";
	std::cout << "   \\/______/  \\/_/\\/_/   \\/_/ \\/_/   \\/______/     \\/______/   \\/_____/   \\/______/   \\/_/\\/_/     \n";
}

void UserInterface::welcomeScreen() {

	displayWelcomeSign();
	system("Color F0");

	std::cout << "\n\n\t\tWelcome to our Battle of Midway !\n"
		"\n\t1. - Press if you want to take part in an excellent battle."
		"\n\t2. - Press if you want to see the help panel."
		"\n\t3. - Press to exit game.\n" << std::endl;
}

int UserInterface::getUserMenuChoice() {
	std::string input{};
	while (true) {
		welcomeScreen();

		std::cout << "\t>> ";
		std::getline(std::cin, input);

		if ((input == "1") || (input == "2")  || (input == "3"))
			break;
		else {
			std::cout << "Invalid input. Try again!\n" << std::endl;

			system("pause");
			system("cls");
		}
	}
	return std::stoi(input);
}


void UserInterface::mainMenu(int choice) {

		switch (choice) {

		case 1: 
			break;

		case 2:
			help();
			break;

		case 3:
			std::cout << "\n\t--- OK, Bye! See you next time! ---\n";
			exit(0);
			break;
		}
}

void UserInterface::help() {
		char temp;
		system("Color 0F");
		std::cout << "\t _________________________________________________________" << std::endl;
		std::cout << "\t|                                                         |" << std::endl;
		std::cout << "\t|                                                         |" << std::endl;
		std::cout << "\t|                     Welcome in help!                    |" << std::endl;
		std::cout << "\t|                                                         |" << std::endl;
		std::cout << "\t|_________________________________________________________|" << std::endl;
		std::cout << "\t _________________________________________________________" << std::endl;
		std::cout << "\t|                       HOW TO PLAY                       |" << std::endl;
		std::cout << "\t|                                                         |" << std::endl;
		std::cout << "\t|  Decide who will go first. You and your opponent will   |" << std::endl;
		std::cout << "\t|  alternate turns calling one shot per turn to try and   |" << std::endl;
		std::cout << "\t|                  hit each other's ships.                |" << std::endl;
		std::cout << "\t|_________________________________________________________|" << std::endl;
		std::cout << "\t _________________________________________________________" << std::endl;
		std::cout << "\t|                    PREPARE FOR BATTLE                   |" << std::endl;
		std::cout << "\t|                                                         |" << std::endl;
		std::cout << "\t| 1. Place each ship in any horizontal or vertical        |" << std::endl;
		std::cout << "\t|    position, but not diagonally.                        |" << std::endl;
		std::cout << "\t| 2. Do not place a ship so that any part of it over laps |" << std::endl;
		std::cout << "\t|    letters, numbers, the edge of the grid or another    |" << std::endl;
		std::cout << "\t|    ship.                                                |" << std::endl;
		std::cout << "\t| 3. Do not change the position of any ship once the game |" << std::endl;
		std::cout << "\t|    has begun.                                           |" << std::endl;
		std::cout << "\t|_________________________________________________________|" << std::endl;
		std::cout << "\t _________________________________________________________" << std::endl;
		std::cout << "\t|                      CALL YOUR SHOT!                    |" << std::endl;
		std::cout << "\t|                                                         |" << std::endl;
		std::cout << "\t| On your turn, pick a target hole on your upright target |" << std::endl;
		std::cout << "\t| grid and call out its location by letter and number.    |" << std::endl;
		std::cout << "\t| Each target hole has a letter-number coordinate that    |" << std::endl;
		std::cout << "\t| corresponds with the same coordinate on your opponent's |" << std::endl;
		std::cout << "\t| ocean grid. To determine each coordinate, find its      |" << std::endl;
		std::cout << "\t| coressponding letter on left side of the target grid    |" << std::endl;
		std::cout << "\t| and its number of the top of the grid.                  |" << std::endl;
		std::cout << "\t|_________________________________________________________|" << std::endl;
		std::cout << "\t _________________________________________________________" << std::endl;
		std::cout << "\t|                      WINNING THE GAME                   |" << std::endl;
		std::cout << "\t|                                                         |" << std::endl;
		std::cout << "\t|   If you're the foirst player to sink yopur opponent's  |" << std::endl;
		std::cout << "\t|   entire fleet of ships, you win the game!              |" << std::endl;
		std::cout << "\t|_________________________________________________________|" << std::endl;
		std::cout << "\n" << std::endl;

		system("pause");
		system("cls");
}

void UserInterface::displayCurrentPlayerBoard(Player player) {

	// stworz sobie tablice 2D "board" wypelniona zerami
	char tempBoard[5][5];
	for (int i = 0; i < sizeof tempBoard / sizeof tempBoard[0]; i++) {
		for (int j = 0; j < sizeof tempBoard[0] / sizeof tempBoard[0][0]; j++) {
			tempBoard[i][j] = '0';
		}
	}

	// dla kazdego elementu wektora ships, wypelnij odpowiednie komorki tablicy "board" iksami tam gdzie jest statek
	for (int i = 0; i < player.getShips().size(); i++) {
		Ship ship = player.getShips()[i];
		int tempX = ship.getX();
		int tempY = ship.getY();
		for (int j = 0; j < ship.getSize(); j++) {
			tempBoard[tempY][tempX] = 'X';
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
		std::cout << i << " ";
	}
	std::cout << std::endl;
	for (int i = 0; i < sizeof tempBoard / sizeof tempBoard[0]; i++) {
		std::cout << (char)(65 + i) << " ";
		for (int j = 0; j < sizeof tempBoard[0] / sizeof tempBoard[0][0]; j++) {
			std::cout << tempBoard[i][j] << " ";
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
				}
				else {
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
		std::cout << i << " ";
	}
	std::cout << std::endl;
	for (int i = 0; i < sizeof tempBoard / sizeof tempBoard[0]; i++) {
		std::cout << (char)(65 + i) << " ";
		for (int j = 0; j < sizeof tempBoard[0] / sizeof tempBoard[0][0]; j++) {
			std::cout << tempBoard[i][j] << " ";
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
		}
		else {
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

bool UserInterface::askIfVertical() {
	bool isVertical;
	std::string userInput;
	char letter = ' ';

	std::cout << "(V)ertical or (H)orizontal?" << std::endl;
	std::cin >> userInput;
	std::transform(userInput.begin(), userInput.end(), userInput.begin(), ::toupper);
	letter = userInput.at(0);
	while (letter != 'V' && letter != 'H') {
		std::cout << "Did I stutter?! (V)ertical or (H)orizontal?" << std::endl;
		std::cin >> userInput;
		std::transform(userInput.begin(), userInput.end(), userInput.begin(), ::toupper);
		letter = userInput.at(0);
	}

	switch (letter)
	{
	case 'V':
		isVertical = true;
		break;
	case 'H':
		isVertical = false;
		break;
	}

	return isVertical;
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
