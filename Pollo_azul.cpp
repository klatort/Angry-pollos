#include "Pollo_azul.h"
#include <math.h>


Pollo_azul::Pollo_azul(int px, int py) :Pollo(px, py)
{

}
Pollo_azul::Pollo_azul(int px, int py, int dir, double angulo) : Pollo(px, py)//constructor auxiliar
{
	habilidad = false;
	this->angulo = angulo;
	d = dir;
}

Pollo_azul::~Pollo_azul()
{
}
void Pollo_azul::Habilidad_Pollo(int i)
{
	if (y < 600 - l1) {
		if (i == 0) {
			dx = (40 * cos(angulo + (23 * System::Math::PI / 12)));
			dy = 40 * sin(angulo + (23 * System::Math::PI / 12));
			y += dy;
			x += dx*bounce;
		}
		if (i == 1)
		{
			dx = (40 * cos(angulo));
			dy = 40 * sin(angulo);
			y += dy;
			x += dx*bounce;
		}
		if (i == 2)
		{
			dx = (40 * cos(angulo + (System::Math::PI / 12)));
			dy = 40 * sin(angulo + (System::Math::PI / 12));
			y += dy;
			x += dx*bounce;
		}
		if (y + 40 * sin(angulo) > 600 - l1&& i == 0) {
			y = 600 - l1;
			dx = 0;
		}
		if (y + 40 * sin(angulo + (23*System::Math::PI / 12)) > 600 - l1&& i == 2) {
			y = 600 - l1;
			dx = 0;
		}
		if (y + 40 * sin(angulo + (System::Math::PI / 12)) > 600 - l1&& i == 1) {
			y = 600 - l1;
			dx = 0;
		}
	}
}