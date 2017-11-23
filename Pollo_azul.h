#pragma once
#include "Pollo.h"
class Pollo_azul :
	public Pollo
{
public:
	Pollo_azul(int px, int py);
	Pollo_azul(int px, int py,int dir, double angulo);
	~Pollo_azul();
	void Habilidad_Pollo(int i);
};

