#pragma once
#include "../IHandChecker.h"

class HighCardChecker : public IHandChecker {
public:
    HandRank check(const Hand& hand) override;
};