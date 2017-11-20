#pragma once
#include "Figura.h"
class Pollo :
	public Figura
{
	int y0;
	float angulo, amplitud, periodo;
public:
	Pollo();
	~Pollo();
	void Mover(Graphics ^ g);
};

