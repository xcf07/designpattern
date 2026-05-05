#include <iostream>
#include "FlushFiveChecker.h"
#include "HandUtils.h"

// Flush Five = Five of a Kind DAN semua suit sama
// Kombinasi terkuat di Balatro
// Contoh: {7H, 7H, 7H, 7H, 7H}
HandRank FlushFiveChecker::check(const Hand& hand) {
    auto counts = getRankCounts(hand);
    bool hasFive = false;
    for (auto& [rank, count] : counts)
        if (count == 5) hasFive = true;

    if (hasFive && allSameSuit(hand)) {
        std::cout << "Detected: FLUSH FIVE\n";
        return HandRank::FLUSH_FIVE;
    }
    if (nextChecker) return nextChecker->check(hand);
    return HandRank::HIGH_CARD;
}