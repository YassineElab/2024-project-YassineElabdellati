#ifndef DOODLEAP_LEVELSTATE_H

#include "State.h"
#include "StateManager.h"
#include "concreteFactory.h"

#define DOODLEAP_LEVELSTATE_H

class LevelState: public State{
private:
    sf::RenderWindow& renderWindow;

    float width;
    float height;
    StateManager& stateManager;

public:
    // Constructor for the level state.
    LevelState(sf::RenderWindow& renderWindow1, StateManager& stateManager1, float width1, float height1);
    // Draws the level state to the screen.
    void draw() override;
    // Updates the level state.
    void update() override;
    // Initializes the level state.
    void init() override;
    // Handles input for the level state.
    void inputController() override;
};

#endif //DOODLEAP_LEVELSTATE_H
