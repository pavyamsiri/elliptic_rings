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

class Array {
public:
    Array(usize size);
    ~Array();
    usize size() const;
    f64 const& operator[](usize index) const;
    f64& operator[](usize index);
    friend std::ostream& operator<<(std::ostream& os, Array const& arr)
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

    Array operator+(Array const& other) const;
    Array operator-(Array const& other) const;
    Array operator*(Array const& other) const;
    Array operator/(Array const& other) const;

private:
    f64* m_data;
    usize m_size;
    usize m_capacity;
};
}

