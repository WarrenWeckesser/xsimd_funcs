//#include <cstdio>
#include <iostream>
#include <vector>
#include "checkit.h"
#include "xsimd_funcs/minmax.hpp"

namespace xsfun = xsimd_funcs;

int main()
{
    auto test = CheckIt(std::cerr);

    std::vector<short> v;

    constexpr std::size_t n = 23457;
    for (std::size_t i = 0; i < n; ++i) {
        v.push_back(static_cast<short>(i % 113));
    }
    for (size_t k = 0; k < v.size(); ++k) {
        short tmp = v[k];
        v[k] = -99;
        xsfun::value_index_pair<short> result = xsfun::min_argmin(v);
        assert_equal_integer(test, result.index, k, "incorrect argmin");
        v[k] = tmp;
    }
    return test.print_summary("Summary: ");
}
