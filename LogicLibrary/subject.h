#ifndef DOODLEAP_SUBJECT_H

#include <vector>
#include "stopwatch.h"

#define DOODLEAP_SUBJECT_H

class Observer;

class Subject{
protected:
    vector<shared_ptr<Observer>> observers;

public:

    // Adds an observer to the subject.
    void addObserver(shared_ptr<Observer> observer);

    // Notifies all registered observers of a change.
    void notifyObservers();

};

#endif //DOODLEAP_SUBJECT_H
