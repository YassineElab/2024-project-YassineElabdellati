#include "bonusEffect.h"
#include "doodleModel.h"
#include "score.h"

void SpringEffect::applyEffect(DoodleModel& doodle, Score& score) {
    auto movement = doodle.getMovement();
    movement.second = doodle.getJumpHeight() + springBoost;
    doodle.setMovement(movement);
    score.addToScore(springScore);
}

void JetpackEffect::applyEffect(DoodleModel& doodle, Score& score) {
    auto movement = doodle.getMovement();
    movement.second = doodle.getJumpHeight() + jetpackBoost;
    doodle.setMovement(movement);
    score.addToScore(jetpackScore);
}
