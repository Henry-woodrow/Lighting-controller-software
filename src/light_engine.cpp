#include "light_engine.h"
#include <algorithm>
#include <chrono>
#include <cstdio>
#include <iostream>

void LightEngine::tick() {
    // takes the current intensity_ value (0.0 to 1.0) and maps it to DMX value (0-255)
    uint8_t dmx_value = static_cast<uint8_t>(intensity_ * 255.0f);

    universe_.set(1, dmx_value);
    ++tickCount;
}

//intensity getter setters
void LightEngine::setIntensity(float intensity) {
    float clamped_intensity = std::clamp(intensity, 0.0f, 1.0f);
    intensity_ = clamped_intensity;
}

float LightEngine::getIntesity() const {
    return intensity_;
}

const DmxUniverse& LightEngine::universe() const {
    return universe_;
}

uint64_t LightEngine::getTickCount() const
{
    return tickCount;
}

uint8_t LightEngine::getChannel(int channel) const
{
    return universe_.get(channel);
}






