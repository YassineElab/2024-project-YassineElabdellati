#ifndef DOODLEAP_DOODLEMODEL_H
#define DOODLEAP_DOODLEMODEL_H

#include "entityModel.h"
#include "platformModel.h"
#include "bonusModel.h"
#include <vector>

using namespace std;

class Score;

class DoodleModel : public EntityModel {
private:
    float maxSpeed;
    float jumpHeight;

    const float baseMaxSpeed = 4.0f;
    const float baseJumpHeight = 14.0f;

    pair<float, float> movement;
    float gravity = 0.2f;
    float startPosX, startPosY;

public:
    // Constructor for the DoodleModel.
    DoodleModel(World& world, float posX, float posY);

    // Returns the current movement vector of the doodle.
   pair<float, float> getMovement();
    // Sets the movement vector of the doodle.
    void setMovement(const pair<float, float>& newMovement);
    // Returns the current jump height of the doodle.
    float getJumpHeight() const;
    // Sets the jump height of the doodle.
    void setJumpHeight(float newJumpHeight);
    // Returns the maximum speed of the doodle.
    float getMaxSpeed() const;
    // Sets the maximum speed of the doodle.
    void setMaxSpeed(float newMaxSpeed);

    // Updates the doodle's state, including position and physics.
    void update() override;
    // Moves the doodle to the right.
    void moveRight();
    // Moves the doodle to the left.
    void moveLeft();
    // Applies gravity to the doodle.
    void gravityPlayer();
    // Checks for and handles collisions with platforms.
    void checkCollisionOnPlatforms(vector<shared_ptr<PlatformModel>>& platforms);
    // Checks for and handles collisions with bonuses.
    void checkCollisionOnBonuses(vector<shared_ptr<BonusModel>>& bonuses, Score& score);

    // Applies a malus effect, reducing speed and jump height.
    void applyMalus(float speedReduction, float jumpReduction);
    // Resets the doodle's stats to their base values.
    void reset();
    // Resets the doodle's position to the starting point.
    void resetPosition();
};

#endif //DOODLEAP_DOODLEMODEL_H
