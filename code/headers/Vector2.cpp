
#pragma once

#include <cmath>
#include <ostream>

/// <summary>
/// Clase matemática de Vector. Admite verctores de 3 coordenadas de tipo int, float y double
/// </summary>
/// <typeparam name="TYPE"></typeparam>
template <class TYPE>
class Vector2
{

private:

    TYPE coordinates[2];

public:

    Vector2() = default;
    ~Vector2() = default;
    Vector2(const Vector2&) = default;

    Vector2(TYPE x, TYPE y)
    {
        coordinates[0] = x;
        coordinates[1] = y;
    }

    Vector2(TYPE(&array)[2])
    {
        coordinates[0] = array[0];
        coordinates[1] = array[1];
    }

public:

    TYPE& x() { return coordinates[0]; }
    TYPE   x() const { return coordinates[0]; }
    TYPE& y() { return coordinates[1]; }
    TYPE   y() const { return coordinates[1]; }

public:

    TYPE squared_modulus() const
    {
        return x() * x() + y() * y();
    }

    TYPE modulus() const
    {
        return sqrt(squared_modulus());
    }

    TYPE length() const
    {
        return modulus();
    }

    Vector2& normalize()
    {
        return *this /= modulus();
    }

    Vector2 normalized() const
    {
        return *this / modulus();
    }

    TYPE dot(const Vector2& other) const
    {
        return this->x() * other.x() + this->y() * other.y();
    }

    Vector2 cross(const Vector2& other) const
    {
        return
        {
             this->y() * other.x() - other.y() * this->x(),
             this->x()* other.y() - other.x() * this->y(),
        };
    }

public:

    Vector2& operator  = (const Vector2&) = default;

    Vector2& operator += (const Vector2& other)
    {
        this->x() += other.x();
        this->y() += other.y();
        return *this;
    }

    Vector2& operator -= (const Vector2& other)
    {
        this->x() -= other.x();
        this->y() -= other.y();
        return *this;
    }

    Vector2& operator *= (const float& value)
    {
        x() *= value;
        y() *= value;
        return  *this;
    }

    Vector2& operator /= (const float& value)
    {
        return *this *= 1.f / value;
    }

    Vector2 operator + (const Vector2& other) const
    {
        return { this->x() + other.x(), this->y() + other.y() };
    }

    Vector2 operator - (const Vector2& other) const
    {
        return { this->x() - other.x(), this->y() - other.y() };
    }

    TYPE   operator * (const Vector2& other) const
    {
        return this->dot(other);
    }

    Vector2 operator * (const float value) const
    {
        return { x() * value, y() };
    }

    Vector2 operator / (const float value) const
    {
        return Vector2(*this) /= value;
    }

    Vector2 operator + () const
    {
        return *this;
    }

    Vector2 operator - () const
    {
        return { -x(), -y() };
    }

public:

    bool operator == (const Vector2& other) const
    {
        return this->x() == other.x() && this->y() == other.y();
    }

    bool operator != (const Vector2& other) const
    {
        return not (*this == other);
    }

    bool operator <  (const Vector2& other) const { return this->squared_modulus() < other.squared_modulus(); }
    bool operator <= (const Vector2& other) const { return this->squared_modulus() <= other.squared_modulus(); }
    bool operator >  (const Vector2& other) const { return this->squared_modulus() > other.squared_modulus(); }
    bool operator >= (const Vector2& other) const { return this->squared_modulus() >= other.squared_modulus(); }

};

// Definiciones abreviadas de tipos de uso habitual:

typedef Vector2< int    > Vector2i;
typedef Vector2< float  > Vector2f;
typedef Vector2< double > Vector2d;

// Funciones auxiliares externas a la clase:

template < typename TYPE >
inline TYPE modulus(const Vector2 < TYPE >& vector)
{
    return vector.modulus();
}

template < typename TYPE >
inline TYPE modulus_of(const Vector2 < TYPE >& vector)
{
    return vector.modulus();
}

template < typename TYPE >
inline TYPE angle_between(const Vector2 < TYPE >& a, const Vector2 < TYPE >& b)
{
    return acos((a * b) / (a.modulus() * b.modulus()));
}



// Sobrecarga de algunos operadores fuera de la clase y del namespace, en el ámbito global:

template < typename TYPE >
inline Vector2 < TYPE > operator * (const float value, const Vector2 < TYPE >& vector)
{
    return vector * value;
}

template < typename TYPE >
inline std::ostream& operator << (std::ostream& os, const Vector2 < TYPE >& vector)
{
    return os << '{' << vector.x() << ',' << vector.y() << '}';
}
