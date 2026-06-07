#include "RuntimeState.h"
#include "RewardCommand.h"

void RuntimeState::executePendingCommands()
{
    for(auto& cmd : pendingCommands)
    {
        cmd->execute(*this);
    }

    pendingCommands.clear();
}