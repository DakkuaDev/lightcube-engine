/**
 * Copyright (C) Daniel Guerra Gallardo
 *
 * @section LICENSE MIT License (Lee el archivo LICENSE para mas información)
 *
 * @section DESCRIPTION
 * LightCube Engine, es un motor de videojuegos propio programado en C++ y creado con propósito educacional
 *
 * @author Daniel Guerra Gallardo
 * Contact: daniel.guerra.gallardo99@gmail.com
 */

#include <iostream>
#include <cstdlib>
#include <SDL.h>
#include <SDL_mixer.h>
#include "LC_Audio.h"

using namespace LC_Audio;
using namespace std;


LC_Audio::Music::Music(std::string _file)
{
	init();

	if (!load_music(_file))
	{
		SDL_Log("No se ha podido inicializar el objeto de sonido");
	}
}

LC_Audio::Music::Music(std::string _file, int _frequency, int _channels, int _chunksize)
	:frequency(_frequency), channels(_channels), chunksize(_chunksize)
{
	init();

	if (!load_music(_file))
	{
		SDL_Log("No se ha podido inicializar el objeto de sonido");
	}
}


LC_Audio::Music::~Music()
{
	Mix_CloseAudio();
}

/// <summary>
/// Inicialización de la reproducción de musica
/// </summary>
void LC_Audio::Music::init()
{
	// Inicializo SDL_mixer
	if (SDL_Init(SDL_INIT_AUDIO) != 0)
	{
		SDL_Log("SDL Mixer no se ha iniciado correctamente");
	}
	else
	{
		// Creamos el sub-sistema de audio
		if (Mix_OpenAudio(frequency, MIX_DEFAULT_FORMAT, channels, chunksize) < 0)
		{
			SDL_Log("No se ha podido crear el sub-sistema de audio");
		}
	}
}

/// <summary>
/// Función de carga de archivo de música
/// </summary>
/// <param name="file"> archivo a cargar </param>
/// <returns> booleano si se pudo completar o no la carga </returns>
bool LC_Audio::Music::load_music(std::string file)
{
	std::string music_path = path + file;

	music = Mix_LoadMUS(music_path.c_str());

	if (music != nullptr) return true;
	
	return false;
}

/// <summary>
/// Función de reprodución
/// </summary>
/// <param name="loop"> parámetro para determinar si se loopea o no </param>
void LC_Audio::Music::play(int loop)
{
	if (not (Mix_FadeInMusic(music, loop, 5000)))
	{
		//SDL_Log("No se ha podido cargar el audio");
		//SDL_Log(Mix_GetError());
	}
}

/// <summary>
/// Función para detener la reprodución de música
/// </summary>
void LC_Audio::Music::stop()
{
	if (music) Mix_FreeMusic(music);
}

/// <summary>
/// Función para manejar el volumen de la música
/// </summary>
/// <param name="volume"> nuevo volumen </param>
void LC_Audio::Music::set_volume(int volume)
{
	Mix_VolumeMusic(volume);
}

