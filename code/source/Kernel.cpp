/*
* * Copyright(C) Daniel Guerra Gallardo
*
* @section LICENSE MIT License(Lee el archivo LICENSE para mas informaci�n)
*
* @section DESCRIPTION
* Clase principal encargada de ejecutar las diferentes especializaciones de Task. Bucle principal del engine.
*
* @author Daniel Guerra Gallardo
* Contact: daniel.guerra.gallardo99@gmail.com
*/

#include "Kernel.h"
#include "Task.h"
#include "LC_Utils.h"

using namespace std;

namespace LightCubeEngine
{

	void Kernel::run() 
	{	
		for (auto& t : tasks) { t->initialize(); }

		stopped = false;
		delta = 1.f / 60.f;
		while (!stopped)
		{		
			for (auto& t : tasks)
			{
				LC_Utils::ExecutionTimer<> timer;
				t->update(delta);
				delta = timer.get_elapsed();
			}
		}	

		for (auto& t : tasks) { t->finalize(); }
	}

	void Kernel::stop()
	{
		stopped = true;
	}

	/// <summary>
	/// Se a�ade una tarea a la lista de tareas 
	/// </summary>
	/// <param name="task"> puntero a la tarea que se desea a�adir </param>
	void Kernel::add_task(Task* task)
	{
		tasks.push_back(task);
	}
}

