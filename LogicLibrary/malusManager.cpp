#include "malusManager.h"
#include <string>

void MalusManager::update(DoodleModel& doodle, const Score& score) {
    int currentScore = 0;
    try {
        currentScore = stoi(score.getScore());
    } catch (const invalid_argument& e) {
        return;
    }

    int nextMalusLevel = currentScore / scoreThreshold;

    if (nextMalusLevel > malusLevel && maxMalusLevel >= nextMalusLevel) {
        malusLevel = nextMalusLevel;
        float speedReduction = malusLevel * 0.05f;
        float jumpReduction = malusLevel * 0.1f;
        doodle.applyMalus(speedReduction, jumpReduction);
    }
}

void MalusManager::reset() {
    malusLevel = 0;
}
