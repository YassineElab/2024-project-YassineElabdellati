#include "entityModel.h"
#include "world.h"

EntityModel::EntityModel(World &world): world(world) {

}

float EntityModel::getPositionX() {
    return this->position.first;
}

float EntityModel::getPositionY() {
    return this->position.second;
}

float EntityModel::getSizeX() {
    return this->size.first;
}

float EntityModel::getSizeY() {
    return this->size.second;
}

bool EntityModel::checkCollisions(EntityModel& player, EntityModel& wall) {

    float playerMinX = min(player.getPositionX(), player.getPositionX() - player.getSizeX());
    float playerMaxX = max(player.getPositionX(), player.getPositionX() - player.getSizeX());
    float playerMinY = min(player.getPositionY(), player.getPositionY() - player.getSizeY());
    float playerMaxY = max(player.getPositionY(), player.getPositionY() - player.getSizeY());

    float wallMinX = min(wall.getPositionX(), wall.getPositionX() + wall.getSizeX());
    float wallMaxX = max(wall.getPositionX(), wall.getPositionX() + wall.getSizeX());
    float wallMinY = min(wall.getPositionY(), wall.getPositionY() - wall.getSizeY());
    float wallMaxY = max(wall.getPositionY(), wall.getPositionY() - wall.getSizeY());

    if ((max(playerMinX, wallMinX) <= min(playerMaxX, wallMaxX)) &&
        (max(playerMinY, wallMinY) <= min(playerMaxY, wallMaxY))) {
        if((wallMaxY > playerMinY) and (playerMaxY > wallMaxY) and (playerMinX <= wallMaxX) and (playerMaxX >= wallMinX)){
            player.setCollisionFromTop(false);
            player.setCollisionFromBottom(true);

            wall.setCollisionFromTop(true);
            wall.setCollisionFromBottom(false);
        }
        return true;
    }
    return false;
}

void EntityModel::setCollisionFromRight(bool collision) {
    collisionFromRight = collision;
}

void EntityModel::setCollisionFromLeft(bool collision) {
    collisionFromLeft = collision;
}

void EntityModel::setCollisionFromTop(bool collision) {
    collisionFromTop = collision;
}

void EntityModel::setCollisionFromBottom(bool collision) {
    collisionFromBottom = collision;
}

bool EntityModel::getCollisionFromRight() const {
    return collisionFromRight;
}

bool EntityModel::getCollisionFromLeft() const {
    return collisionFromLeft;
}

bool EntityModel::getCollisionFromTop() const {
    return collisionFromTop;
}

bool EntityModel::getCollisionFromBottom() const {
    return collisionFromBottom;
}

World EntityModel::getWorld() {
    return this->world;
}

bool EntityModel::getCollisionOnCoins() {
    if(collisionCoins){
        return true;
    }
    return false;

}


deque<int> EntityModel::getLines() {
    return {};
}

void EntityModel::resetLines() {

}

int EntityModel::getNumber() {
    return this->number;
}





