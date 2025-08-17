#include "doodleView.h"

DoodleView::DoodleView(DoodleModel &doodleModel, sf::RenderWindow &window): EntityView(doodleModel, window), renderWindow(window) {
    doodle.setFillColor(sf::Color::Cyan);
    doodle.setRadius(20);
}

void DoodleView::draw() {
    this->renderWindow.draw(doodle);
}

void DoodleView::update() {
    float positionX = this->entityModel.getPositionX();
    float positionY = this->entityModel.getPositionY();

    pair<float, float> ctp = entityModel.getWorld().getCamera().coordinatesToPixels(positionX, positionY, this->entityModel);

    doodle.setPosition(ctp.first, ctp.second);
    this->draw();
}
