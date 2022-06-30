#pragma once
#include "SingleMastedShip.h"

SingleMastedShip::SingleMastedShip(int xArgument, int yArgument)
{
	isHit[0] = false;
	x = xArgument;
	y = yArgument;
	isVertical = true;
	isSunk = false;
	size = 1;
}

bool SingleMastedShip::isWithinTheBoard(int x, int y, bool isVe) {
	if (x < 0 || y < 0 || x > 4 || y > 4) return false;
	else return true;
}
