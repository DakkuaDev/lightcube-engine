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

		shared_ptr< glt::Camera > camera(new glt::Camera(20.f, 1.f, 50.f, 1.f));
		shared_ptr< glt::Light  > light(new glt::Light);


		renderer->add("camera", camera);
		renderer->add("light", light);
		renderer->get("camera")->translate(glt::Vector3(0.f, 18.f, 25.f));
		renderer->get("camera")->rotate_around_x(-0.6f);
		renderer->get("light")->translate(glt::Vector3(50.f, 50.f, 50.f));

	
	}

	//Input_Task::Input_Task() : Task::Task()

	void Render_System::initialize()
	{	
		GLsizei width = GLsizei(scene->get_window()->get_width());
		GLsizei height = GLsizei(scene->get_window()->get_height());

		renderer->get_active_camera()->set_aspect_ratio(float(width) / height);

		glViewport(0, 0, width, height);
	}

	void Render_System::update(float delta)
	{
		scene->get_window()->clear();

		// paralelamente también actualizo el transform del modelo GL-Toolkits
		auto entity_map = scene->get_entities();

		for (auto mesh = entity_map.begin(); mesh != entity_map.end(); mesh++)
		{

			std::shared_ptr< Component > component = mesh->second->get_component("mesh");

			if (component != nullptr)
			{
				//mesh->second->get_transform()->get_matrix();

				std::static_pointer_cast<Mesh_Component>(component)->get_mesh()->set_transformation(mesh->second->get_transform()->get_matrix());
			}
		}

		renderer->render();
		scene->get_window()->swap_buffers();
	}

	// //<summary>
	// //Se crea un nuevo componente de renderizado de maya
	// //</summary>
	// //<param name="id">  identificador del componente (único) </param>
	// //<param name="obj_file_path"> ruta del archivo que se le pasa como .obj </param>
	// //<returns></returns>
	//shared_ptr< Component > Render_System::create_mesh_component(std::string id, std::string obj_file_path) 
	//{
	//	auto mesh = make_shared < glt::Model_Obj >(obj_file_path);
	//	renderer->add(id, mesh);
	//	auto mesh_component = make_shared < Mesh_Component >(mesh); 

	//	return mesh_component;
	//}

	//std::unique_ptr<glt::Render_Node> Render_System::get_renderer()
	//{
	//	return renderer;
	//}

}