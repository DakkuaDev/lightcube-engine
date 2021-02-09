/*
* * Copyright(C) Daniel Guerra Gallardo
*
* @section LICENSE MIT License(Lee el archivo LICENSE para mas información)
*
* @section DESCRIPTION
* Configuración de la escena de juego. Respaldada por la libreria OpenGL-Toolkit de renderizado 3D
*
* @author Daniel Guerra Gallardo
* Contact: daniel.guerra.gallardo99@gmail.com
*/

#include <SDL.h>
#include <OpenGL.hpp>
#include "LC_Graphics.h"

using namespace LC_Graphics;
using namespace std;
using namespace glm;
using namespace glt;


LC_Graphics::SceneRenderer::SceneRenderer(Window& given_window)
{
	window = &given_window;

	renderer.reset(new Render_Node);

	initialize_scene_b();
}

LC_Graphics::SceneRenderer::~SceneRenderer()
{
	// En este caso es necesario definir explícitamente el destructor en el archivo
	// de implementación (CPP) para que el compilador pueda destruir el Render_Node
	// pese a que no hay código explícito.
}


/// <summary>
/// Refresco del renderizado de la escena. En Unity, podría ser el equivalente a la función Update();
/// </summary>
void LC_Graphics::SceneRenderer::update()
{

	// Se ajusta el viewport por si el tamaño de la ventana ha cambiado:

	GLsizei width = GLsizei(window->get_width());
	GLsizei height = GLsizei(window->get_height());

	renderer->get_active_camera()->set_aspect_ratio(float(width) / height);

	glViewport(0, 0, width, height);



	// Se renderiza la escena y se intercambian los buffers de la ventana para
	// hacer visible lo que se ha renderizado:

	window->clear();
	renderer->render();
	window->swap_buffers();
}

void LC_Graphics::SceneRenderer::initialize_scene_a()
{
	// Se crean los elementos básicos necesarios para dibujar un cubo:

	shared_ptr< Model  > cube(new Model);
	shared_ptr< Camera > camera(new Camera(20.f, 1.f, 50.f, 1.f));
	shared_ptr< Light  > light(new Light);

	// Es necesario añadir las mallas a los modelos antes de añadir los modelos a la escena:

	cube->add(shared_ptr< Drawable >(new Cube), Material::default_material());

	// Se añaden los nodos a la escena:

	renderer->add("cube", cube);
	renderer->add("camera", camera);
	renderer->add("light", light);

	// Se configuran algunas propiedades de transformación:

	renderer->get("camera")->translate(glm::vec3(0.f, 0.f, 5.f));
	renderer->get("light")->translate(glm::vec3(10.f, 10.f, 10.f));

	
}

void LC_Graphics::SceneRenderer::initialize_scene_b()
{
	// Se crean los elementos del escenario:
	shared_ptr< Model > scenario(new Model_Obj("../../resources/scenario_demo.obj"));

	shared_ptr< Model > player(new Model_Obj("../../resources/player.obj"));

	shared_ptr< Model  > number_1(new Model_Obj("../../resources/number_1.obj"));
	shared_ptr< Model  > number_2(new Model_Obj("../../resources/number_2.obj"));
	shared_ptr< Model  > number_3(new Model_Obj("../../resources/number_3.obj"));
	shared_ptr< Model  > number_4(new Model_Obj("../../resources/number_4.obj"));
	shared_ptr< Model  > number_5(new Model_Obj("../../resources/number_5.obj"));


	shared_ptr< Camera > camera(new Camera(20.f, 1.f, 50.f, 1.f));
	shared_ptr< Light  > light(new Light);

	// Se añaden los nodos a la escena:

	renderer->add("scenario", scenario);

	renderer->add("player", player);

	renderer->add("number_1", number_1);
	renderer->add("number_2", number_2);
	renderer->add("number_3", number_3);
	renderer->add("number_4", number_4);
	renderer->add("number_5", number_5);

	renderer->add("camera", camera);
	renderer->add("light", light);

	// Se definen 

	auto _scenario = renderer->get("scenario");

	auto _number_1 = renderer->get("number_1");
	auto _number_2 = renderer->get("number_2");
	auto _number_3 = renderer->get("number_3");
	auto _number_4 = renderer->get("number_4");
	auto _number_5 = renderer->get("number_5");

	auto _player = renderer->get("player");

	// Se configuran algunas propiedades de transformación:

	_scenario->translate(glm::vec3(0.f, 0.f, 0.f));

	_number_1->translate(glm::vec3(-7.f, 0.f, -8.f));
	_number_1->set_parent(scenario.get());

	_number_2->translate(glm::vec3(8.f, 0.f, -2.f));
	_number_2->set_parent(scenario.get());

	_number_3->translate(glm::vec3(-8.f, 0.f, 4.f));
	_number_3->set_parent(scenario.get());

	_number_4->translate(glm::vec3(0.f, 0.f, -5.f));
	_number_4->set_parent(scenario.get());

	_number_5->translate(glm::vec3(2.5f, 0.f, 8.f));
	_number_5->set_parent(scenario.get());

	_player->translate(glm::vec3(0.f, 0.f, 0.f));
	_player->set_parent(scenario.get());

	renderer->get("camera")->translate(glm::vec3(0.f, 18.f, 25.f));
	renderer->get("camera")->rotate_around_x(-0.6f);

	renderer->get("light")->translate(glm::vec3(50.f, 50.f, 50.f));
	light->set_intensity(1.f);
}