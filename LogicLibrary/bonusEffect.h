#ifndef DOODLEAP_BONUSEFFECT_H

#include <memory>
#include <string>

#define DOODLEAP_BONUSEFFECT_H

using namespace std;

class DoodleModel;
class Score;

class BonusEffect {
public:
    // Destructor for the bonus effect.
    virtual ~BonusEffect() = default;

    // Applies the bonus effect to the player.
    virtual void applyEffect(DoodleModel& doodle, Score& score) = 0;

    // Gets the duration of the bonus effect.
    virtual float getDuration() const = 0;

    // Updates the bonus effect over time.
    virtual void update(float deltaTime) {}

    // Checks if the bonus effect is currently active.
    virtual bool isActive() const { return getDuration() == 0; }

    // Gets the name of the bonus effect.
    virtual string getName() const = 0;
};

class SpringEffect : public BonusEffect {
private:
    float springBoost = 70.0f;
    int springScore = 500;
    
public:
    // Applies the spring effect to the player.
    void applyEffect(DoodleModel& doodle, Score& score) override;
    // Gets the duration of the spring effect.
    float getDuration() const override { return 0; }
    // Gets the name of the spring effect.
    string getName() const override { return "Spring"; }
};

class JetpackEffect : public BonusEffect {
private:
    static constexpr float jetpackBoost = 140.0f;
    static constexpr int jetpackScore = 500;
    
public:
    // Applies the jetpack effect to the player.
    void applyEffect(DoodleModel& doodle, Score& score) override;
    // Gets the duration of the jetpack effect.
    float getDuration() const override { return 0; }
    // Gets the name of the jetpack effect.
    string getName() const override { return "Jetpack"; }
};

#endif //DOODLEAP_BONUSEFFECT_H
