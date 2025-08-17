#ifndef DOODLEAP_MENUSTATE_H

#include "State.h"
#include "StateManager.h"
#include "concreteFactory.h"
#include "LevelState.h"

#define DOODLEAP_MENUSTATE_H

class MenuState: public State{
private:
    sf::RenderWindow& renderWindow;
    float width;
    float height;
    StateManager& stateManager;
    sf::Sprite sprite;
    bool play;
    int menuSelect;
    sf::Font font;
    sf::Texture background;
    sf::Text menuScreen[8];

public:
    // Constructor for the menu state.
    explicit MenuState(sf::RenderWindow& renderWindow1, StateManager& stateManager1, float width1, float height1);
    // Draws the menu state to the screen.
    void draw() override;
    // Updates the menu state.
    void update() override;
    // Initializes the menu state.
    void init() override;
    // Handles input for the menu state.
    void inputController() override;
    // Moves the menu selection to the right.
    void moveRight();
    // Moves the menu selection to the left.
    void moveLeft();



};


#endif //DOODLEAP_MENUSTATE_H
