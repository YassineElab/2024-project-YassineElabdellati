#include <iostream>
#include "BGTileView.h"

BGTileView::BGTileView(BGTileModel &bgTileModel, sf::RenderWindow &window): EntityView(bgTileModel, window), renderWindow(window) {

}

void BGTileView::update() {
    shapes.clear();
    const auto& lines = this->entityModel.getLines();

    for(auto& line: lines){
        sf::RectangleShape shape(sf::Vector2f(renderWindow.getSize().x, 1));
        shape.setFillColor(sf::Color(128, 128, 128));
        shape.setPosition(sf::Vector2f(0, line % 800));
        shapes.push_back(shape);
    }

    int lines2[] = {25, 50, 75, 100, 125, 150, 175, 200, 225, 250, 275, 300, 325, 350, 375, 400, 425, 450, 475};

    for (auto& line : lines2) {
        sf::RectangleShape shape(sf::Vector2f(1, renderWindow.getSize().y));
        shape.setFillColor(sf::Color(128, 128, 128));
        shape.setPosition(sf::Vector2f(line % renderWindow.getSize().x, 0));
        shapes.push_back(shape);
    }

    this->draw();
}

void BGTileView::draw() {
    for(auto& shape: shapes){
        this->renderWindow.draw(shape);
    }
}

