#pragma once
#include "Player.h"
#include "UserInterface.h"
#include <iostream>



Player::Player(std::string nameArgument) {
	name = nameArgument;
	clearShotsHistory();
}

void Player::setShips(std::vector<Ship> shipsArgument) {
	ships = shipsArgument;
}

std::vector<Ship> Player::getShips() {
	return ships;
}

void Player::placeShips(UserInterface ui) {

	// TODO: Make constants that will hold how many units of different ships should there be

	// prompt user to enter coordinates of twomasted ship and validate ( 1. are they in correct format / 2. aren't they out of range / 3. isn't the end of the boat outside of the border?)
	bool collisionOccured;
	TwoMastedShip tempShip;
	do {
		ui.askForCoordinates();
		int x = ui.getX();
		int y = ui.getY();

		// read coordinates

		//int temp_x = 0;
		//int temp_y = 2;
		int temp_is_vertical = true;
		tempShip = TwoMastedShip(/*temp_x, temp_y*/x, y, temp_is_vertical);

		// validate (4. is there a collision?):
		collisionOccured = isThereACollision(tempShip);
		std::cout << collisionOccured;
	} while (collisionOccured);
	
	// create ship and put it into "ships" vector
	ships.push_back(tempShip);

	// do the same thing for onemasted ship but twice
}

void Player::clearShotsHistory() {
	for (int i = 0; i < sizeof shotsHistory / sizeof shotsHistory[0]; i++) {
		for (int j = 0; j < sizeof shotsHistory[0] / sizeof shotsHistory[0][0]; j++) {
			shotsHistory[i][j] = false;
		}
	}
}

bool Player::isThereACollision(Ship tempShip) {
	bool collision = false;

	// iteruj po kazdym statku
	for (int i = 0; i < ships.size(); i++) {
		if (tempShip.isColliding(ships[i])) {
			collision = true;
		}
	}

	return collision;
}
