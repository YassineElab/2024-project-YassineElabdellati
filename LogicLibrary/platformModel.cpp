#include "platformModel.h"
#include "world.h"

PlatformModel::PlatformModel(World &world, float x, float y, float z, float q): EntityModel(world) {
    this->number = 10;

    this->position.first = x;
    this->position.second = y;

    this->size.first = z;
    this->size.second = q;

    startingPoint.first = position.first;
    startingPoint.second = position.second;

    if(startingPoint.first >= 250){
        dynamicPlace.first = startingPoint.first - 100;
        moveLeft = true;
        startLeft = false;
    }
    else if(startingPoint.first < 250){
        dynamicPlace.first = startingPoint.first + 100;
        moveRight = true;
        startLeft = true;
    }
    if(startingPoint.second > 600){
        dynamicPlace.second = startingPoint.second - 100;
        moveDown = true;
    }
}

void PlatformModel::update() {
    if(this->getPositionY() < this->getWorld().getCamera().getCamHeight()){
        needDelete = true;
    }
    notifyObservers();
}

void PlatformModel::setDelete() {
    needDelete = true;
}

bool PlatformModel::getDelete() const {
    return needDelete;
}

void PlatformModel::dynamicPlatformLeftRight() {
    this->number = 1;
    if(startLeft){
        if(moveRight){
            position.first += 2;
            if(position.first > dynamicPlace.first){
                moveLeft = true;
                moveRight = false;
                moveDown = false;
                moveUp = false;
            }
        }
        if(moveLeft){
            position.first -= 2;
            if(position.first < startingPoint.first){
                moveRight = true;
                moveLeft = false;
                moveDown = false;
                moveUp = false;
            }
        }
    }else{
        if(moveRight){
            position.first += 2;
            if(position.first > startingPoint.first){
                moveLeft = true;
                moveRight = false;
                moveDown = false;
                moveUp = false;
            }
        }
        if(moveLeft){
            position.first -= 2;
            if(position.first < dynamicPlace.first){
                moveRight = true;
                moveLeft = false;
                moveDown = false;
                moveUp = false;
            }
        }
    }

}

void PlatformModel::dynamicPlatformUpDown() {
    this->number = 2;
    if(moveUp){
        position.second += 2;
        if(position.second > startingPoint.second){
            moveDown = true;
            moveUp = false;
            moveRight = false;
            moveLeft = false;
        }
    }
    if(moveDown){
        position.second -= 2;
        if(position.second < dynamicPlace.second){
            moveUp = true;
            moveDown = false;
            moveRight = false;
            moveLeft = false;
        }
    }
}

void PlatformModel::setTempPlatform() {
    this->number = 3;
    tempPlatform = true;
}

bool PlatformModel::getTempPlatform() {
    return tempPlatform;
}

void PlatformModel::setNumber(int number) {
    this->number = number;
}




