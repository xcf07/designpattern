#pragma once

class BlindRule {
public:
    bool checkBlind(int score, int target);
    bool checkBlind(int score); // overload lama tetap dipertahankan
};
