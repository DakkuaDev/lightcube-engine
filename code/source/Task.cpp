/*
* * Copyright(C) Daniel Guerra Gallardo
*
* @section LICENSE MIT License(Lee el archivo LICENSE para mas información)
*
* @section DESCRIPTION
*  La clase base Tarea, es de la que heredarán el conjunto de tareas y sistemas. Serán las encargadas de procesar los datos e información de entidades y componentes.
*
* @author Daniel Guerra Gallardo
* Contact: daniel.guerra.gallardo99@gmail.com
*/


#include "Task.h"
#include "Entity.h"
#include "Scene.h"
#include "Component.h"
#include <iostream>
#include <Render_Node.hpp>

namespace LightCubeEngine
{

	Task::Task(Scene& _scene) 
	{
		scene = &_scene;
	}

	Render_System::Render_System(Scene& _scene) : Task::Task(_scene) 
	{
		renderer.reset(new glt::Render_Node);

		// Inicialización mínima de la escena (Cámara y fuente de luz)
		shared_ptr< glt::Camera > camera(new glt::Camera(20.f, 1.f, 50.f, 1.f));
		shared_ptr< glt::Light  > light(new glt::Light);


		renderer->add("camera", camera);
		renderer->add("light", light);
		renderer->get("camera")->translate(glt::Vector3(0.f, 18.f, 25.f));
		renderer->get("camera")->rotate_around_x(-0.6f);
		renderer->get("light")->translate(glt::Vector3(50.f, 50.f, 50.f));

	
	}

	void Render_System::initialize()
	{	
		GLsizei width = GLsizei(scene->get_window()->get_width());
		GLsizei height = GLsizei(scene->get_window()->get_height());

		renderer->get_active_camera()->set_aspect_ratio(float(width) / height);

		glViewport(0, 0, width, height);
	}

	void Render_System::update(float delta)
	{
		// Limpio el fotograma anterior
		scene->get_window()->clear();

		// paralelamente también actualizo el transform del modelo GL-Toolkits
		auto entity_map = scene->get_entities();	

		//TODO: Giro de los números
		//scene->get_entity("number_1")->get_transform()->set_rotation_x(0.5);
		

		for (auto mesh = entity_map.begin(); mesh != entity_map.end(); mesh++)
		{

			std::shared_ptr< Component > component = mesh->second->get_component("mesh");

			if (component != nullptr)
			{
				std::static_pointer_cast<Mesh_Component>(component)->get_mesh()->set_transformation(mesh->second->get_transform()->get_matrix());
			}
		}


		// Renderizo el nuevo fotograma
		renderer->render();

		// Cambio los buffers 
		scene->get_window()->swap_buffers();
	}

}