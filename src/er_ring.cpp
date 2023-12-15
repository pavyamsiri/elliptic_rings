#include "er_ring.hpp"
#include "er_math.hpp"
#include <cmath>

f64 calculate_ellipse_perimeter(f64 radius, f64 scale_width, f64 scale_height)
{
    (void)radius;
    f64 a = std::max(scale_width, scale_height);
    f64 b = std::min(scale_width, scale_height);
    f64 eccenctricity_squared = 1 - b * b / (a * a);
    f64 perimeter = 4 * a * ER::ellipe(eccenctricity_squared);
    return perimeter;
}

ER::Ring::Ring(f64 radius, f64 eccentricity, f64 mass)
    : m_radius(radius)
    , m_ecc(eccentricity)
    , m_mass(mass)
{
    // a
    m_semi_major = 1.0f / std::sqrt(1 - m_ecc * m_ecc);
    // b
    m_semi_minor = 1.0f;

    m_scale_width = m_semi_minor;
    m_scale_height = m_semi_major;

    // TODO: Should stop using cephes related functions as they need proper licensing
    //      Migrate to calculating them by hand using the Carlson formulation as the STL
    //      functions don't allow for imaginary k.
    // e^2
    f64 ecc_squared = m_ecc * m_ecc;
    f64 second_ecc_squared = ecc_squared / (1 - ecc_squared);
    f64 k_formulation = std::sqrt((1 - second_ecc_squared) * (1 - second_ecc_squared));
    std::cout << "e' = " << second_ecc_squared << std::endl;
    std::cout << "k = " << k_formulation << std::endl;
    f64 ellipk_ecc2 = ER::ellipk(ecc_squared);
    f64 ellipk_ecc2_standard = std::comp_ellint_1(m_ecc);
    std::cout << "e - ellipk - Cephes = " << ellipk_ecc2 << std::endl;
    std::cout << "e - ellipk - STL = " << ellipk_ecc2_standard << std::endl;
    f64 ellipe_ecc2 = ER::ellipe(ecc_squared);
    f64 ellipe_ecc2_standard = std::comp_ellint_2(m_ecc);
    std::cout << "e - ellipe - Cephes = " << ellipe_ecc2 << std::endl;
    std::cout << "e - ellipe - STL = " << ellipe_ecc2_standard << std::endl;
    f64 ellipk_msecc2 = ER::ellipk(-second_ecc_squared);
    f64 ellipk_msecc2_standard = std::comp_ellint_1(second_ecc_squared);
    std::cout << "e' - ellipk - Cephes = " << ellipk_msecc2 << std::endl;
    std::cout << "e' - ellipk - STL = " << ellipk_msecc2_standard << std::endl;
    f64 ellipe_msecc2 = ER::ellipe(-second_ecc_squared);
    f64 ellipe_msecc2_standard = std::comp_ellint_2(second_ecc_squared);
    std::cout << "e' - ellipe - Cephes = " << ellipe_msecc2 << std::endl;
    std::cout << "e' - ellipe - STL = " << ellipe_msecc2_standard << std::endl;

    f64 radius_squared = m_radius * m_radius;

    // perimeter
    m_perimeter = 4 * m_semi_major * m_radius * ellipe_ecc2;

    // Moments of inertia
    f64 moment_of_inertia_z = m_mass * m_semi_major * m_semi_major * radius_squared * ellipe_ecc2 / ellipk_ecc2;
    f64 moment_of_inertia_minor = m_mass * (ellipe_msecc2 - ellipk_msecc2) / ellipk_ecc2 * m_semi_minor * m_semi_major * radius_squared / ecc_squared;
    f64 moment_of_inertia_major = moment_of_inertia_z - moment_of_inertia_minor;
    m_moi_z = moment_of_inertia_z;
    m_moi_major = moment_of_inertia_major;
    m_moi_minor = moment_of_inertia_minor;
}

ER::Ring::~Ring()
{
}
