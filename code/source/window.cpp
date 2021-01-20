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


/// <summary>
/// Constructor de la ventana emergente
/// </summary>
/// <param name="title"> Título de la ventana</param>
/// <param name="w"> ancho de la ventana</param>
/// <param name="h"> alto de la ventana</param>
/// <param name="set_full"> modo de pantalla (full screen o window)</param>
LC_Graphics::Window::Window(const std::string& _title, int _w, int _h, bool _set_full) :
	title(_title), width(_w), height(_h), set_full_screen(_set_full)
{

	gl_context = nullptr;

	// Si no se inicializa cierro la ventana
	if (!init())
	{
		closed = true;
	}
}

/// <summary>
/// Destructor de la ventana emergente
/// </summary>
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
/// Función para capturar los diferentes eventos del usuario
/// </summary>
void LC_Graphics::Window::poll_events()
{
	// Se toma el buffer de la ventana para dibujar en él:

	SDL_Surface* surface = SDL_GetWindowSurface(window);

	if (not surface)
	{
		SDL_Log("No se ha podido acceder al buffer de la ventana.");
	}

	SDL_Event event;

	// Ocurre un evento
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
				SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 200, 200, 200));
				SDL_Log("Has pulsado la barra espaciadora");
				break;

			case SDLK_ESCAPE:
				SDL_Log("Has pulsado la tecla 'ESC'");
				closed = true;
				break;

			case SDLK_RETURN:

			case SDLK_KP_ENTER:
				SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 0, 0, 0));
				SDL_Log("Has pulsado la tecla 'Enter'");
				break;
			}
			break;
		}
		case SDL_MOUSEBUTTONDOWN:
		case SDL_MOUSEMOTION:
		{
			// Si se mueve el ratón mientras se mantiene presionado alguno de sus tres
			// botones principales se dibuja un pequeño rectángulo de color:

			int mouse_x = 0, mouse_y = 0;

			uint32_t buttons = SDL_GetMouseState(&mouse_x, &mouse_y);

			uint8_t  left = buttons & SDL_BUTTON(SDL_BUTTON_LEFT) ? 255 : 0;
			uint8_t  middle = buttons & SDL_BUTTON(SDL_BUTTON_MIDDLE) ? 255 : 0;
			uint8_t  right = buttons & SDL_BUTTON(SDL_BUTTON_RIGHT) ? 255 : 0;

			if (left || middle || right)
			{
				SDL_Rect cursor_area = { mouse_x - 1, mouse_y - 1, 3, 3 };

				SDL_FillRect(surface, &cursor_area, SDL_MapRGB(surface->format, left, middle, right));
			}

			break;
		}
		case SDL_QUIT:
			closed = true;
			break;

		default:
			break;
		}

		// Render (Re-dibujado) de pantalla
		SDL_UpdateWindowSurface(window);
	}	
}

void LC_Graphics::Window::enable_vsync()
{
	if (gl_context) SDL_GL_SetSwapInterval(1);
}

void LC_Graphics::Window::disable_vsync()
{
	if (gl_context) SDL_GL_SetSwapInterval(0);
}

unsigned LC_Graphics::Window::get_width() const
{
	int width = 0, height;

	if (window) SDL_GetWindowSize(window, &width, &height);

	return unsigned(width);
}

unsigned LC_Graphics::Window::get_height() const
{
	int width, height = 0;

	if (window) SDL_GetWindowSize(window, &width, &height);

	return unsigned(height);
}

void LC_Graphics::Window::clear() const
{
	if (gl_context) glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void LC_Graphics::Window::swap_buffers() const
{
	if (gl_context) SDL_GL_SwapWindow(window);
}
