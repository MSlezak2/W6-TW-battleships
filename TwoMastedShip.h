#pragma once
#include "Ship.h"
class TwoMastedShip :
    public Ship
{
public:
    TwoMastedShip(int xArgument, int yArgument, bool isVerticalArgument);
    //bool isHit[2]; // false - nieuszkodzony; true - uszkodzony
    // TODO: MAke isHit private again

private:
};

