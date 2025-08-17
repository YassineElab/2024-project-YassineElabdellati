#ifndef DOODLEAP_OBSERVER_H

#include "doodleModel.h"
#include "BGTileModel.h"

#define DOODLEAP_OBSERVER_H


class Observer{
protected:
    EntityModel& entityModel;

public:
    // Constructor for the Observer.
    Observer(EntityModel& entityModel);

    virtual void update() = 0;

};

#endif //DOODLEAP_OBSERVER_H
