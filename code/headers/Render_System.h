/*
* * Copyright(C) Daniel Guerra Gallardo
*
* @section LICENSE MIT License(Lee el archivo LICENSE para mas información)
*
* @section DESCRIPTION
* Especialización de Task. Encargada de renderizar los gráficos por la ventana.
*
* @author Daniel Guerra Gallardo
* Contact: daniel.guerra.gallardo99@gmail.com
*/

#pragma once

#include <Render_Node.hpp>
#include "Task.h"

using namespace glt;
using namespace std;

namespace LightCubeEngine
{

	class Render_System : public Task
	{
		std::unique_ptr< glt::Render_Node > renderer;

	public:
		Render_System() = default;
		~Render_System() = default;
	public:
		void run() {};
	};
}
