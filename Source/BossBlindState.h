#pragma once
#include "BlindState.h"
#include "GameRuntime.h"
#include "BlindUtils.h"
#include <iostream>

// ============================================================
//  BossBlindState — State Pattern (Concrete State)
//  Blind ketiga (terakhir) di setiap ante
//  Transisi: BossBlind → SmallBlind (ante baru) atau MENANG
// ============================================================
class BossBlindState : public BlindState {
public:
    explicit BossBlindState(int ante) : ante(ante) {}

    std::string getBlindName()   const override { return "Boss Blind"; }
    std::string getBlindType()   const override { return "Boss"; }
    int         getTargetScore() const override { return SCORE_TABLE[ante - 1][2]; }
    int         getRewardMoney() const override { return REWARD_TABLE[ante - 1][2]; }

    void printInfo() const override {
        std::cout << "\n  +-----------------------------------------+\n";
        std::cout << "  |  [BLIND]  *** BOSS BLIND ***  (Ante " << ante << ")  |\n";
        std::cout << "  +-----------------------------------------+\n";
        std::cout << "  | Target Score  : " << getTargetScore() << "\n";
        std::cout << "  | Reward Money  : $" << getRewardMoney() << "\n";
        std::cout << "  | [!] Menang = Naik ke Ante berikutnya     |\n";
        std::cout << "  +-----------------------------------------+\n";
    }

    void play(GameRuntime& runtime) override;
    void skip(GameRuntime& runtime) override;
    void nextState(GameRuntime& runtime) override;

private:
    int ante;
};
