#pragma once
#include <string>
#include <memory>

// Forward declaration
class GameRuntime;

// ============================================================
//  Abstract Base Class: BlindState (State Pattern)
// ============================================================
class BlindState {
public:
    virtual ~BlindState() = default;

    // --- Blind Information ---
    virtual std::string getBlindName()   const = 0;
    virtual int         getTargetScore() const = 0;
    virtual int         getRewardMoney() const = 0;
    virtual std::string getBlindType()   const = 0;

    // --- Blind Progression Behavior ---
    virtual void play(GameRuntime& runtime) = 0;
    virtual void skip(GameRuntime& runtime) = 0;
    virtual void nextState(GameRuntime& runtime) = 0;

    // --- Display ---
    virtual void printInfo() const;
};
