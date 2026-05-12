#include "GameManager.h"
#include <iostream>

void GameManager::runSession() {
    std::cout << "=== Run Started ===\n";
    std::cout << "Generating cards for player...\n";

    Hand hand = handGenerator.generateHand();

    std::cout << "Player selects cards to play...\n";
    handPlayer.generateHand();

    std::cout << "Checking poker hand...\n";
    pokerHandChecker.check(hand);

    std::cout << "Calculating hand score...\n";
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