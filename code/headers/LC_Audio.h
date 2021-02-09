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
	/// <summary>
	/// Clase de reprodución de Música 
	/// </summary>
	class Music
	{
	private:

		Mix_Music* music = nullptr;

		std::string file;
		std::string path = "../../resources/";

		const int frequency = 22050;
		int channels = 2;
		const int chunksize = 4096;

	public:
		Music(std::string file);
		Music(std::string file, int frequency, int channels, int chunksize);
		~Music();

	public:
		bool load_music(std::string file);
		void play(int loop);
		void stop();
		void set_volume(int volume);

	private:
		void init();
	};

	/// <summary>
	/// Clase de reproducción de sonido
	/// </summary>
	class Sound
	{
		Mix_Chunk* sound = nullptr;

		std::string path = "../../resources/";

		const int frequency = 22050;
		int channels = 2;
		const int chunksize = 4096;
	public:
		Sound(std::string file);
		Sound(std::string file, int frequency, int channels, int chunksize);
		~Sound();

	public:
		bool load_sound(std::string file);
		void play(int loop);
		void stop();
		void set_volume(int channel, int volume);

	private:
		void init();
	};
}