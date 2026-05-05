#include <iostream>
#include "FiveOfAKindChecker.h"
#include "HandUtils.h"

// Five of a Kind = lima kartu rank sama (butuh joker/wildcard)
// Contoh: {7H, 7D, 7C, 7S, 7★}
HandRank FiveOfAKindChecker::check(const Hand& hand) {
    auto counts = getRankCounts(hand);
    for (auto& [rank, count] : counts)
        if (count == 5) {
            std::cout << "Detected: FIVE OF A KIND\n";
            return HandRank::FIVE_OF_A_KIND;
        }
    if (nextChecker) return nextChecker->check(hand);
    return HandRank::HIGH_CARD;
}