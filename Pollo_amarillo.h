#pragma once
#include "Pollo.h"
class Pollo_amarillo :
	public Pollo
{
public:
	Pollo_amarillo(int px, int py);
	~Pollo_amarillo();
	void Habilidad_Pollo(int i);
};

