#include <iostream>
#include "ThreeOfAKindChecker.h"
#include "HandUtils.h"

// Three of a Kind = tepat tiga kartu rank sama, tanpa pasang lain
// Contoh: {7H, 7D, 7C, 4H, 2S}
HandRank ThreeOfAKindChecker::check(const Hand& hand) {
    auto counts = getRankCounts(hand);
    bool hasThree = false, hasPair = false;
    for (auto& [rank, count] : counts) {
        if (count == 3) hasThree = true;
        if (count == 2) hasPair  = true;
    }

    // hasThree tapi TIDAK hasPair (kalau ada pair → itu Full House)
    if (hasThree && !hasPair) {
        std::cout << "Detected: THREE OF A KIND\n";
        return HandRank::THREE_OF_A_KIND;
    }
    if (nextChecker) return nextChecker->check(hand);
    return HandRank::HIGH_CARD;
}