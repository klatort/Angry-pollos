#pragma once
#include "Cerdo.h"
#include "Tile.h"
#include "Pollo_amarillo.h"
#include "Pollo_azul.h"
#include "Pollo_rojo.h"
#include "Pollo.h"
#include "Resortera.h"
#include "Cerdo_casco.h"
#include "Cerdo_desnudo.h"
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
	void Mostrar_fondo(Graphics ^g ,Bitmap ^bmp);
	void KillEnemy();
	void Mover_Tiles();
	void Mover_Cerdos();
	void Mostrar_Tiles(Graphics ^g ,Bitmap ^bmp1,Bitmap^bmp2,Bitmap ^bmp3);
	void Mostrar_Cerdos(Graphics ^g ,Bitmap ^bmp1,Bitmap^bmp2);
	void Mostrar_pollos(System::Drawing::Graphics ^g, System::Drawing::Bitmap ^bmp1, System::Drawing::Bitmap ^bmp2, System::Drawing::Bitmap ^bmp3);
	bool Pollo_desaparece(System::Drawing::Graphics ^ g, int i);
	void Mover_pollos(double t, double distancia);
	bool Colision(Figura* a, Figura* b);
	void CheckColision();
	void CheckDeath();
	void NextLevel();
	void CheckColisionC();
	void CheckImpact();
	void Insertar_Cerdos(Cerdo * nuevo);
	void Insertar_Tile(Tile* nuevo);
	void Insertar_Pollo(Pollo * nuevo);
	void Eliminar_Cerdo(int pos);
	void Eliminar_Tile(int pos);
	void Eliminar_Pollo(int pos);
	void Fin_turno(int i);
	void Eliminar_test();
	double Calcular_angulo(double px, double py);
	double Calcular_distancia(double px, double py);
	double getPollody(int i);
	int getPolloy(int i);
	double getPollodx(int i);
	int getN_Pollos();
	void Mostrar_resortera(System::Drawing::Graphics ^g, System::Drawing::Bitmap ^bmp);
	void Pollo_en_resortera(int px, int py);
	void Mostrar_resortera_liga(Graphics ^g, int px, int py);
	void Habilidad_pollo();
	void Habilidad_pollo2();
	void SetpolloAngulo(double angulo);
	bool getpolloHabilidad(int i);
	bool getpolloHabilidad_ultimo();
	void Nuevo_angulo(double t, double distancia);
	void setpolloHabilidad(int i);
};

