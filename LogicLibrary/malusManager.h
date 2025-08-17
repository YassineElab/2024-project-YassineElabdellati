#ifndef DOODLEAP_MALUSMANAGER_H

#include "doodleModel.h"
#include "score.h"

#define DOODLEAP_MALUSMANAGER_H


using namespace std;

class MalusManager {
private:
    int malusLevel = 0;
    int scoreThreshold = 1000;
    const int maxMalusLevel = 20;

public:
    // Default constructor for the malus manager.
    MalusManager() = default;

    // Updates the malus level based on the score and applies effects.
    void update(DoodleModel& doodle, const Score& score);

    // Resets the malus manager's state.
    void reset();
};

#endif //DOODLEAP_MALUSMANAGER_H
