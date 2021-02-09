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
		control.reset(new Control_Task(*this, *input));
		render.reset(new Render_System(*this));

		// Cargo la escena
		load_scene("");

		// Añado las tareas 
		kernel->add_task(input);
		kernel->add_task(control);
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
		// ESCENARIO

		// Cargo la entidad
		shared_ptr<Entity> scenario( new Entity(*this));

		// Añado el componente de maya
		scenario->add_component("mesh", make_shared<Mesh_Component>(Mesh_Component
		( 
			"scenario", 
			"../../resources/scenario_demo.obj",
			*scenario.get(),
			render.get()
		)
		));

		// Añado la entidad al mapa
		this->add_entity("scenario", scenario);	



		shared_ptr<Entity> scenario_win(new Entity(*this));

		scenario_win->add_component("mesh", make_shared<Mesh_Component>(Mesh_Component
		(
			"scenario_win",
			"../../resources/scenario_demo_win.obj",
			*scenario_win.get(),
			render.get()
		)
			));

		this->add_entity("scenario_win", scenario_win);

		// Posiciono la entidad 
		scenario_win->get_transform()->set_position(glm::vec3(99.f, 99.f, 99.f));


		// JUGADOR

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

		// Creo una jerarquia de escena entre una entidad hija y una padre
		player->get_transform()->attached_to(scenario);

		// NUMEROS

		shared_ptr<Entity> number_1(new Entity(*this));

		number_1->add_component("mesh", make_shared<Mesh_Component>(Mesh_Component
		(
			"number_1",
			"../../resources/number_1.obj",
			*number_1.get(),
			render.get()
		)
			));

		// Añado el componente de audio
		number_1->add_component("audio", make_shared<Audio_Component>(Audio_Component("collect_sound.wav")));

		this->add_entity("number_1", number_1);

		number_1->get_transform()->set_position(glm::vec3(-7.f, 0.f, -8.f));
		number_1->get_transform()->attached_to(scenario);



		shared_ptr<Entity> number_2(new Entity(*this));

		number_2->add_component("mesh", make_shared<Mesh_Component>(Mesh_Component
		(
			"number_2",
			"../../resources/number_2.obj",
			*number_2.get(),
			render.get()
		)
			));

		number_2->add_component("audio", make_shared<Audio_Component>(Audio_Component("collect_sound.wav")));

		this->add_entity("number_2", number_2);

		number_2->get_transform()->set_position(glm::vec3(8.f, 0.f, -2.f));
		number_2->get_transform()->attached_to(scenario);




		shared_ptr<Entity> number_3(new Entity(*this));

		number_3->add_component("mesh", make_shared<Mesh_Component>(Mesh_Component
		(
			"number_3",
			"../../resources/number_3.obj",
			*number_3.get(),
			render.get()
		)
			));

		number_3->add_component("audio", make_shared<Audio_Component>(Audio_Component("collect_sound.wav")));

		this->add_entity("number_3", number_3);

		number_3->get_transform()->set_position(glm::vec3(-8.f, 0.f, 4.f));
		number_3->get_transform()->attached_to(scenario);




		shared_ptr<Entity> number_4(new Entity(*this));

		number_4->add_component("mesh", make_shared<Mesh_Component>(Mesh_Component
		(
			"number_4",
			"../../resources/number_4.obj",
			*number_4.get(),
			render.get()
		)
			));

		number_4->add_component("audio", make_shared<Audio_Component>(Audio_Component("collect_sound.wav")));

		this->add_entity("number_4", number_4);

		number_4->get_transform()->set_position(glm::vec3(0.f, 0.f, -5.f));
		number_4->get_transform()->attached_to(scenario);




		shared_ptr<Entity> number_5(new Entity(*this));

		number_5->add_component("mesh", make_shared<Mesh_Component>(Mesh_Component
		(
			"number_5",
			"../../resources/number_5.obj",
			*number_5.get(),
			render.get()
		)
			));

		number_5->add_component("audio", make_shared<Audio_Component>(Audio_Component("end_sound.wav")));

		this->add_entity("number_5", number_5);

		number_5->get_transform()->set_position(glm::vec3(2.5f, 0.f, 8.f));
		number_5->get_transform()->attached_to(scenario);
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

		auto ent = entities.find(id);
		return ent->second;
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