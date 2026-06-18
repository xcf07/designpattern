#include "SmallBlindState.h"
#include "BigBlindState.h"
#include <iostream>

void SmallBlindState::play(GameRuntime& runtime)
{
    playBlind(runtime, this);
}

void SmallBlindState::skip(GameRuntime& runtime)
{
    std::cout << "\n>> SKIP SMALL BLIND\n";
    std::cout << "Reward: +1 Bonus Hand\n";
    nextState(runtime);
}

void SmallBlindState::nextState(GameRuntime& runtime)
{
    runtime.resetPlaysForNewBlind();
    auto next = std::make_shared<BigBlindState>(runtime.getAnte());
    runtime.setState(next);
    std::cout << "\nSmall Blind -> Big Blind\n";
}
