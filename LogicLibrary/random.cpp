#include "random.h"
#include <chrono>

using namespace std;

mt19937 Random::randomNumberEngine;

void Random::init() {
    auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
    randomNumberEngine.seed(seed);
}

int Random::getInt(int min, int max) {
    uniform_int_distribution<int> dist(min, max);
    return dist(randomNumberEngine);
}
