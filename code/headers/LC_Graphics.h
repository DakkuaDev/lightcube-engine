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
	// Clase: SceneRenderer (Sample_Renderer)
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

		void poll_events();
		inline bool is_closed() const { return closed; }

		/** Retorna el ancho actual de la ventana (el usuario puede cambiarlo).
			*/
		unsigned get_width() const;

		/** Retorna el alto actual de la ventana (el usuario puede cambiarlo).
			*/
		unsigned get_height() const;

		/** Borra el buffer de la pantalla usando OpenGL.
			*/
		void clear() const;

		/** Intercambia el buffer visible con el buffer oculto.
			*/
		void swap_buffers() const;

		/* Activar y desactivar sincronización vertical */
		void enable_vsync();
		void disable_vsync();



	private:

		bool init();
	};

	/// <summary>
	/// Clase encargada del renderizado provisional de la escena usando OpenGL-Tookit
	/// </summary>
	class SceneRenderer
	{

		// Se crea un puntero a Render_Node porque al usar una declaración adelantada
		// para no exportar dependencias con esta cabecera, solo se pueden definir
		// punteros o referencias a los tipos declarados de modo adelantado.

		std::unique_ptr< glt::Render_Node > renderer;

		Window* window;

	public:

		SceneRenderer(LC_Graphics::Window& given_window);

		/** En este caso es necesario definir explícitamente el destructor en el archivo
			* de implementación (CPP) para que el compilador pueda destruir el Render_Node.
			* Si se deja que el compilador cree un destructor por defecto en el programa
			* que use el engine, como solo tendrá una declaración adelantada, no sabrá cómo
			* destruirlo y ello dará lugar a un error de compilación.
			*/
		~SceneRenderer();

		void render();
		void SceneExample1();
		void SceneExample2();

	};
}







