#include <chrono>
#include <iostream>
#include <string>

namespace benchmark {
    class Timer {
    public:
        using Clock = std::chrono::high_resolution_clock;
        using Duration = std::chrono::duration<float>;
        using Time = std::chrono::time_point<std::chrono::steady_clock>;
        Timer(std::string_view name);
        ~Timer();
    private:
        Time start;
        Time end;
        std::string_view name;
    };
}
