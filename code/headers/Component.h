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

#pragma once

using namespace std;

namespace LightCubeEngine
{

	class Entity;
	class Model;
	class Camera;
	class Light;

	class Component
	{

		Entity* parent;

	public:
		Component() = default;
		~Component() = default;
	};

	// TODO: Crear el resto de componentes necesarios

	// TODO: Posici�n, rotaci�n, escala con glm + devolver la matriz resultante
	class Transform_Component : public Component
	{
	};

	/// <summary>
	/// Componente de la c�mara. Su proyecci�n, POV...
	/// </summary>
	class Camera_Component : public Component
	{
		shared_ptr< Camera* > camera;

		Camera_Component() = default;
		Camera_Component(Camera* camera);
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
		Light_Component(Light* light);
		~Light_Component() = default;

		shared_ptr< Light* > get_light()
		{
			return light;
		}
	};

	/// <summary>
	/// Componente del modelo gr�fico de la entidad
	/// </summary>
	class Mesh_Component : public Component
	{
		shared_ptr< Model_Obj* > mesh;

		Mesh_Component() = default;
		Mesh_Component(Model* model);
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
