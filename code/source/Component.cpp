/*
* * Copyright(C) Daniel Guerra Gallardo
*
* @section LICENSE MIT License(Lee el archivo LICENSE para mas información)
*
* @section DESCRIPTION
*  La clase base Componente, es de la que heredan el conjunto de componentes individuales que puede llevar asociado una entidad.
*
* @author Daniel Guerra Gallardo
* Contact: daniel.guerra.gallardo99@gmail.com
*/

#include "Component.h"

namespace LightCubeEngine
{
	Transform_Component::Transform_Component(glm::vec3 _position, glm::vec3 _rotation, float _rot_angle, glm::vec3 _scale) 
		: position(_position), rotation(_rotation), rot_angle(_rot_angle), scale(_scale) {};


	/// <summary>
	/// Obtiene la matriz resultante de la transformación del fotograma
	/// </summary>
	/// <returns> devuelve la matriz resultante de las operaciones de traslación, rotación y escala </returns>
	glm::mat4 Transform_Component::get_transform() const
	{
		glm::mat4 new_matrix = glm::mat4();

		new_matrix = glm::translate(new_matrix, position);
		new_matrix = glm::scale(new_matrix, scale);
		new_matrix = glm::rotate(new_matrix, rot_angle, rotation);

		return new_matrix;
	}

	Camera_Component::Camera_Component(shared_ptr< glt::Camera > _camera) : camera (_camera) {};
	Light_Component::Light_Component(shared_ptr< glt::Light > _light) : light (_light) {};
	Mesh_Component::Mesh_Component(shared_ptr< glt::Model_Obj > _mesh) : mesh (_mesh) {};
	
}