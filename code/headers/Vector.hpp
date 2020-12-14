
// Este código es de dominio público.
// angel.rodriguez@esne.edu
// 2020.10

#pragma once

#include <cmath>
#include <ostream>


class Vector
{

    float coordinates[3];

public:

    Vector() = default;
    ~Vector() = default;
    Vector(const Vector & ) = default;

    Vector(float x, float y, float z)
    {
        coordinates[0] = x;
        coordinates[1] = y;
        coordinates[2] = z;
    }

    Vector(float (& array)[3])
    {
        coordinates[0] = array[0];
        coordinates[1] = array[1];
        coordinates[2] = array[2];
    }

public:

    float & x ()       { return coordinates[0]; }
    float   x () const { return coordinates[0]; }
    float & y ()       { return coordinates[1]; }
    float   y () const { return coordinates[1]; }
    float & z ()       { return coordinates[2]; }
    float   z () const { return coordinates[2]; }

public:

    float squared_modulus () const
    {
        return x () * x () + y () * y () + z () * z ();
    }

    float modulus () const
    {
        return sqrt (squared_modulus ());
    }

    float length () const
    {
        return modulus ();
    }

    Vector & normalize ()
    {
        return *this /= modulus ();
    }

    Vector normalized () const
    {
        return *this /  modulus ();
    }

    float dot (const Vector & other) const
    {
        return this->x () * other.x () + this->y () * other.y () + this->z () * other.z ();
    }

    Vector cross (const Vector & other) const
    {
        return
        {
            this->y () * other.z () - other.y () * this->z (),
            this->z () * other.x () - other.z () * this->x (),
            this->x () * other.y () - other.x () * this->y ()
        };
    }

public:

    Vector & operator  = (const Vector & ) = default;

    Vector & operator += (const Vector & other)
    {
        this->x () += other.x ();
        this->y () += other.y ();
        this->z () += other.z ();
        return *this;
    }

    Vector & operator -= (const Vector & other)
    {
        this->x () -= other.x ();
        this->y () -= other.y ();
        this->z () -= other.z ();
        return *this;
    }

    Vector & operator *= (const float & value)
    {
        x () *= value;
        y () *= value;
        z () *= value;
        return  *this;
    }

    Vector & operator /= (const float & value)
    {
        return *this *= 1.f / value;
    }

    Vector operator + (const Vector & other) const
    {
        return { this->x () + other.x (), this->y () + other.y (), this->z () + other.z () };
    }

    Vector operator - (const Vector & other) const
    {
        return { this->x () - other.x (), this->y () - other.y (), this->z () - other.z () };
    }

    float   operator * (const Vector & other) const
    {
        return this->dot (other);
    }

    Vector operator * (const float value) const
    {
        return { x () * value, y () * value, z () * value };
    }

    Vector operator / (const float value) const
    {
        return Vector(*this) /= value;
    }

    Vector operator + () const
    {
        return *this;
    }

    Vector operator - () const
    {
        return { -x (), -y (), -z () };
    }

public:

    bool operator == (const Vector & other) const
    {
        return this->x () == other.x () && this->y () == other.y () && this->z () == other.z ();
    }

    bool operator != (const Vector & other) const
    {
        return not (*this == other);
    }

    bool operator <  (const Vector & other) const { return this->squared_modulus () <  other.squared_modulus (); }
    bool operator <= (const Vector & other) const { return this->squared_modulus () <= other.squared_modulus (); }
    bool operator >  (const Vector & other) const { return this->squared_modulus () >  other.squared_modulus (); }
    bool operator >= (const Vector & other) const { return this->squared_modulus () >= other.squared_modulus (); }

};

// Funciones auxiliares externas a la clase:

inline float modulus (const Vector & vector)
{
    return vector.modulus ();
}

inline float modulus_of (const Vector & vector)
{
    return vector.modulus ();
}

inline float angle_between (const Vector & a, const Vector & b)
{
    return acos ((a * b) / (a.modulus () * b.modulus ()));
}



// Sobrecarga de algunos operadores fuera de la clase y del namespace, en el ámbito global:

inline Vector operator * (const float value, const Vector & vector)
{
    return vector * value;
}

inline std::ostream & operator << (std::ostream & os, const Vector & vector)
{
    return os << '{' << vector.x () << ',' << vector.y () << ',' << vector.z () << '}';
}
