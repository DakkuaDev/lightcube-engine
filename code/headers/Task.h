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
		// Inicialización de la tarea
		virtual void initialize() {};

		// Actualización de la tarea. delta: medición del refresco de actualización.
		virtual void update(float delta) = 0; 

		// Inicialización de la tarea
		virtual void finalize() {};
	};

	/// <summary>
	/// Sistema encargado de procesar el renderizado gráfico 
	/// </summary>
	class Render_System : public Task
	{

	public:
		std::shared_ptr< glt::Render_Node > renderer;

	public:
		Render_System() = default;
		Render_System(Scene& scene);
		~Render_System() {};

	public:
		void initialize();
		void update(float delta);
	};

	/// <summary>
	/// Tarea encargada de procesar los eventos de teclado
	/// </summary>
	class Input_Task : public Task
	{
		std::shared_ptr< LC_Graphics::Keyboard > input_keyboard;

	public:
		std::string key;

	public:
		Input_Task() = default;
		Input_Task(Scene& scene);
		~Input_Task() = default;

	public:
		void update(float delta);
	};

	/// <summary>
	/// Tarea encargada del control de la demo
	/// </summary>
	class Control_Task : public Task
	{
		Input_Task* input;

		int horizontal_move = 0;
		int vertical_move = 0;
		int priority = 0;

	public:
		Control_Task() = default;
		Control_Task(Scene& scene, Input_Task& input);
		~Control_Task() = default;

	public:
		void update(float delta);
	};
}

