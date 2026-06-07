#pragma once
#include "../IHandChecker.h"

class ThreeOfAKindChecker : public IHandChecker {
public:
    HandRank check(const Hand& hand) override;
};