#include "dmx.h"

void DmxUniverse::set(uint16_t channel, uint8_t value) {
    if (channel >= 1 && channel <= 512) {
        channels_[channel - 1] = value;
    }
}

uint8_t DmxUniverse::get(uint16_t channel) const {
    if (channel >= 1 && channel <= 512) {
        return channels_[channel - 1];
    }
    return 0; // or handle error as appropriate
}

const std::array<uint8_t, 512>& DmxUniverse::data() const {
    return channels_;
}