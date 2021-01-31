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
#include "Entity.h"
#include "Component.h"
#include "LC_Graphics.h"

using namespace LC_Graphics;

namespace LightCubeEngine
{
	Scene::Scene(Window _window) 
	{
		// Hago que el puntero de ventana apunte a la ventana que le pasa el usuario
		window = &_window;
		
		// Creo las entidades (TODO: Inicializarlas con sus componentes)
		Entity* player = nullptr;
		Entity* scenario = nullptr;

		// Añado las entidades
		add_entity("player", player);
		add_entity("scenario", scenario);

		// Añado los componentes (NO FUNCIONA)
		//player->add_component("player_mesh", Mesh_Component*);
		//scenario->add_component("scenario_mesh", Mesh_Component*);

		// debugging
		entities.size();
		
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

	Window* Scene::get_window()
	{
		return window;
	}

	void Scene::add_entity(std::string id, Entity* entity)
	{
		// Inserto la entidad dada en el mapa
		entities.insert(pair< std::string, std::shared_ptr< Entity >>(id, entity));
	}

	Entity* Scene::get_entity(std::string id)
	{
		// Busco en el mapa la entidad y la devuelvo
		auto ent = entities.at(id).get();
		return ent;
	}
}