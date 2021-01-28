/*
* * Copyright(C) Daniel Guerra Gallardo
*
* @section LICENSE MIT License(Lee el archivo LICENSE para mas información)
*
* @section DESCRIPTION
* Clase encargada de mostrar todos los elementos que se van a reproducir en la escena del engine
*
* @author Daniel Guerra Gallardo
* Contact: daniel.guerra.gallardo99@gmail.com
*/

#include "Scene.h"
#include "Kernel.h"
#include "LC_Graphics.h"

using namespace LC_Graphics;

namespace LightCubeEngine
{
	Scene::Scene(Window& _window) : window(_window)
	{
		//TODO: Añadir tareas o sistemas que se vayan a utilizar en la escena (procesado de componentes)
		//kernel->add_task();
	}

	//  Read input -> update -> render
	void Scene::run()
	{
		kernel->run();
	}

	void Scene::stop()
	{
		kernel->stop();
	}

	Window& Scene::get_window()
	{
		return window;
	}
}