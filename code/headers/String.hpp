
// Este código es de dominio público.
// angel.rodriguez@esne.edu
// 2020.10
// Programa modificado por Daniel Guerra Gallardo

#include <cstddef>
#include <initializer_list>
#include <iostream>

using namespace std;

class String
{
public:

    typedef       char *       Iterator;
    typedef const char * Const_Iterator;

private:

    char * chars;
    size_t size;

public:

    String() { reset (); }
    ~String() { deallocate (); }

    String(const char  character);
    String(const char   * string);
    String(const String &  other);
    String(      String && other) noexcept;

    String(std::initializer_list< char >);

public:

    size_t length () const
    {
        return size;
    }

    bool empty () const
    {
        return size == 0;
    }

    void clear ()
    {
        if (size > 0)
        {
            deallocate ();
            reset ();
        }
    }

    Iterator begin ()
    {
        return chars;
    }

    Iterator end ()
    {
        return chars + size;
    }

    Const_Iterator begin () const
    {
        return chars;
    }

    Const_Iterator end () const
    {
        return chars + size;
    }

    auto printf()
    {

        if (chars)
        {
            for (auto c : *this) cout << c;
        }
        cout << endl;
  
       /* char* buffer = new char[100];
        if (chars)
        {
            for (auto c : *this) *buffer++ = c;
        }
        return buffer;*/

        //const size_t total = length();
        //char* buffer = new char[total];
        //char* source = begin();
        //
        //for (int i = 0; i < total; ++i)
        //{
        //    buffer[i] = source[i];
        //    buffer++; source++;
        //}
       /* return chars;*/
    }

public:

    String & operator  = (const String &  other);
    String & operator  = (      String && other) noexcept;

    String & operator += (const String &  other);
    String   operator +  (const String &  other) const { return String(*this) += other; }

    bool     operator == (const String &  other) const;
    bool     operator != (const String &  other) const { return not (*this == other); }

    char   & operator [] (size_t index)        { return chars[index]; }
    char     operator [] (size_t index) const  { return chars[index]; }


    explicit operator bool () const
    {
        return size > 0;
    }

private:

    void reset ()
    {
        chars = nullptr;
        size  = 0;
    }

    void allocate ()
    {
        chars = new char[size];
    }

    void allocate (size_t new_size)
    {
        chars = new char[size = new_size];
    }

    void deallocate ()
    {
        delete [] chars;
    }

    void copy (const char * source)
    {
        for (char * target = chars, * end = chars + size; target < end; )
        {
            *target++ = *source++;
        }
    }

    static size_t length_of (const char * string)
    {
        auto    ending  = string;
        while (*ending) ++ending;
        return  ending  - string;
    }

};

ostream& operator << (ostream& out, String& string);



