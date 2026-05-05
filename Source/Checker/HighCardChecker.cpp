#include <iostream>
#include "HighCardChecker.h"

// High Card = tidak ada kombinasi apapun
// Ini adalah CHECKER TERAKHIR, selalu true sebagai default
HandRank HighCardChecker::check(const Hand& hand) {
    std::cout << "Detected: HIGH CARD\n";
    return HandRank::HIGH_CARD;
}