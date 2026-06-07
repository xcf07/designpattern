#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include "HandGenerator.h"
#include "HandPlayer.h"
#include "PokerHandChecker.h"
#include "ScoringRule.h"
#include "BlindRule.h"
#include "RewardRule.h"
#include "GameRuntime.h"           // DITAMBAHKAN
#include "ConcreteBlindStates.h"   // DITAMBAHKAN

class GameManager {
private:
    HandGenerator    handGenerator;
    HandPlayer       handPlayer;
    PokerHandChecker pokerHandChecker;
    ScoringRule      scoringRule;
    BlindRule        blindRule;
    RewardRule       rewardRule;
    GameRuntime      runtime;      // DITAMBAHKAN: session state

public:
    void runSession();
};

#endif
