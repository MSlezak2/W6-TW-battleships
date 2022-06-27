#pragma once
#include "Board.h"

class Ship {
public:
	bool isTooCloseToAnotherShip(int x, int y, Board board);
	bool isWithinTheBoard(int x, int y, Board board);

	bool isHit(int x, int y);

protected:
	int x, y;
	bool isVertical; // true - pionowo; false - poziomo
};