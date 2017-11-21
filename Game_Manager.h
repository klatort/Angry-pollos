#pragma once
#include "Tile.h"
#include "Pollo.h"
#include "Resortera.h"
class Game_Manager
{
	Tile ** T;
	Resortera *resortera;
	int *N_Tiles;
	int	*N_Pollos;
	Pollo** bolita;
public:

	Game_Manager();
	~Game_Manager();
	void Pollo_desaparece(System::Drawing::Graphics ^ g);
	void Mover_pollos(System::Drawing::Graphics ^ g, double angulo, double t,double distancia);
	bool Colision(Figura* a, Figura* b);
	void CheckColision();
	void CheckImpact();
	void Insertar_Tile(Tile* nuevo);
	void Insertar_Pollo(Pollo * nuevo);
	void Eliminar_Tile(int pos);
	void Eliminar_Pollo(int pos);
	void Eliminar_test();
	double Calcular_angulo(double px, double py);
	double Calcular_distancia(double px, double py);
	int getN_Pollos();
	void Mostrar_resortera(Graphics ^g);
};

