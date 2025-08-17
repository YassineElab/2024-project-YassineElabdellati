#ifndef DOODLEAP_BONUSMODEL_H

#include "entityModel.h"
#include "bonusEffect.h"
#include <memory>
#include <string>

#define DOODLEAP_BONUSMODEL_H


using namespace std;

class BonusModel : public EntityModel {
private:
    unique_ptr<BonusEffect> effect;
    bool needDelete = false;
    string bonusType;
    
public:
    // Constructor for the BonusModel.
    BonusModel(World& world, const string& type);
    
    // Updates the state of the bonus model.
    void update() override;
    
    // Sets the position of the bonus model.
    void setPosition(float x, float y);
    
    // Checks if the bonus model should be deleted.
    bool getDelete() const;

    // Applies the bonus effect to the player.
    void applyBonusEffect(DoodleModel& doodle, Score& score);

    // Returns the type of the bonus.
    const string& getBonusType() const;

    // Checks if the bonus has a timed effect.
    bool isTimedEffect() const;

    // Updates the bonus effect over time.
    void updateEffect(float deltaTime);

    // Checks if the bonus effect is currently active.
    bool isEffectActive() const;
};

#endif //DOODLEAP_BONUSMODEL_H
