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
	void Mover();
	void Mostrar_pollo(System::Drawing::Graphics ^ g, System::Drawing::Bitmap ^bmp);
};

