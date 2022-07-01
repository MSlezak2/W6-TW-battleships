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
