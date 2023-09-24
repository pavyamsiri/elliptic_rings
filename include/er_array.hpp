#pragma once
#include <stdexcept>
#include <iostream>

#include "er_defines.hpp"

namespace ER
{
    class ArrayException : public std::exception
    {
    public:
        const char *what()
        {
            return "The two Arrays are not the same size!";
        }
    };

    class Array
    {
    public:
        Array(size_t size);
        ~Array();
        size_t size() const;
        float64_t const &operator[](size_t index) const;
        float64_t &operator[](size_t index);
        friend std::ostream &operator<<(std::ostream &os, const Array &arr)
        {
            os << "[";
            for (size_t i = 0; i < arr.size(); i++)
            {
                os << arr[i];
                if (i < arr.size() - 1)
                {
                    os << ", ";
                }
            }
            os << "]";
            return os;
        }

        Array operator+(Array const &other) const;
        Array operator-(Array const &other) const;
        Array operator*(Array const &other) const;
        Array operator/(Array const &other) const;

    private:
        float64_t *m_data;
        size_t m_size;
        size_t m_capacity;
    };
}