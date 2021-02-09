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
		
		glm::mat4 transform_matrix = rotate_matrix;

		return transform_matrix;
	}

	/// <summary>
	/// Jerarquia de escena (atachea una entidad padre a una hija)
	/// </summary>
	/// <param name="parent_entity"></param>
	/// <returns></returns>
	glm::mat4 Transform_Component::attached_to(std::shared_ptr< Entity >& parent_entity)
	{
		parent = parent_entity.get();

		return parent->get_transform()->get_matrix() * this->get_matrix();
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
	/// Rota sobe 'y' la entidad
	/// </summary>
	/// <param name="angle"> ángulo de rotación </param>
	void Transform_Component::rotate(float angle)
	{
		rot_angle += angle;
	}

	/// <summary>
	/// Fija una nueva escala a la entidad
	/// </summary>
	/// <param name="new_scale"> vector escala </param>
	void Transform_Component::set_scale(glm::vec3 new_scale)
	{
		scale = new_scale;
	}

	/// <summary>
	/// Devuelve el vector position
	/// </summary>
	/// <returns> vector posición </returns>
	glm::vec3 Transform_Component::get_position()
	{
		return position;
	}

	/// <summary>
	/// Devuelve el vector rotación
	/// </summary>
	/// <returns> vector rotación </returns>
	glm::vec3 Transform_Component::get_rotation()
	{
		return rotation;
	}

	/// <summary>
	/// Devuelve el vector escala
	/// </summary>
	/// <returns> vector escala </returns>
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


	Audio_Component::Audio_Component(std::string _file)
	{
		sound.reset(new LC_Audio::Sound(_file));
	}

	/// <summary>
	/// Reproduce un sonido
	/// </summary>
	/// <param name="loop"> loopeo del sonido (-1) sin loopeo (0) </param>
	void Audio_Component::play_sound(int loop)
	{
		sound->play(loop);
	}

	/// <summary>
	/// Cambia el volumen de la pista de reproducción
	/// </summary>
	/// <param name="channel"> canal seleccionado </param>
	/// <param name="volume"> nuevo volumen </param>
	void Audio_Component::set_volume(int channel, int volume)
	{
		sound->set_volume(channel, volume);
	}
	
}