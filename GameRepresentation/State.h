#ifndef DOODLEAP_STATE_H
#define DOODLEAP_STATE_H

class State{
public:
    // Draws the state to the screen.
    virtual void draw() = 0;
    // Updates the state.
    virtual void update() = 0;
    // Initializes the state.
    virtual void init() = 0;
    // Handles input for the state.
    virtual void inputController() = 0;
};


#endif //DOODLEAP_STATE_H
