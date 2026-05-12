#ifndef POKER_HAND_CHECKER_H
#define POKER_HAND_CHECKER_H

#include "Hand.h"

#include "Checker/FlushFiveChecker.h"
#include "Checker/FlushHouseChecker.h"
#include "Checker/FiveOfAKindChecker.h"
#include "Checker/RoyalFlushChecker.h"
#include "Checker/StraightFlushChecker.h"
#include "Checker/FourOfAKindChecker.h"
#include "Checker/FullHouseChecker.h"
#include "Checker/FlushChecker.h"
#include "Checker/StraightChecker.h"
#include "Checker/ThreeOfAKindChecker.h"
#include "Checker/TwoPairChecker.h"
#include "Checker/PairChecker.h"
#include "Checker/HighCardChecker.h"

class PokerHandChecker {
private:
    FlushFiveChecker flushFive;
    FlushHouseChecker flushHouse;
    FiveOfAKindChecker fiveOfAKind;
    RoyalFlushChecker royalFlush;
    StraightFlushChecker straightFlush;
    FourOfAKindChecker fourOfAKind;
    FullHouseChecker fullHouse;
    FlushChecker flush;
    StraightChecker straight;
    ThreeOfAKindChecker threeOfAKind;
    TwoPairChecker twoPair;
    PairChecker pair;
    HighCardChecker highCard;

public:
    PokerHandChecker();

    void check(Hand& hand);
};

#endif