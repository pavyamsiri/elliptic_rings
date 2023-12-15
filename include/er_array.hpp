#pragma once
#include "er_defines.hpp"
#include <iostream>

namespace ER {
class ArrayException : public std::exception {
    using std::exception::what;

public:
    char const* what()
    {
        return "The two Arrays are not the same size!";
    }
};

class Array1D {
public:
    Array1D(usize size);
    ~Array1D();
    usize size() const;
    f64 const& operator[](usize index) const;
    f64& operator[](usize index);
    friend std::ostream& operator<<(std::ostream& os, Array1D const& arr)
    {
        os << "[";
        for (usize i = 0; i < arr.size(); i++) {
            os << arr[i];
            if (i < arr.size() - 1) {
                os << ", ";
            }
        }
        os << "]";
        return os;
    }

    Array1D operator+(Array1D const& other) const;
    Array1D operator-(Array1D const& other) const;
    Array1D operator*(Array1D const& other) const;
    Array1D operator/(Array1D const& other) const;

private:
    f64* m_data;
    usize m_size;
};
class Array3D {
public:
    Array3D(usize size);
    ~Array3D();
    usize size() const;
    f64 const& get_x(usize element_index) const
    {
        usize actual_index = 3 * element_index + 0;
        return m_data[actual_index];
    }
    void set_x(usize element_index, f64 value)
    {
        usize actual_index = 3 * element_index + 0;
        m_data[actual_index] = value;
    }
    f64 const& get_y(usize element_index) const
    {
        usize actual_index = 3 * element_index + 1;
        return m_data[actual_index];
    }
    void set_y(usize element_index, f64 value)
    {
        usize actual_index = 3 * element_index + 1;
        m_data[actual_index] = value;
    }
    f64 const& get_z(usize element_index) const
    {
        usize actual_index = 3 * element_index + 2;
        return m_data[actual_index];
    }
    void set_z(usize element_index, f64 value)
    {
        usize actual_index = 3 * element_index + 2;
        m_data[actual_index] = value;
    }
    friend std::ostream& operator<<(std::ostream& os, Array3D const& arr)
    {
        os << "[";
        for (usize i = 0; i < arr.size(); i++) {
            os << "[" << arr.get_x(i) << ", ";
            os << arr.get_y(i) << ", ";
            os << arr.get_z(i) << "]";
            if (i < arr.size() - 1) {
                os << ", ";
            }
        }
        os << "]";
        return os;
    }

    Array3D operator+(Array3D const& other) const;
    Array3D operator-(Array3D const& other) const;
    Array3D operator*(Array3D const& other) const;
    Array3D operator/(Array3D const& other) const;

private:
    f64* m_data;
    usize m_size;
};
}
