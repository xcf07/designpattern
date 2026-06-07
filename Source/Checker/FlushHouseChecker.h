#pragma once
#include "../IHandChecker.h"

class FlushHouseChecker : public IHandChecker {
public:
    HandRank check(const Hand& hand) override;
};