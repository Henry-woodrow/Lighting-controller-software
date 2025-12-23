#pragma once
#include "dmx.h"
#include <cstdint>

class LightEngine {
public:

    void setIntensity(float intensity); // this is what dmx or midi will use when setting intensity of each channel
    
    void tick();

    const DmxUniverse& universe() const;

    uint64_t getTickCount() const;
    uint8_t  getChannel(int channel) const;
    
    float getIntensity() const; // helper function to get intensity value for a channel


private:
    DmxUniverse universe_;


    //testing tick variables can remove later
    int value_ = 0;
    int direction_ = 1;

    // end testing variables
    float intensity_ ;

    uint64_t tickCount = 0;
    uint8_t dmx[512]{};
    


};
