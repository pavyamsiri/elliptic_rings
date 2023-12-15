#include "er_array.hpp"
#include "er_math.hpp"
#include "er_ring.hpp"
#include <iostream>

int main(int argc, char* argv[])
{
    (void)argc;
    (void)argv;
    ER::Array1D arr1(10);
    ER::Array1D arr2(10);
    for (usize i = 0; i < arr1.size(); i++) {
        arr1[i] = i;
        arr2[i] = i + 1;
    }
    ER::Array1D add_arr = arr1 + arr2;
    ER::Array1D sub_arr = arr1 - arr2;
    ER::Array1D mul_arr = arr1 * arr2;
    ER::Array1D div_arr = arr1 / arr2;
    ER::Array1D zero_div = arr2 / arr1;
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
    ER::Ring ring(1, 0.3, 1);
    std::cout << ring << std::endl;

    // Test 3D arrays
    ER::Array3D arr3(3);
    ER::Array3D arr4(3);
    for (usize i = 0; i < arr3.size(); ++i) {
        arr3.set_x(i, -(f64)i + 2.0f);
        arr3.set_y(i, 3.0f * (f64)i + 2.0f);
        arr3.set_z(i, 0.5f * (f64)i - 3.0f);
        arr4.set_x(i, (f64)i - 7.0f);
        arr4.set_y(i, -5.0f * (f64)i + 0.2f);
        arr4.set_z(i, 4.0f * (f64)i);
    }

    ER::Array3D add_arr3 = arr3 + arr4;
    ER::Array3D sub_arr3 = arr3 - arr4;
    ER::Array3D mul_arr3 = arr3 * arr4;
    ER::Array3D div_arr3 = arr3 / arr4;
    ER::Array3D zero_div3 = arr3 / arr4;
    std::cout << "Array 3: " << arr3 << std::endl;
    std::cout << "Array 4: " << arr4 << std::endl;
    std::cout << "Add: " << add_arr3 << std::endl;
    std::cout << "Sub: " << sub_arr3 << std::endl;
    std::cout << "Mul: " << mul_arr3 << std::endl;
    std::cout << "Div: " << div_arr3 << std::endl;
    std::cout << "Zero Div: " << zero_div3 << std::endl;

    return 0;
}
