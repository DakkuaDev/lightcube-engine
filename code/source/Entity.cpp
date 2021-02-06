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

#include "Entity.h"
#include "Component.h"
#include "glm/glm.hpp"

namespace LightCubeEngine
{

	Entity::Entity(Scene &_scene)
	{
		scene = &_scene; 

		// Transform inicial compartido por las entidades
		transform = std::make_shared<Transform_Component>(Transform_Component(glm::vec3 (0,0,0), glm::vec3 (0,0,0), 90, glm::vec3(1,1,1))); 
	}

	/// <summary>
	/// Se añade un componente al mapa
	/// </summary>
	/// <param name="id"> identificador del componente (único) </param>
	/// <param name="new_component"> puntero al nuevo componente </param>
	void Entity::add_component(std::string id, std::shared_ptr< Component > new_component)
	{
		if (new_component != nullptr)
		{
			components.insert(pair< std::string, std::shared_ptr< Component > >(id, new_component));
		}
	}
		

	/// <summary>
	/// Se obtiene el componente haciendo una búsqueda en su mapa
	/// </summary>
	/// <param name="id"> identificador del componente (único) </param>
	/// <returns> se devuelve el puntero al componente buscado </returns>
	std::shared_ptr< Component > Entity::get_component(std::string id)
	{
		if (components.size() > 0)
		{
			auto comp = components.at(id);
			return comp;
		}
	}

	/// <summary>
	/// Se obtiene el transform del componente
	/// </summary>
	/// <returns> puntero al transform buscado </returns>
	std::shared_ptr< Transform_Component > Entity::get_transform()
	{	
		if (transform != nullptr)
		{
			return transform;
		}
	}

	/// <summary>
	/// Se obtiene la escena
	/// </summary>
	/// <returns> puntero a la escena </returns>
	Scene* Entity::get_scene()
	{
		return scene; 
	} 
}