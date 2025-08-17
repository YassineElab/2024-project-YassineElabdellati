#include "subject.h"
#include "observer.h"
#include <algorithm>

void Subject::addObserver(shared_ptr<Observer> observer) {
    observers.push_back(observer);
}

void Subject::notifyObservers() {
    for(auto &observer: observers){
        observer->update();
    }
}
