/*
* * Copyright(C) Daniel Guerra Gallardo
*
* @section LICENSE MIT License(Lee el archivo LICENSE para mas informaci�n)
*
* @section DESCRIPTION
* Clase base. Recopila el conjunto de tareas individuales que realizan operaciones dentro del bucle del motor.
*
* @author Daniel Guerra Gallardo
* Contact: daniel.guerra.gallardo99@gmail.com
*/

#pragma once

#include <memory>
#include <Render_Node.hpp>

using namespace std;
using namespace glt;

namespace LightCubeEngine
{
	class Scene;
	class Render_Node;
	class Component;

	class Task
	{
	protected:
		Scene* scene;

	public:
		Task() = default;
		~Task() = default;

	public:
		virtual void initialize() {};
		virtual void finalize() {};
		virtual void update(float delta) = 0; 
	};

	// TODO: A�adir tarea de lectura de input del teclado, el sistema de sonido, y el sistema de control

	/// <summary>
	/// Sistema encargado del renderizado gr�fico de la escena
	/// </summary>
	class Render_System : public Task
	{
		glt::Render_Node renderer;

	public:
		Render_System();
		~Render_System() = default;

	public:
		void initialize();
		void update(float delta);
		//shared_ptr< Component > create_render_component(const string obj_file_path);
	};
}

