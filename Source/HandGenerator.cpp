#include <iostream>
#include "HandGenerator.h"

Hand HandGenerator::generateHand() {
    Hand hand;

    std::cout << "Enter hand value (1-13): ";
    std::cin >> hand.value;

    while (hand.value < 1 || hand.value > 13) {
        std::cout << "Invalid input. Enter hand value (1-13): ";
        std::cin >> hand.value;
    }

    return hand;
}