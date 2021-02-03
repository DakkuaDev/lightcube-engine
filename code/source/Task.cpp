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
#include "Scene.h"
#include "Component.h"

namespace LightCubeEngine
{

	Render_System::Render_System() {}

	void Render_System::initialize()
	{
		// TODO: Crear el renderer, Crear una luz, crear una cámara
	}

	void Render_System::update(float delta)
	{
		scene->get_window()->clear();
	    // TODO: Antes del render, actualizar el transform de todos los modelos según el transform de las entidades
		renderer.render();
		scene->get_window()->swap_buffers();
	}

	/// <summary>
	/// Se crea un nuevo componente de renderizado
	/// </summary>
	/// <param name="id">  identificador del componente (único) </param>
	/// <param name="obj_file_path"> ruta del archivo que se le pasa como .obj </param>
	/// <returns></returns>
	shared_ptr< Component > Render_System::create_render_component(std::string id, std::string obj_file_path)
	{
		auto mesh = make_shared < glt::Model_Obj >(obj_file_path);
		renderer.add(id, mesh);
		auto mesh_component = make_shared < Mesh_Component >(mesh);

		return mesh_component;
	}

}