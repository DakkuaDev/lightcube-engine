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

namespace LightCubeEngine
{
	Entity::Entity(Scene* scene) {}

	/// <summary>
	/// Se añade un componente al mapa
	/// </summary>
	/// <param name="id"> identificador del componente (único) </param>
	/// <param name="new_component"> puntero al nuevo componente </param>
	void Entity::add_component(std::string id, std::shared_ptr< Component > new_component)
	{
		components.insert(pair< std::string, std::shared_ptr< Component > >(id, new_component));
	}

	/// <summary>
	/// Se obtiene el componente haciendo una búsqueda en su mapa
	/// </summary>
	/// <param name="id"> identificador del componente (único) </param>
	/// <returns> se devuelve el puntero al componente buscado </returns>
	Component* Entity::get_component(std::string id)
	{
		auto comp = components.at(id).get();
		return comp;
	}

	/// <summary>
	/// Se obtiene el transform del componente
	/// </summary>
	/// <returns> puntero al transform buscado </returns>
	Transform_Component* Entity::get_transform()
	{	
		return transform;
	}
}