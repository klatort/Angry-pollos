#pragma once
#include "Figura.h"
class Pollo :
	public Figura
{

public:
	double dy;
	bool habilidad;
	float bounce;
	Pollo(int px, int py);
	~Pollo();
	double angulo;
	void Mover(double t,double distancia);
	void Nuevo_angulo(double t, double distancia);
	virtual void Habilidad_Pollo(int i);
	virtual void Mostrar_pollo(System::Drawing::Graphics ^g, System::Drawing::Bitmap ^bmp);
	void Mostrar_pollo_resortera(int px, int py);
	void Setbounce(float b);
	void SetpolloAngulo(double angulo);
};

