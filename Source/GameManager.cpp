#include <iostream>
#include "GameManager.h"

void GameManager::runSession() {
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

    // chain tertinggi ke terendah
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

    std::cout << "=== Run Started ===\n";
    std::cout << "Generating cards for player...\n";

    Hand hand = handGenerator.generateHand();

    std::cout << "Player selects cards to play...\n";
    handPlayer.generateHand();

    std::cout << "Calculating hand score...\n";
    flushFive.check(hand);

    int score = scoringRule.scoreHand(hand);
    std::cout << "Final score = " << score << "\n";

    std::cout << "Checking blind requirement...\n";
    bool win = blindRule.checkBlind(score);
    std::cout << "Result: " << (win ? "WIN" : "LOSE") << "\n";

    std::cout << "Calculating reward...\n";
    int money = rewardRule.earnMoney(win, score);
    std::cout << "Money gained: " << money << "\n";

    std::cout << "=== Run Ended ===\n";
}