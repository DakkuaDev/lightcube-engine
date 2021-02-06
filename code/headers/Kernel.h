/*
* * Copyright(C) Daniel Guerra Gallardo
*
* @section LICENSE MIT License(Lee el archivo LICENSE para mas información)
*
* @section DESCRIPTION
* El Kernel es la clase del bucle principal del engine para cada escena. Contiene a las tareas que ejecutará de forma constante.
*
* @author Daniel Guerra Gallardo
* Contact: daniel.guerra.gallardo99@gmail.com
*/

#pragma once

#include <iostream>
#include <memory>
#include <chrono>
#include <set>
#include <list>

#include "LC_Utils.h"

using namespace std;
using namespace LC_Utils;

namespace LightCubeEngine
{
	class Task;
	class Render_System;

	class Kernel
	{
		bool stopped;
		float delta;

		list< std::shared_ptr< Task > > tasks;

	public:
		Kernel() = default;
		~Kernel() = default;

	public:

		void run();
		void stop();

		void add_task(std::shared_ptr< Task > task);
	};
}
