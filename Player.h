#pragma once
#include "Ship.h"
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

	void setShips(std::vector<Ship> shipsArgument);
	std::vector<Ship> getShips();
	bool shotsHistory[5][5]; // tablica przechowuje dla kazdego elementu na planszy informacje czy przeciwnik juz tam strzelal (true) czy jeszcze nie (false)
	void placeShips(UserInterface ui);
	void handleTheShoot(int x, int y);

private:
	std::string playerName;
	std::vector<Ship> ships; // przechowuje stan floty gracza (jego statki)

	void clearShotsHistory();
	bool isThereACollision(Ship tempShip);

};