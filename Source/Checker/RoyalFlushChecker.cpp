#include <iostream>
#include <algorithm>
#include "RoyalFlushChecker.h"
#include "HandUtils.h"

// Royal Flush = 10, J, Q, K, A dengan suit yang sama
// Contoh: {10H, JH, QH, KH, AH}
HandRank RoyalFlushChecker::check(const Hand& hand) {
    if (!allSameSuit(hand)) {
        if (nextChecker) return nextChecker->check(hand);
        return HandRank::HIGH_CARD;
    }

    std::vector<int> ranks;
    for (auto& card : hand.cards) ranks.push_back(card.rank);
    std::sort(ranks.begin(), ranks.end());

    if (ranks == std::vector<int>{10,11,12,13,14}) {
        std::cout << "Detected: ROYAL FLUSH\n";
        return HandRank::ROYAL_FLUSH;
    }
    if (nextChecker) return nextChecker->check(hand);
    return HandRank::HIGH_CARD;
}