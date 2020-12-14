/**
 * Copyright (C) Daniel Guerra Gallardo
 *
 * @section LICENSE MIT License (Lee el archivo LICENSE para mas información)
 *
 * @section DESCRIPTION
 * LightCube Engine, es un motor de videojuegos propio creado como propósito educacional
 *
 * @author Daniel Guerra Gallardo
 * Contact: daniel.guerra.gallardo99@gmail.com
 */

// TEST MAIN -> Recordar cambiar este proyecto a libreria en vez de ejecutable una vez finalizas las pruebas

#include <iostream>
#include <SDL.h>
#include "window.h"

using namespace std;

int main(int argc, char* argv[])
{
	// Creo un objeto de tipo ventana
	myWindow window("Test Window", 800, 600);

	// Genero el bucle de la aplicación hasta que suceda algo
	while (!window.isClosed())
	{
		window.pollEvents();
	}

	return 0;
}
