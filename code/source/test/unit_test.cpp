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


// Test Unitarios
#include <gtest/gtest.h>


TEST(initialTest, subTest)
{
	ASSERT_TRUE(1 == 1);
   
}

int main(int argument_count, char* arguments[])
{
    testing::InitGoogleTest(&argument_count, arguments);

    return RUN_ALL_TESTS();
}
