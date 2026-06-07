#pragma once
#include "../IHandChecker.h"

class FlushChecker : public IHandChecker {
public:
    HandRank check(const Hand& hand) override;
};