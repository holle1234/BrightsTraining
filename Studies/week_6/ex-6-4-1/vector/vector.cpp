#include "vector.h"


// Vector constructor
vector3D::Vector::Vector(unsigned int x, unsigned int y, unsigned int z) :
    _x(x), _y(y), _z(z) {}

// namespace definition for overloading <<
std::ostream& vector3D::operator<<(std::ostream &os, const Vector &v)
{
    return os << "xyz " << v._x << ":" << v._y << ":" << v._z << ":";
}

vector3D::Vector vector3D::Vector::operator+(const Vector &another) const
{
    return Vector(this->_x + _x, this->_y + _y, this->_z + _z);
}

vector3D::Vector vector3D::Vector::operator-(const Vector &another) const
{
    return Vector(this->_x - _x, this->_y - _y, this->_z - _z);
}

vector3D::Vector& vector3D::Vector::operator+=(const Vector &another)
{
    this->_x += _x;
    this->_y += _y;
    this->_z += _z;
    return *this;
}

vector3D::Vector& vector3D::Vector::operator-=(const Vector &another)
{
    this->_x -= _x;
    this->_y -= _y;
    this->_z -= _z;
    return *this;
}

