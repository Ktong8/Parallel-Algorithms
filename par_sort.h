#pragma once
#include <vector>
#include <thread>

namespace par_sort {
    void merge(int* a, int na, int* b, int nb, int* c) {
        while (na > 0 && nb > 0) {
            if (*a <= *b) {
                *(c++) = *(a++);
                na--;
            } else {
                *(c++) = *(b++);
                nb--;
            }
        }
        while (na > 0) {
            *(c++) = *(a++);
            na--;
        }
        while (nb > 0) {
            *(c++) = *(b++);
            nb--;
        }
    }

    template <size_t N>
    void par_merge_sort(int a[N], int b[N]) {
        assert(N > 0);
        if (N == 1) {
            b[0] = a[0];
            return;
        }
        int c[N];
        std::thread first (std::ref(par_merge_sort<N/2>), std::ref(a), std::ref(c));
        par_merge_sort<N-N/2>(a+N/2, c+N/2);
        first.join();
        merge(c, N/2, c + N/2, N - N/2, b);
    }

    template <size_t N>
    void merge_sort(int a[N], int b[N]) {
        assert(N > 0);
        if (N == 1) {
            b[0] = a[0];
            return;
        }
        int c[N];
        merge_sort<N/2>(a, c);
        merge_sort<N-N/2>(a+N/2, c+N/2);
        merge(c, N/2, c+N/2, N-N/2, b);
    }
}
