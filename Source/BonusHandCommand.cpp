#include "BonusHandCommand.h"
#include "RuntimeState.h"

void BonusHandCommand::execute(RuntimeState& state)
{
    state.remainingHands += 1;
}