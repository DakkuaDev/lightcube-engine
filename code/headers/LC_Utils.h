/**
 * Copyright (C) Daniel Guerra Gallardo 
 *
 * @section LICENSE MIT License (Lee el archivo LICENSE para mas información)
 *
 * @section DESCRIPTION
 * Módulo de contenedores, tipos complejos generales, algoritmos... Utilidades varias para LightCube Engine
 *
 * @author Daniel Guerra Gallardo
 * Contact: daniel.guerra.gallardo99@gmail.com
 */

#pragma once

#include <type_traits>
#include <initializer_list>
#include <memory>
#include <chrono>
#include <iostream>
#include <cstddef>
#include <fstream>
#include <internal/utf8.h>
#include <internal/rapidxml.hpp>

using namespace std;
using namespace rapidxml;

namespace LC_Utils
{
    
    /// <summary>
    /// Macros definidas a modo de depuración en consola en modo debug. Sintaxis inspirada en Unity Engine.
    /// </summary>
    #ifndef STD_OUTPUT_HANDLE
    #define STD_OUTPUT_HANDLE
    #endif // !STD_OUTPUT_HANDLE

    #ifdef LC_DEBUG
    #define DEBUG_LOG(x) std::cout << x 
    #define N_DEBUG_LOG(x) std::cout << x << std::endl

    #define DEBUG_WARNING(x) std::cout << "\x1B[33m" << x << "\033[0m"
    #define N_DEBUG_WARNING(x) std::cout << "\x1B[33m" << x << "\033[0m" << std::endl

    #define DEBUG_ERROR(x) std::cout << "\x1B[31m" << x << "\033[0m" 
    #define N_DEBUG_ERROR(x) std::cout << "\x1B[31m" << x << "\033[0m" << std::endl
    #else
    #define DEBUG_LOG(x)
    #define N_DEBUG_LOG(x)

    #define DEBUG_WARNING(x)
    #define N_DEBUG_WARNING(x)

    #define DEBUG_ERROR(x)
    #define N_DEBUG_ERROR(x)
    #endif // LC_DEBUG

    // Clases: ObjectPool & ExecutionTimer
    // Code Blacksmith
    // https://twitter.com/codeblacksmith

    // Clases: String (Modificada)
    // Angel Rodrigez
    // angel.rodriguez@esne.edu

    /// <summary>
    /// Object Pool: Sistema que me ayuda a optimizar la instanciación / destrucción de objetos en particiones, 
    /// en vez de alojarlas en la HEAP de la memoria y probocar un 'memory leak'. Util para uso de partículas o cualquier otro elementos
    /// donde necesitemos instanciar muchos objetos al mismo tiempo, lo que obligaría en un caso normal a reservar memoria individualmente
    /// y consumiendo demasiados recursos. Haciendo uso de un object pool, logramos reducir el tiempo en esto notablemente.
    /// </summary>
    /// <typeparam name="T"> El objeto que se le pasa</typeparam>
    /// <typeparam name="size"> Tamaño de la piscina de objetos</typeparam>
    template<class T, size_t size = 2048>
    class ObjectPool final // TODO: Separar en Cabecera + Implementación
    {
    public:
        const static std::size_t Size = size;

        using value_type = T;
        using pointer = value_type*;

        ObjectPool()
        {
            for (auto i = 1; i < Size; ++i)
                mPool[i - 1].mNext = &mPool[i];

            mNextFree = &mPool[0];
        }

        ObjectPool(const ObjectPool&) = delete;

        ObjectPool(ObjectPool&& other) noexcept
            : mPool{ std::move(other.mPool) }
            , mNextFree{ other.mNextFree }
        {
            other.mNextFree = nullptr;
        }

        ~ObjectPool() = default;

        [[nodiscard]] pointer allocate()
        {
            if (mNextFree == nullptr)
                throw std::bad_alloc{};

            const auto item = mNextFree;
            mNextFree = item->mNext;

            return reinterpret_cast<pointer>(&item->mStorage);
        }

        void deallocate(pointer p) noexcept
        {
            const auto item = reinterpret_cast<Item*>(p);

            item->mNext = mNextFree;
            mNextFree = item;
        }

        template<class ...Args>
        [[nodiscard]] pointer construct(Args&& ...args)
        {
            return new (allocate()) value_type(std::forward<Args>(args)...);
        }

        void destroy(pointer p) noexcept
        {
            if (p == nullptr)
                return;

            p->~value_type();
            deallocate(p);
        }

        ObjectPool& operator =(const ObjectPool&) = delete;

        ObjectPool& operator =(ObjectPool&& other) noexcept
        {
            if (this == &other)
                return *this;

            mPool = std::move(other.mPool);
            mNextFree = other.mNextFree;

            other.mNextFree = nullptr;

            return *this;
        }

    private:
        union Item
        {
            std::aligned_storage_t<sizeof(value_type), alignof(value_type)> mStorage;
            Item* mNext;
        };

        std::unique_ptr<Item[]> mPool = std::make_unique<Item[]>(Size);
        Item* mNextFree = nullptr;
    };

    /// <summary>
    /// Cronómetro que utiliza la libreria standar de C++ y es capaz de medir en milisegundos en ciclos de reloj
    /// </summary>
    /// <typeparam name="Resolution">unidad de medida de la clase</typeparam>
    template<class Resolution = std::chrono::milliseconds>
    class ExecutionTimer final
    {
    public:
        using Clock = std::conditional_t<std::chrono::high_resolution_clock::is_steady,
            std::chrono::high_resolution_clock,
            std::chrono::steady_clock>;

        ExecutionTimer() = default;
        ~ExecutionTimer() = default;

        void end_timer()
        {
            DEBUG_LOG("Crono Elapsed Time: ");
            DEBUG_LOG(std::chrono::duration_cast<Resolution>(Clock::now() - mStart).count());
            DEBUG_LOG("\n");
        };

        float get_elapsed()
        {
            std::chrono::duration<float> elapsed = Clock::now() - mStart;
            return elapsed.count();
        }

    private:
        Clock::time_point mStart = Clock::now();
    };

    /// <summary>
    /// Clase string genérica para añadir funcionalidad adicional a C++ 
    /// </summary>
    class String 
    {
    public:

        typedef       char* Iterator;
        typedef const char* Const_Iterator;

    private:

        char* chars;
        size_t size;

    public:

        String() { reset(); }
        ~String() { deallocate(); }

        String(const char  character);
        String(const char* string);
        String(const String& other);
        String(String&& other) noexcept;

        String(std::initializer_list< char >);

    public:

        size_t length() const
        {
            return size;
        }

        bool empty() const
        {
            return size == 0;
        }

        void clear()
        {
            if (size > 0)
            {
                deallocate();
                reset();
            }
        }

        Iterator begin()
        {
            return chars;
        }

        Iterator end()
        {
            return chars + size;
        }

        Const_Iterator begin() const
        {
            return chars;
        }

        Const_Iterator end() const
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
        }

    public:

        String& operator  = (const String& other);
        String& operator  = (String&& other) noexcept;

        String& operator += (const String& other);
        String   operator +  (const String& other) const { return String(*this) += other; }

        bool     operator == (const String& other) const;
        bool     operator != (const String& other) const { return not (*this == other); }

        char& operator [] (size_t index) { return chars[index]; }
        char     operator [] (size_t index) const { return chars[index]; }


        explicit operator bool() const
        {
            return size > 0;
        }

    private:

        void reset()
        {
            chars = nullptr;
            size = 0;
        }

        void allocate()
        {
            chars = new char[size];
        }

        void allocate(size_t new_size)
        {
            chars = new char[size = new_size];
        }

        void deallocate()
        {
            delete[] chars;
        }

        void copy(const char* source)
        {
            for (char* target = chars, *end = chars + size; target < end; )
            {
                *target++ = *source++;
            }
        }

        static size_t length_of(const char* string)
        {
            auto    ending = string;
            while (*ending) ++ending;
            return  ending - string;
        }

    };

    ostream& operator << (ostream& out, String& string);

    /// <summary>
    /// Clase de lectura / escritura de archivos de texto
    /// </summary>
    class Serialization
    {
    private:
        
        std::string file_name;
        std::string path = "../../../lightcube-engine/resources/";    
        std::string resource;

    public:

        Serialization() = default;
        Serialization(std::string _file_name)
        {
            file_name = _file_name;
            resource = path + _file_name;
        }
        ~Serialization() = default;

    public:

        // Función de lectura de archivo
        void read()
        {
            N_DEBUG_WARNING(resource);

            std::ifstream file(resource, std::ifstream::binary);

            if (file)
            {
                // Obtengo la longitud de la cadena
                file.seekg(0, ifstream::end);

                if (file.good())
                {
                    auto length = file.tellg();

                    if (length > 0)
                    {
                        file.seekg(0, ifstream::beg);

                        char* buffer = new char[length];

                        if (file.good())
                        {
                            DEBUG_LOG("Leyendo ");
                            DEBUG_LOG(length);
                            N_DEBUG_LOG(" caracteres");

                            // Leo el bloque de cadena
                            file.read(buffer, length);

                            if (file.good())
                            {
                                file.close();

                                DEBUG_LOG("Se ha leido correctamente el archivo: ");
                                N_DEBUG_LOG(file_name);
                            }
                            else
                            {
                                N_DEBUG_ERROR("No se ha podido leer el archivo");
                            }
                        } 

                        delete[] buffer;
                    }              
                }          
            }  
        }

        // Función de lectura de archivos XML
        void read_xml();
        bool parse_scene(xml_node<>* scene_node);
        // TODO: gets de los objetos de retorno

        // Función de escritura de archivo
        void write(string out)
        {
            N_DEBUG_WARNING(resource);

            std::ofstream file(resource, std::ofstream::binary);

            if (file.is_open())
            {
                DEBUG_LOG("Escribiendo '");
                DEBUG_LOG(out);
                N_DEBUG_LOG("' en el archivo");

                // Sobreescritura textual del contenido
                file << out;

                if (file.good())
                {
                    file.close();

                    DEBUG_LOG("Se ha escrito correctamente el archivo: ");
                    N_DEBUG_LOG(file_name);
                }
                else
                {
                    N_DEBUG_ERROR("No se ha podido escribir el archivo");
                }              
            }
        }

    };
}

