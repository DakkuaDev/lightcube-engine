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

#include "Scene.h"
#include "Entity.h"
#include "Task.h"
#include "Component.h"

namespace LightCubeEngine
{
	Component::Component(Entity &e)
	{
		parent = &e; 
	}
	
	Transform_Component::Transform_Component(glm::vec3 _position, glm::vec3 _rotation, float _rot_angle, glm::vec3 _scale) 
		: position(_position), rotation(_rotation), rot_angle(_rot_angle), scale(_scale) {};


	/// <summary>
	/// Obtiene la matriz resultante de la transformación del fotograma
	/// </summary>
	/// <returns> devuelve la matriz resultante de las operaciones de traslación, rotación y escala </returns>
	glm::mat4 Transform_Component::get_matrix() const
	{
		glm::mat4 identity(1.0f);

		glm::mat4 translate_matrix = glm::translate(identity, position);
		glm::mat4 scale_matrix = glm::scale(translate_matrix, scale);
		glm::mat4 rotate_matrix = glm::rotate(scale_matrix, rot_angle, rotation);
		
		glm::mat4 transform_matrix = scale_matrix;

		return transform_matrix;
	}

	glm::vec4 Transform_Component::get_transform_vector() const
	{
		glm::vec4 transformed_vector = glm::vec4() * get_matrix();
		return transformed_vector;
	}

	Camera_Component::Camera_Component(shared_ptr< glt::Camera > _camera) : camera (_camera) {};
	Light_Component::Light_Component(shared_ptr< glt::Light > _light) : light (_light) {};
	Mesh_Component::Mesh_Component(std::string id, std::string model_path, Entity& e, Render_System *render) 
	{

		mesh = make_shared<glt::Model_Obj>(glt::Model_Obj(model_path));
		parent = &e; 
		render->renderer->add(id, mesh); 
		//parent->get_scene()->get_renderer()->renderer->add(id, mesh);
	};
	
}