
// Este código es de dominio público.
// angel.rodriguez@esne.edu
// 2020.10

#pragma once

#include <cmath>
#include <ostream>

/// <summary>
/// Clase matemática de Vector. Admite verctores de 3 coordenadas de tipo int, float y double
/// </summary>
/// <typeparam name="TYPE"></typeparam>
template <class TYPE>
class Vector3
{

private:

    TYPE coordinates[3];

public:

    Vector3() = default;
    ~Vector3() = default;
    Vector3(const Vector3 & ) = default;

    Vector3(TYPE x, TYPE y, TYPE z)
    {
        coordinates[0] = x;
        coordinates[1] = y;
        coordinates[2] = z;
    }

    Vector3(TYPE (& array)[3])
    {
        coordinates[0] = array[0];
        coordinates[1] = array[1];
        coordinates[2] = array[2];
    }

public:

    TYPE & x ()       { return coordinates[0]; }
    TYPE   x () const { return coordinates[0]; }
    TYPE & y ()       { return coordinates[1]; }
    TYPE   y () const { return coordinates[1]; }
    TYPE & z ()       { return coordinates[2]; }
    TYPE   z () const { return coordinates[2]; }

public:
    
    TYPE squared_modulus () const
    {
        return x () * x () + y () * y () + z () * z ();
    }

    TYPE modulus () const
    {
        return sqrt (squared_modulus ());
    }

    TYPE length () const
    {
        return modulus ();
    }

    Vector3 & normalize ()
    {
        return *this /= modulus ();
    }

    Vector3 normalized () const
    {
        return *this /  modulus ();
    }

    TYPE dot (const Vector3 & other) const
    {
        return this->x () * other.x () + this->y () * other.y () + this->z () * other.z ();
    }

    Vector3 cross (const Vector3 & other) const
    {
        return
        {
            this->y () * other.z () - other.y () * this->z (),
            this->z () * other.x () - other.z () * this->x (),
            this->x () * other.y () - other.x () * this->y ()
        };
    }

public:

    Vector3 & operator  = (const Vector3 & ) = default;

    Vector3 & operator += (const Vector3 & other)
    {
        this->x () += other.x ();
        this->y () += other.y ();
        this->z () += other.z ();
        return *this;
    }

    Vector3 & operator -= (const Vector3 & other)
    {
        this->x () -= other.x ();
        this->y () -= other.y ();
        this->z () -= other.z ();
        return *this;
    }

    Vector3 & operator *= (const float & value)
    {
        x () *= value;
        y () *= value;
        z () *= value;
        return  *this;
    }

    Vector3 & operator /= (const float & value)
    {
        return *this *= 1.f / value;
    }

    Vector3 operator + (const Vector3 & other) const
    {
        return { this->x () + other.x (), this->y () + other.y (), this->z () + other.z () };
    }

    Vector3 operator - (const Vector3 & other) const
    {
        return { this->x () - other.x (), this->y () - other.y (), this->z () - other.z () };
    }

    TYPE   operator * (const Vector3 & other) const
    {
        return this->dot (other);
    }

    Vector3 operator * (const float value) const
    {
        return { x () * value, y () * value, z () * value };
    }

    Vector3 operator / (const float value) const
    {
        return Vector3(*this) /= value;
    }

    Vector3 operator + () const
    {
        return *this;
    }

    Vector3 operator - () const
    {
        return { -x (), -y (), -z () };
    }

public:

    bool operator == (const Vector3 & other) const
    {
        return this->x () == other.x () && this->y () == other.y () && this->z () == other.z ();
    }

    bool operator != (const Vector3 & other) const
    {
        return not (*this == other);
    }

    bool operator <  (const Vector3 & other) const { return this->squared_modulus () <  other.squared_modulus (); }
    bool operator <= (const Vector3 & other) const { return this->squared_modulus () <= other.squared_modulus (); }
    bool operator >  (const Vector3 & other) const { return this->squared_modulus () >  other.squared_modulus (); }
    bool operator >= (const Vector3 & other) const { return this->squared_modulus () >= other.squared_modulus (); }

};

// Definiciones abreviadas de tipos de uso habitual:

typedef Vector3< int    > Vector3i;
typedef Vector3< float  > Vector3f;
typedef Vector3< double > Vector3d;

// Funciones auxiliares externas a la clase:

template < typename TYPE >
inline TYPE modulus (const Vector3 < TYPE > & vector)
{
    return vector.modulus ();
}

template < typename TYPE >
inline TYPE modulus_of (const Vector3 < TYPE > & vector)
{
    return vector.modulus ();
}

template < typename TYPE >
inline TYPE angle_between (const Vector3 < TYPE > & a, const Vector3 < TYPE > & b)
{
    return acos ((a * b) / (a.modulus () * b.modulus ()));
}



// Sobrecarga de algunos operadores fuera de la clase y del namespace, en el ámbito global:

template < typename TYPE >
inline Vector3 < TYPE > operator * (const float value, const Vector3 < TYPE > & vector)
{
    return vector * value;
}

template < typename TYPE >
inline std::ostream & operator << (std::ostream & os, const Vector3 < TYPE > & vector)
{
    return os << '{' << vector.x () << ',' << vector.y () << ',' << vector.z () << '}';
}

/// <summary>
/// Clase matemática de Vector2. Admite verctores de 2 coordenadas de tipo int, float y double
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
             this->x() * other.y() - other.x() * this->y(),
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


