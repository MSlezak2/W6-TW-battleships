#pragma once
#include "Ship.h"
class SingleMastedShip :
    public Ship
{
private:
    bool isHit; // false - nieuszkodzony; true - uszkodzony
    bool isSunk;
};