/*
* * Copyright(C) Daniel Guerra Gallardo
*
* @section LICENSE MIT License(Lee el archivo LICENSE para mas información)
*
* @section DESCRIPTION
* La Escena es la clase encargada de mostrar y actualizar todos las entidades que se ven en la pantalla. Le envia al Kernel las tareas que deberá procesar
*
* @author Daniel Guerra Gallardo
* Contact: daniel.guerra.gallardo99@gmail.com
*/

#pragma once

#include <iostream>
#include <memory>
#include <map>

#include "LC_Graphics.h"

using namespace std;
using namespace LC_Graphics;

namespace LightCubeEngine
{
	class Kernel;
	class Task;
	class Render_System;
	class Input_Task;
	class Mesh_Component;
	class Entity;

	class Scene
	{
		LC_Graphics::Window* window;
		std::shared_ptr< Kernel > kernel;

		// TODO: Añadir las tareas y sistemas que falten
		std::shared_ptr< Render_System > render;
		std::shared_ptr< Input_Task > input;

		typedef std::string id;

		std::map<id, std::shared_ptr< Entity > > entities;

	public:

		// TODO: Pensar, si añado XML, donde lo meto + cuando cargo las tareas
		Scene() = default;
		Scene(LC_Graphics::Window& window);
		~Scene() = default;

	public:

		void run();
		void stop();

		LC_Graphics::Window* get_window();

		std::shared_ptr< Entity >& get_entity(id);
		std::map<std::string, std::shared_ptr< Entity > > &get_entities();
		std::shared_ptr<Render_System>& get_renderer();

		void add_entity(id,  std::shared_ptr<Entity> e); 

		void load_scene(const std::string&);
	};
}
