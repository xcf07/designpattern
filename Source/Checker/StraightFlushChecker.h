#pragma once
#include "../IHandChecker.h"

class StraightFlushChecker : public IHandChecker {
public:
    HandRank check(const Hand& hand) override;
};