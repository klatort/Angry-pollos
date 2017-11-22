#pragma once
#include "Figura.h"
class Pollo :
	public Figura
{
	double dy;
	float bounce;
public:
	Pollo(int px, int py);
	~Pollo();
	void Mover(double angulo,double t,double distancia);
	virtual void Habilidad_Pollo();
	virtual void Mostrar_pollo(System::Drawing::Graphics ^g, System::Drawing::Bitmap ^bmp);
	void Mostrar_pollo_resortera(int px, int py);
	void Setbounce(float b);
};

