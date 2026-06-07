#pragma once

#include "RewardCommand.h"

class BonusHandCommand : public RewardCommand
{
public:
    void execute(RuntimeState& state) override;
};