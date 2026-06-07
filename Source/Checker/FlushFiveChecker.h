#pragma once
#include "../IHandChecker.h"

class FlushFiveChecker : public IHandChecker {
public:
    HandRank check(const Hand& hand) override;
};