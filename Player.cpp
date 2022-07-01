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

	// prompt user to enter coordinates of twomasted ship and validate ( 1. are they in correct format / 2. aren't they out of range / 3. isn't the end of the boat outside of the border?)
	bool collisionOccured = true;
	bool isOutsideOfTheBoard = true;
	Ship tempShip;
	int x, y;
	int temp_is_vertical;
	do {
		std::cout << "Place your two-masted ship:" << std::endl;
		// read coordinates
		ui.askForCoordinates();
		x = ui.getX();
		y = ui.getY();

		temp_is_vertical = ui.askIfVertical();
		tempShip = TwoMastedShip(x, y, temp_is_vertical);

		// validate (4. is there a collision?):
		isOutsideOfTheBoard = !tempShip.isWithinTheBoard();
		collisionOccured = isThereACollision(tempShip);
	} while (collisionOccured || isOutsideOfTheBoard);
	// create ship and put it into "ships" vector
	ships.push_back(tempShip);
	system("cls");
	ui.displayCurrentPlayerBoard(*this);

	for (int i = 0; i < 2; i++) {
		// do the same thing for onemasted ship but twice
		collisionOccured = true;
		do {
			// read coordinates
			std::cout << "Place your single-masted ship:" << std::endl;
			ui.askForCoordinates();
			x = ui.getX();
			y = ui.getY();

			temp_is_vertical = true;
			tempShip = SingleMastedShip(/*temp_x, temp_y*/x, y);

			// validate (4. is there a collision?):
			collisionOccured = isThereACollision(tempShip);
		} while (collisionOccured);
		// create ship and put it into "ships" vector
		ships.push_back(tempShip);
		system("cls");
		ui.displayCurrentPlayerBoard(*this);
	}
	system("pause");
}

void Player::handleTheShoot(int x, int y) {
	for (int i = 0; i < ships.size(); i++) {
		bool hit = ships[i].handleTheShoot(x, y);
		if (hit) {
			howManyHits++;
		}
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
