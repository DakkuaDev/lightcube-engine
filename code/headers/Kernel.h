/*
* * Copyright(C) Daniel Guerra Gallardo
*
* @section LICENSE MIT License(Lee el archivo LICENSE para mas información)
*
* @section DESCRIPTION
* El Kernel es la clase del bucle principal del engine para cada escena. Contiene a las tareas que ejecutará de forma constante.
*
* @author Daniel Guerra Gallardo
* Contact: daniel.guerra.gallardo99@gmail.com
*/

#pragma once

#include <iostream>
#include <chrono>
#include <set>
#include <list>

#include "LC_Utils.h"

using namespace std;
using namespace LC_Utils;

namespace LightCubeEngine
{
	class Task;

	class Kernel
	{
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
		void run();
		void stop();

		void add_task(Task* task);
	};
}
