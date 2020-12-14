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

#include <string>
#include <SDL.h>

using namespace std;

/// <summary>
/// Clase de personalización de la ventana emergente con SDL2
/// </summary>
class myWindow
{
private:

	string title = "";
	int width = 800;
	int height = 600;

	bool closed = false;

	SDL_Window* window = nullptr;

public:

	myWindow() = default;
	myWindow(const string& title, int width, int height);
	~myWindow();

	void pollEvents();
	inline bool isClosed() const { return closed; }

private:

	bool init();
};

