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

#include "Scene.h"

using namespace std;

namespace LightCubeEngine
{
	class Task
	{
		//Scene* scene;

	public:
		Task() = default;
		~Task() = default;

	public:
		virtual void run() = 0;
	};
}

