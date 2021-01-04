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
//#define SDL_MAIN_HANDLED

// Declaraciones adelantadas

///////////////////////////////////////// SDL /////////////////////////////////////////

typedef struct SDL_Window   SDL_Window;
typedef void* SDL_GLContext;

/////////////////////////////////// OPENGL TOOLKIT ////////////////////////////////////

namespace glt
{

    class Render_Node;

}