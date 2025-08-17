#ifndef DOODLEAP_ABSTRACTFACTORY_H

#include "memory"
#include "doodleModel.h"
#include "BGTileModel.h"
#include "platformModel.h"
#include "bonusModel.h"

#define DOODLEAP_ABSTRACTFACTORY_H

class AbstractFactory{
public:
    // Creates a new DoodleModel.
    virtual shared_ptr<DoodleModel> createDoodle(World& world, float posX, float posY) = 0;
    // Creates a new BGTileModel.
    virtual shared_ptr<BGTileModel> createBGTile(World& world) = 0;
    // Creates a new PlatformModel.
    virtual shared_ptr<PlatformModel> createPlatform(World& world, float x, float y, float z, float q) = 0;
    // Creates a new BonusModel of a specific type.
    virtual shared_ptr<BonusModel> createBonus(World& world, const string& bonusType) = 0;
};

#endif //DOODLEAP_ABSTRACTFACTORY_H