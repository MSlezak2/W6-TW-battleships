#pragma once

class Ship {
public:
	bool isTooCloseToAnotherShip(int x, int y);
	bool isWithinTheBoard(int x, int y);

	bool isHit(int x, int y);
	bool getIsSunk();

protected:
	int x, y;
	bool isVertical; // true - pionowo; false - poziomo
	bool isSunk;
};