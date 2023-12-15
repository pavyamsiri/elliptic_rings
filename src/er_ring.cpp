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

    // e^2
    f64 ecc_squared = m_ecc * m_ecc;
    f64 second_ecc_squared = ecc_squared / (1 - ecc_squared);
    f64 ellipk_ecc2 = ER::ellipk(ecc_squared);
    f64 ellipe_ecc2 = ER::ellipe(ecc_squared);
    f64 ellipk_msecc2 = ER::ellipk(-second_ecc_squared);
    f64 ellipe_msecc2 = ER::ellipe(-second_ecc_squared);

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
