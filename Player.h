#pragma once
#include <string>
#include <vector>
#include "Ship.h"

class Player {

public:
	Player(std::string nameArgument);
	void setShips(std::vector<Ship> shipsArgument);
	std::vector<Ship> getShips();
	bool shotsHistory[5][5]; // tablica przechowuje dla kazdego elementu na planszy informacje czy przeciwnik juz tam strzelal (true) czy jeszcze nie (false)
	//TODO: make shotsHitsory private again

private:
	std::string name;
	std::vector<Ship> ships; // przechowuje stan floty gracza (jego statki)

	void clearShotsHistory();

};

