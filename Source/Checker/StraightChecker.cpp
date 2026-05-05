#include <iostream>
#include "StraightChecker.h"
#include "HandUtils.h"

// Straight = 5 kartu berurutan, suit boleh beda
// Contoh: {5H, 6D, 7C, 8S, 9H}
HandRank StraightChecker::check(const Hand& hand) {
    bool flush = allSameSuit(hand);   // kalau flush juga → Straight Flush
    bool straight = isSequential(hand);

    if (straight && !flush) {
        std::cout << "Detected: STRAIGHT\n";
        return HandRank::STRAIGHT;
    }
    if (nextChecker) return nextChecker->check(hand);
    return HandRank::HIGH_CARD;
}