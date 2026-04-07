#pragma once

#include "HandGenerator.h"
#include "HandPlayer.h"
#include "ScoringRule.h"
#include "BlindRule.h"
#include "RewardRule.h"

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

class GameManager {
public:
    void runSession();

private:
    HandGenerator handGenerator;
    HandPlayer handPlayer;
    ScoringRule scoringRule;
    BlindRule blindRule;
    RewardRule rewardRule;
};