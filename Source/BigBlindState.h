#pragma once
#include "BlindState.h"
#include "GameRuntime.h"
#include "BlindUtils.h"
#include <iostream>

// ============================================================
//  BigBlindState — State Pattern (Concrete State)
//  Blind kedua di setiap ante
//  Transisi: BigBlind → BossBlind
// ============================================================
class BigBlindState : public BlindState {
public:
    explicit BigBlindState(int ante) : ante(ante) {}

    std::string getBlindName()   const override { return "Big Blind"; }
    std::string getBlindType()   const override { return "Big"; }
    int         getTargetScore() const override { return SCORE_TABLE[ante - 1][1]; }
    int         getRewardMoney() const override { return REWARD_TABLE[ante - 1][1]; }

    void printInfo() const override {
        std::cout << "\n  +-----------------------------------------+\n";
        std::cout << "  |  [BLIND]  BIG BLIND  (Ante " << ante << ")            |\n";
        std::cout << "  +-----------------------------------------+\n";
        std::cout << "  | Target Score  : " << getTargetScore() << "\n";
        std::cout << "  | Reward Money  : $" << getRewardMoney() << "\n";
        std::cout << "  +-----------------------------------------+\n";
    }

    void play(GameRuntime& runtime) override;
    void skip(GameRuntime& runtime) override;
    void nextState(GameRuntime& runtime) override;

private:
    int ante;
};
