#pragma once
#include <stdlib.h>
using namespace System::Drawing;
class Figura
{
protected:
	int x, y, l1, l2, fila, columna,d;
	bool Vivo;
public:
	int dx;
	Figura();
	Figura(int px, int py);
	~Figura();
	int getx();
	int gety();
	int getL1();
	int getL2();
	int getd();
	void setVivo(bool muerte);
	virtual void Mover(Graphics ^g);
	void Mostrar(Graphics ^g);
};

