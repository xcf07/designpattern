#include "ConcreteBlindStates.h"
#include "HandGenerator.h"
#include "ScoringRule.h"
#include "PokerHandChecker.h"
#include <iostream>

// ============================================================
//  Helper: Jalankan satu ronde menggunakan PokerHandChecker
//  yang sudah ada di codebase lama
// ============================================================
static int playOneRound() {
    PokerHandChecker checker;   // sudah setup chain di constructor-nya
    HandGenerator    generator;
    ScoringRule      scorer;

    Hand hand = generator.generateHand();
    checker.check(hand);                          // chain of responsibility berjalan
    int score = scorer.convertRankToScore(hand.detectedRank);

    std::cout << "  >> Skor hand ini: " << score << "\n";
    return score;
}

// ============================================================
//  Helper: Logic PLAY yang dipakai ketiga blind
// ============================================================
static void playBlind(GameRuntime& runtime, BlindState* state) {
    std::cout << "\n  >> Kamu memilih PLAY " << state->getBlindName() << "!\n";
    std::cout << "  Kamu punya " << runtime.getRemainingPlays() << " kesempatan bermain.\n";

    int plays = runtime.getRemainingPlays();
    for (int i = 0; i < plays; ++i) {
        std::cout << "\n  --- Hand " << (i + 1) << " ---\n";
        int earned = playOneRound();
        runtime.addScore(earned);

        std::cout << "  Skor terkumpul: " << runtime.getCurrentScore()
                  << " / " << state->getTargetScore() << "\n";
        printScoreBar(runtime.getCurrentScore(), state->getTargetScore());

        if (runtime.getCurrentScore() >= state->getTargetScore()) {
            std::cout << "\n  ✓ TARGET TERCAPAI di hand ke-" << (i + 1) << "!\n";
            break;
        }
    }

    if (runtime.getCurrentScore() >= state->getTargetScore()) {
        runtime.addMoney(state->getRewardMoney());
        std::cout << "  + Reward: $" << state->getRewardMoney()
                  << " | Total uang: $" << runtime.getMoney() << "\n";
        state->nextState(runtime);
    } else {
        std::cout << "\n  ✗ GAGAL! Skor tidak mencapai target.\n";
        std::cout << "  >> GAME OVER\n";
        runtime.setGameOver(true);
    }
}

// ============================================================
//  SmallBlindState
// ============================================================
void SmallBlindState::play(GameRuntime& runtime) {
    playBlind(runtime, this);
}

void SmallBlindState::skip(GameRuntime& runtime) {
    std::cout << "\n  >> Kamu memilih SKIP Small Blind!\n";
    std::cout << "  [Reward Command] BonusHandCommand akan aktif di NextBlind.\n";
    nextState(runtime);
}

void SmallBlindState::nextState(GameRuntime& runtime) {
    runtime.resetPlaysForNewBlind();
    auto next = std::make_shared<BigBlindState>(runtime.getAnte());
    runtime.setState(next);
    std::cout << "\n  >> State: Small Blind → Big Blind\n";
}

// ============================================================
//  BigBlindState
// ============================================================
void BigBlindState::play(GameRuntime& runtime) {
    playBlind(runtime, this);
}

void BigBlindState::skip(GameRuntime& runtime) {
    std::cout << "\n  >> Kamu memilih SKIP Big Blind!\n";
    std::cout << "  [Reward Command] FreePlayingCard akan aktif di NextAnte.\n";
    nextState(runtime);
}

void BigBlindState::nextState(GameRuntime& runtime) {
    runtime.resetPlaysForNewBlind();
    auto next = std::make_shared<BossBlindState>(runtime.getAnte());
    runtime.setState(next);
    std::cout << "\n  >> State: Big Blind → Boss Blind\n";
}

// ============================================================
//  BossBlindState
// ============================================================
void BossBlindState::play(GameRuntime& runtime) {
    playBlind(runtime, this);
}

void BossBlindState::skip(GameRuntime& runtime) {
    std::cout << "\n  >> Kamu memilih SKIP Boss Blind!\n";
    std::cout << "  [Reward Command] BonusHand + FreePlayingCard aktif di Start.\n";
    nextState(runtime);
}

void BossBlindState::nextState(GameRuntime& runtime) {
    if (runtime.getAnte() >= GameRuntime::MAX_ANTE) {
        std::cout << "\n";
        std::cout << "  ╔══════════════════════════════════════════╗\n";
        std::cout << "  ║      🏆  SELAMAT! KAMU MENANG!  🏆       ║\n";
        std::cout << "  ║  Semua Ante telah berhasil diselesaikan! ║\n";
        std::cout << "  ╚══════════════════════════════════════════╝\n";
        runtime.setGameOver(true);
        return;
    }

    runtime.incrementAnte();
    runtime.resetPlaysForNewBlind();
    int newAnte = runtime.getAnte();
    std::cout << "\n  *** ANTE " << (newAnte - 1) << " SELESAI! Masuk ke ANTE " << newAnte << " ***\n";

    auto next = std::make_shared<SmallBlindState>(newAnte);
    runtime.setState(next);
    std::cout << "  >> State: Boss Blind → Small Blind (Ante " << newAnte << ")\n";
}
