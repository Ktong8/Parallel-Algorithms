#include <array>
#include <vector>
#include <ranges>
#include <algorithm>
#include <execution>

namespace prefix_sums {
    template <typename T, size_t N>
    T prefix_sum(std::array<T, N>& arr) {
        if (N == 1) {
            return arr[0];
        }
        if (N == 2) {
            return arr[0] + arr[1];
        }
        std::array<T, (N+1)/2> next;
        std::ranges::iota_view indices((size_t) 0, (N+1)/2);
        std::for_each(
            std::execution::par,
            indices.begin(),
            indices.end(),
            [&next, &arr] (size_t i) {
                next[i] = arr[2*i];
                if (2*i + 1 < N) [[likely]] {
                    next[i] += arr[2*i+1];
                }
            }
        );
        return prefix_sum(next);
    }

    template <typename T>
    T prefix_sum(std::vector<T>& arr) {
        if (arr.size() == 1) {
            return arr[0];
        }
        if (arr.size() == 2) {
            return arr[0] + arr[1];
        }
        std::vector<T> next((arr.size() + 1) / 2);
        std::ranges::iota_view indices((size_t) 0, (arr.size() + 1) / 2);
        std::for_each(
            std::execution::par,
            indices.begin(),
            indices.end(),
            [&next, &arr] (size_t i) {
                next[i] = arr[2*i];
                if (2*i + 1 < arr.size()) [[likely]] {
                    next[i] += arr[2*i + 1];
                }
            }
        );
        return prefix_sum(next);
    }
}
