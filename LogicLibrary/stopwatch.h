#ifndef DOODLEAP_STOPWATCH_H
#include <memory>
#include <chrono>
#define DOODLEAP_STOPWATCH_H

using namespace std;

class Stopwatch{
private:
    static shared_ptr<Stopwatch> time;
    chrono::time_point<chrono::steady_clock> currFrame;
    chrono::time_point<chrono::steady_clock> prevFrame;
    chrono::duration<double> deltaTime;
    float deltaTimeCounter;

public:
    // Constructor for the stopwatch.
    Stopwatch();
    // Returns the shared pointer to the stopwatch instance.
    static shared_ptr<Stopwatch> getTime();
    // Calculates the time delta since the last frame.
    void nextFrame();
    // Returns the movement multiplier for frame-rate.
    float movementMul() const;
};

#endif //DOODLEAP_STOPWATCH_H
