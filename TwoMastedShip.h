#pragma once
#include "Ship.h"
class TwoMastedShip :
    public Ship
{
public:
    TwoMastedShip();
    TwoMastedShip(int xArgument, int yArgument, bool isVerticalArgument);
    bool isWithinTheBoard(int x, int y, bool isVe);
    //bool isHit[2]; // false - nieuszkodzony; true - uszkodzony
    // TODO: MAke isHit private again

private:
};

