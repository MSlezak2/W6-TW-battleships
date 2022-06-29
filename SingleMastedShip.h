#pragma once
#include "Ship.h"
class SingleMastedShip :
    public Ship
{
public:
    SingleMastedShip(int xArgument, int yArgument, bool isVerticalArgument);
    //bool isHit; // false - nieuszkodzony; true - uszkodzony
    // TODO: make isHit private again

private:
};