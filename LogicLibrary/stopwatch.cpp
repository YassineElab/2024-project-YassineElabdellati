#include "stopwatch.h"

Stopwatch::Stopwatch() {
    prevFrame = chrono::steady_clock::now();
}

shared_ptr<Stopwatch> Stopwatch::getTime() {
    if(!time){
        time = make_shared<Stopwatch>();
    }
    return time;
}

void Stopwatch::nextFrame() {
    currFrame = chrono::steady_clock::now();
    deltaTime = currFrame - prevFrame;
    deltaTimeCounter = deltaTime.count();
    prevFrame = currFrame;
}

float Stopwatch::movementMul() const {
    return this->deltaTimeCounter * 60.f;
}
