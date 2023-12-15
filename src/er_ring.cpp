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

ER::Ring::Ring(f64 radius, f64 scale_width, f64 scale_height, f64 angle, f64 mass)
    : m_radius(radius)
    , m_scale_width(scale_width)
    , m_scale_height(scale_height)
    , m_angle(angle)
    , m_mass(mass)
{
    // a
    m_semi_major = std::max(scale_width, scale_height);
    // b
    m_semi_minor = std::min(scale_width, scale_height);

    // e
    m_ecc = std::sqrt(
        1 - m_semi_minor * m_semi_minor / (m_semi_major * m_semi_major));

    // perimeter
    m_perimeter = 4 * m_semi_major * ER::ellipe(m_ecc * m_ecc);
}
