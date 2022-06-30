#pragma once
#include "Player.h"

class UserInterface {
public:
	void welcomeScreen(); // ekran powitalny (gdzie user ma wybor - "graj" albo "help")
	void help(); // ekran z instrukcja
	void displayResults(); // ekran na koniec gry (kto wygral itd)
	void displayCurrentPlayerBoard(Player player);  // wyswietl moja plansze (moje statki i ich stan)
	void displayRivalsBoard(Player rivalPlayer); // wyswietl plansze przeciwnika (gdzie juz strzelalem, co trafilem, co zaptopilem itd.)
	void askForCoordinates(); // od razu waliduje czy podany input jest wspolrzedna, i czy nie wykracza poza ramy
	
	int getX();
	int getY();
	int getIsVertical();

private:
	int x, y;
	bool isVertical;
};

