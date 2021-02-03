/*
* * Copyright(C) Daniel Guerra Gallardo
*
* @section LICENSE MIT License(Lee el archivo LICENSE para mas información)
*
* @section DESCRIPTION
* Clase base. Recopila el conjunto de tareas individuales que realizan operaciones dentro del bucle del motor.
*
* @author Daniel Guerra Gallardo
* Contact: daniel.guerra.gallardo99@gmail.com
*/


#include "Task.h"
#include "Scene.h"
#include "Component.h"
#include "LC_Graphics.h"

using namespace std;
using namespace glt;

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

	//shared_ptr< Component > Render_System::create_render_component(const std::string obj_file_path)
	//{
	//	auto model = make_shared < Mesh_Component >(obj_file_path);
	//	//renderer.add(id, model);
	//	auto render_component = make_shared < Mesh_Component >();

	//	return render_component;
	//}
}