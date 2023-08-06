#include "par_sum_test.h"

void TestVectorSum() {
    std::vector<int> arr{1,2,3,4,5,6};
    assert (prefix_sums::prefix_sum(arr) == 21);
}

void TestArraySum() {
    std::array<int, 6> arr{{1,2,3,4,5,6}};
    assert (prefix_sums::prefix_sum(arr) == 21);
}

void TestVectorArrSum() {
    std::vector<int> arr{1,2,3,4,5,6};
    assert (prefix_sums::prefix_sum_arr(arr) == 21);
}
