#include "camera.h"

Camera::Camera(int width, int height): width(width), height(height) {

}

float Camera::getWidth() const {
    return this->width;
}

float Camera::getHeight() const {
    return this->height;
}

float Camera::getCamHeight() const {
    return this->camHeight;
}

pair<float, float> Camera::coordinatesToPixels(float coordinatesF, float coordinatesS, EntityModel& entityModel) const {
    pair<float, float> ctp(coordinatesF, (this->height -((coordinatesS + entityModel.getSizeY()) - this->camHeight)));
    return ctp;
}

float Camera::screenScroller(float heightDiff) {
    this->camHeight += heightDiff;
    return 0;
}

float Camera::getHeightDiff() const {
    return heightDiff;
}

void Camera::resetHeightDiff() {
    heightDiff = 0;
}

void Camera::setHeightDiff(float hd) {
    heightDiff = hd;
}
