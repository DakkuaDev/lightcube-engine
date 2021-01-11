/**
 * Copyright (C) Daniel Guerra Gallardo
 *
 * @section LICENSE MIT License (Lee el archivo LICENSE para mas información)
 *
 * @section DESCRIPTION
 * LightCube Engine, es un motor de videojuegos propio creado como propósito educacional
 *
 * @author Daniel Guerra Gallardo
 * Contact: daniel.guerra.gallardo99@gmail.com
 */

#pragma once

// Macro para definir los colores de escritura de consola
#ifndef STD_OUTPUT_HANDLE
#define STD_OUTPUT_HANDLE
#endif // !STD_OUTPUT_HANDLE


// Logging de configuración Debug. Me inspiro en el logging de Unity a consola para su sintaxis
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

