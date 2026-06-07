#include <iostream>
#include "FullHouseChecker.h"
#include "HandUtils.h"

// Full House = tiga kartu rank sama + dua kartu rank sama
// Contoh: {8H, 8D, 8C, KH, KS}
HandRank FullHouseChecker::check(const Hand& hand)
{
    auto counts = getRankCounts(hand);

    bool hasThree = false;
    bool hasPair = false;

    for (auto& entry : counts)
    {
        int rank = entry.first;
        int count = entry.second;

        if (count == 3)
            hasThree = true;

        if (count == 2)
            hasPair = true;
    }

    if (hasThree && hasPair)
    {
        std::cout << "Detected: FULL HOUSE\n";
        return HandRank::FULL_HOUSE;
    }

    if (nextChecker)
        return nextChecker->check(hand);

    return HandRank::HIGH_CARD;
}