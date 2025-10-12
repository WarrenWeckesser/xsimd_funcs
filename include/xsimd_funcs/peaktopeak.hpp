#include <vector>
#include <type_traits>

#include "xsimd_funcs/minmax.hpp"

namespace xsimd_funcs {

long double peaktopeak(const std::vector<long double>& x)
{
    xsimd_funcs::minmax_pair<long double> mm = xsimd_funcs::minmax_scalar_loop(x);
    return mm.max - mm.min;
}

template<typename T>
using IsSignedIntegerType = std::enable_if_t<(std::is_signed<T>::value &&
                                              std::is_integral<T>::value)>;

template<typename T>
using IsNotSignedIntegerType = std::enable_if_t<(!(std::is_signed<T>::value &&
                                                   std::is_integral<T>::value))>;


template<typename T, typename = IsNotSignedIntegerType<T>>
T peaktopeak(const std::vector<T>& x)
{
    xsimd_funcs::minmax_pair<T> mm = xsimd_funcs::minmax(x);
    return mm.max - mm.min;
}


template<typename Int, typename = IsSignedIntegerType<Int>>
std::make_unsigned_t<Int>
peaktopeak(const std::vector<Int>& x)
{
    using Unsigned = std::make_unsigned_t<Int>;

    xsimd_funcs::minmax_pair<Int> mm = xsimd_funcs::minmax(x);
    if (mm.min < 0 && mm.max > 0) {
        return static_cast<Unsigned>(mm.max) + static_cast<Unsigned>(-mm.min);
    }
    else {
        return static_cast<Unsigned>(mm.max - mm.min);
    }
}

} // namespace xsimd_funcs
