#include "er_array.hpp"
#include "er_math.hpp"
#include "er_ring.hpp"
#include <iostream>

int main(int argc, char* argv[])
{
    (void)argc;
    (void)argv;
    ER::Array arr1(10);
    ER::Array arr2(10);
    for (usize i = 0; i < arr1.size(); i++) {
        arr1[i] = i;
        arr2[i] = i + 1;
    }
    ER::Array add_arr = arr1 + arr2;
    ER::Array sub_arr = arr1 - arr2;
    ER::Array mul_arr = arr1 * arr2;
    ER::Array div_arr = arr1 / arr2;
    ER::Array zero_div = arr2 / arr1;
    std::cout << "Array 1: " << arr1 << std::endl;
    std::cout << "Array 2: " << arr2 << std::endl;
    std::cout << "Add: " << add_arr << std::endl;
    std::cout << "Sub: " << sub_arr << std::endl;
    std::cout << "Mul: " << mul_arr << std::endl;
    std::cout << "Div: " << div_arr << std::endl;
    std::cout << "Zero Div: " << zero_div << std::endl;

    // Test special functions
    f64 m = 0.5;
    f64 result = ER::ellipe(m);
    std::cout << "Elliptic integral of the second kind with m = " << m << ": " << result << std::endl;

    // Test rings
    ER::Ring ring(1, 1, 2, 0, 1);
    std::cout << ring << std::endl;

    return 0;
}

