#ifndef DOODLEAP_RANDOM_H

#include <random>

#define DOODLEAP_RANDOM_H

using namespace std;

class Random {
public:
    // Initializes the random number generator.
    static void init();
    // Returns a random integer within a specified range.
    static int getInt(int min, int max);

private:
    static mt19937 randomNumberEngine;
};


#endif //DOODLEAP_RANDOM_H
