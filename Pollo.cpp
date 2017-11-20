#include "Pollo.h"



Pollo::Pollo()
{
	tag = 1;
	dx = 25;
	y = 0;
	x = 0;
	y0 = 500;
	amplitud = 600;
	angulo = 180;
	periodo = 1;
	l1 = l2 = 20;
}


Pollo::~Pollo()
{
}

void Pollo::Mover(System::Drawing::Graphics ^ g)
{
	if (amplitud > 1)
	{
		x += dx;
		double anguloenradianes = System::Math::PI *angulo / 180;
		y = y0 - amplitud * (System::Math::Sin(anguloenradianes * periodo));
		angulo += 5;
		if (angulo > 180 / periodo)
		{
			angulo = 0;
			amplitud = amplitud*0.20;
		}
	}
	else
		y = y0;

	g->FillEllipse(gcnew System::Drawing::SolidBrush(System::Drawing::Color::Green), x, y, 20, 20);
}
