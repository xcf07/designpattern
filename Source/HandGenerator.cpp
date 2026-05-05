#include <iostream>
#include <algorithm>
#include <random>
#include "HandGenerator.h"

Hand HandGenerator::generateHand() {
    std::cout << "Generating hand...\n";

    // Buat deck 52 kartu
    std::vector<Card> deck;
    char suits[] = {'H', 'D', 'C', 'S'};
    for (char suit : suits) {
        for (int rank = 2; rank <= 14; rank++) {
            deck.push_back({rank, suit});
        }
    }

    // Acak deck
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(deck.begin(), deck.end(), g);

    // Ambil 5 kartu pertama
    Hand hand;
    for (int i = 0; i < 5; i++) {
        hand.cards.push_back(deck[i]);
    }

    // Tampilkan kartu yang dihasilkan
    std::cout << "Cards: ";
    for (auto& card : hand.cards) {
        std::cout << card.rank << card.suit << " ";
    }
    std::cout << "\n";

    return hand;
}