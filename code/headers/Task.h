/*
* * Copyright(C) Daniel Guerra Gallardo
*
* @section LICENSE MIT License(Lee el archivo LICENSE para mas información)
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
	class Render_Node;

	/// <summary>
	/// Clase base de tareas
	/// </summary>
	class Task
	{

		// Considerar si quiero añadir prioridad a las tareas o añadirlas por XML ya en orden. Tambiñen podríamos llamar a las tareas en orden y ya.

	protected:
		Scene* scene;

	public:
		Task() = default;
		~Task() = default;

	public:
		virtual void initialize() {};
		virtual void finalize() {};
		virtual void run() = 0;
	};

	///// <summary>
	///// Sistema encargado del renderizado de la escena
	///// </summary>
	//class Render_System : public Task
	//{
	//	std::unique_ptr< glt::Render_Node > renderer;

	//public:
	//	Render_System() = default;
	//	~Render_System() = default;

	//public:
	//	void run();
	//};
}

