#pragma once
#include <stdlib.h>
using namespace System::Drawing;
class Figura
{
protected:
	int x, y, tag/*kejesto?*/, l1, l2, fila, columna, d;
	bool Vivo;
public:
	double dx, dy;
	Figura();
	Figura(int px, int py);
	~Figura();
	int getd();
	int getx();
	int gety();
	int getL1();
	int getL2();
	void setVivo(bool muerte);
	virtual void Mover(Graphics ^g);
	void Mostrar(Graphics ^g);
};

