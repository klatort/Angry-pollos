#include "Pollo_amarillo.h"
#include <math.h>


Pollo_amarillo::Pollo_amarillo(int px, int py):Pollo(px,py)
{
}


Pollo_amarillo::~Pollo_amarillo()
{
}
void Pollo_amarillo::Habilidad_Pollo(int i)
{
	if (y < 600 - l1) {
			dx = (40 * cos(angulo));
			dy = 15 * sin(angulo);
			y += dy;
			x += dx*bounce;
		if (y + 35 * sin(angulo) > 600 - l1) {
			y = 600 - l1;
			dx = 0;
		}
	}
}