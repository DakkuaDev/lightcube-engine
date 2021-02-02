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

#pragma once

#include "LC_Math.h"

using namespace std;
using namespace glm;

namespace LightCubeEngine
{

	class Entity;
	class Model;
	class Camera;
	class Light;
	class Model_Obj;

	class Component
	{

		Entity* parent;

	public:
		Component() = default;
		~Component() = default;
	};

	// TODO: Crear el resto de componentes necesarios

	// TODO: Posición, rotación, escala con glm + devolver la matriz resultante
	class Transform_Component : public Component
	{
		typedef LC_Math::Vector3f vec3;

		vec3 position;
		vec3 rotation;
		vec3 scale;

	public:
		Transform_Component() = default;
		Transform_Component(vec3 pos, vec3 rot, vec3 sca);
		~Transform_Component() = default;

	public:
		glm::mat4 get_transform() const;
	};

	/// <summary>
	/// Componente de la cámara. Su proyección, POV...
	/// </summary>
	class Camera_Component : public Component
	{
		shared_ptr< Camera* > camera;

		Camera_Component() = default;
		Camera_Component(shared_ptr< Camera* > camera);
		~Camera_Component() = default;

		shared_ptr< Camera* > get_camera()
		{
			return camera;
		}
	};

	/// <summary>
	/// Componente de luz direccional. Intensidad, color...
	/// </summary>
	class Light_Component : public Component
	{
		shared_ptr< Light* > light;

		Light_Component() = default;
		Light_Component(shared_ptr< Light* > light);
		~Light_Component() = default;

		shared_ptr< Light* > get_light()
		{
			return light;
		}
	};

	/// <summary>
	/// Componente del modelo gráfico de la entidad
	/// </summary>
	class Mesh_Component : public Component
	{
		shared_ptr< Model_Obj* > mesh;

		Mesh_Component() = default;
		Mesh_Component(shared_ptr< Model_Obj* > model);
		~Mesh_Component() = default;

		shared_ptr< Model_Obj* > get_mesh()
		{
			return mesh;
		}
	};

	// TODO
	class Audio_Component : public Component
	{

	};
}
