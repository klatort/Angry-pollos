#pragma once
#include "Game_Manager.h"
class Juego
{
	Game_Manager ** Niveles;
	int* N_Niveles;
public:
	void Insertar_Nivel(Game_Manager * nuevo);
	Game_Manager** GetNivel();
	void Pasar_Nivel(int* Nivel);
	Juego();
	~Juego();
};

