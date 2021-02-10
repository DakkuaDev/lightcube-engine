/**
 * Copyright (C) Daniel Guerra Gallardo
 *
 * @section LICENSE MIT License (Lee el archivo LICENSE para mas informaci�n)
 *
 * @section DESCRIPTION
 * LightCube Engine, es un motor de videojuegos propio programado en C++ y creado con prop�sito educacional
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
/// Inicializaci�n de la reproducci�n de musica
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
/// Funci�n de carga de archivo de m�sica
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
/// Funci�n de reproduci�n
/// </summary>
/// <param name="loop"> par�metro para determinar si se loopea o no </param>
void LC_Audio::Music::play(int loop)
{
	if (not (Mix_FadeInMusic(music, loop, 5000)))
	{
		//SDL_Log("No se ha podido cargar el audio");
		//SDL_Log(Mix_GetError());
	}
}

/// <summary>
/// Funci�n para detener la reproduci�n de m�sica
/// </summary>
void LC_Audio::Music::stop()
{
	if (music) Mix_FreeMusic(music);
}

/// <summary>
/// Funci�n para manejar el volumen de la m�sica
/// </summary>
/// <param name="volume"> nuevo volumen </param>
void LC_Audio::Music::set_volume(int volume)
{
	Mix_VolumeMusic(volume);
}

