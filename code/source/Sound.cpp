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
#include <SDL.h>
#include <SDL_mixer.h>
#include "LC_Audio.h"

using namespace LC_Audio;
using namespace std;

LC_Audio::Sound::Sound()
{
	Sound::init();
}

LC_Audio::Sound::Sound(int _frequency, int _channels, int _chunksize)
	:frequency(_frequency), channels(_channels), chunksize(_chunksize)
{
	Sound::init();
}


LC_Audio::Sound::~Sound()
{
	Mix_CloseAudio();
}

/// <summary>
/// Inicialización de la reproducción de sonidos
/// </summary>
void LC_Audio::Sound::init()
{

	// Inicializo SDL_Mixer
	if (SDL_Init(SDL_INIT_AUDIO) != 0)
	{
		SDL_Log("SDL Mixer no se ha iniciado correctamente");
	}

	// Inicializo SDL_Mixer
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
/// Función para comenzar a reproducir 
/// </summary>
/// <param name="file"> nombre del archivo que se va a reproducir</param>
/// <param name="loop"> repetición constante de la música (0: false, 1: true)</param>
void LC_Audio::Sound::play(std::string file, int loop)
{
	std::string sound_path = path + file;

	// Se le pasa la ruta
	sound = Mix_LoadWAV(sound_path.c_str());

	if (not (Mix_PlayChannel(-1, sound, loop)))
	{
		SDL_Log("No se ha podido cargar el audio");
		SDL_Log(Mix_GetError());
	}	
}

/// <summary>
/// Función para detener la reprodución 
/// </summary>
void LC_Audio::Sound::stop()
{
	if (sound) Mix_FreeChunk(sound);
}