#include "highscoreManager.h"
#include <iostream>

using namespace std;

HighscoreManager::HighscoreManager(const string& filepath)
    : filename(filepath) {
    loadHighscores();
}

void HighscoreManager::loadHighscores() {
    highscores.clear();
    ifstream file(filename);
    if (file.is_open()) {
        int score;
        while (file >> score) {
            highscores.push_back(score);
        }
        file.close();
        sort(highscores.begin(), highscores.end(), greater<int>());
    }
}

void HighscoreManager::saveHighscores() {
    ofstream file(filename, ios::trunc);
    if (file.is_open()) {
        cout << "Saving highscores to " << filename << endl;
        for (int score : highscores) {
            file << score << endl;
        }
        file.close();
    } else {
        cout << "Error: Could not open file to save highscores: " << filename << endl;
    }
}

bool HighscoreManager::addScore(int score) {
    highscores.push_back(score);
    sort(highscores.begin(), highscores.end(), greater<int>());
    if (highscores.size() > MAX_HIGHSCORES) {
        highscores.resize(MAX_HIGHSCORES);
    }
    saveHighscores();
    return true;
}

int HighscoreManager::getTopScore() const {
    return highscores.empty() ? 0 : highscores.front();
}

vector<int> HighscoreManager::getAllHighscores() const {
    return highscores;
}



void HighscoreManager::reset() {
    highscores.clear();
    saveHighscores();
}
