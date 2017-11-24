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
	return angulo;
}

double Resortera::Calcular_Distancia(double px, double py)
{
	distancia = sqrt(pow(px - (x + 10), 2) + pow(py - (y + 5), 2));
	if (distancia >= 121)
		distancia = 121;
	return distancia;
}

Resortera::~Resortera()
{
}
void Resortera::Mostrar_resortera(System::Drawing::Graphics ^g, System::Drawing::Bitmap ^bmp)
{
		g->DrawImage(bmp, x, y, 60, 108);
}

void Resortera::Mostrar_liga(Graphics ^ g, int px, int py)
{
	System::Drawing::Pen^p = gcnew System::Drawing::Pen(System::Drawing::Color::DarkRed, 6);
	g->DrawLine(p, x, y + 25, px, py);
	g->DrawLine(p, x + 52, y + 25, px, py);
}
void Resortera::Mostrar_angulo(Graphics ^g)
{
	Pen ^p = gcnew Pen(Color::Yellow);
	Drawing2D::GraphicsPath^path = gcnew Drawing2D::GraphicsPath();
	g->DrawPath(p, path);//(distancia / 20)*(10 * sin(angulo)*10 + 0.5 * 9.81 * (10*10));
}
