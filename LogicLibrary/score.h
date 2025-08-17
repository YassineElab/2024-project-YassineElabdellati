#ifndef DOODLEAP_SCORE_H

#include "observer.h"
#include "stopwatch.h"
#include "vector"
#include "string"
#include <iostream>
#include <fstream>
#include <algorithm>

#define DOODLEAP_SCORE_H

class Score: Subject {
private:
    int currentScore = 0;
    int bonusScore = 0;

public:
    // Constructor for the Score class.
    Score(EntityModel &entityModel);

    // Updates the score.
    void update();

    // Returns the current score as a string.
    string getScore() const;

    // Sets the current score.
    void setCurrentScore(int score);

    // Adds a value to the current score.
    void addToScore(int add);

    // Resets the score.
    void reset();
};


#endif //DOODLEAP_SCORE_H
