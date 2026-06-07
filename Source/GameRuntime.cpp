#include "GameRuntime.h"
#include "BlindState.h"
#include <iostream>

GameRuntime::GameRuntime()
    : currentAnte(1),
      money(4),
      currentScore(0),
      remainingPlays(4),
      gameOver(false),
      currentState(nullptr)
{}

void GameRuntime::addMoney(int amount)  { money += amount; }
void GameRuntime::addScore(int score)   { currentScore += score; }
void GameRuntime::resetScore()          { currentScore = 0; }
void GameRuntime::incrementAnte()       { currentAnte++; }

void GameRuntime::resetPlaysForNewBlind() {
    remainingPlays = 4;
    currentScore   = 0;
}

void GameRuntime::setState(std::shared_ptr<BlindState> newState) {
    currentState = newState;
}

void GameRuntime::printSeparator(char c, int width) const {
    for (int i = 0; i < width; ++i) std::cout << c;
    std::cout << "\n";
}

void GameRuntime::printStatus() const {
    printSeparator('=', 50);
    std::cout << "  GAME STATUS\n";
    printSeparator('-', 50);
    std::cout << "  Ante          : " << currentAnte << " / " << MAX_ANTE << "\n";
    std::cout << "  Uang          : $" << money << "\n";
    std::cout << "  Skor Sekarang : " << currentScore << "\n";
    std::cout << "  Sisa Plays    : " << remainingPlays << "\n";
    if (currentState) {
        std::cout << "  Blind Aktif   : " << currentState->getBlindName() << "\n";
        std::cout << "  Target Score  : " << currentState->getTargetScore() << "\n";
    }
    printSeparator('=', 50);
}
