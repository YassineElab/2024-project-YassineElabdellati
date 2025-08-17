#include "bonusView.h"

BonusView::BonusView(BonusModel& bonusModel, sf::RenderWindow& window) : EntityView(bonusModel, window), renderWindow(window) {
    BonusModel& bonusRef = static_cast<BonusModel&>(entityModel);
    if (bonusRef.getBonusType() == "spring") {
        bonus.setFillColor(sf::Color::Blue);
    } else if (bonusRef.getBonusType() == "jetpack") {
        bonus.setFillColor(sf::Color::Red);
    } else {
        bonus.setFillColor(sf::Color::Yellow);
    }
    
    bonus.setSize(sf::Vector2f(entityModel.getSizeX(), entityModel.getSizeY()));
    bonus.setPosition(entityModel.getPositionX(), entityModel.getPositionY());
}

void BonusView::update() {
    float positionX = this->entityModel.getPositionX();
    float positionY = this->entityModel.getPositionY();

    pair<float, float> ctp = entityModel.getWorld().getCamera().coordinatesToPixels(positionX, positionY, this->entityModel);

    bonus.setPosition(ctp.first + 45, ctp.second);

    this->draw();
}

void BonusView::draw() {
    this->renderWindow.draw(bonus);
}
