#pragma once
#include "dmx.h"
#include <cstdint>

class Engine {
public:

    void setIntensity(float intensity); // this is what dmx or midi will use when setting intensity of each channel
    void tick();
    const DmxUniverse& universe() const;

private:
    DmxUniverse universe_;

    //testing tick variables can remove later
    int value_ = 0;
    int direction_ = 1;

    // end testing variables

    float intensity_ = 0.0f; // current intensity level (0.0 to 1.0)


};
