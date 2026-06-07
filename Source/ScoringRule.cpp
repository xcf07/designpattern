#include "ScoringRule.h"

ScoringRule::ScoringRule() {}

// scoreHand: menggunakan detectedRank yang sudah diisi oleh PokerHandChecker
int ScoringRule::scoreHand(const Hand& hand) {
    return convertRankToScore(hand.detectedRank);
}

int ScoringRule::convertRankToScore(HandRank rank) {
    switch (rank) {
        case HandRank::HIGH_CARD:         return 5;
        case HandRank::PAIR:              return 10;
        case HandRank::TWO_PAIR:          return 20;
        case HandRank::THREE_OF_A_KIND:   return 30;
        case HandRank::STRAIGHT:          return 40;
        case HandRank::FLUSH:             return 50;
        case HandRank::FULL_HOUSE:        return 60;
        case HandRank::FOUR_OF_A_KIND:    return 70;
        case HandRank::STRAIGHT_FLUSH:    return 100;
        case HandRank::ROYAL_FLUSH:       return 120;
        case HandRank::FIVE_OF_A_KIND:    return 140;
        case HandRank::FLUSH_HOUSE:       return 160;
        case HandRank::FLUSH_FIVE:        return 200;
        default:                          return 0;
    }
}
