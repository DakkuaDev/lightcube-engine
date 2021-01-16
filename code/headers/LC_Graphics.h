/**
 * Copyright (C) Daniel Guerra Gallardo
 *
 * @section LICENSE MIT License (Lee el archivo LICENSE para mas informaci�n)
 *
 * @section DESCRIPTION
 * M�dulo de dibujado de gr�ficos de LightCube Engine
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
	/// Clase de personalizaci�n de la ventana emergente (Singleton)
	/// </summary>
	class Window
	{
	private:

		string title = "";
		int width = 800;
		int height = 600;
		bool set_full_screen = false;

		bool closed = false;

		SDL_Window* window = nullptr;

	public:

		Window() = default;
		Window(const string& title, int width, int height, bool set_full_screen);
		~Window();

		void pollEvents();
		inline bool isClosed() const { return closed; }

	private:

		bool init();
	};

}


