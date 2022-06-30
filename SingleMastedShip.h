#pragma once
#include "Ship.h"
class SingleMastedShip :
    public Ship
{
public:
    SingleMastedShip(int xArgument, int yArgument);
    //bool isWithinTheBoard(int x, int y, bool isVe);
    //bool isHit; // false - nieuszkodzony; true - uszkodzony
    // TODO: make isHit private again

private:
};