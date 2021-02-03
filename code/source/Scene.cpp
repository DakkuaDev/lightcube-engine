/*
* * Copyright(C) Daniel Guerra Gallardo
*
* @section LICENSE MIT License(Lee el archivo LICENSE para mas información)
*
* @section DESCRIPTION
* La Escena es la clase encargada de mostrar y actualizar todos las entidades que se ven en la pantalla. Le envia al Kernel las tareas que deberá procesar
*
* @author Daniel Guerra Gallardo
* Contact: daniel.guerra.gallardo99@gmail.com
*/

#include "Scene.h"
#include "Kernel.h"
#include "Task.h"
#include "Entity.h"

namespace LightCubeEngine
{
	Scene::Scene(Window& _window) 
	{
		window = &_window;

		// Cargo la escena
		load_scene("");

		// Añado las tareas ( input -> update -> render  )
		kernel->add_task(render);	
	}


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

		e->add_component("render", render->create_render_component("render", "../../resources/scenario_demo.obj"));
		entities["e1"] = e;
		
	}

	/// <summary>
	/// Se obtiene un puntero a la ventana de la escena
	/// </summary>
	/// <returns> el puntero de la escena buscada </returns>
	LC_Graphics::Window* Scene::get_window()
	{
		return window;
	}
	 
	/// <summary>
	/// Se obtiene la entidad haciendo una búsqueda en su mapa
	/// </summary>
	/// <param name="id"> identificador de la entidad (único) </param>
	/// <returns> se devuelve el puntero a la entidad buscada </returns>
	Entity* Scene::get_entity(std::string id)
	{
		auto ent = entities.at(id).get();
		return ent;
	}
}