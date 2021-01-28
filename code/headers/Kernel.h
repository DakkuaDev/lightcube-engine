/*
* * Copyright(C) Daniel Guerra Gallardo
*
* @section LICENSE MIT License(Lee el archivo LICENSE para mas información)
*
* @section DESCRIPTION
* Clase principal encargada de ejecutar las diferentes especializaciones de Task. Bucle principal del engine.
*
* @author Daniel Guerra Gallardo
* Contact: daniel.guerra.gallardo99@gmail.com
*/

#pragma once

#include <iostream>
#include <set>
#include <list>

using namespace std;

namespace LightCubeEngine
{
	class Task;

	class Kernel
	{
		Task* task;

		bool stopped;
		list< std::shared_ptr<Task> > tasks;

	public:
		Kernel() = default;
		~Kernel() = default;

	public:
		//void add_task(task);
		void run();
		void stop();
	};
}
