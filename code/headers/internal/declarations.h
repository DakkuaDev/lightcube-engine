/**
 * Copyright (C) Daniel Guerra Gallardo & �ngel Rodr�guez Ballesteros (Initial Template) 
 *
 * @section LICENSE MIT License (Lee el archivo LICENSE para mas informaci�n)
 *
 * @section DESCRIPTION
 * LightCube Engine, es un motor de videojuegos propio creado como prop�sito educacional
 *
 * @author Daniel Guerra Gallardo
 * Contact: daniel.guerra.gallardo99@gmail.com / angel.rodriguez@esne.edu
 */

#pragma once
#define SDL_MAIN_HANDLED

// Declaraciones adelantadas

///////////////////////////////////////// SDL /////////////////////////////////////////

typedef struct SDL_Window   SDL_Window;
typedef void* SDL_GLContext;

/////////////////////////////////// OPENGL TOOLKIT ////////////////////////////////////

namespace glt
{

    class Render_Node;

}