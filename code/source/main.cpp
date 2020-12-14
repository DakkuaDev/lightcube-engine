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

// Include de Librerias
#include <iostream>
#include <SDL.h>

// Include del Engine
#include "Window.h"
#include "String.hpp"
#include "Vector.hpp"

using namespace std;


int main(int argc, char* argv[])
{
	// Creo un objeto de tipo string
	String x{ "Hello World!" };

	// Lo leo por pantalla iterándolo
	// TODO: Preguntar a angel si se puede sobrecargar el operador <<

	if (x)
	{
		for (auto c : x) cout << c;
	}
	
	// Creo un objeto de tipo vector

	Vector y{ 1, 1, 1 };
	 cout << "\n" << y << endl;

	// Creo un objeto de tipo ventana
	myWindow window("Test Window", 800, 600);

	// Genero el bucle de la aplicación hasta que suceda algo
	while (!window.isClosed())
	{
		window.pollEvents();
	}

	return 0;
}
