#include "entityView.h"

EntityView::EntityView(EntityModel &entityModel, sf::RenderWindow &window): Observer(entityModel), renderWindow(window) {

}
