#include "parallel_prefix_sum.h"
#include <iostream>

int main() {
    std::vector<int> a{1,2,3,4,5,6,7};
    std::cout << prefix_sums::prefix_sum(a) << "\n";
    std::array<int, 7> b{{1,2,3,4,5,6,7}};
    std::cout << prefix_sums::prefix_sum(b) << "\n";
    return 0;
}
