#include "Ship.h"

void Ship::hitShip(int segment) {
    isHit[segment] = true;
    checkIfSunk();
}

bool Ship::getIsSunk()
{
    return isSunk;
}

int Ship::getSize()
{
    return size;
}

int Ship::getX()
{
    return x;
}

int Ship::getY()
{
    return y;
}

bool Ship::getIsVertical()
{
    return isVertical;
}

bool* Ship::getIsHit()
{
    return isHit;
}

void Ship::checkIfSunk(){
    bool tempIsSunk = true;
    for (int i = 0; i < size; i++) {
        if (isHit[i] == false) {
            tempIsSunk = false;
        }
    }
    isSunk = tempIsSunk;
}
