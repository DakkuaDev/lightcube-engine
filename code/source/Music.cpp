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

/// <summary>
/// Constructor de la reproducci�n de m�sica 
/// </summary>
/// <param name="_frequency"> Frecuencia de sonido</param>
/// <param name="_channels"> N�mero de canales</param>
/// <param name="_chunksize"> Capacidad de chucks reservados a sonido</param>
LC_Audio::Music::Music(int _frequency, int _channels, int _chunksize)
	:frequency(_frequency),channels(_channels), chunksize(_chunksize)
{
	init();
}

/// <summary>
/// Destructor de la reproducci�n de m�sica 
/// </summary>
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
	auto music = Music::music;
	std::string music_path = path + file;

	// Se le pasa la ruta
    music = Mix_LoadMUS(music_path.c_str());

	if (!music)
	{
		SDL_Log("No se ha podido cargar el audio");
	}
	else
	{
		// Se reproduce
		Mix_PlayMusic(music, loop);
	}
}

/// <summary>
/// Funci�n para detener la reproduci�n de m�sica
/// </summary>
void LC_Audio::Music::stop()
{
	auto music = Music::music;
	if (music) Mix_FreeMusic(music);
}

