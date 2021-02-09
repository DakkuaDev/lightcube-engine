/*
* * Copyright(C) Daniel Guerra Gallardo
*
* @section LICENSE MIT License(Lee el archivo LICENSE para mas información)
*
* @section DESCRIPTION
* La clase base Componente, es de la que heredan el conjunto de componentes individuales que puede llevar asociado una entidad.
*
* @author Daniel Guerra Gallardo
* Contact: daniel.guerra.gallardo99@gmail.com
*/

#pragma once

#include <memory>

#include <Camera.hpp>
#include <Light.hpp>
#include <Model.hpp>
#include <Model_Obj.hpp>

#include "LC_Math.h"
#include "LC_Audio.h"

using namespace std;
using namespace glm;
using namespace glt;
using namespace LC_Math;

namespace LightCubeEngine
{

	class Entity;

	class Model;
	class Model_Obj;
	class Camera;
	class Light;
	class Render_System; 

	class Component
	{
	protected:
		Entity* parent;

	public:
		Component() = default;
		Component(Entity& p); 
		~Component() = default;
	};

	/// <summary>
	/// Componente de la matriz de transformación (pósición, rotación y escala) asociada a la entidad
	/// </summary>
	class Transform_Component : public Component
	{
		glm::vec3 position;
		glm::vec3 rotation;
		glm::vec3 scale;

		float rot_angle;

	public:
		Transform_Component() = default;
		Transform_Component(glm::vec3 pos, glm::vec3 rot, float rot_angle, glm::vec3 sca);
		~Transform_Component() = default;

	public:
		glm::mat4 get_matrix() const;
		glm::mat4 attached_to(std::shared_ptr< Entity >& parent_entity);
		glm::vec4 get_transform_vector() const;

		void set_position(glm::vec3 new_position);
		void translate(glm::vec3 coord);
		
		void rotate(float angle);

		void set_scale(glm::vec3 new_scale);

		glm::vec3 get_position();
		glm::vec3 get_rotation();
		glm::vec3 get_scale();
	};

	/// <summary>
	/// Componente de la cámara. Su proyección, POV...
	/// </summary>
	class Camera_Component : public Component
	{
		shared_ptr< glt::Camera > camera;

	public:
		Camera_Component() = default;
		Camera_Component(shared_ptr< glt::Camera > camera);
		~Camera_Component() = default;

	public:
		shared_ptr< glt::Camera > get_camera()
		{
			return camera;
		}
	};

	/// <summary>
	/// Componente de luz direccional. Intensidad, color...
	/// </summary>
	class Light_Component : public Component
	{
		shared_ptr< glt::Light > light;

	public:
		Light_Component() = default;
		Light_Component(shared_ptr< glt::Light > light);
		~Light_Component() = default;

	public:
		shared_ptr< glt::Light > get_light()
		{
			return light;
		}
	};

	/// <summary>
	/// Componente del modelo gráfico de la entidad
	/// </summary>
	class Mesh_Component : public Component
	{
		shared_ptr< glt::Model_Obj > mesh;
		typedef std::string id;

	public:
		Mesh_Component() = default;
		Mesh_Component(id, std::string model_path, Entity& e, Render_System *render);
		~Mesh_Component() = default;

	public:
		shared_ptr< glt::Model_Obj > &get_mesh()
		{
			return mesh;
		}
	};

	/// <summary>
	/// Componente de sonido de la entidad
	/// </summary>
	class Audio_Component : public Component
	{
		shared_ptr<LC_Audio::Sound> sound;

	public:
		Audio_Component(std::string file);
		~Audio_Component() = default;

	public:
		void play_sound(int loop);
		void set_volume(int channel, int volume);
	};
}
