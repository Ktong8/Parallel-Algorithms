#include "parallel_prefix_sum.h"
#include "timer.h"
#include <iostream>

constexpr int VECTOR_LEN = 100000;
constexpr int ARRAY_LEN = 1000;

long long prefix_sum_loop(std::vector<int>& arr) {
    long long sum = 0ll;
    for (int i = 0; i < arr.size(); ++i) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    using benchmark::Timer;
    std::vector<int> a(VECTOR_LEN);
    std::array<int, ARRAY_LEN> b{{}};
    for (int i = 0; i < VECTOR_LEN; ++i) {
        a[i] = i;
    }
    for (int i = 0; i < ARRAY_LEN; ++i) {
        b[i] = i;
    }
    {
        std::string message = "Vector with " + std::to_string(VECTOR_LEN) + " integers";
        Timer timer = Timer(message);
        prefix_sums::prefix_sum(a);
    }
    {
        std::string message = "Array with " + std::to_string(ARRAY_LEN) + " integers";
        Timer timer = Timer(message);
        prefix_sums::prefix_sum(b);
    }
    {
        std::string message = "Vector with " + std::to_string(VECTOR_LEN) + " integers regular";
        Timer timer = Timer(message);
        prefix_sums::prefix_sum(a);
    }
    return 0;
}
