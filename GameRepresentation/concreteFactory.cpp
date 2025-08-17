#include "concreteFactory.h"
#include "doodleView.h"
#include "BGTileView.h"
#include "platformView.h"
#include "bonusView.h"

using namespace std;

ConcreteFactory::ConcreteFactory(sf::RenderWindow& window1): window(window1) {

}

shared_ptr<DoodleModel> ConcreteFactory::createDoodle(World &world, float posX, float posY) {
    shared_ptr<DoodleModel> doodleModel = make_shared<DoodleModel>(world, posX, posY);
    auto doodleView = make_shared<DoodleView>(*doodleModel, window);
    doodleModel->addObserver(doodleView);
    return doodleModel;
}

shared_ptr<BGTileModel> ConcreteFactory::createBGTile(World &world) {
    shared_ptr<BGTileModel> bgTileModel = make_shared<BGTileModel>(world);
    auto bgTileView = make_shared<BGTileView>(*bgTileModel, window);
    bgTileModel->addObserver(bgTileView);
    return bgTileModel;
}

shared_ptr<PlatformModel> ConcreteFactory::createPlatform(World &world, float x, float y, float z, float q) {
    shared_ptr<PlatformModel> platformModel = make_shared<PlatformModel>(world, x, y, z, q);
    auto platformView = make_shared<PlatformView>(*platformModel, window);
    platformModel->addObserver(platformView);
    return platformModel;
}

shared_ptr<BonusModel> ConcreteFactory::createBonus(World& world, const string& bonusType) {
    shared_ptr<BonusModel> bonusModel = make_shared<BonusModel>(world, bonusType);
    auto bonusView = make_shared<BonusView>(*bonusModel, window);
    bonusModel->addObserver(bonusView);
    return bonusModel;
}


