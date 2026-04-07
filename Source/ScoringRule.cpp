#include "ScoringRule.h"

ScoringRule::ScoringRule() {}

int ScoringRule::scoreHand(const Hand& hand) {
    switch (hand.value) {
        case 1:  return 5;
        case 2:  return 10;
        case 3:  return 20;
        case 4:  return 30;
        case 5:  return 40;
        case 6:  return 50;
        case 7:  return 60;
        case 8:  return 70;
        case 9:  return 100;
        case 10: return 120;
        case 11: return 140;
        case 12: return 160;
        case 13: return 200;
        default: return 0;
    }
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