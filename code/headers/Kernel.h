/*
* * Copyright(C) Daniel Guerra Gallardo
*
* @section LICENSE MIT License(Lee el archivo LICENSE para mas información)
*
* @section DESCRIPTION
* Clase principal encargada de ejecutar las diferentes especializaciones de Task. Bucle principal del engine.
*
* @author Daniel Guerra Gallardo
* Contact: daniel.guerra.gallardo99@gmail.com
*/

#pragma once

#include <iostream>
#include <chrono>
#include <set>
#include <list>

using namespace std;

namespace LightCubeEngine
{
	class Task;

	class Kernel
	{
		Task* task;

		bool stopped;
		float delta;
		list< Task* > tasks;

	public:
		Kernel() = default;
		~Kernel() = default;

	public:
		// TODO: Crear estados (ciclo de vida): Inicialización (cargado de datos) , running, 
		// pausado (la aplicación pasa a un segundo plano) , detener (guardado de datos importantes) y finalización
		// Puede ser interesante guardar punteros a objetos con std:fuction para hacer callbacks a los estados del ciclo de vida
		void run() noexcept;
		void stop();
		void add_task(Task* task);
	};
}
