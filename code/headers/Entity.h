/*
* * Copyright(C) Daniel Guerra Gallardo
*
* @section LICENSE MIT License(Lee el archivo LICENSE para mas información)
*
* @section DESCRIPTION
* Clase que guarda todas las entidades de la escena que se esté mostrando en el engine. 
*
* @author Daniel Guerra Gallardo
* Contact: daniel.guerra.gallardo99@gmail.com
*/

#pragma once

#include <iostream>
#include <map>
#include "Scene.h"
#include "Component.h"

using namespace std;

namespace LightCubeEngine
{
	class Entity
	{
		//Scene* scene;
		//std::map<std::string, Component*> component_map;

	public:
		Entity() = default;
		~Entity() = default;
	};
}
