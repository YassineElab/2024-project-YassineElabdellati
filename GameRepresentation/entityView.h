#ifndef DOODLEAP_ENTITYVIEW_H

#include <SFML/Graphics.hpp>
#include "../LogicLibrary/doodleModel.h"
#include "../LogicLibrary/BGTileModel.h"
#include "../LogicLibrary/platformModel.h"
#include "../LogicLibrary/world.h"

#define DOODLEAP_ENTITYVIEW_H

class EntityView: public Observer{
protected:
    sf::RenderWindow& renderWindow;
    // Constructor for the EntityView.
    EntityView(EntityModel& entityModel, sf::RenderWindow& window);

    sf::Sprite sprite;
    sf::Texture texture;


public:
    // Virtual function to draw the entity.
    virtual void draw() = 0;

};

#endif //DOODLEAP_ENTITYVIEW_H
