#pragma once
#include "Pollo.h"


class Resortera
{
	Pollo * lepollo;
	int x, y;
	double angulo, distancia;
public:
	double Calcular_Distancia(double px, double py);
	void Mostrar_resortera(Graphics ^g);
	double Calcular_Angulo(double px, double py);
	Resortera();
	~Resortera();
};

