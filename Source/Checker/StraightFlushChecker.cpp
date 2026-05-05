#include <iostream>
#include "StraightFlushChecker.h"
#include "HandUtils.h"

// Straight Flush = berurutan DAN suit sama, tapi bukan Royal Flush
// Contoh: {5H, 6H, 7H, 8H, 9H}
HandRank StraightFlushChecker::check(const Hand& hand) {
    bool flush    = allSameSuit(hand);
    bool straight = isSequential(hand);

    // Cek apakah ini Royal Flush (10,J,Q,K,A)
    std::vector<int> ranks;
    for (auto& card : hand.cards) ranks.push_back(card.rank);
    std::sort(ranks.begin(), ranks.end());
    bool isRoyal = (ranks == std::vector<int>{10,11,12,13,14});

    if (flush && straight && !isRoyal) {
        std::cout << "Detected: STRAIGHT FLUSH\n";
        return HandRank::STRAIGHT_FLUSH;
    }
    if (nextChecker) return nextChecker->check(hand);
    return HandRank::HIGH_CARD;
}