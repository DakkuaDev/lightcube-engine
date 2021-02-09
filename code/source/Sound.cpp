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
#include <SDL.h>
#include <SDL_mixer.h>
#include "LC_Audio.h"

using namespace LC_Audio;
using namespace std;

LC_Audio::Sound::Sound(std::string _file)
{
	init();

	if (!load_sound(_file))
	{
		SDL_Log("No se ha podido inicializar el objeto de sonido");
	}
}

LC_Audio::Sound::Sound(std::string _file, int _frequency, int _channels, int _chunksize)
	:frequency(_frequency), channels(_channels), chunksize(_chunksize)
{
	init();

	if (!load_sound(_file))
	{
		SDL_Log("No se ha podido inicializar el objeto de sonido");
	}
}


LC_Audio::Sound::~Sound()
{
	Mix_CloseAudio();
}

/// <summary>
/// Inicializaci�n de la reproducci�n de sonidos
/// </summary>
void LC_Audio::Sound::init()
{
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
/// Funci�n de carga de archivo de sonido
/// </summary>
/// <param name="file"> archivo a cargar </param>
/// <returns> booleano si se pudo completar o no la carga </returns>
bool LC_Audio::Sound::load_sound(std::string file)
{
	std::string sound_path = path + file;
	sound = Mix_LoadWAV(sound_path.c_str());

	if (sound != nullptr) return true;

	return false;
}

/// <summary>
/// Funci�n para comenzar a reproducir el sonido
/// </summary>
/// <param name="loop"> repetici�n constante de la m�sica (0: false, -1: true)</param>
void LC_Audio::Sound::play(int loop)
{
	if (not (Mix_PlayChannel(-1, sound, loop)))
	{
		//SDL_Log("No se ha podido cargar el audio");
		//SDL_Log(Mix_GetError());
	}	
}

/// <summary>
/// Funci�n para detener la reproduci�n 
/// </summary>
void LC_Audio::Sound::stop()
{
	if (sound) Mix_FreeChunk(sound);
}

/// <summary>
/// Funci�n para manejar el volumen de la m�sica
/// </summary>
/// <param name="volume"> nuevo volumen </param>
void LC_Audio::Sound::set_volume(int channel, int volume)
{
	Mix_Volume(channel, volume);
}