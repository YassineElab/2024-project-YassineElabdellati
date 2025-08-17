#ifndef DOODLEAP_PLATFORMVIEW_H

#include "entityView.h"

#define DOODLEAP_PLATFORMVIEW_H


class PlatformView: public EntityView {
private:
    sf::RenderWindow& renderWindow;

    sf::RectangleShape platform;
public:
    // Constructor for the PlatformView.
    PlatformView(PlatformModel& platformModel , sf::RenderWindow &window);

    // Updates the platformview.
    void update() override;

    // Draws the platformview.
    void draw() override;
};


#endif //DOODLEAP_PLATFORMVIEW_H
