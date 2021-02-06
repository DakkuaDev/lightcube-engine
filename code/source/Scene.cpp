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
#include "Component.h"

namespace LightCubeEngine
{
	Scene::Scene(Window& _window) 
	{
		window = &_window;
		
		kernel.reset(new Kernel()); 
		render.reset(new Render_System(*this));

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
		shared_ptr<Entity> e( new Entity(*this));
		//shared_ptr< glt::Model_Obj > scenario(new glt::Model_Obj("../../resources/scenario_demo.obj"));

	
		e->add_component("mesh", make_shared<Mesh_Component>(Mesh_Component
		( 
			"scenario", 
			"../../resources/scenario_demo.obj",
			*e.get(),
			render.get()
		)
		));

		//render->renderer->add("scenario", make_shared<glt::Model_Obj>(glt::Model_Obj("../../resources/scenario_demo.obj")));

		this->add_entity("scenario", e);	
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
	std::shared_ptr< Entity > Scene::get_entity(std::string id)
	{
		if (entities.size() > 0)
		{
			auto ent = entities.at(id);
			return ent;
		}
	}

	std::map<std::string, std::shared_ptr< Entity > > &Scene::get_entities()
	{
		return this->entities;
	}

	void Scene::add_entity(std::string id, std::shared_ptr<Entity> e)
	{
		entities.insert(pair< std::string, std::shared_ptr< Entity > >(id, e));	
	}

	std::shared_ptr<Render_System> &Scene::get_renderer()
	{
		return render; 
	}


}