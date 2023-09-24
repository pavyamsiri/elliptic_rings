#include <cmath>
#include "er_math.hpp"
#include "er_ring.hpp"

float64_t calculate_ellipse_perimeter(float64_t radius, float64_t scale_width, float64_t scale_height)
{
    float64_t a = std::max(scale_width, scale_height);
    float64_t b = std::min(scale_width, scale_height);
    float64_t eccenctricity_squared = 1 - b * b / (a * a);
    float64_t perimeter = 4 * a * ER::ellipe(eccenctricity_squared);
    return perimeter;
}

ER::Ring::Ring(float64_t radius, float64_t scale_width, float64_t scale_height, float64_t angle, float64_t mass)
    : m_radius(radius), m_scale_width(scale_width), m_scale_height(scale_height), m_angle(angle), m_mass(mass)
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
