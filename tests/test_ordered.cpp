#include <algorithm>
#include <cstdint>
#include <vector>
#include "xsimd_funcs/ordered.hpp"
#include "checkit.h"

namespace xsfun = xsimd_funcs;

template <typename T>
void check_increasing(CheckIt& test)
{
    for (int n = 128; n < 256; ++n) {
        std::vector<T> x;
        for (int i = 0; i < n; ++i) {
            x.push_back(static_cast<T>(i % 7));
        }
        auto result1 = xsfun::is_increasing(x);
        assert_false(test, result1, "x is not increasing");

        std::sort(x.begin(), x.end());
        auto result2 = xsfun::is_increasing(x);
        assert_true(test, result2, "x is increasing");
    }
}

int
main()
{
    auto test = CheckIt(std::cerr);

    check_increasing<float>(test);
    check_increasing<double>(test);
    check_increasing<unsigned char>(test);
    check_increasing<int16_t>(test);
    check_increasing<uint32_t>(test);
    check_increasing<long>(test);
    check_increasing<uint64_t>(test);

    return test.print_summary("test_ordered summary: ");
}
