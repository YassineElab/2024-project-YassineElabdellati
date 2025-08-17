#ifndef DOODLEAP_DOODLEVIEW_H

#include "entityView.h"

#define DOODLEAP_DOODLEVIEW_H

class DoodleView: public EntityView{
private:
    sf::RenderWindow& renderWindow;

    sf::CircleShape doodle;

public:
    // Constructor for the doodle view.
    DoodleView(DoodleModel& doodleModel, sf::RenderWindow& window);

    // Updates the doodle view.
    void update() override;

    // Draws the doodle to the screen.
    void draw() override;
};

#endif //DOODLEAP_DOODLEVIEW_H
