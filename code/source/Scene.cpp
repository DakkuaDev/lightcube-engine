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
		input.reset(new Input_Task(*this));
		render.reset(new Render_System(*this));

		// Cargo la escena
		load_scene("");

		// Añado las tareas ( input -> update -> render  )
		kernel->add_task(input);
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

	/// <summary>
	/// Clase encargada de añadir y crear todas las entidades de la escena
	/// </summary>
	/// <param name=""> Posible XML de la escena a cargar (TODO) </param>
	void Scene::load_scene(const std::string&)
	{
		// SCENARIO

		shared_ptr<Entity> scenario( new Entity(*this));

		scenario->add_component("mesh", make_shared<Mesh_Component>(Mesh_Component
		( 
			"scenario", 
			"../../resources/scenario_demo.obj",
			*scenario.get(),
			render.get()
		)
		));

		this->add_entity("scenario", scenario);	


		// PLAYER

		shared_ptr<Entity> player(new Entity(*this));

		player->add_component("mesh", make_shared<Mesh_Component>(Mesh_Component
		(
			"player",
			"../../resources/player.obj",
			*player.get(),
			render.get()
		)
			));

		this->add_entity("player", player);

		// NUMBERS

		shared_ptr<Entity> number_1(new Entity(*this));

		number_1->add_component("mesh", make_shared<Mesh_Component>(Mesh_Component
		(
			"number_1",
			"../../resources/number_1.obj",
			*number_1.get(),
			render.get()
		)
			));

		this->add_entity("number_1", number_1);

		number_1->get_transform()->set_position(glm::vec3(-7.f, 0.f, -8.f));



		shared_ptr<Entity> number_2(new Entity(*this));

		number_2->add_component("mesh", make_shared<Mesh_Component>(Mesh_Component
		(
			"number_2",
			"../../resources/number_2.obj",
			*number_2.get(),
			render.get()
		)
			));

		this->add_entity("number_2", number_2);

		number_2->get_transform()->set_position(glm::vec3(8.f, 0.f, -2.f));




		shared_ptr<Entity> number_3(new Entity(*this));

		number_3->add_component("mesh", make_shared<Mesh_Component>(Mesh_Component
		(
			"number_3",
			"../../resources/number_3.obj",
			*number_3.get(),
			render.get()
		)
			));

		this->add_entity("number_3", number_3);

		number_3->get_transform()->set_position(glm::vec3(-8.f, 0.f, 4.f));




		shared_ptr<Entity> number_4(new Entity(*this));

		number_4->add_component("mesh", make_shared<Mesh_Component>(Mesh_Component
		(
			"number_4",
			"../../resources/number_4.obj",
			*number_4.get(),
			render.get()
		)
			));

		this->add_entity("number_4", number_4);

		number_4->get_transform()->set_position(glm::vec3(0.f, 0.f, -5.f));




		shared_ptr<Entity> number_5(new Entity(*this));

		number_5->add_component("mesh", make_shared<Mesh_Component>(Mesh_Component
		(
			"number_5",
			"../../resources/number_5.obj",
			*number_5.get(),
			render.get()
		)
			));

		this->add_entity("number_5", number_5);

		number_5->get_transform()->set_position(glm::vec3(2.5f, 0.f, 8.f));
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
	/// Se obtiene el render de la escena
	/// </summary>
	/// <returns> puntero al sistema de render </returns>
	std::shared_ptr<Render_System>& Scene::get_renderer()
	{
		return render;
	}
	 
	/// <summary>
	/// Se obtiene la entidad haciendo una búsqueda en su mapa
	/// </summary>
	/// <param name="id"> identificador de la entidad (único) </param>
	/// <returns> se devuelve el puntero a la entidad buscada </returns>
	std::shared_ptr< Entity >& Scene::get_entity(std::string id)
	{
		if (entities.size() > 0)
		{
			auto ent = entities.find(id);
			return ent->second;
		}
	}

	/// <summary>
	/// Se obtiene el mapa de entidades
	/// </summary>
	/// <returns> devuelve un puntero al mapa </returns>
	std::map<std::string, std::shared_ptr< Entity > > &Scene::get_entities()
	{
		return this->entities;
	}

	/// <summary>
	/// Añede una entidad al mapa
	/// </summary>
	/// <param name="id"> id único asociado a la entidad</param>
	/// <param name="entity"> puntero a la entidad </param>
	void Scene::add_entity(std::string id, std::shared_ptr<Entity> entity)
	{
		entities.insert(pair< std::string, std::shared_ptr< Entity > >(id, entity));	
	}




}