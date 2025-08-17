#include "doodleModel.h"
#include "world.h"

DoodleModel::DoodleModel(World &world, float posX, float posY)
    : EntityModel(world), startPosX(posX), startPosY(posY) {
    this->size.first = 20;
    this->size.second = 20;
    reset();
}

void DoodleModel::update() {
    position.first += movement.first;

    if (position.first < 0) {
        position.first = 0;
        movement.first = 0;
    } else if (position.first + (2*size.first) > 500) {
        position.first = 500 - (2*size.first);
        movement.first = 0;
    }

    position.second += movement.second;
    notifyObservers();
}

void DoodleModel::moveRight() {
    movement.first += 1.f * world.getStopwatch()->movementMul();
    if(movement.first > maxSpeed){
        movement.first = maxSpeed;
    }
}

void DoodleModel::moveLeft() {
    movement.first -= 1.f * world.getStopwatch()->movementMul();
    if(movement.first < -maxSpeed){
        movement.first = -maxSpeed;
    }
}

void DoodleModel::gravityPlayer() {
    movement.second -= gravity;
}

void DoodleModel::checkCollisionOnPlatforms(vector<shared_ptr<PlatformModel>> &platforms) {
    for (auto& platform : platforms) {
        if (checkCollisions(*this, *platform)) {
            if (collisionFromBottom) {
                if (platform->getCollisionFromTop()) {
                    if (platform->getTempPlatform()) {
                        platform->setDelete();
                    }
                    movement.second = jumpHeight;
                }
            }
        } else {
            platform->setCollisionFromTop(false);
        }
    }
}

void DoodleModel::checkCollisionOnBonuses(vector<shared_ptr<BonusModel>> &bonuses, Score& score) {
    for (auto& bonus : bonuses) {
        if (checkCollisions(*this, *bonus)) {
            if (collisionFromBottom) {
                if (bonus->getCollisionFromTop()) {
                    bonus->applyBonusEffect(*this, score);
                }
            }
        } else {
            bonus->setCollisionFromTop(false);
        }
    }
}

pair<float, float> DoodleModel::getMovement() { return movement; }
void DoodleModel::setMovement(const pair<float, float>& newMovement) { movement = newMovement; }
float DoodleModel::getJumpHeight() const { return jumpHeight; }
void DoodleModel::setJumpHeight(float newJumpHeight) { jumpHeight = newJumpHeight; }
float DoodleModel::getMaxSpeed() const { return maxSpeed; }
void DoodleModel::setMaxSpeed(float newMaxSpeed) { maxSpeed = newMaxSpeed; }

void DoodleModel::applyMalus(float speedReduction, float jumpReduction) {
    maxSpeed = max(1.0f, baseMaxSpeed - speedReduction);
    jumpHeight = max(5.0f, baseJumpHeight - jumpReduction);
}

void DoodleModel::reset() {
    maxSpeed = baseMaxSpeed;
    jumpHeight = baseJumpHeight;
    resetPosition();
}

void DoodleModel::resetPosition() {
    this->position.first = startPosX;
    this->position.second = startPosY;
    this->movement = {0, 0};
}
