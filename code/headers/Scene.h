/*
* * Copyright(C) Daniel Guerra Gallardo
*
* @section LICENSE MIT License(Lee el archivo LICENSE para mas información)
*
* @section DESCRIPTION
* Clase encargada de mostrar todos los elementos que se van a reproducir en la escena del engine
*
* @author Daniel Guerra Gallardo
* Contact: daniel.guerra.gallardo99@gmail.com
*/

#pragma once

#include <iostream>
#include <map>
#include "LC_Graphics.h"

using namespace std;
using namespace LC_Graphics;

namespace LightCubeEngine
{
	class Kernel;
	class Task;
	class Render_System;
	class Entity;

	class Scene
	{
		Window* window;
		Kernel* kernel;
		Render_System* render;

		typedef std::string id;

		std::map<std::string, std::shared_ptr< Entity > > entities;

	public:

		// TODO: Pensar, si añado XML, donde lo meto + cuando cargo las tareas
		Scene() = default;
		Scene(Window& window);
		~Scene() = default;

	public:

		void run();

		// TODO: implementar función de stop(): Se sale de la escena -> Por ejemplo cuando el usuario cierra la aplicación
		void stop();

		Window* get_window();
		void add_entity(id, Entity* entity);
		Entity* get_entity(id);
		void load_scene(const std::string&);
	};
}
