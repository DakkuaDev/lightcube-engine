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

#include "Kernel.h"
#include "Task.h"

using namespace std;

namespace LightCubeEngine
{

	Kernel::Kernel() 
	{
		// TODO: Añadir todas las tareas y sistemas al constructor
		add_task(render);
	}

	void Kernel::run() noexcept
	{	
		stopped = false;
		while (!stopped)
		{
			// TODO: Añadir timer para obtener el parámetro delta que podemos pasar el update(). 
			for (auto & t : tasks)
			{
				t->run();
			}
		}	
	}

	void Kernel::stop()
	{
		stopped = true;
	}

	void Kernel::add_task(Task* task)
	{
		tasks.push_back(task);
	}
}

