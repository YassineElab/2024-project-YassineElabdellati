#ifndef DOODLEAP_PLATFORMMODEL_H

#include "entityModel.h"

#define DOODLEAP_PLATFORMMODEL_H


class PlatformModel: public EntityModel {
private:
    bool needDelete = false;
    bool tempPlatform = false;
    bool startLeft = false;

    bool moveRight = false;
    bool moveLeft = false;
    bool moveUp = false;
    bool moveDown = false;

    pair<float, float> startingPoint;
    pair<float, float> dynamicPlace;

public:
    // Constructor for the PlatformModel.
    PlatformModel(World &world, float x, float y, float z, float q);

    // Updates the state of the platform.
    void update() override;

    // Marks the platform for deletion.
    void setDelete();

    // Checks if the platform is marked for deletion.
    bool getDelete() const;

    // Handles the horizontal movement of a dynamic platform.
    void dynamicPlatformLeftRight();

    // Handles the vertical movement of a dynamic platform.
    void dynamicPlatformUpDown();

    // Sets the platform as temporary.
    void setTempPlatform();

    // Checks if the platform is temporary.
    bool getTempPlatform();

    // Sets the number of the platform.
    void setNumber(int number);
};


#endif //DOODLEAP_PLATFORMMODEL_H
