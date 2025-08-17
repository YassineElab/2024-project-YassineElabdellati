#ifndef DOODLEAP_STATEMANAGER_H

#include "stack"
#include "memory"
#include "State.h"

#define DOODLEAP_STATEMANAGER_H

using namespace std;

class StateManager{
private:
    stack<shared_ptr<State>> states;
    shared_ptr<State> newState;

    bool add = false;
    bool remove = false;
    bool topReplacement = false;

public:
    // Constructor for the state manager.
    StateManager();
    // Adds a new state to the stack.
    void addState(shared_ptr<State> newState1, bool topReplacement1 = true);
    // Removes the current state from the stack.
    void removeState();
    // Processes any pending state changes.
    void stateChanges();
    // Gets the currently active state.
    shared_ptr<State> getActiveState();
};


#endif //DOODLEAP_STATEMANAGER_H
