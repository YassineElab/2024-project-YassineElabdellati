#include "game.h"
#include "concreteFactory.h"
#include "window.h"
#include "MenuState.h"

shared_ptr<Stopwatch> Stopwatch::time = 0;

Game::Game(int width, int height) {
    sf::RenderWindow window(sf::VideoMode(width, height), "Doodle Jump");
    window.setFramerateLimit(60);

    StateManager stateManager;
    Window window1(width, height, window, stateManager);

    stateManager.addState(shared_ptr<State>(new MenuState(window, stateManager, width, height)), true);

    while(window1.isOpen()){
        stateManager.stateChanges();
        stateManager.getActiveState()->inputController();
        stateManager.getActiveState()->update();
    }
}
