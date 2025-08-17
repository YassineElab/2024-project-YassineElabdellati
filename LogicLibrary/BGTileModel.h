#ifndef DOODLEAP_BGTILEMODEL_H

#include <deque>
#include "entityModel.h"
#include "vector"

#define DOODLEAP_BGTILEMODEL_H


class BGTileModel: public EntityModel {
private:
    deque<int> lines;

public:
    // Constructor for the BGTileModel.
    explicit BGTileModel(World &world);

    // Updates the background tile.
    void update() override;

    // Returns the lines from the background tile.
    deque<int> getLines() override;

    // Resets the lines of the background tile.
    void resetLines() override;

};


#endif //DOODLEAP_BGTILEMODEL_H
