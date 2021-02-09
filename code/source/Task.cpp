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

#include <SDL.h>
#include <OpenGL.hpp>

#include "LC_Audio.h"

using namespace glm;

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
		// Comprueba si el usuario ha cerrado la ventana
		if (scene->get_window()->is_closed())
		{
			scene->stop();
		}

		// Limpio el fotograma anterior
		scene->get_window()->clear();

		// paralelamente también actualizo el transform del modelo GL-Toolkits
		auto entity_map = scene->get_entities();	



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


	Input_Task::Input_Task(Scene& _scene) : Task::Task(_scene) 
	{
		input_keyboard.reset(new Keyboard(*scene->get_window()));
		key = "";
	}

	void Input_Task::update(float delta)
	{
		key = input_keyboard->poll_events();
	}

	Control_Task::Control_Task(Scene& _scene, Input_Task& _input) : Task::Task(_scene)
	{
		input = &_input;

		std::string file = "bg_music.wav";
		bg_music.play(file, 1);
	}

	void Control_Task::update(float delta)
	{

		// Control del jugador 
		auto _player = scene->get_entity("player")->get_transform();

		if (input->key == "up" && (vertical_move < 25 || onWin))
		{
			_player->translate(glm::vec3(0.f, 0.f, -0.5f));
			vertical_move += 1;
		}
		else if (input->key == "down" && (vertical_move > -25 || onWin))
		{
			_player->translate(glm::vec3(0.f, 0.f, 0.5f));
			vertical_move -= 1;
		}
		else if (input->key == "right" && (horizontal_move < 15 || onWin))
		{
			_player->translate(glm::vec3(0.5f, 0.f, 0.f));
			horizontal_move += 1;
		}
		else if (input->key == "left" && (horizontal_move > -18 || onWin))
		{
			_player->translate(glm::vec3(-0.5f, 0.f, 0.f));
			horizontal_move -= 1;
		}

		// Mecánica: Recolecta de números en orden
		auto _number_1 = scene->get_entity("number_1")->get_transform();
		auto _number_2 = scene->get_entity("number_2")->get_transform();
		auto _number_3 = scene->get_entity("number_3")->get_transform();
		auto _number_4 = scene->get_entity("number_4")->get_transform();
		auto _number_5 = scene->get_entity("number_5")->get_transform();

		_number_1->rotate(0.02f);
		_number_2->rotate(0.02f);
		_number_3->rotate(0.02f);
		_number_4->rotate(0.02f);
		_number_5->rotate(0.02f);

		float distance_1 = glm::length(_number_1->get_position() - _player->get_position());
		float distance_2 = glm::length(_number_2->get_position() - _player->get_position());
		float distance_3 = glm::length(_number_3->get_position() - _player->get_position());
		float distance_4 = glm::length(_number_4->get_position() - _player->get_position());
		float distance_5 = glm::length(_number_5->get_position() - _player->get_position());

		if (distance_1 <= 1)
		{
			if (priority == 0)
			{
				_number_1->set_position(glm::vec3(99.f, 99.f, 99.f));

				//std::shared_ptr< Component > component = scene->get_entity("number_1")->get_component("audio");
				//std::static_pointer_cast<Audio_Component>(component)->play_music("collect_sound.wav", 0);

				priority++;
			}
		}

		if (distance_2 <= 1)
		{
			if (priority == 1)
			{
				_number_2->set_position(glm::vec3(99.f, 99.f, 99.f));
				priority++;
			}
		}

		if (distance_3 <= 1)
		{
			if (priority == 2)
			{
				_number_3->set_position(glm::vec3(99.f, 99.f, 99.f));
				priority++;
			}
		}

		if (distance_4 <= 1)
		{
			if (priority == 3)
			{
				_number_4->set_position(glm::vec3(99.f, 99.f, 99.f));
				priority++;
			}
		}

		if (distance_5 <= 1)
		{
			if (priority == 4)
			{
				_number_5->set_position(glm::vec3(99.f, 99.f, 99.f));

				// Finalización de partida

				//bg_music.stop();

				scene->get_entity("scenario")->get_transform()->set_position(glm::vec3(99.f, 99.f, 99.f));
				scene->get_entity("scenario_win")->get_transform() ->set_position(glm::vec3(0.f, 0.f, 0.f));

				onWin = true;
			}
		}
	}

}