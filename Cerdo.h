#pragma once
#include "Figura.h"
class Cerdo:
	public Figura
{
	int resistencia;
public:
	void Mover();
	virtual void Mostrar(System::Drawing::Graphics ^g, System::Drawing::Bitmap ^bmp);
	void Impulso(int pdx, int d);
	void Damage(int pdx);
	void Gravedad(int pdy);
	Cerdo(int px, int py, int pl1, int pl2);
	Cerdo();
	~Cerdo();
};

