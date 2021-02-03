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

#include <Camera.hpp>
#include <Light.hpp>
#include <Model.hpp>
#include <Model_Obj.hpp>

#include "LC_Math.h"

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

	class Component
	{
	protected:
		Entity* parent;

	public:
		Component() = default;
		~Component() = default;
	};

	// TODO: Crear el resto de componentes necesarios (control: scripting, audio)

	/// <summary>
	/// Componente de la matriz de transformación (pósición, rotación y escala) asociada a la entidad
	/// </summary>
	class Transform_Component : public Component
	{
		glm::vec3 position;
		glm::vec3 rotation;
		glm::vec3 scale;

		// TODO: Convertir a ángulo euler + gets de pos, rot y scale 
		float rot_angle;

	public:
		Transform_Component() = default;
		Transform_Component(glm::vec3 pos, glm::vec3 rot, float rot_angle, glm::vec3 sca);
		~Transform_Component() = default;

	public:
		glm::mat4 get_transform() const;
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

	public:
		Mesh_Component() = default;
		Mesh_Component(shared_ptr< glt::Model_Obj > mesh);
		~Mesh_Component() = default;

	public:
		shared_ptr< glt::Model_Obj > get_mesh()
		{
			return mesh;
		}
	};

	// TODO
	class Audio_Component : public Component
	{

	};
}
