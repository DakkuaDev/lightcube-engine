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

	/// <summary>
	/// Obtiene el vector resultante de la transformación del fotograma
	/// </summary>
	/// <returns> devuelve el vector resultante de la operación de la matriz </returns>
	glm::vec4 Transform_Component::get_transform_vector() const
	{
		glm::vec4 transformed_vector = glm::vec4() * get_matrix();
		return transformed_vector;
	}

	/// <summary>
	/// Posiciona la traslación a unas nuevas coordenadas a la entidad
	/// </summary>
	/// <param name="new_position"> vector posición </param>
	void Transform_Component::set_position(glm::vec3 new_position)
	{
		position = new_position;
	}

	/// <summary>
	/// Traslada sobre las anteriores coordenadas a la entidad
	/// </summary>
	/// <param name="coord"> vector traslación </param>
	void Transform_Component::translate(glm::vec3 coord)
	{
		position += coord;
	}

	/// <summary>
	/// Rota sobre las coordenadas anteriores de la entidad (x, y, z)
	/// </summary>
	/// <param name="_rot_x"></param>
	void Transform_Component::rotate_x(float _rot_x)
	{
		rotation += glm::vec3(_rot_x, 0.f, 0.f);
	}
	void Transform_Component::rotate_y(float _rot_y)
	{
		rotation += glm::vec3(0.f, _rot_y, 0.f);
	}
	void Transform_Component::rotate_z(float _rot_z)
	{
		rotation += glm::vec3(0.f, 0.f, _rot_z);
	}

	/// <summary>
	/// Fija una nueva escala a la entidad
	/// </summary>
	/// <param name="new_scale"> vector escala </param>
	void Transform_Component::set_scale(glm::vec3 new_scale)
	{
		scale = new_scale;
	}

	glm::vec3 Transform_Component::get_position()
	{
		return position;
	}

	glm::vec3 Transform_Component::get_rotation()
	{
		return rotation;
	}

	glm::vec3 Transform_Component::get_scale()
	{
		return scale;
	}

	Camera_Component::Camera_Component(shared_ptr< glt::Camera > _camera) : camera (_camera) {};
	Light_Component::Light_Component(shared_ptr< glt::Light > _light) : light (_light) {};
	Mesh_Component::Mesh_Component(std::string id, std::string model_path, Entity& e, Render_System *render) 
	{

		mesh = make_shared<glt::Model_Obj>(glt::Model_Obj(model_path));
		parent = &e; 
		render->renderer->add(id, mesh); 
	};

	Audio_Component::Audio_Component(LC_Audio::Music& _music) : music(&_music) {};
	Audio_Component::Audio_Component(LC_Audio::Sound& _sound) : sound(&_sound) {};
	
}