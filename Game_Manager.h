#pragma once
#include "Tile.h"
#include "Pollo.h"
class Game_Manager
{
	Tile ** T;
	int *N_Tiles;
	int	*N_Pollos;
	Pollo** bolita;
public:

	Game_Manager();
	~Game_Manager();
	void Pollo_desaparece(System::Drawing::Graphics ^ g);
	void Mover_pollos(System::Drawing::Graphics ^ g);
	bool Colision(Figura* a, Figura* b);
	void CheckColision();
	void CheckImpact();
	void Insertar_Tile(Tile* nuevo);
	void Insertar_Pollo(Pollo * nuevo);
	void Eliminar_Tile(int pos);
	void Eliminar_Pollo(int pos);
};

