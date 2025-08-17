#ifndef DOODLEAP_BG_TILEVIEW_H

#include "entityView.h"

#define DOODLEAP_BG_TILEVIEW_H


class BGTileView: public EntityView {
private:
    vector<sf::RectangleShape> shapes;

    sf::RenderWindow& renderWindow;

public:
    // Constructor for the background tile view.
    BGTileView(BGTileModel& bgTileModel, sf::RenderWindow& window);

    // Updates the background tile view.
    void update() override;

    // Draws the background tiles to the screen.
    void draw() override;
};


#endif //DOODLEAP_BG_TILEVIEW_H
