#ifndef DOODLEAP_ENTITYMODEL_H

#include <vector>
#include <deque>
#include "subject.h"

#define DOODLEAP_ENTITYMODEL_H

class World;

class EntityModel: public Subject{
protected:
    explicit EntityModel(World& world);

    World& world;

    pair<float, float> position;
    pair<float, float> size;
    int number;

    bool inFear = false;

    bool collisionCoins = false;

    bool collisionFromTop = false;
    bool collisionFromBottom = false;
    bool collisionFromLeft = false;
    bool collisionFromRight = false;


public:
    // Returns the x-coordinate of the entity's position.
    float getPositionX();

    // Returns the y-coordinate of the entity's position.
    float getPositionY();

    // Returns the width of the entity.
    float getSizeX();

    // Returns the height of the entity.
    float getSizeY();

    // Returns the entity's number.
    int getNumber();

    // Returns true if the entity is colliding with coins.
    bool getCollisionOnCoins();

    // Virtual function to update the entity's state.
    virtual void update() = 0;

    // Returns a reference to the game world.
    World getWorld();

    // Returns the lines associated with the entity.
    virtual deque<int> getLines();

    // Resets the lines associated with the entity.
    virtual void resetLines();

    // Checks for collision between two entities.
    bool checkCollisions(EntityModel& player, EntityModel& wall);

    // Sets the collision state from the right.
    void setCollisionFromRight(bool collision);
    // Sets the collision state from the left.
    void setCollisionFromLeft(bool collision);
    // Sets the collision state from the top.
    void setCollisionFromTop(bool collision);
    // Sets the collision state from the bottom.
    void setCollisionFromBottom(bool collision);

    // Returns the collision state from the right.
    bool getCollisionFromRight() const;
    // Returns the collision state from the left.
    bool getCollisionFromLeft() const;
    // Returns the collision state from the top.
    bool getCollisionFromTop() const;
    // Returns the collision state from the bottom.
    bool getCollisionFromBottom() const;

};

#endif //DOODLEAP_ENTITYMODEL_H
