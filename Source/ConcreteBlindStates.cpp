#include "ConcreteBlindStates.h"
#include "HandGenerator.h"
#include "ScoringRule.h"
#include "PokerHandChecker.h"

#include <iostream>

// ============================================================
// Helper: Jalankan satu ronde
// ============================================================

static int playOneRound()
{
    PokerHandChecker checker;
    HandGenerator generator;
    ScoringRule scorer;

    Hand hand = generator.generateHand();

    checker.check(hand);

    int score =
        scorer.convertRankToScore(
            hand.detectedRank);

    std::cout
        << "  >> Skor hand ini: "
        << score
        << "\n";

    return score;
}

// ============================================================
// Helper: Play Blind
// ============================================================

static void playBlind(
    GameRuntime& runtime,
    BlindState* state)
{
    std::cout
        << "\n>> PLAY "
        << state->getBlindName()
        << "\n";

    std::cout
        << "Kesempatan bermain: "
        << runtime.getRemainingPlays()
        << "\n";

    int plays =
        runtime.getRemainingPlays();

    for (int i = 0; i < plays; ++i)
    {
        std::cout
            << "\n--- Hand "
            << (i + 1)
            << " ---\n";

        int earned =
            playOneRound();

        runtime.addScore(earned);

        std::cout
            << "Score: "
            << runtime.getCurrentScore()
            << " / "
            << state->getTargetScore()
            << "\n";

        printScoreBar(
            runtime.getCurrentScore(),
            state->getTargetScore());

        if (
            runtime.getCurrentScore()
            >= state->getTargetScore())
        {
            std::cout
                << "\nTARGET TERCAPAI!\n";
            break;
        }
    }

    if (
        runtime.getCurrentScore()
        >= state->getTargetScore())
    {
        runtime.addMoney(
            state->getRewardMoney());

        std::cout
            << "\nReward Money: $"
            << state->getRewardMoney()
            << "\n";

        std::cout
            << "Total Money: $"
            << runtime.getMoney()
            << "\n";

        // =====================
        // SHOP
        // =====================

        std::cout
            << "\n=========== SHOP ===========\n";

        std::cout
            << "Current Money: $"
            << runtime.getMoney()
            << "\n";

        std::cout
            << "Tekan ENTER untuk lanjut...";

        std::cin.ignore();
        std::cin.get();

        state->nextState(runtime);
    }
    else
    {
        std::cout
            << "\nGAGAL mencapai target.\n";

        std::cout
            << "GAME OVER\n";

        runtime.setGameOver(true);
    }
}

// ============================================================
// Small Blind
// ============================================================

void SmallBlindState::play(
    GameRuntime& runtime)
{
    playBlind(runtime, this);
}

void SmallBlindState::skip(
    GameRuntime& runtime)
{
    std::cout
        << "\n>> SKIP SMALL BLIND\n";

    std::cout
        << "Reward: +1 Bonus Hand\n";

    nextState(runtime);
}

void SmallBlindState::nextState(
    GameRuntime& runtime)
{
    runtime.resetPlaysForNewBlind();

    auto next =
        std::make_shared<BigBlindState>(
            runtime.getAnte());

    runtime.setState(next);

    std::cout
        << "\nSmall Blind -> Big Blind\n";
}

// ============================================================
// Big Blind
// ============================================================

void BigBlindState::play(
    GameRuntime& runtime)
{
    playBlind(runtime, this);
}

void BigBlindState::skip(
    GameRuntime& runtime)
{
    std::cout
        << "\n>> SKIP BIG BLIND\n";

    std::cout
        << "Reward: +1 Hand Size\n";

    nextState(runtime);
}

void BigBlindState::nextState(
    GameRuntime& runtime)
{
    runtime.resetPlaysForNewBlind();

    auto next =
        std::make_shared<BossBlindState>(
            runtime.getAnte());

    runtime.setState(next);

    std::cout
        << "\nBig Blind -> Boss Blind\n";
}

// ============================================================
// Boss Blind
// ============================================================

void BossBlindState::play(
    GameRuntime& runtime)
{
    playBlind(runtime, this);
}

void BossBlindState::skip(
    GameRuntime& runtime)
{
    std::cout
        << "\n>> SKIP BOSS BLIND\n";

    std::cout
        << "Reward: +1 Bonus Hand\n";

    std::cout
        << "Reward: +1 Hand Size\n";

    nextState(runtime);
}

void BossBlindState::nextState(
    GameRuntime& runtime)
{
    if (
        runtime.getAnte()
        >= GameRuntime::MAX_ANTE)
    {
        std::cout << "\n";

        std::cout
            << "=====================================\n";

        std::cout
            << "         SELAMAT KAMU MENANG!\n";

        std::cout
            << "=====================================\n";

        runtime.setGameOver(true);
        return;
    }

    runtime.incrementAnte();

    runtime.resetPlaysForNewBlind();

    int newAnte =
        runtime.getAnte();

    std::cout
        << "\nANTE NAIK KE "
        << newAnte
        << "\n";

    auto next =
        std::make_shared<SmallBlindState>(
            newAnte);

    runtime.setState(next);

    std::cout
        << "Boss Blind -> Small Blind\n";
}