#pragma once
#include "Cerdo.h"
#include "Tile.h"
#include "Pollo.h"
#include "Resortera.h"
class Game_Manager
{
	Cerdo** C;
	Tile ** T;
	Pollo** bolita;
	Resortera *resortera;
	int *N_Tiles;
	int	*N_Pollos;
	int *N_Cerdos;
public:

	Game_Manager();
	~Game_Manager();
	void KillEnemy();
	void Pollo_desaparece(System::Drawing::Graphics ^ g);
	void Mover_pollos(System::Drawing::Graphics ^ g, double angulo, double t,double distancia);
	bool Colision(Figura* a, Figura* b);
	void CheckColision();
	void CheckColisionC();
	void CheckImpact();
	void Insertar_Cerdos(Cerdo * nuevo);
	void Insertar_Tile(Tile* nuevo);
	void Insertar_Pollo(Pollo * nuevo);
	void Eliminar_Cerdo(int pos);
	void Eliminar_Tile(int pos);
	void Eliminar_Pollo(int pos);
	void Eliminar_test();
	double Calcular_angulo(double px, double py);
	double Calcular_distancia(double px, double py);
	int getN_Pollos();
	void Mostrar_resortera(Graphics ^g);
};

