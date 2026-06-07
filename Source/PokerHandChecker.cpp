#include "PokerHandChecker.h"

PokerHandChecker::PokerHandChecker() {
    // Chain tertinggi ke terendah
    flushFive.setNext(&flushHouse);
    flushHouse.setNext(&fiveOfAKind);
    fiveOfAKind.setNext(&royalFlush);
    royalFlush.setNext(&straightFlush);
    straightFlush.setNext(&fourOfAKind);
    fourOfAKind.setNext(&fullHouse);
    fullHouse.setNext(&flush);
    flush.setNext(&straight);
    straight.setNext(&threeOfAKind);
    threeOfAKind.setNext(&twoPair);
    twoPair.setNext(&pair);
    pair.setNext(&highCard);
}

void PokerHandChecker::check(Hand& hand) {
    // Jalankan chain dan simpan hasilnya ke hand.detectedRank
    hand.detectedRank = flushFive.check(hand);
}
