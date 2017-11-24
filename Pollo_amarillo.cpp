#include "Pollo_amarillo.h"
#include <math.h>


Pollo_amarillo::Pollo_amarillo(int px, int py):Pollo(px,py)
{
	dx = 20.000000000000001;
}


Pollo_amarillo::~Pollo_amarillo()
{
}
void Pollo_amarillo::Habilidad_Pollo(int i)
{
	if (y < 600 - l1) {
		if (dx*bounce > 20 || dx*bounce <-20) {
			dx = (80 * cos(angulo));
			dy = 80* sin(angulo);
			y += dy;
			x += dx*bounce;
			if (y + 60 * sin(angulo) > 600 - l1) {
				y = 600 - l1;
				dx = 0;
			}
		}
		else
		{
			dy = 80;
			y += dy;
			if (y > 600 - l1) {
				y = 600 - l1;
				dx = 0;
			}
		}
	}
}