/*
* * Copyright(C) Daniel Guerra Gallardo
*
* @section LICENSE MIT License(Lee el archivo LICENSE para mas informaci�n)
*
* @section DESCRIPTION
* Clase base. Se especializado con distintas funcionalidades / m�dulos desacoplados que se les pueden a�adir a las entidades.
*
* @author Daniel Guerra Gallardo
* Contact: daniel.guerra.gallardo99@gmail.com
*/

#include "Component.h"
#include <Camera.hpp>
#include <Model.hpp>
#include <Light.hpp>

using namespace std;

namespace LightCubeEngine
{
	Camera_Component::Camera_Component(Camera* _camera) : camera(_camera) {};
	Light_Component::Light_Component(Light* _light) : light(_light) {};
	Mesh_Component::Mesh_Component(Model* _mesh) : mesh(_mesh) {};
	
}