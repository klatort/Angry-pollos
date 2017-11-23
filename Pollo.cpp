#include "Pollo.h"
#include <math.h>


Pollo::Pollo()
{
}

Pollo::Pollo(int px, int py)
{
	dx = 0;
	dy = 0;
	y = 500;
	x = 100;
//	l1 = l2 = 20;
	l1 = l2 = 48;
	bounce = 1;
	fila = columna = 0;
	x = px - l1 / 2;
	y = py - l2 / 2;
	angulo = 0;
	habilidad = true;
	if (x +(l1/2) <= 110)
		 d = 1;
	if (x + (l1 / 2) > 110)
		 d = -1;
}


Pollo::~Pollo()
{
}

//void Pollo::Mover(double angulo, double t, double distancia)
//{
//	if (y < 600) {
//		dy = (distancia / 10)*(10 * sin(angulo)*t + 0.5 * 9.81 * (t*t));
//		y += dy;
//		dx = (distancia / 10)*(10 * cos(angulo)*t)*bounce;
//		x += dx;
//		pos = (y + (distancia / 10)*(10 * sin(angulo)*t + 0.5 * 9.81 * (t*t))) > y ? x - dx + 50 : x;
//	}
//	if (y >= 60-l1) {
//		y = 600-l1;
//		dx = 0;
//	}
//}


/*void Pollo::Mover(System::Drawing::Graphics ^ g, double angulo, double t,double distancia)
{

	if (y < 600) {
		dy = (distancia / 10)*(10 * sin(angulo)*t + 0.5 * 9.81 * (t*t));
		y += dy;
		dx = (distancia / 10)*(10 * cos(angulo)*t)*bounce;
		x += dx;
		pos = (y + (distancia / 10)*(10 * sin(angulo)*t + 0.5 * 9.81 * (t*t))) > y ? x-dx+50:x;
	}
	 if(y >= 600) {
		y = 600;
		dx = 0;
	}

	g->FillEllipse(gcnew System::Drawing::SolidBrush(System::Drawing::Color::Green), pos, y, l1, l2);
}*/

void Pollo::Mover(double t, double distancia)
{
	if (y < 600) {
		dy = (distancia / 10)*(10 * sin(angulo)*t + 0.5 * 9.81 * (t*t));
		y += dy;
		dx = (distancia / 10)*(10 * cos(angulo)*t)*bounce;
		x += dx;
		//pos = (y + (distancia / 10)*(10 * sin(angulo)*t + 0.5 * 9.81 * (t*t))) > y ? x - dx + 50 : x;
	}
	if (y >= 600 - l1) {
		y = 600 - l1;
		dx = 0;
	}
}

void Pollo::Nuevo_angulo(double t, double distancia)
{
	angulo = atan2(((distancia / 20)*(10 * sin(angulo)*t + 0.5 * 9.81 * (t*t))), (distancia / 20)*(10 * cos(angulo)*t));
}

void Pollo::Habilidad_Pollo(int i)
{
}

void Pollo::Mostrar_pollo(System::Drawing::Graphics ^ g, System::Drawing::Bitmap ^ bmp)
{
	{
		int ancho_sprite = bmp->Width / 2;
		int alto_sprite = bmp->Height / 4;
		
			
			if (d == 1 && y < 600 - l1)
			 {
			fila = 3;
			columna++;
			if (columna <= 3) {
				System::Drawing::Rectangle cut = System::Drawing::Rectangle(0 * ancho_sprite, (fila*alto_sprite), ancho_sprite, alto_sprite-1);
				g->DrawImage(bmp, x, y, cut, System::Drawing::GraphicsUnit::Pixel);
				
			}
			if (columna > 3) {
				System::Drawing::Rectangle cut = System::Drawing::Rectangle(1 * ancho_sprite, (fila*alto_sprite), ancho_sprite, alto_sprite-1);
				g->DrawImage(bmp, x, y, cut, System::Drawing::GraphicsUnit::Pixel);
				
			}
			if (columna > 6) { columna = 0; }
			}
		
			if (d == -1 && y < 600 - l1)
			 {
			fila = 2;
			columna++;
			if (columna <= 3) {
				System::Drawing::Rectangle cut = System::Drawing::Rectangle(0 * ancho_sprite, (fila*alto_sprite), ancho_sprite, alto_sprite-1);
				g->DrawImage(bmp, x, y, cut, System::Drawing::GraphicsUnit::Pixel);
				
			}
			if (columna > 3) {
				System::Drawing::Rectangle cut = System::Drawing::Rectangle(1 * ancho_sprite, (fila*alto_sprite), ancho_sprite, alto_sprite-1);
				g->DrawImage(bmp, x, y, cut, System::Drawing::GraphicsUnit::Pixel);
				
			}
			if (columna > 6) { columna = 0; }
			}
		if (y == 600 - l1 &&d == 1)
			{
			fila = 1;
			System::Drawing::Rectangle cut = System::Drawing::Rectangle(1 * ancho_sprite, (fila*alto_sprite), ancho_sprite, alto_sprite - 1);
			g->DrawImage(bmp, x, y, cut, System::Drawing::GraphicsUnit::Pixel);
			}
		if (y == 600 - l1 && d == -1)
			 {
			fila = 0;
			System::Drawing::Rectangle cut = System::Drawing::Rectangle(0 * ancho_sprite, (fila*alto_sprite), ancho_sprite, alto_sprite - 1);
			g->DrawImage(bmp, x, y, cut, System::Drawing::GraphicsUnit::Pixel);
			}
		}
		
}

void Pollo::Mostrar_pollo_resortera(int px, int py)
{
	x = px - l1 / 2;
	y = py - l2 / 2;
	if (x + (l1 / 2) <= 110)
		 d = 1;
	if (x + (l1 / 2)  > 110)
		 d = -1;
}

void Pollo::Setbounce(float b) 
{
	bounce *= b;
	d *= -1;
}

void Pollo::SetpolloAngulo(double ang)
{
	angulo = ang;
}
