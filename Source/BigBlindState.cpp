#include "BigBlindState.h"
#include "BossBlindState.h"
#include <iostream>

void BigBlindState::play(GameRuntime& runtime)
{
    playBlind(runtime, this);
}

void BigBlindState::skip(GameRuntime& runtime)
{
    std::cout << "\n>> SKIP BIG BLIND\n";
    std::cout << "Reward: +1 Hand Size\n";
    nextState(runtime);
}

void BigBlindState::nextState(GameRuntime& runtime)
{
    runtime.resetPlaysForNewBlind();
    auto next = std::make_shared<BossBlindState>(runtime.getAnte());
    runtime.setState(next);
    std::cout << "\nBig Blind -> Boss Blind\n";
}
