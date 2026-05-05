#include <iostream>
#include "FlushHouseChecker.h"
#include "HandUtils.h"

// Flush House = Full House (3+2) DAN semua suit sama
// Contoh: {8H, 8H, 8H, KH, KH} (versi Balatro)
HandRank FlushHouseChecker::check(const Hand& hand) {
    auto counts = getRankCounts(hand);
    bool hasThree = false, hasPair = false;
    for (auto& [rank, count] : counts) {
        if (count == 3) hasThree = true;
        if (count == 2) hasPair  = true;
    }

    if (hasThree && hasPair && allSameSuit(hand)) {
        std::cout << "Detected: FLUSH HOUSE\n";
        return HandRank::FLUSH_HOUSE;
    }
    if (nextChecker) return nextChecker->check(hand);
    return HandRank::HIGH_CARD;
}