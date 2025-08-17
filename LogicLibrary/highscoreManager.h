#ifndef DOODLEAP_HIGHSCOREMANAGER_H
#define DOODLEAP_HIGHSCOREMANAGER_H

#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

class HighscoreManager {
private:
    vector<int> highscores;
    string filename;
    static const int MAX_HIGHSCORES = 5;

public:
    // Constructor for the highscore manager.
    HighscoreManager(const string& filepath = "savedHighscores.txt");
    
    // Loads highscores from the file.
    void loadHighscores();
    
    // Saves highscores to the file.
    void saveHighscores();
    
    // Adds a new score to the highscores list.
    bool addScore(int score);
    
    // Returns the highest score.
    int getTopScore() const;
    
    // Returns all highscores.
    vector<int> getAllHighscores() const;
    
    // Resets all highscores.
    void reset();
};

#endif //DOODLEAP_HIGHSCOREMANAGER_H
