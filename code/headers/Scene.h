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
#include "Kernel.h"
#include "Entity.h"
#include "LC_Graphics.h"

using namespace std;
using namespace LC_Graphics;

namespace LightCubeEngine
{
	class Scene
	{
		//LC_Graphics::Window& window;
		//std::map<std::string, Entity*> entity_map;
		//Kernel* kernel;

	public:
		Scene() = default;
		//Scene(LC_Graphics::Window& window);
		~Scene() = default;

	public:

		void run();
		void stop();
	};
}
