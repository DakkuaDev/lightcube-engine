/**
 * Copyright (C) Daniel Guerra Gallardo & Ángel Rodríguez Ballesteros (Initial Template) 
 *
 * @section LICENSE MIT License (Lee el archivo LICENSE para mas información)
 *
 * @section DESCRIPTION
 * LightCube Engine, es un motor de videojuegos propio creado como propósito educacional
 *
 * @author Daniel Guerra Gallardo
 * Contact: daniel.guerra.gallardo99@gmail.com / angel.rodriguez@esne.edu
 */

#pragma once


// Declaraciones adelantadas


//////////////////////////////////// SDL ///////////////////////////////////////////////

typedef struct SDL_Window   SDL_Window;
typedef void* SDL_GLContext;
typedef union SDL_Event;



//////////////////////////////////// SDL_stdinc ////////////////////////////////////////

typedef uint8_t Uint8;
typedef uint32_t Uint32;
typedef uint8_t Uint8;

//////////////////////////////////// SDL MIXER ////////////////////////////////////////

typedef struct _Mix_Music Mix_Music;
typedef struct Mix_Chunk;

/////////////////////////////////// OPENGL TOOLKIT ////////////////////////////////////

namespace glt
{

    class Render_Node;

}