#include "RewardRule.h"

int RewardRule::earnMoney(bool win, int score) {
    return win ? score : 0;
}