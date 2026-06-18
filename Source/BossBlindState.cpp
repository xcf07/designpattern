#include "BossBlindState.h"
#include "SmallBlindState.h"
#include <iostream>

void BossBlindState::play(GameRuntime& runtime)
{
    playBlind(runtime, this);
}

void BossBlindState::skip(GameRuntime& runtime)
{
    std::cout << "\n>> SKIP BOSS BLIND\n";
    std::cout << "Reward: +1 Bonus Hand\n";
    std::cout << "Reward: +1 Hand Size\n";
    nextState(runtime);
}

void BossBlindState::nextState(GameRuntime& runtime)
{
    if (runtime.getAnte() >= GameRuntime::MAX_ANTE)
    {
        std::cout << "\n";
        std::cout << "=====================================\n";
        std::cout << "         SELAMAT KAMU MENANG!\n";
        std::cout << "=====================================\n";
        runtime.setGameOver(true);
        return;
    }

    runtime.incrementAnte();
    runtime.resetPlaysForNewBlind();

    int newAnte = runtime.getAnte();
    std::cout << "\nANTE NAIK KE " << newAnte << "\n";

    auto next = std::make_shared<SmallBlindState>(newAnte);
    runtime.setState(next);
    std::cout << "Boss Blind -> Small Blind\n";
}
