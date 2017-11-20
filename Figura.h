#pragma once
#include <stdlib.h>
using namespace System::Drawing;
class Figura
{
protected:
	int x, y, tag, l1, l2;
	bool Vivo;
public:
	int dx;
	Figura();
	Figura(int px,int py);
	~Figura();
	int getx();
	int gety();
	int getL1();
	int getL2();
	void Death();
	virtual void Mover(Graphics ^g);
	void Mostrar(Graphics ^g);
};
