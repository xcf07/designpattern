#include <iostream>
#include "FiveOfAKindChecker.h"

HandRank FiveOfAKindChecker::check(const Hand& hand) {
    if (hand.value == 11) {
        std::cout << "Detected: FIVE OF A KIND\n";
        return HandRank::FIVE_OF_A_KIND;
    }
    if (nextChecker) return nextChecker->check(hand);
    return HandRank::UNKNOWN;
}