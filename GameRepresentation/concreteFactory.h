#ifndef DOODLEAP_CONCRETEFACTORY_H

#include "../LogicLibrary/abstractFactory.h"
#include <SFML/Graphics.hpp>

#define DOODLEAP_CONCRETEFACTORY_H

class ConcreteFactory: public AbstractFactory{
private:
    sf::RenderWindow& window;

public:
    // Constructor for the concrete factory.
    explicit ConcreteFactory(sf::RenderWindow& window1);

    // Creates a new doodle character.
    shared_ptr<DoodleModel> createDoodle(World& world, float posX, float posY) override;

    // Creates a new background tile.
    shared_ptr<BGTileModel> createBGTile(World& world) override;

    // Creates a new platform.
    shared_ptr<PlatformModel> createPlatform(World& world, float x, float y, float z, float q) override;

    // Creates a new bonus item.
    shared_ptr<BonusModel> createBonus(World& world, const string& bonusType) override;
};





#endif //DOODLEAP_CONCRETEFACTORY_H
