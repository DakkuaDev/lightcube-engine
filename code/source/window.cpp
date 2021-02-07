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


#include <iostream>						// Cuidado con el orden de estas cabeceras.
#include <cassert>
#include <SDL.h>
#include <OpenGL.hpp>
#include "LC_Graphics.h"

using namespace LC_Graphics;
using namespace std;


LC_Graphics::Window::Window(const std::string& _title, int _w, int _h, bool _set_full) :
	title(_title), width(_w), height(_h), set_full_screen(_set_full)
{
	gl_context = nullptr;

	if (!init())
	{
		closed = true;
	}
}


LC_Graphics::Window::~Window()
{
	SDL_GL_DeleteContext(gl_context);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

/// <summary>
/// Inicialización de la ventana emergente
/// </summary>
bool LC_Graphics::Window::init()
{
	// Inicializo SDL
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		SDL_Log("SDL no se ha iniciado correctamente");
	}

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);

	// Construyo la ventana
	window = SDL_CreateWindow(
		title.c_str(),
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		width, height,
		SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN
	);

	// Compruebo que se ha creado correctamente
	if (window == nullptr)
	{
		SDL_Log("La ventana no se ha podido crear correctamente");
		return 0;
	}
	else
	{
		// Creo el contexto de Open GL
		gl_context = SDL_GL_CreateContext(window);

		if (gl_context && glt::initialize_opengl_extensions())
		{
			if (set_full_screen)
			{
				SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);
			}
		}
	}

	return true;
}

/// <summary>
/// Retorna el ancho actual de la ventana (el usuario puede cambiarlo).
/// </summary>
/// <returns> retorno del ancho de ventana </returns>
unsigned LC_Graphics::Window::get_width() const
{
	int width = 0, height;

	if (window) SDL_GetWindowSize(window, &width, &height);

	return unsigned(width);
}

/// <summary>
/// Retorna el alto actual de la ventana (el usuario puede cambiarlo).
/// </summary>
/// <returns> retorno del alto de ventana </returns>
unsigned LC_Graphics::Window::get_height() const
{
	int width, height = 0;

	if (window) SDL_GetWindowSize(window, &width, &height);

	return unsigned(height);
}

/// <summary>
///  Borra el buffer de la pantalla usando OpenGL.
/// </summary>
void LC_Graphics::Window::clear() const
{
	if (gl_context) glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

/// <summary>
/// Intercambia el buffer visible con el buffer oculto.
/// </summary>
void LC_Graphics::Window::swap_buffers() const
{
	if (gl_context) SDL_GL_SwapWindow(window);
}

/// <summary>
/// Activa la sincronización vertical
/// </summary>
void LC_Graphics::Window::enable_vsync()
{
	if (gl_context) SDL_GL_SetSwapInterval(1);
}

/// <summary>
/// Desactiva la sincronización vertical
/// </summary>
void LC_Graphics::Window::disable_vsync()
{
	if (gl_context) SDL_GL_SetSwapInterval(0);
}

/// <summary>
/// Eventos de teclado asociados a la ventana
/// </summary>
void LC_Graphics::Window::poll_events()
{
	SDL_Event event;

	if (SDL_PollEvent(&event))
	{
		switch (event.type)
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
			// TODO: Tengo que llamar a finalización de tareas
			this->set_closed(true);
			

		default:
			break;
		}
	}
}
