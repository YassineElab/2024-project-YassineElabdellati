#ifndef DOODLEAP_BONUSVIEW_H
#define DOODLEAP_BONUSVIEW_H

#include "entityView.h"
#include "../LogicLibrary/bonusModel.h"
#include <SFML/Graphics.hpp>

class BonusView : public EntityView {
private:
    sf::RenderWindow& renderWindow;
    sf::RectangleShape bonus;
    
public:
    // Constructor for the bonus view.
    BonusView(BonusModel& bonusModel, sf::RenderWindow& window);
    
    // Updates the bonus view.
    void update() override;
    
    // Draws the bonus to the screen.
    void draw() override;
};

#endif //DOODLEAP_BONUSVIEW_H
