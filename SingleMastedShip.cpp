#include "SingleMastedShip.h"

SingleMastedShip::SingleMastedShip(int xArgument, int yArgument, bool isVerticalArgument)
{
	isHit[0] = false;
	x = xArgument;
	y = yArgument;
	isVertical = isVerticalArgument;
	isSunk = false;
	size = 1;
}


