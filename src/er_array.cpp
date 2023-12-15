#include "er_array.hpp"

ER::Array::Array(usize size)
{
    m_size = size;
    m_capacity = size;
    m_data = new f64[size];
}

ER::Array::~Array()
{
    delete[] m_data;
}

usize ER::Array::size() const
{
    return m_size;
}

f64& ER::Array::operator[](usize index)
{
    return m_data[index];
}

f64 const& ER::Array::operator[](usize index) const
{
    return m_data[index];
}

ER::Array ER::Array::operator+(Array const& other) const
{
    if (m_size != other.size()) {
        throw ArrayException();
    }
    Array result(m_size);
    for (usize i = 0; i < m_size; i++) {
        result[i] = m_data[i] + other[i];
    }
    return result;
}

ER::Array ER::Array::operator-(Array const& other) const
{
    if (m_size != other.size()) {
        throw ArrayException();
    }
    Array result(m_size);
    for (usize i = 0; i < m_size; i++) {
        result[i] = m_data[i] - other[i];
    }
    return result;
}

ER::Array ER::Array::operator*(Array const& other) const
{
    if (m_size != other.size()) {
        throw ArrayException();
    }
    Array result(m_size);
    for (usize i = 0; i < m_size; i++) {
        result[i] = m_data[i] * other[i];
    }
    return result;
}

ER::Array ER::Array::operator/(Array const& other) const
{
    if (m_size != other.size()) {
        throw ArrayException();
    }
    Array result(m_size);
    for (usize i = 0; i < m_size; i++) {
        result[i] = m_data[i] / other[i];
    }
    return result;
}

