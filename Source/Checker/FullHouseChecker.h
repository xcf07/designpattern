#pragma once
#include "../IHandChecker.h"

class FullHouseChecker : public IHandChecker {
public:
    HandRank check(const Hand& hand) override;
};