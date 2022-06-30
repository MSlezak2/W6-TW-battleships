#pragma once
#include "TwoMastedShip.h"

TwoMastedShip::TwoMastedShip()
{

}

TwoMastedShip::TwoMastedShip(int xArgument, int yArgument, bool isVerticalArgument)
{
	isHit[0] = false;
	isHit[1] = false;
	x = xArgument;
	y = yArgument;
	isVertical = isVerticalArgument;
	isSunk = false;
	size = 2;
}

bool TwoMastedShip::isWithinTheBoard(int x, int y, bool isVe) {
	if (isVe == true) {
		if (x < 0 || y < 0 || x > 4 || y > 4 || y + 1 > 4) return false; //y pion
	}
	else if (isVe != true) {
		if (x < 0 || y < 0 || x > 4 || y > 4 || x + 1 > 4) return false;
	}
	else return true;
}