#pragma once
#include "BlindState.h"
#include "GameRuntime.h"
#include <iostream>

// ============================================================
//  Score Table (Balatro Reference)
//  Ante | SmallBlind | BigBlind | BossBlind
//    1  |    300     |   450   |    600
//    2  |    800     |  1200   |   1600
//    3  |   2000     |  3000   |   4000
// ============================================================
static const int SCORE_TABLE[3][3] = {
    {300,  450,  600},
    {800,  1200, 1600},
    {2000, 3000, 4000}
};

static const int REWARD_TABLE[3][3] = {
    {3, 4, 5},
    {4, 5, 6},
    {5, 6, 8}
};

static void printScoreBar(int current, int target) {
    int barWidth = 30;
    int filled   = (target > 0) ? (current * barWidth / target) : 0;
    if (filled > barWidth) filled = barWidth;
    std::cout << "  [";
    for (int i = 0; i < barWidth; ++i)
        std::cout << (i < filled ? '#' : '-');
    std::cout << "] " << current << "/" << target << "\n";
}

// ============================================================
//  SmallBlindState
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

// ============================================================
//  BigBlindState
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

// ============================================================
//  BossBlindState
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
