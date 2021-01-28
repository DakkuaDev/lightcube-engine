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
	void Entity::add(id, Component*)
	{
		// TODO: Función que añade componentes
	}

	Component* Entity::get(id)
	{
		// TODO: Busca en el mapa de componentes y devuelve el puntero asociado a ese componente
		return nullptr;
	}

	Transform_Component& Entity::get_transform()
	{	
		return *transform;
	}
}