#pragma once
#include "Ship.h"
class TwoMastedShip :
    public Ship
{
private:
    bool isHit[2]; // false - nieuszkodzony; true - uszkodzony
    bool isSunk;
};

