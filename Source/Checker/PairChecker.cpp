#include <iostream>
#include "PairChecker.h"
#include "HandUtils.h"

// Pair = tepat satu pasang rank yang sama
// Contoh: {10H, 10D, 5C, 8H, 2S} → ada dua 10
HandRank PairChecker::check(const Hand& hand) {
    auto counts = getRankCounts(hand);
    int pairs = 0;
    for (auto& [rank, count] : counts)
        if (count == 2) pairs++;

    if (pairs == 1) {
        std::cout << "Detected: PAIR\n";
        return HandRank::PAIR;
    }
    if (nextChecker) return nextChecker->check(hand);
    return HandRank::HIGH_CARD;
}