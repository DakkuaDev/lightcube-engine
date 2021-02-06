/*
* * Copyright(C) Daniel Guerra Gallardo
*
* @section LICENSE MIT License(Lee el archivo LICENSE para mas informaci�n)
*
* @section DESCRIPTION
* La clase base Tarea, es de la que heredar�n el conjunto de tareas y sistemas. Ser�n las encargadas de procesar los datos e informaci�n de entidades y componentes.
*
* @author Daniel Guerra Gallardo
* Contact: daniel.guerra.gallardo99@gmail.com
*/

#pragma once

#include <iostream>
#include <memory>


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
		Scene* scene;
		typedef std::string id;

	public:
		Task() = default;
		Task(Scene& scene);
		~Task() = default;

	public:
		// Inicializaci�n de la tarea
		virtual void initialize() {};

		// Finalizaci�n de la tarea
		virtual void finalize() {};

		// Actualizaci�n de la tarea. delta: medici�n del refresco de actualizaci�n.
		virtual void update(float delta) = 0; 
	};

	// TODO: A�adir tarea de lectura de input del teclado, el sistema de sonido, y el sistema de control

	/// <summary>
	/// Sistema encargado de procesar el renderizado gr�fico 
	/// </summary>
	class Render_System : public Task
	{

	public:
		std::shared_ptr< glt::Render_Node > renderer;

	public:
		Render_System() = default;
		Render_System(Scene& scene);
		~Render_System() = default;

	public:
		void initialize();
		void update(float delta);
	};

	//class Input_Task : public Task
	//{
	//	std::unique_ptr< LC_Graphics::Keyboard > input_keyboard;

	//public:
	//	Input_Task() = default;
	//	Input_Task(Scene& scene);
	//	~Input_Task() = default;

	//public:
	//	void initialize();
	//	void update(float delta);
	//}
}

