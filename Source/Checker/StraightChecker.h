#pragma once
#include "../IHandChecker.h"

class StraightChecker : public IHandChecker {
public:
    HandRank check(const Hand& hand) override;
};