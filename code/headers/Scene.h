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

#pragma once

#include <iostream>
#include <map>
#include "LC_Graphics.h"

using namespace std;
using namespace LC_Graphics;

namespace LightCubeEngine
{

	class Kernel;
	class Entity;

	class Scene
	{
		Window* window = nullptr;

		std::map<std::string, std::shared_ptr< Entity > > entities;
		Kernel* kernel;

	public:
		Scene() = default;
		Scene(Window* window);
		~Scene() = default;

	public:

		void run();
		void stop();

		Window* get_window();
	};
}
