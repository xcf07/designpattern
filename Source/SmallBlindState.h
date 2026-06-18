#pragma once
#include "BlindState.h"
#include "GameRuntime.h"
#include "BlindUtils.h"
#include <iostream>

// ============================================================
//  SmallBlindState — State Pattern (Concrete State)
//  Blind pertama di setiap ante
//  Transisi: SmallBlind → BigBlind
// ============================================================
class SmallBlindState : public BlindState {
public:
    explicit SmallBlindState(int ante) : ante(ante) {}

    std::string getBlindName()   const override { return "Small Blind"; }
    std::string getBlindType()   const override { return "Small"; }
    int         getTargetScore() const override { return SCORE_TABLE[ante - 1][0]; }
    int         getRewardMoney() const override { return REWARD_TABLE[ante - 1][0]; }

    void printInfo() const override {
        std::cout << "\n  +-----------------------------------------+\n";
        std::cout << "  |  [BLIND]  SMALL BLIND  (Ante " << ante << ")          |\n";
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
