#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include "HandGenerator.h"
#include "HandPlayer.h"
#include "PokerHandChecker.h"
#include "ScoringRule.h"
#include "BlindRule.h"
#include "RewardRule.h"

class GameManager {
private:
    HandGenerator handGenerator;
    HandPlayer handPlayer;
    PokerHandChecker pokerHandChecker;
    ScoringRule scoringRule;
    BlindRule blindRule;
    RewardRule rewardRule;

public:
    void runSession();
};

#endif