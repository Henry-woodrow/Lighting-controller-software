#include "light_engine.h"
#include <chrono>
#include <thread>
#include <iostream>

int main() {
    Engine engine;

    using clock = std::chrono::steady_clock;
    const auto tick_duration = std::chrono::milliseconds(25); // 40 Hz

    while (true) {
        auto start = clock::now();

        engine.tick();

        static int counter = 0;
        if (++counter % 10 == 0) {
            std::cout << "Ch1 = " << (int)engine.universe().get(1) << "\n";
        }

        auto elapsed = clock::now() - start;
        if (elapsed < tick_duration) {
            std::this_thread::sleep_for(tick_duration - elapsed);
        }
    }
}
