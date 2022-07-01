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