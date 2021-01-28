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

	class Component
	{

		Entity* parent;

	public:
		Component() = default;
		~Component() = default;
	};

	// TODO: Crear clases hijas: Mayas, C�mara, Luz (par Render)...

	class Transform_Component : public Component
	{
		// TODO: posici�n, rotaci�n, escala + devolver la matriz resultante
	};

	class Camera_Component : public Component
	{
		// TODO: proyecci�n...
	};

	class Light_Component : public Component
	{
		// TODO: intensidad, color...
	};

	class Mesh_Component : public Component
	{

	};

	class Audio_Component : public Component
	{

	};
}
