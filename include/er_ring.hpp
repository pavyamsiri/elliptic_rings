#pragma once
#include <iostream>
#include "er_math.hpp"

namespace ER
{
    class Ring
    {
    public:
        Ring(float64_t radius, float64_t scale_width, float64_t scale_height, float64_t angle, float64_t mass);
        ~Ring() {}

        friend std::ostream &operator<<(std::ostream &os, const Ring &ring)
        {
            os << "Ring: " << std::endl;
            os << "Semi-major axis length = " << ring.m_semi_major << std::endl;
            os << "Semi-minor axis length = " << ring.m_semi_minor << std::endl;
            os << "Perimeter = " << ring.m_perimeter << std::endl;
            os << "Eccentricity = " << ring.m_ecc << std::endl;
            os << "Angle = " << ring.m_angle << std::endl;
            os << "Mass = " << ring.m_mass;

            return os;
        }

        float64_t get_perimeter() const { return m_perimeter; }
        float64_t get_eccentricity() const { return m_ecc; }
        float64_t get_eccentricity_squared() const { return m_ecc * m_ecc; }
        float64_t get_moment_of_inertia() const { return 0.0; };
        float64_t get_semi_major_axis_length() const { return m_semi_major; };
        float64_t get_semi_minor_axis_length() const { return m_semi_minor; };

    private:
        const float64_t m_radius;
        const float64_t m_scale_width;
        const float64_t m_scale_height;
        const float64_t m_angle;
        const float64_t m_mass;
        float64_t m_perimeter;
        // float64_t m_moment_of_inertia;
        float64_t m_semi_major;
        float64_t m_semi_minor;
        float64_t m_ecc;
    };
}