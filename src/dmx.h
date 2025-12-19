#pragma once
#include <array>
#include <cstdint>

class DmxUniverse {
public:
    void set(uint16_t channel, uint8_t value);
    uint8_t get(uint16_t channel) const;
    const std::array<uint8_t, 512>& data() const;


private:
    std::array<uint8_t, 512> channels_{}; // initialized to 0
};