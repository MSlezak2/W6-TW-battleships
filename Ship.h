#pragma once

class Ship {
public:
	/*virtual*/ bool isWithinTheBoard();

	bool handleTheShoot(int shootX, int shootY);

	bool getIsSunk();
	int getSize();
	int getX();
	int getY();
	bool getIsVertical();
	bool* getIsHit();
	bool isColliding(Ship anotherShip);

	void doesIntesectsWithTheArea(int x1, int x0, int x2, int xk, int y1, int y0, int yk, bool& isColliding, int y2);

protected:
	int x, y;
	int size;
	bool isVertical; // true - pionowo; false - poziomo
	bool isSunk;
	bool isHit[4];

	void checkIfSunk();
};