#include "BlindRule.h"

bool BlindRule::checkBlind(int score, int target) {
    return score >= target;
}

bool BlindRule::checkBlind(int score) {
    return score >= 50;
}
