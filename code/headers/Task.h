/*
* * Copyright(C) Daniel Guerra Gallardo
*
* @section LICENSE MIT License(Lee el archivo LICENSE para mas información)
*
* @section DESCRIPTION
* La clase base Tarea, es de la que heredarán el conjunto de tareas y sistemas. Serán las encargadas de procesar los datos e información de entidades y componentes.
*
* @author Daniel Guerra Gallardo
* Contact: daniel.guerra.gallardo99@gmail.com
*/

#pragma once

#include <iostream>
#include <memory>
#include <Render_Node.hpp>

#include "LC_Graphics.h"

using namespace std;
using namespace glt;
using namespace LC_Graphics;

namespace LightCubeEngine
{
	class Scene;
	class Entity;
	class Component;
	class Render_Node;

	class Task
	{
	protected:
		std::shared_ptr< Scene > scene;
		typedef std::string id;

	public:
		Task() = default;
		~Task() = default;

	public:
		// Inicialización de la tarea
		virtual void initialize() {};

		// Finalización de la tarea
		virtual void finalize() {};

		// Actualización de la tarea. delta: medición del refresco de actualización.
		virtual void update(float delta) = 0; 
	};

	// TODO: Añadir tarea de lectura de input del teclado, el sistema de sonido, y el sistema de control

	/// <summary>
	/// Sistema encargado de procesar el renderizado gráfico 
	/// </summary>
	class Render_System : public Task
	{
		std::unique_ptr< glt::Render_Node > renderer;

	public:
		Render_System() = default;
		~Render_System() = default;

	public:
		void initialize();
		void update(float delta);
		shared_ptr< Component > create_mesh_component(id, std::string obj_file_path);
	};
}

