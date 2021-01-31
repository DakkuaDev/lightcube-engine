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

	// TODO: Posición, rotación, escala con glm + devolver la matriz resultante
	class Transform_Component : public Component
	{
	};

	/// <summary>
	/// Componente de la cámara. Su proyección, POV...
	/// </summary>
	class Camera_Component : public Component
	{
		Camera* camera;

		Camera_Component() = default;
		Camera_Component(Camera* camera);
		~Camera_Component() = default;

		Camera* get_camera()
		{
			return camera;
		}
	};

	/// <summary>
	/// Componente de luz direccional. Intensidad, color...
	/// </summary>
	class Light_Component : public Component
	{
		Light* light;

		Light_Component() = default;
		Light_Component(Light* light);
		~Light_Component() = default;

		Light* get_light()
		{
			return light;
		}
	};

	/// <summary>
	/// Componente del modelo gráfico de la entidad
	/// </summary>
	class Mesh_Component : public Component
	{
		Model* mesh;

		Mesh_Component() = default;
		Mesh_Component(Model* model);
		~Mesh_Component() = default;

		Model* get_mesh()
		{
			return mesh;
		}
	};

	// TODO
	class Audio_Component : public Component
	{

	};
}
