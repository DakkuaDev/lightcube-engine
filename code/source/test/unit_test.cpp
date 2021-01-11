/**
 * Copyright (C) Daniel Guerra Gallardo
 *
 * @section LICENSE MIT License (Lee el archivo LICENSE para mas informaci�n)
 *
 * @section DESCRIPTION
 *Aplicaci�n de Test usando la librer�a de Google Test para ver que LighCube Engine funciona correctamente
 *
 * @author Daniel Guerra Gallardo
 * Contact: daniel.guerra.gallardo99@gmail.com
 */

#include <gtest/gtest.h>
#include <ObjectPool.h>
#include <Windows.h>

TEST(initialTest, subTest)
{
	ASSERT_TRUE(1 == 1);

  //  ASSERT_NO_FATAL_FAILURE(
		//// Creo un objeto de tipo ventana
		//	myWindow window("Test Window", 800, 600);

		//// Genero el bucle de la aplicaci�n hasta que suceda algo
		//while (!window.isClosed())
		//{
		//	window.pollEvents();
		//}
  //  )
    
}

int main(int argument_count, char* arguments[])
{
    testing::InitGoogleTest(&argument_count, arguments);

    return RUN_ALL_TESTS();
}
