/**
 * Copyright (C) Daniel Guerra Gallardo
 *
 * @section LICENSE MIT License (Lee el archivo LICENSE para mas información)
 *
 * @section DESCRIPTION
 * LightCube Engine, es un motor de videojuegos propio programado en C++ y creado con propósito educacional
 *
 * @author Daniel Guerra Gallardo
 * Contact: daniel.guerra.gallardo99@gmail.com
 */

#include <SDL.h>
#include <OpenGL.hpp>
#include "LC_Graphics.h"

using namespace LC_Graphics;
using namespace std;

LC_Graphics::Keyboard::Keyboard(Window& given_window)
{
	window = &given_window;
}


/// <summary>
/// Listado de eventos capturados por teclado
/// </summary>
void LC_Graphics::Keyboard::poll_events()
{
	SDL_Event event;

	if (SDL_PollEvent(&event))
	{
		switch ( event.type)
		{
		case SDL_KEYDOWN:
		{
			// Si se pulsan ciertas teclas se borra el contenido de la ventana:

			switch (event.key.keysym.sym)
			{
			case SDLK_SPACE:
				SDL_Log("Has pulsado la barra espaciadora");
				break;

			case SDLK_KP_ENTER:
				SDL_Log("Has pulsado la tecla 'Enter'");
				break;
			}
			break;
		}
		case SDL_QUIT:
			window->set_closed(true);
		default:
			break;
		}
	}
}
