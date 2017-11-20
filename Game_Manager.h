#pragma once
#include "Tile.h"
#include "Pollo.h"
class Game_Manager
{
	Tile ** T;
	int *N_Tiles;
public:
	Pollo* bolita;
	Game_Manager();
	~Game_Manager();
	bool Colision(Figura* a, Figura* b);
	void CheckColision();
	void CheckImpact();
	void Insertar_Tile(Tile* nuevo);
	void Eliminar(int pos);
};

