#include "ChosenHand.h"
#include <iostream>

ChosenHand::ChosenHand(const Hand& h)
    : hand(h)
{
}

void ChosenHand::setHand(const Hand& h)
{
    hand = h;
}

Hand ChosenHand::getHand() const
{
    return hand;
}

void ChosenHand::displayHand() const
{
    std::cout << "Chosen Hand:\n";

    for (const auto& card : hand.cards)
    {
        std::cout << card.rank << card.suit << " ";
    }

    std::cout << std::endl;
}