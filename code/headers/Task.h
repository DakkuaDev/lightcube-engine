/*
* * Copyright(C) Daniel Guerra Gallardo
*
* @section LICENSE MIT License(Lee el archivo LICENSE para mas información)
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
		// Considerar si quiero añadir prioridad a las tareas.
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

	/// <summary>
	/// Sistema encargado del renderizado gráfico de la escena
	/// </summary>
	class Render_System : public Task
	{
		glt::Render_Node renderer;

	public:
		Render_System();
		~Render_System() = default;

	public:
		void update(float delta);
		//shared_ptr< Component > create_render_component(const string obj_file_path);
	};
}

