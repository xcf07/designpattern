#include <iostream>
#include "FreePlayingCardCommand.h"
#include "RuntimeState.h"

void FreePlayingCardCommand::execute(RuntimeState& state)
{
    std::cout << "Free playing card awarded!\n";
}