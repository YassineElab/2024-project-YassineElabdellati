#ifndef DOODLEAP_CAMERA_H
#include <utility>
#include "entityModel.h"
#define DOODLEAP_CAMERA_H

using namespace std;

class Camera{
private:
    float width = 0;
    float height = 0;
    float camHeight = 0;

    float heightDiff = 0;

    bool isAutomatic;
public:
    // Constructor for the Camera.
    Camera(int width, int height);
    
    // Returns the width of the camera view.
    float getWidth() const;
    
    // Returns the height of the camera view.
    float getHeight() const;
    
    //Returns the current camera height
    float getCamHeight() const;
    
    // Converts world coordinates to pixel coordinates.
    pair<float, float> coordinatesToPixels(float coordinatesF, float coordinatesS, EntityModel& entityModel) const;
    
    //By adding height to the camera, the screen that the player sees will go up
    float screenScroller(float heightDiff);

    // Returns the height difference for scrolling.
    float getHeightDiff() const;

    // Sets the height difference for scrolling.
    void setHeightDiff(float hd);

    // Resets the height difference for scrolling.
    void resetHeightDiff();
};

#endif //DOODLEAP_CAMERA_H