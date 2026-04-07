#include <iostream>
#include "Hand.h"
#include "HighCardChecker.h"
#include "PairChecker.h"
#include "TwoPairChecker.h"
#include "ThreeOfAKindChecker.h"
#include "StraightChecker.h"
#include "FlushChecker.h"
#include "FullHouseChecker.h"
#include "FourOfAKindChecker.h"
#include "StraightFlushChecker.h"
#include "RoyalFlushChecker.h"
#include "FiveOfAKindChecker.h"
#include "FlushHouseChecker.h"
#include "FlushFiveChecker.h"

int main() {
    // Buat semua checker
    HighCardChecker      highCard;
    PairChecker          pair;
    TwoPairChecker       twoPair;
    ThreeOfAKindChecker  threeOfAKind;
    StraightChecker      straight;
    FlushChecker         flush;
    FullHouseChecker     fullHouse;
    FourOfAKindChecker   fourOfAKind;
    StraightFlushChecker straightFlush;
    RoyalFlushChecker    royalFlush;
    FiveOfAKindChecker   fiveOfAKind;
    FlushHouseChecker    flushHouse;
    FlushFiveChecker     flushFive;

    // Sambungkan chain (dari terendah ke tertinggi)
    highCard.setNext(&pair);
    pair.setNext(&twoPair);
    twoPair.setNext(&threeOfAKind);
    threeOfAKind.setNext(&straight);
    straight.setNext(&flush);
    flush.setNext(&fullHouse);
    fullHouse.setNext(&fourOfAKind);
    fourOfAKind.setNext(&straightFlush);
    straightFlush.setNext(&royalFlush);
    royalFlush.setNext(&fiveOfAKind);
    fiveOfAKind.setNext(&flushHouse);
    flushHouse.setNext(&flushFive);

    // Test semua hand
    std::cout << "=== Testing All Hand Types ===\n\n";
    for (int i = 1; i <= 13; i++) {
        Hand hand;
        hand.value = i;
        std::cout << "Hand value " << i << ": ";
        highCard.check(hand);
    }

    return 0;
}