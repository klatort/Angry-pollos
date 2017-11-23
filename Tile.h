#pragma once
#include "Figura.h"
class Tile:
	public Figura
{
	int resistencia;
public:
	void Mover(Graphics ^g);
	void Mostrar(Graphics ^g);
	void Impulso(int pdx);
	void Damage(int pdx);
	void Gravedad(int pdy);
	Tile();
	Tile(int px,int py,int pl1,int pl2);
	~Tile();
};

