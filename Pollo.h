#pragma once
#include "Figura.h"
class Pollo :
	public Figura
{
	double dy;
	float bounce;
public:
	Pollo();
	~Pollo();
	void Mover(Graphics ^ g, double angulo,double t,double distancia);
	virtual void Habilidad_Pollo();
	void Setbounce(float b);
};

