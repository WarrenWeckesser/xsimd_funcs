#include <cstdint>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "xsimd_funcs/all_same.hpp"
#include "checkit.h"
namespace xsfun = xsimd_funcs;

int
main()
{
    auto test = CheckIt(std::cerr);

    std::vector<float> x{};
    for (int i = 0; i < 17; ++i) {
        bool x_all_same = xsfun::all_same(x);
        std::stringstream msg;
        msg << "x.size() = " << x.size() << "  x_all_same  = " << x_all_same;
        assert_true(test, x_all_same, msg.str());
        x.push_back(1.5f);
    }
    for (std::size_t i = 0; i < x.size(); ++i) {
        float v = x[i];
        x[i] = 3.0;
        bool x_all_same = xsfun::all_same(x);
        std::stringstream msg;
        msg << "x.size() = " << x.size() << "  x_all_same  = " << x_all_same;
        assert_false(test, x_all_same, msg.str());
        x[i] = v;
    }

    std::vector<double> y{0.5};
    for (int i = 0; i < 17; ++i) {
        y.push_back(1.5);
        bool y_all_same = xsfun::all_same(y);
        std::stringstream msg;
        msg << "y.size() = " << y.size() << "  y_all_same  = " << y_all_same;
        assert_false(test, y_all_same, msg.str());
        y.pop_back();
        y.push_back(0.5);
    }

    std::vector<int32_t> z{};
    for (int i = 0; i < 17; ++i) {
        bool z_all_same = xsfun::all_same(z);
        std::stringstream msg;
        msg << "z.size() = " << z.size() << "  z_all_same  = " << z_all_same;
        assert_true(test, z_all_same, msg.str());
        z.push_back(10);
    }

    return test.print_summary("test_all_same summary: ");
}
