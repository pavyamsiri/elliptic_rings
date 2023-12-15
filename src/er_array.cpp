#include "er_array.hpp"

ER::Array1D::Array1D(usize size)
{
    m_size = size;
    m_data = new f64[size];
}

ER::Array1D::~Array1D()
{
    delete[] m_data;
}

usize ER::Array1D::size() const
{
    return m_size;
}

f64& ER::Array1D::operator[](usize index)
{
    return m_data[index];
}

f64 const& ER::Array1D::operator[](usize index) const
{
    return m_data[index];
}

ER::Array1D ER::Array1D::operator+(Array1D const& other) const
{
    if (m_size != other.size()) {
        throw ArrayException();
    }
    Array1D result(m_size);
    for (usize i = 0; i < m_size; i++) {
        result[i] = m_data[i] + other[i];
    }
    return result;
}

ER::Array1D ER::Array1D::operator-(Array1D const& other) const
{
    if (m_size != other.size()) {
        throw ArrayException();
    }
    Array1D result(m_size);
    for (usize i = 0; i < m_size; i++) {
        result[i] = m_data[i] - other[i];
    }
    return result;
}

ER::Array1D ER::Array1D::operator*(Array1D const& other) const
{
    if (m_size != other.size()) {
        throw ArrayException();
    }
    Array1D result(m_size);
    for (usize i = 0; i < m_size; i++) {
        result[i] = m_data[i] * other[i];
    }
    return result;
}

ER::Array1D ER::Array1D::operator/(Array1D const& other) const
{
    if (m_size != other.size()) {
        throw ArrayException();
    }
    Array1D result(m_size);
    for (usize i = 0; i < m_size; i++) {
        result[i] = m_data[i] / other[i];
    }
    return result;
}

ER::Array3D::Array3D(usize size)
{
    m_size = size;
    m_data = new f64[3 * size];
}

ER::Array3D::~Array3D()
{
    delete[] m_data;
}

usize ER::Array3D::size() const
{
    return m_size;
}

ER::Array3D ER::Array3D::operator+(Array3D const& other) const
{
    if (m_size != other.size()) {
        throw ArrayException();
    }
    Array3D result(m_size);
    for (usize i = 0; i < m_size; i++) {
        result.set_x(i, this->get_x(i) + other.get_x(i));
        result.set_y(i, this->get_y(i) + other.get_y(i));
        result.set_z(i, this->get_z(i) + other.get_z(i));
    }
    return result;
}

ER::Array3D ER::Array3D::operator-(Array3D const& other) const
{
    if (m_size != other.size()) {
        throw ArrayException();
    }
    Array3D result(m_size);
    for (usize i = 0; i < m_size; i++) {
        result.set_x(i, this->get_x(i) - other.get_x(i));
        result.set_y(i, this->get_y(i) - other.get_y(i));
        result.set_z(i, this->get_z(i) - other.get_z(i));
    }
    return result;
}

ER::Array3D ER::Array3D::operator*(Array3D const& other) const
{
    if (m_size != other.size()) {
        throw ArrayException();
    }
    Array3D result(m_size);
    for (usize i = 0; i < m_size; i++) {
        result.set_x(i, this->get_x(i) * other.get_x(i));
        result.set_y(i, this->get_y(i) * other.get_y(i));
        result.set_z(i, this->get_z(i) * other.get_z(i));
    }
    return result;
}

ER::Array3D ER::Array3D::operator/(Array3D const& other) const
{
    if (m_size != other.size()) {
        throw ArrayException();
    }
    Array3D result(m_size);
    for (usize i = 0; i < m_size; i++) {
        result.set_x(i, this->get_x(i) / other.get_x(i));
        result.set_y(i, this->get_y(i) / other.get_y(i));
        result.set_z(i, this->get_z(i) / other.get_z(i));
    }
    return result;
}
