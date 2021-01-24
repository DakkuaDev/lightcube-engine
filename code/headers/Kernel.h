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

#include <set>
#include "Task.h"

using namespace std;

namespace LightCubeEngine
{
	class Kernel
	{
		bool stopped;
		//set< Task* > tasks;

	public:
		Kernel() = default;
		~Kernel() = default;

	public:
		//void add_task(Task* task);
		void run();
	};
}
