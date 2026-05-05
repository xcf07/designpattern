#include <iostream>
#include "FlushChecker.h"
#include "HandUtils.h"

// Flush = semua suit sama, rank tidak berurutan
// Contoh: {2H, 5H, 8H, JH, 3H}
HandRank FlushChecker::check(const Hand& hand) {
    bool flush = allSameSuit(hand);
    bool straight = isSequential(hand);

    if (flush && !straight) {
        std::cout << "Detected: FLUSH\n";
        return HandRank::FLUSH;
    }
    if (nextChecker) return nextChecker->check(hand);
    return HandRank::HIGH_CARD;
}