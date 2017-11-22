#include "Resortera.h"
#include <math.h>


Resortera::Resortera()
{
	x = 100;
	y = 500;
	angulo = 0.0;
	distancia = 0.0;
}


double Resortera::Calcular_Angulo(double px, double py)
{
	angulo = System::Math::PI +atan2(py - y, px - x);
	return (angulo);
}

double Resortera::Calcular_Distancia(double px, double py)
{
	distancia = sqrt(pow(px - (x+10), 2) + pow(py - (y+5), 2));
	if (distancia >= 121)
		distancia = 121;
	return distancia;
}

Resortera::~Resortera()
{
}
void Resortera::Mostrar_resortera(Graphics ^g)
{
	Pen ^p = gcnew Pen(Color::Green);
	g->DrawRectangle(p, x, y, 20, 80);
	Brush ^b = gcnew SolidBrush(Color::Brown);
	g->FillRectangle(b, x, y, 20, 80);
	//Cambiar esto por Bitmap
}
void Resortera::Mostrar_liga(Graphics ^g, int px, int py)
{
	System::Drawing::Pen^p = gcnew System::Drawing::Pen(System::Drawing::Color::Crimson,6);
	g->DrawLine(p,x, y + 5, px, py);
	g->DrawLine(p, x + 20, y + 5, px, py);
}
