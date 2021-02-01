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


#include "Task.h"
#include "Scene.h"
#include "LC_Graphics.h"

using namespace std;
using namespace glt;

namespace LightCubeEngine
{

	Render_System::Render_System()
	{
		// Se crea un nuevo render node de OpenGL Toolkit:
		renderer.reset(new glt::Render_Node);
	}

	void Render_System::update(float delta)
	{
		scene->get_window()->clear();
	    // TODO: Antes del render, actualizar el transform de todos los modelos
		renderer->render();
		scene->get_window()->swap_buffers();
	}
}