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
//
//bool TwoMastedShip::isWithinTheBoard(int newX, int newY, bool isVe) {
//	if (isVe == true) {
//		if (newX < 0 || newY < 0 || newX > 4 || newY > 4 || newY + 1 > 4) return false; //y pion
//	}
//	else if (isVe != true) {
//		if (newX < 0 || newY < 0 || newX > 4 || newY > 4 || newX + 1 > 4) return false;
//	}
//	else return true;
//}