#pragma once
#include "Figura.h"
class Cerdo:
	public Figura
{
	int resistencia;
public:
	void Mover(Graphics ^g);
	void Mostrar(Graphics ^g);
	void Impulso(int pdx);
	void Damage(int pdx);
	void Gravedad(int pdy);
	Cerdo(int px, int py, int pl1, int pl2);
	Cerdo();
	~Cerdo();
};

