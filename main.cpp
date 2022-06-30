#pragma once
#include <iostream>
#include "Player.h"
#include "SingleMastedShip.h"
#include "TwoMastedShip.h"
#include "UserInterface.h"

int main() {
	Player player_1 = Player("player_1");
	
	// mockowanie vectora ze statkami:
	SingleMastedShip ship_1 = SingleMastedShip(3,2);
	SingleMastedShip ship_2 = SingleMastedShip(4, 4);
	ship_2.hitShip(0);
	TwoMastedShip ship_3 = TwoMastedShip(1, 1, true);
	ship_3.hitShip(0);
	std::vector<Ship> tempShips;
	tempShips.push_back(ship_1);
	tempShips.push_back(ship_2);
	tempShips.push_back(ship_3);
	player_1.setShips(tempShips);

	player_1.shotsHistory[0][4] = true;
	// wyswietlanie planszy obecnego gracza

	UserInterface ui;
	ui.displayCurrentPlayerBoard(player_1);

	// wyswietlanie planszy przeciwnika
	std::cout << std::endl;
	ui.displayRivalsBoard(player_1);

	player_1.placeShips(ui);

	ui.displayCurrentPlayerBoard(player_1);

	getchar();
	std::cout << "test";

	return 0;
}