
// Este código es de dominio público.
// angel.rodriguez@esne.edu
// 2020.10
// Programa modificado por Daniel Guerra Gallardo

#include "String.hpp"
#include <iostream>

using namespace std;

String::String(const char character)
{
    allocate (1);
    chars[0] = character;
}

String::String(const char * string)
{
    if (string)
    {
        size = length_of (string);

        if (size > 0)
        {
            allocate ();
            copy (string);

            return;
        }
    }
    else
        size = 0;

    chars = nullptr;
}

String::String(const String & other)
{
    this->size = other.size;

    if (size == 0)
    {
        chars = nullptr;
    }
    else
    {
        allocate ();
        copy (other.chars);
    }
}

String::String(String && other) noexcept
{
    this->chars = other.chars;
    this->size  = other.size;

    other.reset ();
}

String::String(std::initializer_list< char > char_list)
{
    size = char_list.size ();

    if (size == 0)
    {
        chars = nullptr;
    }
    else
    {
        allocate ();
        copy (char_list.begin ());
    }
}

String & String::operator = (const String & other)
{
    if (this != &other)
    {
        if (other.size == 0)
        {
            clear ();
        }
        else
        {
            if (other.size != this->size)
            {
                deallocate ();
                allocate (other.size);
            }

            copy (other.chars);
        }
    }

    return *this;
}

String & String::operator = (String && other) noexcept
{
    this->chars = other.chars;
    this->size  = other.size;

    other.reset ();

    return *this;
}

String & String::operator += (const String & other)
{
    if (other.size > 0)
    {
        if (this->size == 0)
        {
            *this = other;
        }
        else
        {
            size_t total  = this->size + other.size;
            char * buffer = new char[total];
            char * target = buffer;

            for (const char * source = this->chars, * end = source + this->size; source < end; ) *target++ = *source++;
            for (const char * source = other.chars, * end = source + other.size; source < end; ) *target++ = *source++;

            deallocate ();

            chars = buffer;
            size  = total;
        }
    }

    return *this;
}

bool String::operator == (const String & other) const
{
    if (this->size != other.size) return false;

    if (this != &other)
    {
        for (const char * a = this->chars, * b = other.chars, * end = a + size; a < end; ++a, ++b)
        {
            if (*a != *b) return false;
        }
    }

    return true;
}

// No funciona correctamente
ostream& operator << (ostream& out, String& string)
{

    const size_t total = string.length();
    char* buffer = new char[total];

    for (char* target = string.begin(), *end = string.end(); target < end; )
    {
        *target++ = *buffer++;
    }
    
    return out << buffer;
}



