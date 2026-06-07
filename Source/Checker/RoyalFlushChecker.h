#pragma once
#include "../IHandChecker.h"

class RoyalFlushChecker : public IHandChecker {
public:
    HandRank check(const Hand& hand) override;
};