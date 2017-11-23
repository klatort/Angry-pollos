#include "Tile.h"



void Tile::Mover(Graphics ^g)
{
	x += dx;
	y += (y + l2 <= 590)? dy:0;
	Mostrar(g);
}

void Tile::Damage(int pdx)
{
	resistencia -= pdx;
}

void Tile::Mostrar(Graphics ^g)
{
	Pen ^p = gcnew Pen(Color::Green);
	g->DrawRectangle(p, x, y, l1, l2);
	Brush ^b = resistencia >= 10? gcnew SolidBrush(Color::Orange): gcnew SolidBrush(Color::Red);
	g->FillRectangle(b, x, y, l1, l2);
	//Cambiar esto por Bitmap
}

void Tile::Impulso(int pdx)
{
	dx = pdx/2;
}

void Tile::Gravedad(int pdy)
{
	dy = pdy;
}


Tile::Tile()
{

}

Tile::Tile(int px, int py, int pl1, int pl2):Figura(px,py)
{
	dx = 0;
	dy = 10;
	l1 = pl1;
	l2 = pl2;
	resistencia = 10;
}


Tile::~Tile()
{
}
