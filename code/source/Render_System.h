/*
* * Copyright(C) Daniel Guerra Gallardo
*
* @section LICENSE MIT License(Lee el archivo LICENSE para mas información)
*
* @section DESCRIPTION
* Especialización de Task. Encargada de renderizar los gráficos por la ventana.
*
* @author Daniel Guerra Gallardo
* Contact: daniel.guerra.gallardo99@gmail.com
*/


#include <Render_Node.hpp>
#include "Task.h"

using namespace glt;
using namespace std;

namespace LightCubeEngine
{
	class Render_System : public Task
	{
	private:
		std::unique_ptr< glt::Render_Node > renderer;
	public:
		void run() override
		{
			// TODO: Añadier clase Scene y desde ahí llamar a clear() y swap_buffers()
			renderer.reset(new Render_Node);
			renderer->render();
		}
	};
}

