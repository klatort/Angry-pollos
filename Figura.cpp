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

void Figura::Death()
{
	Vivo = false;
}

void Figura::Mover(Graphics ^ g)
{
}

void Figura::Mostrar(Graphics ^ g)
{
}
