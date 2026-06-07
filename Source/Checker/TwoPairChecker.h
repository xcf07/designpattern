#pragma once
#include "../IHandChecker.h"

class TwoPairChecker : public IHandChecker {
public:
    HandRank check(const Hand& hand) override;
};