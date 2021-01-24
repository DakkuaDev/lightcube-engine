/**
 * Copyright (C) Daniel Guerra Gallardo
 *
 * @section LICENSE MIT License (Lee el archivo LICENSE para mas información)
 *
 * @section DESCRIPTION
 * Módulo de música y sonido (mixer) de LightCube Engine
 *
 * @author Daniel Guerra Gallardo
 * Contact: daniel.guerra.gallardo99@gmail.com
 */

#pragma once

#include "internal/declarations.h"

using namespace std;

namespace LC_Audio
{
	class Music
	{
	private:

		Mix_Music* music = nullptr;

		std::string path = "../../../lightcube-engine/resources/";

		std::string title = "";
		const int frequency = 22050;
		int channels = 2;
		const int chunksize = 4096;

	public:
		Music() = default;
		Music(int frequency, int channels, int chunksize);
		~Music();

	public:
		void play(std::string file, int loop);
		void stop();
		void set_volume();

	private:
		void init();
	};

	class Sound
	{
		Mix_Chunk* sound = nullptr;

		std::string path = "../../../lightcube-engine/resources/";

		std::string title = "";
		const int frequency = 22050;
		int channels = 2;
		const int chunksize = 4096;
	public:
		Sound() = default;
		Sound(int frequency, int channels, int chunksize);
		~Sound();

	public:
		void play(std::string file, int loop);
		void stop();
		void set_volume();

	private:
		void init();
	};
}