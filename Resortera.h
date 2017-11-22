#pragma once

using namespace System::Drawing;
class Resortera
{
	int x, y;
	double angulo, distancia;
public:
	double Calcular_Distancia(double px, double py);
	void Mostrar_resortera(Graphics ^g);
	void Mostrar_liga(Graphics ^g, int px, int py);
	double Calcular_Angulo(double px, double py);
	Resortera();
	~Resortera();
};

