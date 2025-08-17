#ifndef DOODLEAP_WINDOW_H

#include "../LogicLibrary/windowV.h"
#include <SFML/Graphics.hpp>
#include "StateManager.h"
#include "string"

#define DOODLEAP_WINDOW_H

class Window: public WindowV{
private:
    sf::RenderWindow& renderWindow;
    StateManager& stateManager;

    int width;
    int height;

public:
    // Constructor for the Window class.
    Window(int width, int height, sf::RenderWindow& window, StateManager& stateManager1);

    // Clears the window.
    void clear() override;

    void draw() override;

    // Checks if the window is currently open.
    bool isOpen() override;

    // Handles key press events
    void keyPresses(char* c) override;

    // Displays the contents on the screen.
    void display() override;

    // Checks for window close events.
    void checkForClose() override;

    // Returns the width of the window.
    int getWindowWidth() override;

    // Returns the height of the window.
    int getWindowHeight() override;

    // Renders a string of text at a given position to the screen.
    void textToScreen(float posX, float posY, string input) override;

};

#endif //DOODLEAP_WINDOW_H
