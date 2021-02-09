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


LC_Audio::Music::Music()
{
	Music::init();
}

LC_Audio::Music::Music(int _frequency, int _channels, int _chunksize)
	:frequency(_frequency), channels(_channels), chunksize(_chunksize)
{
	Music::init();
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
/// Funci�n para comenzar a reproducir 
/// </summary>
/// <param name="file"> nombre del archivo que se va a reproducir</param>
/// <param name="loop"> repetici�n constante de la m�sica (0: false, 1: true)</param>
void LC_Audio::Music::play(std::string file, int loop)
{
	std::string music_path = path + file;
	SDL_Log(music_path.c_str());

	// Se le pasa la ruta
	music = Mix_LoadMUS(music_path.c_str());

	if (not (Mix_FadeInMusic(music, loop, 4000)))
	{
		SDL_Log("No se ha podido cargar el audio");
		SDL_Log(Mix_GetError());
	}
}

/// <summary>
/// Funci�n para detener la reproduci�n de m�sica
/// </summary>
void LC_Audio::Music::stop()
{
	if (music) Mix_FreeMusic(music);
}

