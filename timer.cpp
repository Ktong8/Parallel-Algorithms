#include "timer.h"

benchmark::Timer::Timer(std::string_view name)
    : start(std::chrono::steady_clock::now())
    , name(name) {
}

benchmark::Timer::~Timer() {
    end = std::chrono::steady_clock::now();
    std::chrono::duration<float> duration = end - start;
    std::cout << name << " completed in " << duration.count() << " seconds\n";
}
