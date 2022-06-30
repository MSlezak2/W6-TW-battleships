#include "Player.h"
#include <iostream>
#include <string>

#include "UserInterface.h"
#include "SingleMastedShip.h"

Player::Player() {
	clearShotsHistory();
}

Player::Player(std::string nameArgument) {
	playerName = nameArgument;
	clearShotsHistory();
}

std::string Player::getName() {
	return playerName;
}

void Player::setName(){
	std::cin >> playerName;
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
	bool collisionOccured = true;
	bool isOutsideOfTheBoard = true;
	Ship tempShip;
	int x, y;
	int temp_is_vertical;
	do {
		// read coordinates
		ui.askForCoordinates();
		x = ui.getX();
		y = ui.getY();

		temp_is_vertical = true;
		tempShip = TwoMastedShip(x, y, temp_is_vertical);

		// validate (4. is there a collision?):
		isOutsideOfTheBoard = tempShip.isWithinTheBoard();
		collisionOccured = isThereACollision(tempShip);
	} while (collisionOccured || isOutsideOfTheBoard);
	// create ship and put it into "ships" vector
	ships.push_back(tempShip);
	ui.displayCurrentPlayerBoard(*this);

	for (int i = 0; i < 2; i++) {
		// do the same thing for onemasted ship but twice
		collisionOccured = true;
		do {
			// read coordinates
			ui.askForCoordinates();
			x = ui.getX();
			y = ui.getY();

			//int temp_x = 0;
			//int temp_y = 2;
			temp_is_vertical = true;
			tempShip = SingleMastedShip(/*temp_x, temp_y*/x, y);

			// validate (4. is there a collision?):
			collisionOccured = isThereACollision(tempShip);
		} while (collisionOccured);
		// create ship and put it into "ships" vector
		ships.push_back(tempShip);
		ui.displayCurrentPlayerBoard(*this);
	}
	
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
