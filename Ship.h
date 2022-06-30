#pragma once

class Ship {
public:
	/*virtual*/ bool isWithinTheBoard();
	void hitShip(int segment); // only for testing purpose TODO: remove it

	bool handleTheShoot(int shootX, int shootY);

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