#include "Player.h"

void Player::setShips(std::vector<Ship> shipsArgument)
{
	ships = shipsArgument;
}

std::vector<Ship> Player::getShips()
{
	return ships;
}
