#pragma once
#include "Hand.h"

class ChosenHand
{
private:
    Hand hand;

public:
    ChosenHand() = default;
    ChosenHand(const Hand& h);

    void setHand(const Hand& h);
    Hand getHand() const;

    void displayHand() const;
};