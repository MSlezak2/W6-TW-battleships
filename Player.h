#pragma once
#include <string>
#include <vector>
#include "Ship.h"

class Player {

public:
	void setShips(std::vector<Ship> shipsArgument);
	std::vector<Ship> getShips();

private:
	std::string name;
	std::vector<Ship> ships; // przechowuje stan floty gracza (jego statki)
	bool shotsHistory[5][5]; // tablica przechowuje dla kazdego elementu na planszy informacje czy przeciwnik juz tam strzelal (true) czy jeszcze nie (false)


};

