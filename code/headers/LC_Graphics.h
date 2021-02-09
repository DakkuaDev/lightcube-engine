/**
 * Copyright (C) Daniel Guerra Gallardo
 *
 * @section LICENSE MIT License (Lee el archivo LICENSE para mas información)
 *
 * @section DESCRIPTION
 * Módulo de dibujado de gráficos varios de LightCube Engine
 *
 * @author Daniel Guerra Gallardo
 * Contact: daniel.guerra.gallardo99@gmail.com
 */

#pragma once

#include <Render_Node.hpp>
#include <Model_Obj.hpp>
#include <Cube.hpp>
#include <Model.hpp>
#include <Light.hpp>

#include <memory>
#include "internal/declarations.h"

using namespace std;
using namespace glt;

namespace LC_Graphics
{
	// Funciones: get_width(),  get_height(), clear(), swap_buffers(), enable_vsync(), disable_vsync()
	// Clase: SceneRenderer
	// Angel Rodrigez
	// angel.rodriguez@esne.edu

	/// <summary>
	/// Clase de personalización de la ventana emergente (Singleton)
	/// </summary>
	class Window
	{
	private:
		std::string title = "";
		int width = 800;
		int height = 600;
		bool set_full_screen = false;

		bool closed = false;

		SDL_Window* window = nullptr;
		SDL_GLContext gl_context;

	public:

		Window() = default;
		Window(const std::string& title, int width, int height, bool set_full_screen);
		~Window();

		inline bool is_closed() const { return closed; }
		inline void set_closed(bool is) { closed = is; }

		unsigned get_width() const;
		unsigned get_height() const;

		void clear() const;
		void swap_buffers() const;

		void enable_vsync();
		void disable_vsync();

		std::string poll_events();

	private:

		bool init();
	};

	/// <summary>
	/// Clase encargada de recoger los eventos de teclado y procesarlos
	/// </summary>
	class Keyboard
	{
		Window* window;

	public:
		Keyboard() = default;
		Keyboard(Window& window);
		~Keyboard() = default;

	public:
		std::string poll_events();
	};

	/// <summary>
	/// Clase encargada del renderizado de la escena procesando los datos de uso de OpenGL-Toolkit
	/// </summary>
	class SceneRenderer
	{

		// Se crea un puntero a Render_Node porque al usar una declaración adelantada
		// para no exportar dependencias con esta cabecera, solo se pueden definir
		// punteros o referencias a los tipos declarados de modo adelantado.

		std::unique_ptr< glt::Render_Node > renderer;

	public:

		SceneRenderer();

		/** En este caso es necesario definir explícitamente el destructor en el archivo
			* de implementación (CPP) para que el compilador pueda destruir el Render_Node.
			* Si se deja que el compilador cree un destructor por defecto en el programa
			* que use el engine, como solo tendrá una declaración adelantada, no sabrá cómo
			* destruirlo y ello dará lugar a un error de compilación.
			*/
		~SceneRenderer();

	public:
		void data();
	};
}