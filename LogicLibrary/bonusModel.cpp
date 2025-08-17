#include "bonusModel.h"
#include "world.h"

BonusModel::BonusModel(World& world, const string& type) 
    : EntityModel(world), bonusType(type) {
    this->size.first = 20;
    this->size.second = 20;

    if (type == "spring") {
        effect = make_unique<SpringEffect>();
    } else if (type == "jetpack") {
        effect = make_unique<JetpackEffect>();
    }
}

void BonusModel::update() {
    if(this->getPositionY() < this->getWorld().getCamera().getCamHeight()){
        needDelete = true;
    }

    if (effect && effect->getDuration() > 0) {
        effect->update(0.016f);
        if (!effect->isActive()) {
            needDelete = true;
        }
    }
    notifyObservers();
}

void BonusModel::setPosition(float x, float y) {
    this->position.first = x + 50;
    this->position.second = y + 20;
}

bool BonusModel::getDelete() const {
    return needDelete;
}

void BonusModel::applyBonusEffect(DoodleModel& doodle, Score& score) {
    if (effect) {
        effect->applyEffect(doodle, score);
        if (effect->getDuration() == 0) {
            needDelete = true;
        }
    }
}

const string& BonusModel::getBonusType() const {
    return bonusType;
}

bool BonusModel::isTimedEffect() const {
    return effect && effect->getDuration() > 0;
}

void BonusModel::updateEffect(float deltaTime) {
    if (effect) {
        effect->update(deltaTime);
    }
}

bool BonusModel::isEffectActive() const {
    return effect && effect->isActive();
}
