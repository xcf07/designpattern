#include <iostream>
#include "HighCardChecker.h"

HandRank HighCardChecker::check(const Hand& hand) {
    if (hand.value == 1) {
        std::cout << "Detected: HIGH CARD\n";
        return HandRank::HIGH_CARD;
    }
    if (nextChecker) return nextChecker->check(hand);
    return HandRank::HIGH_CARD;
}