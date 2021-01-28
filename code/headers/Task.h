/*
* * Copyright(C) Daniel Guerra Gallardo
*
* @section LICENSE MIT License(Lee el archivo LICENSE para mas informaci�n)
*
* @section DESCRIPTION
* Clase base. Recopila el conjunto de tareas individuales que realizan operaciones dentro del bucle del motor.
*
* @author Daniel Guerra Gallardo
* Contact: daniel.guerra.gallardo99@gmail.com
*/

#pragma once

using namespace std;

namespace LightCubeEngine
{
	class Scene;

	class Task
	{
		// ORDEN DEL CICLO DE LECTURA: Inputs -> Update -> Render (Al cargar la escena en el archivo ya condicionamos esto cargando las tareas necesarias)
		int priotiry;

	protected:
		Scene* scene;

	public:
		Task() = default;
		~Task() = default;

	public:
		virtual void run() = 0;
	};
}
