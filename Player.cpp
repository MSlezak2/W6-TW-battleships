#include "Player.h"

Player::Player(std::string nameArgument)
{
	name = nameArgument;
	clearShotsHistory();
}

void Player::setShips(std::vector<Ship> shipsArgument)
{
	ships = shipsArgument;
}

std::vector<Ship> Player::getShips()
{
	return ships;
}

void Player::clearShotsHistory() {
	for (int i = 0; i < sizeof shotsHistory / sizeof shotsHistory[0]; i++) {
		for (int j = 0; j < sizeof shotsHistory[0] / sizeof shotsHistory[0][0]; j++) {
			shotsHistory[i][j] = false;
		}

	}
}
