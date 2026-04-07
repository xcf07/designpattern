#include <iostream>
#include "Hand.h"
#include "Checker/HighCardChecker.h"
#include "Checker/PairChecker.h"
#include "Checker/TwoPairChecker.h"
#include "Checker/ThreeOfAKindChecker.h"
#include "Checker/StraightChecker.h"
#include "Checker/FlushChecker.h"
#include "Checker/FullHouseChecker.h"
#include "Checker/FourOfAKindChecker.h"
#include "Checker/StraightFlushChecker.h"
#include "Checker/RoyalFlushChecker.h"
#include "Checker/FiveOfAKindChecker.h"
#include "Checker/FlushHouseChecker.h"
#include "Checker/FlushFiveChecker.h"

int main() {
    HighCardChecker highCard;
    PairChecker pair;
    TwoPairChecker twoPair;
    ThreeOfAKindChecker threeOfAKind;
    StraightChecker straight;
    FlushChecker flush;
    FullHouseChecker fullHouse;
    FourOfAKindChecker fourOfAKind;
    StraightFlushChecker straightFlush;
    RoyalFlushChecker royalFlush;
    FiveOfAKindChecker fiveOfAKind;
    FlushHouseChecker flushHouse;
    FlushFiveChecker flushFive;

    // Chain dari tertinggi ke terendah
    flushFive.setNext(&flushHouse);
    flushHouse.setNext(&fiveOfAKind);
    fiveOfAKind.setNext(&royalFlush);
    royalFlush.setNext(&straightFlush);
    straightFlush.setNext(&fourOfAKind);
    fourOfAKind.setNext(&fullHouse);
    fullHouse.setNext(&flush);
    flush.setNext(&straight);
    straight.setNext(&threeOfAKind);
    threeOfAKind.setNext(&twoPair);
    twoPair.setNext(&pair);
    pair.setNext(&highCard);

    std::cout << "=== Testing All Hand Types ===\n\n";

    for (int i = 1; i <= 13; i++) {
        Hand hand;
        hand.value = i;

        std::cout << "Hand value " << i << ": ";
        flushFive.check(hand);
    }

    return 0;
}