#pragma once

class Ship {
public:
	bool isTooCloseToAnotherShip(int x, int y);
	/*virtual*/ bool isWithinTheBoard(int x, int y, bool isVe) {};
	void hitShip(int segment); // only for testing purpose TODO: remove it

	bool getIsSunk();
	int getSize();
	int getX();
	int getY();
	bool getIsVertical();
	bool* getIsHit();
	bool isColliding(Ship anotherShip);
	

protected:
	int x, y;
	int size;
	bool isVertical; // true - pionowo; false - poziomo
	bool isSunk;
	bool isHit[4];

	void checkIfSunk();
};