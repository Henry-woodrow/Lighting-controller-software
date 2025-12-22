#include "light_engine.h"
#include <chrono>
#include <thread>
#include <iostream>

int main() {
    LightEngine engine;

    float fader = 0.0f;
    float direction = 1.0f;

    using clock = std::chrono::steady_clock;
    const auto tick_duration = std::chrono::milliseconds(25); // 40 Hz

    while (true) {
        auto start = clock::now();

        // Update fader value
        // Increment or decrement fader based on direction
        fader += direction * 0.1f;
        
        // Update intensity based on fader
        if (fader >= 1.0f) {
            fader = 1.0f;
            direction = -1.0f;
        } else if (fader <= 0.0f) {
            fader = 0.0f;
            direction = 1.0f;
        }

        engine.setIntensity(fader);
        engine.tick();
        

        // Output current tick count and channel 1 value
        std::cout
            << "Tick " << engine.getTickCount()
            << " | Ch1: "
            << static_cast<int>(engine.getChannel(1))
            << std::endl;



        auto elapsed = clock::now() - start;
        if (elapsed < tick_duration) {
            std::this_thread::sleep_for(tick_duration - elapsed);
        }
    }
}
