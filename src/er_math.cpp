#include "er_math.hpp"
#include <cmath>
#include <limits>

f64 ER::ellipk(f64 m)
{
    f64 answer = M_PI_2 / ER::agm(1, std::sqrt(1 - m));
    return answer;
}

f64 ER::ellipe(f64 m)
{
    f64 a = 1.0f - m;
    f64 b = 1.0f;
    f64 arithmetic_mean = 0.5f * a + 0.5f * b;
    f64 geometric_mean = std::sqrt(a * b);
    f64 power_sum = 0.0f;
    f64 power_coefficient = 0.25f;
    while (std::abs(arithmetic_mean - geometric_mean) >= 2.7f * std::numeric_limits<f64>::epsilon() * std::abs(arithmetic_mean)) {
        f64 new_arithmetic_mean = 0.5f * arithmetic_mean + 0.5f * geometric_mean;
        f64 new_geometric_mean = std::sqrt(arithmetic_mean * geometric_mean);
        arithmetic_mean = new_arithmetic_mean;
        geometric_mean = new_geometric_mean;
        f64 mean_difference = arithmetic_mean - geometric_mean;
        power_coefficient *= 2.0f;
        power_sum += power_coefficient * mean_difference * mean_difference;
    }
    f64 rf = ellipk(m);
    f64 answer = 0.5f * (1 + std::sqrt(a) - 0.5f * m - power_sum) * rf;
    return answer;
}

f64 ER::agm(f64 a, f64 b)
{
    f64 arithmetic_mean = 0.5f * a + 0.5f * b;
    f64 geometric_mean = std::sqrt(a * b);
    while (std::abs(arithmetic_mean - geometric_mean) >= std::numeric_limits<f64>::epsilon()) {
        f64 new_arithmetic_mean = 0.5f * arithmetic_mean + 0.5f * geometric_mean;
        f64 new_geometric_mean = std::sqrt(arithmetic_mean * geometric_mean);
        arithmetic_mean = new_arithmetic_mean;
        geometric_mean = new_geometric_mean;
    }
    return arithmetic_mean;
}
