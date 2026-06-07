#pragma once

class RuntimeState;

class RewardCommand
{
public:
    virtual ~RewardCommand() = default;
    virtual void execute(RuntimeState& state) = 0;
};