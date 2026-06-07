#pragma once

#include <vector>
#include <memory>

class RewardCommand;

class RuntimeState
{
public:
    int ante = 1;
    int totalScore = 0;
    int remainingHands = 4;
    int remainingDiscards = 3;

    std::vector<std::unique_ptr<RewardCommand>> pendingCommands;

    void executePendingCommands();
};