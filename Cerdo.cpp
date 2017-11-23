#include "Cerdo.h"



void Cerdo::Mostrar(Graphics ^ g)
{
	Pen ^p = gcnew Pen(Color:: Blue);
	g->DrawEllipse(p, x, y, l1, l2);
	Brush ^b = resistencia >= 5 ? gcnew SolidBrush(Color::Green) : gcnew SolidBrush(Color::Red);
	g->FillEllipse(b, x, y, l1, l2);
}

void Cerdo::Mover(Graphics ^ g)
{
	x += dx;
	y += (y + l2 <= 590)? dy:0;
	Mostrar(g);
}

void Cerdo::Impulso(int pdx)
{
	dx = pdx / 4;
}

void Cerdo::Damage(int pdx)
{
	resistencia -= pdx;
}

void Cerdo::Gravedad(int pdy)
{
	dy = pdy;
}

Cerdo::Cerdo(int px, int py, int pl1, int pl2) :Figura(px ,py)
{
	dx = 0;
	dy = 10;
	l1 = pl1;
	l2 = pl2;
	resistencia = 5;
}

Cerdo::Cerdo()
{
}


Cerdo::~Cerdo()
{
}
