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
		y += (distancia/10)*(10*sin(angulo)*t + 0.5 * 9.81 * (t*t));
		dx = (distancia / 10)*(10 * cos(angulo)*t);
		x += dx*bounce;
	}
	if((y + (distancia / 10)*(10 * sin(angulo) + 0.5 * 9.81 * (t*t))) >600) {
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