/*
* * Copyright(C) Daniel Guerra Gallardo
*
* @section LICENSE MIT License(Lee el archivo LICENSE para mas información)
*
* @section DESCRIPTION
*  El Kernel es la clase del bucle principal del engine para cada escena. Contiene a las tareas que ejecutará de forma constante.
*
* @author Daniel Guerra Gallardo
* Contact: daniel.guerra.gallardo99@gmail.com
*/

#include "Kernel.h"
#include "Task.h"

namespace LightCubeEngine
{

	/// <summary>
	/// Bucle principal de ejecución del motor
	/// </summary>
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

	/// <summary>
	/// Flag para parar la ejecución del bucle del motor
	/// </summary>
	void Kernel::stop()
	{
		stopped = true;
	}

	/// <summary>
	/// Se añade una tarea a la lista de tareas 
	/// </summary>
	/// <param name="task"> puntero a la tarea que se desea añadir </param>
	void Kernel::add_task(Task* task)
	{
		tasks.push_back(task);
	}
}

