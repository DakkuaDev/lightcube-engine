/*
* * Copyright(C) Daniel Guerra Gallardo
*
* @section LICENSE MIT License(Lee el archivo LICENSE para mas información)
*
* @section DESCRIPTION
* Clase base. Se especializado con distintas funcionalidades / módulos desacoplados que se les pueden añadir a las entidades.
*
* @author Daniel Guerra Gallardo
* Contact: daniel.guerra.gallardo99@gmail.com
*/

#include "Component.h"
#include <Camera.hpp>
#include <Light.hpp>
#include <Model.hpp>
#include <Model_Obj.hpp>

using namespace std;

namespace LightCubeEngine
{
	Transform_Component::Transform_Component(vec3 _position, vec3 _rotation, float _rot_angle, vec3 _scale) 
		: position(_position), rotation(_rotation), rot_angle(_rot_angle), scale(_scale) {};

	glm::mat4 Transform_Component::get_transform() const
	{
		glm::mat4 new_matrix = glm::mat4();

		new_matrix = glm::translate(new_matrix, position);
		new_matrix = glm::scale(new_matrix, scale);
		new_matrix = glm::rotate(new_matrix, rot_angle, rotation);

		return new_matrix;
	}

	Camera_Component::Camera_Component(shared_ptr< Camera >& _camera) : camera (_camera) {};
	Light_Component::Light_Component(shared_ptr< Light >& _light) : light (_light) {};
	Mesh_Component::Mesh_Component(shared_ptr< Model_Obj >& _mesh) : mesh (_mesh) {};
	
}