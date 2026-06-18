#pragma once
#include "BlindState.h"
#include "GameRuntime.h"
#include <iostream>

// ============================================================
//  Tabel Data Bersama (dipakai SmallBlind, BigBlind, BossBlind)
//  Ante | SmallBlind | BigBlind | BossBlind
//    1  |    300     |   450   |    600
//    2  |    800     |  1200   |   1600
//    3  |   2000     |  3000   |   4000
// ============================================================
inline const int SCORE_TABLE[3][3] = {
    {300,  450,  600},
    {800,  1200, 1600},
    {2000, 3000, 4000}
};

inline const int REWARD_TABLE[3][3] = {
    {3, 4, 5},
    {4, 5, 6},
    {5, 6, 8}
};

// Helper: cetak progress bar skor
inline void printScoreBar(int current, int target) {
    int barWidth = 30;
    int filled   = (target > 0) ? (current * barWidth / target) : 0;
    if (filled > barWidth) filled = barWidth;
    std::cout << "  [";
    for (int i = 0; i < barWidth; ++i)
        std::cout << (i < filled ? '#' : '-');
    std::cout << "] " << current << "/" << target << "\n";
}

// Helper: logika utama bermain satu blind
void playBlind(GameRuntime& runtime, BlindState* state);

// Helper: jalankan satu ronde kartu
int playOneRound();
