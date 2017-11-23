#include "Figura.h"

using namespace System;

Figura::Figura()
{
	Vivo = true;
}

Figura::Figura(int px, int py)
{
	x = px;
	y = py;
	Vivo = true;
	fila = columna = 0;
}

int Figura::getL1()
{
	return l1;
}

int Figura::getL2()
{
	return l2;
}

Figura::~Figura()
{
}

int Figura::getx()
{
	return x;
}

int Figura::gety()
{
	return y;
}

void Figura::setVivo(bool muerte)
{
	Vivo = muerte;
}

void Figura::Mover(Graphics ^ g)
{
}

void Figura::Mostrar(Graphics ^ g)
{
}
int Figura::getd()
{
	return d;
}
