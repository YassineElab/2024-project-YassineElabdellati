#ifndef DOODLEAP_WINDOWV_H

#include "string"

#define DOODLEAP_WINDOWV_H

class WindowV{
public:
    // Clears the window.
    virtual void clear() = 0;
    // Draws all elements.
    virtual void draw() = 0;
    // Checks if the window is currently open.
    virtual bool isOpen() = 0;
    // Handles key press events.
    virtual void keyPresses(char* c) = 0;
    // Displays the contents on the screen.
    virtual void display() = 0;
    // Checks for window close events.
    virtual void checkForClose() = 0;
    // Returns the width of the window.
    virtual int getWindowWidth() = 0;
    // Returns the height of the window.
    virtual int getWindowHeight() = 0;
    // Renders a string of text at a given position to the screen.
    virtual void textToScreen(float posX, float posY, std::string input) = 0;
};

#endif //DOODLEAP_WINDOWV_H
