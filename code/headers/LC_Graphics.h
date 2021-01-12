/**
 * Copyright (C) Daniel Guerra Gallardo
 *
 * @section LICENSE MIT License (Lee el archivo LICENSE para mas información)
 *
 * @section DESCRIPTION
 * Módulo de dibujado de gráficos de LightCube Engine
 *
 * @author Daniel Guerra Gallardo
 * Contact: daniel.guerra.gallardo99@gmail.com
 */

#pragma once

#include "internal/declarations.h"

using namespace std;

namespace LC_Graphics
{
	/// <summary>
	/// Clase de personalización de la ventana emergente con SDL2
	/// </summary>
	class Window
	{
	private:

		string title = "";
		int width = 800;
		int height = 600;

		bool closed = false;

		SDL_Window* window = nullptr;

	public:

		Window() = default;
		Window(const string& title, int width, int height);
		~Window();

		void pollEvents();
		inline bool isClosed() const { return closed; }

	private:

		bool init();
	};

}


