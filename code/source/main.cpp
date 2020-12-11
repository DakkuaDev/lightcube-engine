/**
 * Copyright (C) Daniel Guerra Gallardo
 *
 * @section LICENSE MIT License (see LICENSE file for more information)
 * 
 * @section DESCRIPTION
 * This is LightCube Engine, a personal game engine for education purpouses.
 * 
 * @author Daniel Guerra Gallardo
 * Contact: daniel.guerra.gallardo99@gmail.com
 *
 */

//#include <SDL.h>
#include <gtest/gtest.h>

int main()
{
	return 0;
}

/// <summary>
/// Google Test Library overview experiments to test out
/// </summary>
namespace myTest
{

	int sum(int n)
	{
		auto result = n + 5;

		return result;
	}

	TEST(BasicTest, SubTest1)
	{
		ASSERT_TRUE(1 == 2);
	}
	
	TEST(ExperimentTest, SumComprobation)
	{
		EXPECT_EQ(sum(5), 10);
	}

}