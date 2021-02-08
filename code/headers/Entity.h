/*
* * Copyright(C) Daniel Guerra Gallardo
*
* @section LICENSE MIT License(Lee el archivo LICENSE para mas información)
*
* @section DESCRIPTION
*  La clase Entidad, corresponde a todos aquellos elementos que se encuentran contenidos en la escena y que a su vez contienen componentes que los definen.
*
* @author Daniel Guerra Gallardo
* Contact: daniel.guerra.gallardo99@gmail.com
*/

#pragma once

#include <iostream>
#include <memory>
#include <map>

using namespace std;

namespace LightCubeEngine
{

	class Scene;
	class Component;

	class Transform_Component;

	class Entity
	{
		Scene* scene;		

		std::shared_ptr< Transform_Component > transform;

		typedef std::string id;
		std::map<id, std::shared_ptr< Component >> components;
		
	public:
		Entity(Scene &scene);
		~Entity() = default;

	public:
		std::shared_ptr< Component > get_component(id);
		void add_component(id, std::shared_ptr< Component > new_component);

		std::shared_ptr< Transform_Component >& get_transform();

		Scene* get_scene(); 
	};
}
