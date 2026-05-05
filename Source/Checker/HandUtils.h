#pragma once
#include "Hand.h"
#include <map>
#include <algorithm>

// Hitung frekuensi setiap rank
// Contoh: {10H, 10D, 5C, 5H, 5S} → {10:2, 5:3}
inline std::map<int,int> getRankCounts(const Hand& hand) {
    std::map<int,int> counts;
    for (auto& card : hand.cards)
        counts[card.rank]++;
    return counts;
}

// Cek apakah semua suit sama
// Contoh: {2H,5H,9H,JH,AH} → true (semua H)
inline bool allSameSuit(const Hand& hand) {
    char suit = hand.cards[0].suit;
    for (auto& card : hand.cards)
        if (card.suit != suit) return false;
    return true;
}

// Cek apakah rank berurutan
// Contoh: {5,6,7,8,9} → true
inline bool isSequential(const Hand& hand) {
    std::vector<int> ranks;
    for (auto& card : hand.cards)
        ranks.push_back(card.rank);
    std::sort(ranks.begin(), ranks.end());
    for (int i = 1; i < ranks.size(); i++)
        if (ranks[i] != ranks[i-1] + 1) return false;
    return true;
}