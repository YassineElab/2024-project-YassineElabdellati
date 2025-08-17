#include "platformView.h"

PlatformView::PlatformView(PlatformModel &platformModel, sf::RenderWindow &window): EntityView(platformModel, window), renderWindow(window) {
    platform.setSize(sf::Vector2f(entityModel.getSizeX(), entityModel.getSizeY()));
    platform.setPosition(entityModel.getPositionX(), entityModel.getPositionY());
}

void PlatformView::update() {
    float positionX = this->entityModel.getPositionX();
    float positionY = this->entityModel.getPositionY();

    pair<float, float> ctp = entityModel.getWorld().getCamera().coordinatesToPixels(positionX, positionY, this->entityModel);

    platform.setPosition(ctp.first + 45, ctp.second);

    if(this->entityModel.getNumber() == 15){
        platform.setFillColor(sf::Color::Green);
        platform.setOutlineThickness(2.0f);
        platform.setOutlineColor(sf::Color::Black);
    }else if(this->entityModel.getNumber() == 1){
        platform.setFillColor(sf::Color::Blue);
        platform.setOutlineThickness(2.0f);
        platform.setOutlineColor(sf::Color::Black);
    }else if(this->entityModel.getNumber() == 2){
        platform.setFillColor(sf::Color::Yellow);
        platform.setOutlineThickness(2.0f);
        platform.setOutlineColor(sf::Color::Black);
    }else if(this->entityModel.getNumber() == 3){
        platform.setFillColor(sf::Color::White);
        platform.setOutlineThickness(2.0f);
        platform.setOutlineColor(sf::Color::Black);
    }

    this->draw();
}

void PlatformView::draw() {
    this->renderWindow.draw(platform);
}
