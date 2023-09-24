#include "er_array.hpp"

ER::Array::Array(size_t size)
{
    m_size = size;
    m_capacity = size;
    m_data = new float64_t[size];
}

ER::Array::~Array()
{
    delete[] m_data;
}

size_t ER::Array::size() const
{
    return m_size;
}

float64_t &ER::Array::operator[](size_t index)
{
    return m_data[index];
}

float64_t const &ER::Array::operator[](size_t index) const
{
    return m_data[index];
}

ER::Array ER::Array::operator+(Array const &other) const
{
    if (m_size != other.size())
    {
        throw ArrayException();
    }
    Array result(m_size);
    for (size_t i = 0; i < m_size; i++)
    {
        result[i] = m_data[i] + other[i];
    }
    return result;
}

ER::Array ER::Array::operator-(Array const &other) const
{
    if (m_size != other.size())
    {
        throw ArrayException();
    }
    Array result(m_size);
    for (size_t i = 0; i < m_size; i++)
    {
        result[i] = m_data[i] - other[i];
    }
    return result;
}

ER::Array ER::Array::operator*(Array const &other) const
{
    if (m_size != other.size())
    {
        throw ArrayException();
    }
    Array result(m_size);
    for (size_t i = 0; i < m_size; i++)
    {
        result[i] = m_data[i] * other[i];
    }
    return result;
}

ER::Array ER::Array::operator/(Array const &other) const
{
    if (m_size != other.size())
    {
        throw ArrayException();
    }
    Array result(m_size);
    for (size_t i = 0; i < m_size; i++)
    {
        result[i] = m_data[i] / other[i];
    }
    return result;
}