#include <iostream>
#include "Player.h"
#include "SingleMastedShip.h"
#include "TwoMastedShip.h"

int main() {

	Player player_1;

	SingleMastedShip ship_1;
	SingleMastedShip ship_2;
	TwoMastedShip ship_3;
	std::vector<Ship> tempShips;
	tempShips.push_back(ship_1);
	tempShips.push_back(ship_2);
	tempShips.push_back(ship_3);
	player_1.setShips(tempShips);

	for (int i = 0; i < player_1.getShips().size(); i++)
	{
		std::cout << player_1.getShips()[i].getIsSunk();
	}

	//std::string input;
	//getchar();
	std::cout << "test";

	return 0;
}