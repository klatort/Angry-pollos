#include "Cerdo.h"



void Cerdo::Mostrar(System::Drawing::Graphics ^g, System::Drawing::Bitmap ^bmp)
{
	int ancho_sprite = bmp->Width / 2;
	int alto_sprite = bmp->Height / 2;


	if (d == 1)
	{
		fila = 1;
		columna++;
		if (columna <= 4) {
			System::Drawing::Rectangle cut = System::Drawing::Rectangle(0 * ancho_sprite, (fila*alto_sprite), ancho_sprite, alto_sprite);
			g->DrawImage(bmp, x, y, cut, System::Drawing::GraphicsUnit::Pixel);

		}
		if (columna > 4) {
			System::Drawing::Rectangle cut = System::Drawing::Rectangle(1 * ancho_sprite, (fila*alto_sprite), ancho_sprite, alto_sprite);
			g->DrawImage(bmp, x, y, cut, System::Drawing::GraphicsUnit::Pixel);

		}
		if (columna > 8) { columna = 0; }
	}

	if (d == -1)
	{
		fila = 0;
		columna++;
		if (columna <= 4) {
			System::Drawing::Rectangle cut = System::Drawing::Rectangle(0 * ancho_sprite, (fila*alto_sprite), ancho_sprite-1, alto_sprite);
			g->DrawImage(bmp, x, y, cut, System::Drawing::GraphicsUnit::Pixel);

		}
		if (columna > 4) {
			System::Drawing::Rectangle cut = System::Drawing::Rectangle(1 * ancho_sprite, (fila*alto_sprite), ancho_sprite, alto_sprite-1);
			g->DrawImage(bmp, x, y, cut, System::Drawing::GraphicsUnit::Pixel);

		}
		if (columna > 8) { columna = 0; }
	}
}

void Cerdo::Mover()
{
	dx /= 2;
	x += dx;
	y += (y + l2 <= 600)? dy:0;
}

void Cerdo::Impulso(int pdx, int d)
{

	if (pdx == 0&& d == 1)
	{
		dx = 48;
	}
	if (pdx == 0 && d == -1)
	{
		dx = -48;
	}
	else {
		this->d = (d *-1);
		dx = pdx;
	}
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
	d = -1;
	resistencia = 5;
}

Cerdo::Cerdo()
{
}


Cerdo::~Cerdo()
{
}
