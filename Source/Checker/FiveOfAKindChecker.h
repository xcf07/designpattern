#pragma once
#include "../IHandChecker.h"

class FiveOfAKindChecker : public IHandChecker {
public:
    HandRank check(const Hand& hand) override;
};