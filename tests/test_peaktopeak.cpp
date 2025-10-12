#include <algorithm>
#include <random>
#include <cstdint>
#include <iostream>
#include <vector>
#include "xsimd_funcs/peaktopeak.hpp"
#include "checkit.h"
namespace xsfun = xsimd_funcs;

int
main()
{
    auto test = CheckIt(std::cerr);
    
    std::random_device rd;
    std::mt19937 g(rd());

    std::vector<float> x{1.0, -3.5, 10.0, -2.0, 0.25, 1.75, -6.0, 3.25, 0.0, 0.0, 0.0};
    for (size_t k = 0; k < 10; ++k) { 
        std::shuffle(x.begin(), x.end(), g);
        auto xptp = xsfun::peaktopeak(x);
        assert_equal_fp(test, xptp, 16.0f, "incorrect float peak-to-peak value");
    }

    std::vector<int16_t> y{10, -300, 200, 32000, 0, -175, -2000, 3, 10, 10, 10, -1,
                           -3000, 0, 0, 0, 0, 0};
    for (size_t k = 0; k < 10; ++k) { 
        std::shuffle(y.begin(), y.end(), g);
        auto yptp = xsfun::peaktopeak(y);
        assert_equal_fp(test, yptp, static_cast<uint16_t>(35000), "incorrect peak-to-peak value");
    }

    return test.print_summary("test_peaktopeak summary: ");
}
