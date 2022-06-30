#pragma once
#include "Ship.h"

void Ship::hitShip(int segment) {
    isHit[segment] = true;
    checkIfSunk();
}

bool Ship::getIsSunk() {
    return isSunk;
}

int Ship::getSize() {
    return size;
}

int Ship::getX() {
    return x;
}

int Ship::getY()
{
    return y;
}

bool Ship::getIsVertical() {
    return isVertical;
}

bool* Ship::getIsHit() {
    return isHit;
}

bool Ship::isColliding(Ship anotherShip) {
   
    bool isColliding = false;
    int x0, xk, y0, yk;
    // wyznacz obszar "okupowany" przez ten drugi statek (wspolrzedne wiercholkow prostokata)
    if (anotherShip.getIsVertical()) {
        x0 = anotherShip.getX() == 0 ? 0 : anotherShip.getX() - 1;
        xk = anotherShip.getX() == 5 ? 5 : anotherShip.getX() + 1;
        y0 = anotherShip.getY();
        yk = anotherShip.getY() + anotherShip.getSize() - 1;
    } else {
        x0 = anotherShip.getX();
        xk = anotherShip.getX() + anotherShip.getSize() - 1;
        y0 = anotherShip.getY() == 0 ? 0 : anotherShip.getY() - 1;
        yk = anotherShip.getY() == 5 ? 5 : anotherShip.getY() + 1;
    }

    // znajdz wspolrzedne poczatku i konca statku
    int x1 = x;
    int y1 = y;
    int x2 = isVertical ? x : x + size - 1;
    int y2 = isVertical ? y + size - 1 : y;
    
    // sprawdz czy jest kolizja (patrz schemat - przypadek 2)
    if ((x1 >= 0 && x1 <= x0) && (x2 >= xk) && (y1 >= y0 && y1 <= yk)) {
        isColliding = true;
    }

    // sprawdz czy jest kolizja (patrz schemat - przypadek 6)
    if ((y1 >= 0 && y1 <= y0) && (y2 >= yk) && (x1 >= x0 && x1 <= xk)) {
        isColliding = true;
    }

    // sprawdz czy jest kolizja (patrz schemat - pozostale przypadki)
    if ( ((x1 >= x0 && x1 <= xk) || (x2 >= x0 && x2 <= xk)) && ((y1 >= y0 && y1 <= yk) || (y2 >= y0 && y2 <= yk))) {
        isColliding = true;
    }

    // sprawdz czy nie ma kolizji "za wierzcholkami" statku
    if (anotherShip.getIsVertical()) {

    }


    return isColliding;
}

void Ship::checkIfSunk() {
    bool tempIsSunk = true;
    for (int i = 0; i < size; i++) {
        if (isHit[i] == false) {
            tempIsSunk = false;
        }
    }
    isSunk = tempIsSunk;
}
