#include <algorithm>
#include <cstdint>
#include <iostream>
#include <random>
#include <vector>
#include "xsimd_funcs/minmax.hpp"
#include "checkit.h"

namespace xsfun = xsimd_funcs;

int
main()
{
    auto test = CheckIt(std::cerr);

    std::random_device rd;
    std::mt19937 g(rd());

    for (size_t p = 1; p < 8; ++p) {
        size_t n = 1 << p;
        for (size_t k = 0; k < n; ++k) {
            size_t size = 3*n + k;
            std::vector<float> x;
            for (size_t j = 0; j < size; ++j) {
                x.push_back(static_cast<float>(j));
            }
            for (int i = 0; i < 16; ++i) {
                std::shuffle(x.begin(), x.end(), g);
                auto result = xsfun::minmax(x);
                assert_equal_fp(test, result.min, 0.0f,
                                "min value not correct");
                assert_equal_fp(test, result.max, static_cast<float>(size - 1),
                                "max value not correct");
            }
        }
    }

    return test.print_summary("test_minmax summary: ");
}
