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

#include "Entity.h"

using namespace std;

namespace LightCubeEngine
{
	Entity::Entity()
	{
		// Añado los componentes (NO FUNCIONA)
		//add_component("transform", transform);
		//add_component("mesh", mesh);
	}

	void Entity::add_component(std::string id, Component*)
	{
		// Inserto la entidad dada en el mapa
		components.insert(pair< std::string, std::shared_ptr< Component >>(id, component));
	}

	Component* Entity::get_component(std::string id)
	{
		// Busco en el mapa el componente y la devuelvo
		auto comp = components.at(id).get();
		return comp;
	}

	Transform_Component& Entity::get_transform()
	{	
		return *transform;
	}
}