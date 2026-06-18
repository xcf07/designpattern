#include "BlindUtils.h"
#include "HandGenerator.h"
#include "ScoringRule.h"
#include "PokerHandChecker.h"
#include <iostream>

// ============================================================
//  Helper: Jalankan satu ronde kartu
// ============================================================
int playOneRound()
{
    PokerHandChecker checker;
    HandGenerator    generator;
    ScoringRule      scorer;

    Hand hand = generator.generateHand();
    checker.check(hand);

    int score = scorer.convertRankToScore(hand.detectedRank);

    std::cout << "  >> Skor hand ini: " << score << "\n";
    return score;
}

// ============================================================
//  Helper: Logic bermain blind (dipakai ketiga blind)
// ============================================================
void playBlind(GameRuntime& runtime, BlindState* state)
{
    std::cout << "\n>> PLAY " << state->getBlindName() << "\n";
    std::cout << "Kesempatan bermain: " << runtime.getRemainingPlays() << "\n";

    int plays = runtime.getRemainingPlays();

    for (int i = 0; i < plays; ++i)
    {
        std::cout << "\n--- Hand " << (i + 1) << " ---\n";

        int earned = playOneRound();
        runtime.addScore(earned);

        std::cout << "Score: " << runtime.getCurrentScore()
                  << " / "     << state->getTargetScore() << "\n";

        printScoreBar(runtime.getCurrentScore(), state->getTargetScore());

        if (runtime.getCurrentScore() >= state->getTargetScore())
        {
            std::cout << "\nTARGET TERCAPAI!\n";
            break;
        }
    }

    if (runtime.getCurrentScore() >= state->getTargetScore())
    {
        runtime.addMoney(state->getRewardMoney());

        std::cout << "\nReward Money: $" << state->getRewardMoney() << "\n";
        std::cout << "Total Money: $"   << runtime.getMoney()       << "\n";

        std::cout << "\n=========== SHOP ===========\n";
        std::cout << "Current Money: $" << runtime.getMoney() << "\n";
        std::cout << "Tekan ENTER untuk lanjut...";
        std::cin.ignore();
        std::cin.get();

        state->nextState(runtime);
    }
    else
    {
        std::cout << "\nGAGAL mencapai target.\n";
        std::cout << "GAME OVER\n";
        runtime.setGameOver(true);
    }
}
