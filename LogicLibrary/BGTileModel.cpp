#include "BGTileModel.h"
#include "world.h"

BGTileModel::BGTileModel(World &world) : EntityModel(world) {
    for(int i = 0; i < this->getWorld().getCamera().getHeight(); i+=25){
        this->lines.push_back(i);
    }
}

void BGTileModel::update() {
    if(lines.front() < this->getWorld().getCamera().getCamHeight()){
        lines.pop_front();
    }

    if(lines.back() < this->getWorld().getCamera().getCamHeight() + 800){
        lines.push_back(lines.back() + 25);
    }

    notifyObservers();
}

deque<int> BGTileModel::getLines(){
    return lines;
}

void BGTileModel::resetLines() {
    lines.clear();
}
