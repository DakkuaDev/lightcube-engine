/*
* * Copyright(C) Daniel Guerra Gallardo
*
* @section LICENSE MIT License(Lee el archivo LICENSE para mas informaci�n)
*
* @section DESCRIPTION
*  La clase base Tarea, es de la que heredar�n el conjunto de tareas y sistemas. Ser�n las encargadas de procesar los datos e informaci�n de entidades y componentes.
*
* @author Daniel Guerra Gallardo
* Contact: daniel.guerra.gallardo99@gmail.com
*/


#include "Task.h"
#include "Entity.h"
#include "Scene.h"
#include "Component.h"

namespace LightCubeEngine
{

	void Render_System::initialize()
	{
		// TODO: Crear el renderer, Crear una luz, crear una c�mara
		renderer.reset(new glt::Render_Node);
	}

	void Render_System::update(float delta)
	{
		scene->get_window()->clear();

		// paralelamente tambi�n actualizo el transform del modelo GL-Toolkits
		auto entity_map = scene->get_entities();

		for (auto mesh = entity_map.begin(); mesh != entity_map.end(); mesh++)
		{
			std::shared_ptr< Component > c = mesh->second->get_component("mesh");

			if (c != nullptr)
			{
				std::shared_ptr< Mesh_Component > m;
				m->get_mesh()->set_transformation(mesh->second->get_transform()->get_matrix());
			}
		}

		renderer->render();
		scene->get_window()->swap_buffers();
	}

	 //<summary>
	 //Se crea un nuevo componente de renderizado de maya
	 //</summary>
	 //<param name="id">  identificador del componente (�nico) </param>
	 //<param name="obj_file_path"> ruta del archivo que se le pasa como .obj </param>
	 //<returns></returns>
	shared_ptr< Component > Render_System::create_mesh_component(std::string id, std::string obj_file_path) 
	{
		auto mesh = make_shared < glt::Model_Obj >(obj_file_path);
		renderer->add(id, mesh);
		auto mesh_component = make_shared < Mesh_Component >(mesh); 

		return mesh_component;
	}

}