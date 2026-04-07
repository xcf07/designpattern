#pragma once
#include "Hand.h"

class ScoringRule {
public:
    ScoringRule();
    int scoreHand(const Hand& hand);
    int convertRankToScore(HandRank rank);
};