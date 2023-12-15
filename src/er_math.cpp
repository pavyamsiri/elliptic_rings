#include "er_math.hpp"
#include <cmath>

static f64 P[] = {
    1.53552577301013293365E-4,
    2.50888492163602060990E-3,
    8.68786816565889628429E-3,
    1.07350949056076193403E-2,
    7.77395492516787092951E-3,
    7.58395289413514708519E-3,
    1.15688436810574127319E-2,
    2.18317996015557253103E-2,
    5.68051945617860553470E-2,
    4.43147180560990850618E-1,
    1.00000000000000000299E0
};

static f64 Q[] = {
    3.27954898576485872656E-5,
    1.00962792679356715133E-3,
    6.50609489976927491433E-3,
    1.68862163993311317300E-2,
    2.61769742454493659583E-2,
    3.34833904888224918614E-2,
    4.27180926518931511717E-2,
    5.85936634471101055642E-2,
    9.37499997197644278445E-2,
    2.49999999999888314361E-1
};

// TODO: This a naive implementation, there is a faster algorithm that reduces the number of multiplications
static f64 polyeval(f64 x, f64 const coefficients[], usize N)
{
    f64 ans = 0;
    for (usize i = 0; i <= N; i++) {
        ans += coefficients[N - i] * pow(x, i);
    }
    return ans;
}

f64 ER::ellipe(f64 m)
{
    f64 x = 1 - m;
    if (m > 1) {
        return NAN;
    } else if (m == 1.0) {
        return 1.0;
    } else if (m < 0.0) {
        return ER::ellipe(1.0 - 1.0 / x) * std::sqrt(x);
    } else {
        f64 p = polyeval(x, P, 10);
        f64 q = polyeval(x, Q, 9);
        return p - std::log(x) * x * q;
    }
}

