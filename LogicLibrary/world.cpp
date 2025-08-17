#include "world.h"
#include "abstractFactory.h"
#include "random.h"
#include <iostream>
#include <algorithm>

World::World(WindowV &windowV1, AbstractFactory &abstractFactory1): windowV(windowV1), abstractFactory(abstractFactory1),
                                                                  camera(Camera(windowV.getWindowWidth(), windowV.getWindowHeight())),
                                                                    score(*doodle) {
    Random::init();
    createBGTile();
    createDoodle(50,50);
    createPlatform(0, 0, 100, 20);
    createPlatform(100, 150, 100, 20);
}

void World::gameLoop() {
    while(windowV.isOpen() and gameIsRunning){
        this->windowV.clear();
        this->windowV.draw();

        gameIsRunning = this->update();

        string scoreString = "";

        this->windowV.textToScreen(250, 0, score.getScore());

        this->windowV.display();
        this->windowV.checkForClose();
    }
}

bool World::update() {
    this->stopwatch->nextFrame();

    bgtile->update();

    malusManager.update(*doodle, score);
    doodle->update();

    for(auto bonus: bonuses){
        bonus->update();
    }

    score.setCurrentScore(camera.getCamHeight());

    doodle->checkCollisionOnBonuses(bonuses, score);

    for(auto platform: platforms){
        platform->update();

        if(platform->getNumber() == 10){
            int random = Random::getInt(0, 6);
            if(random == 0 or random == 1){
                platform->setNumber(0);
            }else if(random == 2 or random == 3){
                platform->dynamicPlatformLeftRight();
            }else if(random == 4 or random == 5){
                platform->dynamicPlatformUpDown();
            }else if(random == 6){
                platform->setTempPlatform();
            }
        }
        else if(platform->getNumber() == 0){
            int random = Random::getInt(0, 16);
            if(random == 0 or random == 1 or random == 2 or random == 3){
                createBonus("spring", platform->getPositionX(), platform->getPositionY());
            }
            if(random == 4){
                createBonus("jetpack", platform->getPositionX(), platform->getPositionY());
            }
            platform->setNumber(15);
        }
        else if(platform->getNumber() == 1){
            platform->dynamicPlatformLeftRight();
        }else if(platform->getNumber() == 2){
            platform->dynamicPlatformUpDown();
        }
    }

    if(doodle->getPositionY() >= camera.getCamHeight() + camera.getHeight() *0.8){
        float heightDiff = abs((camera.getCamHeight() + camera.getHeight() *0.8) - doodle->getPositionY());
        camera.screenScroller(heightDiff);
        camera.setHeightDiff(heightDiff);
    }

    platforms.erase(remove_if(platforms.begin(), platforms.end(), [](const shared_ptr<PlatformModel>& platform) {
                               return platform->getDelete();
    }), platforms.end());

    bonuses.erase(remove_if(bonuses.begin(), bonuses.end(), [](const shared_ptr<BonusModel>& bonus) {
                               return bonus->getDelete();
    }), bonuses.end());

    while(platforms.back()->getPositionY() <  camera.getCamHeight() + 800){
        float x = Random::getInt(0, windowV.getWindowWidth() - 150);
        float y = platforms.back()->getPositionY() + 250.f;
        createPlatform(x, y, 100, 20);
    }

    if(doodlePos < doodle->getPositionY()){
        doodlePos = doodle->getPositionY();
    }
    else if(doodlePos > doodle->getPositionY()){
        doodlePos = doodle->getPositionY();
        doodle->checkCollisionOnPlatforms(platforms);
        doodle->checkCollisionOnBonuses(bonuses, score);
    }

    if(doodle->getPositionY() + doodle->getSizeY() < camera.getCamHeight()){
        int finalScore = stoi(score.getScore());
        highscoreManager.addScore(finalScore);
        doodle->reset();
        malusManager.reset();
        return false;
    }

    char press[4] = {-1, -1, };

    windowV.keyPresses(press);

    if (press[0] == 'A') {
        doodle->moveLeft();
    } else if (press[1] == 'D') {
        doodle->moveRight();
    }

    doodle->gravityPlayer();

    return true;
}

void World::createDoodle(float x, float y) {
    this->doodle = this->abstractFactory.createDoodle(*this, x, y);
}

void World::createBGTile() {
    this->bgtile = this->abstractFactory.createBGTile(*this);
}

void World::createPlatform(float x, float y, float z, float q) {
    this->platform = this->abstractFactory.createPlatform(*this, x, y, z, q);
    platforms.push_back(this->platform);
}

void World::createBonus(const string& bonusType, float x, float y) {
    auto bonus = this->abstractFactory.createBonus(*this, bonusType);
    bonus->setPosition(x, y);
    bonuses.push_back(bonus);
}



shared_ptr<Stopwatch> World::getStopwatch() {
    return this->stopwatch;
}

Camera &World::getCamera() {
    return this->camera;
}

