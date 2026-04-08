#include <iostream>
#include <cstdint>
#include <vector>
#include <chrono>
#include <cmath>
#include <string>

#include "xsimd_funcs/minmax.hpp"
namespace xsfun = xsimd_funcs;
using namespace std;

using Clock = std::chrono::steady_clock;
using Second = std::chrono::duration<double, std::ratio<1> >;


template<typename T>
double speedup_array(size_t n)
{
    double t1, t2;

    std::vector<T> x;
    x.resize(n);
    for (size_t i = 0; i < n; ++i) {
        x[i] = 60 + 50*sin(700.1*i/n);
    }
    x[3*n/4] = 1;

    auto tstart1 = Clock::now();
    auto result1 = xsfun::minmax(x);
    t1 = 1000*chrono::duration_cast<Second>(Clock::now() - tstart1).count();

    auto tstart2 = Clock::now();
    auto result2 = xsfun::minmax_scalar_loop(x);
    t2 = 1000*chrono::duration_cast<Second>(Clock::now() - tstart2).count();

    if (result1.min != result2.min) {
        cerr << "result1.min != result2.min: " << result1.min << " " << result2.min << "\n";
    }

    if (result1.max != result2.max) {
        cerr << "result1.max != result2.max: " << result1.max << " " << result2.max << "\n";
    }

    return t2/t1;
}

template<typename T>
void check(const char *name, size_t n, int nrepeats)
{
    double s = 0.0;
    for (int k = 0; k < nrepeats; ++k) {
        s += speedup_array<T>(n);
    }
    cout << name << " (size = " << sizeof(T) << "): " << s/nrepeats << "\n";
}

int main()
{
    size_t n = 50000;
    int nrepeats = 20;

    cout << "\nminmax_timing\n";

    check<float>          ("float          ", n, nrepeats);
    check<double>         ("double         ", n, nrepeats);
    check<short>          ("short          ", n, nrepeats);
    check<unsigned short> ("unsigned short ", n, nrepeats);
    check<int>            ("int            ", n, nrepeats);
    check<long int>       ("long int       ", n, nrepeats);
}
