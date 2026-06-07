#include "BlindState.h"
#include <iostream>

void BlindState::printInfo() const {
    std::cout << "  [Blind] " << getBlindName()
              << " | Target: " << getTargetScore()
              << " | Reward: $" << getRewardMoney() << "\n";
}
