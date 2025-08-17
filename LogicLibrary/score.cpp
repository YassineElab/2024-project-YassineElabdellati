#include "score.h"
#include "algorithm"
#include "fstream"

Score::Score(EntityModel &entityModel) {

}

void Score::update() {
    notifyObservers();
}

string Score::getScore() const {
    return to_string(currentScore + bonusScore);
}

void Score::addToScore(int add) {
    bonusScore += add;
}

void Score::setCurrentScore(int score) {
    currentScore = score;
}

void Score::reset() {
    currentScore = 0;
    bonusScore = 0;
}
