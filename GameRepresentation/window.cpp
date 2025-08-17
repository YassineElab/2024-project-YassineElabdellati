#include "window.h"

Window::Window(int width, int height, sf::RenderWindow& window, StateManager& stateManager1): stateManager(stateManager1), renderWindow(window), width(width), height(height) {

}

void Window::clear() {
    return this->renderWindow.clear(sf::Color::White);
}

void Window::draw() {

}

bool Window::isOpen() {
    return this->renderWindow.isOpen();
}

void Window::keyPresses(char *c) {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)){
        c[0] = 'A';
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)){
        c[1] = 'D';
    }
}

void Window::display() {
    return this->renderWindow.display();
}

void Window::checkForClose() {
    sf::Event event;
    renderWindow.pollEvent(event);
    if(event.type == sf::Event::Closed){
        this->renderWindow.close();
    }
}

int Window::getWindowWidth() {
    return this->width;
}

int Window::getWindowHeight() {
    return this->height;
}

void Window::textToScreen(float posX, float posY, string input) {
    sf::Text textSFML;

    sf::Font font;
    font.loadFromFile("../fonts/arial.ttf");

    textSFML.setString(input);
    textSFML.setCharacterSize(50);
    textSFML.setFont(font);
    textSFML.setPosition(posX, posY);
    textSFML.setFillColor(sf::Color::Black);
    renderWindow.draw(textSFML);
}

