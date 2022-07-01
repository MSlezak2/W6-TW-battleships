#pragma once
#include <iostream>
#include "Player.h"

class UserInterface
{
public:
	int choice;
	void welcomeScreen();
	int getUserMenuChoice();
	void mainMenu(int choice);
	void help(); // ekran z instrukcja
	void displayWelcomeSign();
	void displayEndGameSign(); // ekran na koniec gry (kto wygral itd)

/* funkcje Michala i Wojtka */
	void displayCurrentPlayerBoard(Player player);  // wyswietl moja plansze (moje statki i ich stan)
	void displayRivalsBoard(Player rivalPlayer); // wyswietl plansze przeciwnika (gdzie juz strzelalem, co trafilem, co zaptopilem itd.)
	void askForCoordinates(); // od razu waliduje czy podany input jest wspolrzedna, i czy nie wykracza poza ramy
	bool askIfVertical();

	int getX();
	int getY();
	int getIsVertical();
/**/

private:
	int x, y;
	bool isVertical;
};

