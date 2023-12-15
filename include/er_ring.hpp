#pragma once
#include "er_defines.hpp"
#include <iostream>

namespace ER {
class Ring {
public:
    // TODO: Add rotation axis, rotation angle, bend amplitude, disk scale length
    Ring(f64 radius, f64 eccentricity, f64 mass);
    ~Ring();

    friend std::ostream& operator<<(std::ostream& os, Ring const& ring)
    {
        os << "Ring: " << std::endl;
        os << "Semi-major axis length = " << ring.m_semi_major << std::endl;
        os << "Semi-minor axis length = " << ring.m_semi_minor << std::endl;
        os << "Perimeter = " << ring.m_perimeter << std::endl;
        os << "Eccentricity = " << ring.m_ecc << std::endl;
        os << "Mass = " << ring.m_mass << std::endl;
        os << "Moment of inertia (major axis) = " << ring.m_moi_major << std::endl;
        os << "Moment of inertia (minor axis) = " << ring.m_moi_minor << std::endl;
        os << "Moment of inertia (z axis) = " << ring.m_moi_z << std::endl;

        return os;
    }

    f64 get_perimeter() const { return m_perimeter; }
    f64 get_eccentricity() const { return m_ecc; }
    f64 get_eccentricity_squared() const { return m_ecc * m_ecc; }
    f64 get_semi_major_axis_length() const { return m_semi_major; }
    f64 get_semi_minor_axis_length() const { return m_semi_minor; }

private:
    f64 const m_radius;
    f64 const m_ecc;
    f64 const m_mass;
    f64 m_perimeter;
    f64 m_semi_major;
    f64 m_semi_minor;
    f64 m_scale_width;
    f64 m_scale_height;
    f64 m_moi_major;
    f64 m_moi_minor;
    f64 m_moi_z;
};
}
