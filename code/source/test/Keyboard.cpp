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

#include "LC_Graphics.h"

using namespace LC_Graphics;
using namespace std;


LC_Graphics::Keyboard::Keyboard(Window& _window) 
{
	window = &_window;
}

/// <summary>
/// Listado de eventos capturados por teclado
/// </summary>
void LC_Graphics::Keyboard::poll_events()
{
	window->poll_events();	
}
