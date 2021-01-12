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


#include <iostream>						// Cuidado con el orden de estas cabeceras.
#include <SDL.h>
#include "LC_Graphics.h"

using namespace LC_Graphics;
using namespace std;


/// <summary>
/// Constructor de la ventana
/// </summary>
/// <param name="title"> Título de la ventana</param>
/// <param name="w"> ancho de la ventana</param>
/// <param name="h"> alto de la ventana</param>
LC_Graphics::Window::Window(const string& title, int w, int h) :
	title(title), width(w), height(h)
{
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
		cout << "SDL no se ha iniciado correctamente" << endl;
	}

	// Construyo la ventana

	window = SDL_CreateWindow(
		title.c_str(),
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		width, height,
		0
	);

	// Compruebo que se ha creado correctamente

	if (window == nullptr)
	{
		cout << "La ventana no se ha podido crear correctamente" << endl;
		return 0;
	}

	return true;
}

/// <summary>
/// Función para capturar los diferentes eventos de SDL2
/// </summary>
void LC_Graphics::Window::pollEvents()
{
	SDL_Event event;

	// Ocurre un evento
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			closed = true;
		default:
			break;
		}
	}
}
