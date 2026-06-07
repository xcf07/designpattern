#pragma once
#include <vector>
#include "Checker/Card.h"

enum class HandRank {
    HIGH_CARD,
    PAIR,
    TWO_PAIR,
    THREE_OF_A_KIND,
    STRAIGHT,
    FLUSH,
    FULL_HOUSE,
    FOUR_OF_A_KIND,
    STRAIGHT_FLUSH,
    ROYAL_FLUSH,
    FIVE_OF_A_KIND,
    FLUSH_HOUSE,
    FLUSH_FIVE,
    UNKNOWN
};

struct Hand {
    std::vector<Card> cards;
    HandRank detectedRank = HandRank::UNKNOWN; // DITAMBAHKAN: diisi oleh PokerHandChecker
};
