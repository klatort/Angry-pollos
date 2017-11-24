#include "Tile.h"



void Tile::Mover()
{
	dx /= 1.3;
	x += dx;
	y += (y + l2 <= 600)? dy:0;
}

void Tile::Damage(int pdx)
{
	resistencia -= pdx;
}

void Tile::Mostrar(System::Drawing::Graphics ^g, System::Drawing::Bitmap ^bmp)
{
	g->DrawImage(bmp, x, y, l1, l2);
}

void Tile::Impulso(int pdx)
{
	if (pdx == 0)
	{
		dx = 48;
	}
	else
	dx = pdx;
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
