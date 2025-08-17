#include "LevelState.h"
#include "../LogicLibrary/world.h"
#include "window.h"

LevelState::LevelState(sf::RenderWindow& renderWindow1, StateManager &stateManager1, float width1, float height1): renderWindow(renderWindow1), stateManager(stateManager1) {
    width = width1;
    height = height1;
}

void LevelState::draw() {
    
}

void LevelState::update() {
    ConcreteFactory concreteFactory(renderWindow);
    Window window1(width, height, renderWindow, stateManager);
    World world(window1, concreteFactory);
    world.gameLoop();
}

void LevelState::init() {

}

void LevelState::inputController() {

}

