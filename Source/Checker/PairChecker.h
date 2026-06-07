#pragma once
#include "../IHandChecker.h"

class PairChecker : public IHandChecker {
public:
    HandRank check(const Hand& hand) override;
};