#pragma once
#include "Hand.h"

// Base class untuk Chain of Responsibility
// Dipisah dari PokerHandChecker agar Checker/*.h bisa include tanpa circular dependency
class IHandChecker {
public:
    virtual ~IHandChecker() = default;
    virtual HandRank check(const Hand& hand) = 0;
    void setNext(IHandChecker* next) { nextChecker = next; }
protected:
    IHandChecker* nextChecker = nullptr;
};
