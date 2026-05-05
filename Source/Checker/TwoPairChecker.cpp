#include <iostream>
#include "TwoPairChecker.h"
#include "HandUtils.h"

// Two Pair = dua pasang rank berbeda
// Contoh: {10H, 10D, 5C, 5H, 2S} → pasang 10 dan pasang 5
HandRank TwoPairChecker::check(const Hand& hand) {
    auto counts = getRankCounts(hand);
    int pairs = 0;
    for (auto& [rank, count] : counts)
        if (count == 2) pairs++;

    if (pairs == 2) {
        std::cout << "Detected: TWO PAIR\n";
        return HandRank::TWO_PAIR;
    }
    if (nextChecker) return nextChecker->check(hand);
    return HandRank::HIGH_CARD;
}