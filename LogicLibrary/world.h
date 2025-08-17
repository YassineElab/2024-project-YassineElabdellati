#ifndef DOODLEAP_WORLD_H

#include "windowV.h"
#include "memory"
#include "doodleModel.h"
#include "BGTileModel.h"
#include "platformModel.h"
#include "bonusModel.h"
#include "highscoreManager.h"
#include "malusManager.h"
#include <vector>
#include "score.h"
#include "camera.h"

#define DOODLEAP_WORLD_H

class AbstractFactory;

enum SuccessEnum {ImportAborted, PartialImport, Success};

class World{
protected:
    WindowV& windowV;
    AbstractFactory& abstractFactory;
    shared_ptr<Stopwatch> stopwatch = stopwatch->getTime();

    shared_ptr<DoodleModel> doodle;
    shared_ptr<BGTileModel> bgtile;
    shared_ptr<PlatformModel> platform;
    vector<shared_ptr<PlatformModel>> platforms;
    
    vector<shared_ptr<BonusModel>> bonuses;

    float doodlePos = 100;
    Score score;
    HighscoreManager highscoreManager;
    MalusManager malusManager;

    bool gameIsRunning = true;

    Camera camera;

public:
    // Constructor for the World class.
    explicit World(WindowV& windowV1, AbstractFactory& abstractFactory1);

    // Main game loop for the world.
    void gameLoop();

    // Updates the state of the world and all its entities.
    bool update();

    // Creates the doodle character at a specific position.
    void createDoodle(float x, float y);

    // Creates the background tile.
    void createBGTile();

    // Creates a platform at a specific position.
    void createPlatform(float x, float y, float z, float q);

    // Creates a bonus of a specific type at a given position.
    void createBonus(const string& bonusType, float x, float y);

    // Returns a shared pointer to the stopwatch.
    shared_ptr<Stopwatch> getStopwatch();

    // Returns a reference to the camera.
    Camera& getCamera();
};

#endif //DOODLEAP_WORLD_H
