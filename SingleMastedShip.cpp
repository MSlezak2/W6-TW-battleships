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

//bool SingleMastedShip::isWithinTheBoard(int newX, int newY, bool isVe) {
//	if (newX < 0 || newY < 0 || newX > 4 || newY > 4) return false;
//	else return true;
//}
