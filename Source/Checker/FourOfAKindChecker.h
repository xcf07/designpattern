#pragma once
#include "../IHandChecker.h"

class FourOfAKindChecker : public IHandChecker {
public:
    HandRank check(const Hand& hand) override;
};