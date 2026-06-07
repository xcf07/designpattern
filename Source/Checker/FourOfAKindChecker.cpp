#include <iostream>
#include "FourOfAKindChecker.h"
#include "HandUtils.h"

// Four of a Kind = empat kartu rank sama
// Contoh: {9H, 9D, 9C, 9S, 2H}
HandRank FourOfAKindChecker::check(const Hand& hand)
{
    auto counts = getRankCounts(hand);

    for (auto& entry : counts)
    {
        int rank = entry.first;
        int count = entry.second;

        if (count == 4)
        {
            std::cout << "Detected: FOUR OF A KIND\n";
            return HandRank::FOUR_OF_A_KIND;
        }
    }

    if (nextChecker)
        return nextChecker->check(hand);

    return HandRank::HIGH_CARD;
}