/*
* * Copyright(C) Daniel Guerra Gallardo
*
* @section LICENSE MIT License(Lee el archivo LICENSE para mas informaci�n)
*
* @section DESCRIPTION
* Clase encargada de mostrar todos los elementos que se van a reproducir en la escena del engine
*
* @author Daniel Guerra Gallardo
* Contact: daniel.guerra.gallardo99@gmail.com
*/

#include "Scene.h"
#include "Kernel.h"
#include "Task.h"
#include "Entity.h"
#include "Component.h"

#include "LC_Graphics.h"

using namespace LC_Graphics;

namespace LightCubeEngine
{
	Scene::Scene(Window& _window) 
	{
		window = &_window;

		// A�ado las tareas
		kernel->add_task(render);

		// Cargo la escena
		load_scene("");
		
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

	// TODO
	void Scene::load_scene(const std::string&)
	{
		auto e = make_shared< Entity >(this);
		//e->add_component("render", render->create_render_component("scenario.obj"));
		entities["e1"] = e;
		
	}

	/// <summary>
	/// Se obtiene un puntero a la ventana de la escena
	/// </summary>
	/// <returns> el puntero de la escena buscada </returns>
	Window* Scene::get_window()
	{
		return window;
	}

	/// <summary>
	/// Se a�ade una entidad al mapa
	/// </summary>
	/// <param name="id"> identificador de la entidad (�nico) </param>
	/// <param name="entity"> puntero a la nueva entidad </param>
	void Scene::add_entity(std::string id, Entity* entity)
	{
		entities.insert(pair< std::string, std::shared_ptr< Entity >>(id, entity));
	}
	 
	/// <summary>
	/// Se obtiene la entidad haciendo una b�squeda en su mapa
	/// </summary>
	/// <param name="id"> identificador de la entidad (�nico) </param>
	/// <returns> se devuelve el puntero a la entidad buscada </returns>
	Entity* Scene::get_entity(std::string id)
	{
		auto ent = entities.at(id).get();
		return ent;
	}
}