#pragma once
#include <memory>
#include <string>

class BlindState;

// ============================================================
//  GameRuntime — Runtime Session State
// ============================================================
class GameRuntime {
public:
    GameRuntime();

    // --- Getters ---
    int  getAnte()           const { return currentAnte; }
    int  getMoney()          const { return money; }
    int  getCurrentScore()   const { return currentScore; }
    int  getRemainingPlays() const { return remainingPlays; }
    bool isGameOver()        const { return gameOver; }

    // --- Setters ---
    void addMoney(int amount);
    void addScore(int score);
    void resetScore();
    void incrementAnte();
    void resetPlaysForNewBlind();
    void setGameOver(bool val) { gameOver = val; }

    // --- Blind State Management ---
    void        setState(std::shared_ptr<BlindState> newState);
    BlindState* getState() const { return currentState.get(); }

    // --- Display ---
    void printStatus() const;
    void printSeparator(char c = '=', int width = 50) const;

    static const int MAX_ANTE = 3;

private:
    int  currentAnte;
    int  money;
    int  currentScore;
    int  remainingPlays;
    bool gameOver;

    std::shared_ptr<BlindState> currentState;
};
