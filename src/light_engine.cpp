#include "light_engine.h"

void Engine::tick() {
    float intensity = 0.5f;
    


    value_ += direction_ * 5;
    if (value_ >= 255) { value_ = 255; direction_ = -1; }
    if (value_ <= 0)   { value_ = 0;   direction_ = 1;  }

    universe_.set(1, static_cast<uint8_t>(value_));
}

const DmxUniverse& Engine::universe() const {
    return universe_;
}
