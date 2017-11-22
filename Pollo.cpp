#include "Pollo.h"
#include <math.h>


Pollo::Pollo()
{
	dx = 0;
	dy = 0;
	y = 500;
	x = 100;
	l1 = l2 = 20;
	bounce = 1;
}


Pollo::~Pollo()
{
}


void Pollo::Mover(System::Drawing::Graphics ^ g, double angulo, double t,double distancia)
{

	if (y < 600) {
		y += (distancia/10)*(6*sin(angulo) + 0.5 * 9.81 * (t*t));
		dx = (distancia / 10)*(6 * cos(angulo));
		x += dx*bounce;
	}
	else {
		y = 600;
		dx = 0;
	}

	g->FillEllipse(gcnew System::Drawing::SolidBrush(System::Drawing::Color::Green), x, y, 20, 20);
}

void Pollo::Habilidad_Pollo()
{

}

void Pollo::Setbounce(float b) 
{
	bounce *= b;
}