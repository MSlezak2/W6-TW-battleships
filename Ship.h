#pragma once

class Ship {
public:
	bool isTooCloseToAnotherShip(int x, int y);
	bool isWithinTheBoard(int x, int y);
	void hitShip(int segment); // only for testing purpose TODO: remove it

	bool getIsSunk();
	int getSize();
	int getX();
	int getY();
	bool getIsVertical();
	bool* getIsHit();
	

protected:
	int x, y;
	int size;
	bool isVertical; // true - pionowo; false - poziomo
	bool isSunk;
	bool isHit[4];

	void checkIfSunk();
};