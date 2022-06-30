#pragma once
#include "Ship.h"
//#include "UserInterface.h"
#include "TwoMastedShip.h"
#include <string>
#include <vector>

class UserInterface; // forward declaration to prevent circular include dependency

class Player
{
public:
	Player();
	Player(std::string nameArgument);
	std::string getName();
	void setName();
	int howManyHits{0};
	
/* funkcje Michala i Wojtka */
	void setShips(std::vector<Ship> shipsArgument);
	std::vector<Ship> getShips();
	bool shotsHistory[5][5]; // tablica przechowuje dla kazdego elementu na planszy informacje czy przeciwnik juz tam strzelal (true) czy jeszcze nie (false)
	//TODO: make shotsHitsory private again
	void placeShips(UserInterface ui);
/**/

private:
	std::string playerName;

	std::vector<Ship> ships; // przechowuje stan floty gracza (jego statki)

	void clearShotsHistory();
	bool isThereACollision(Ship tempShip);

};