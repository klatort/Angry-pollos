#pragma once
class Figura
{
protected:
	int x, y, tag, l;
	bool Vivo;
public:
	int dx;
	Figura();
	~Figura();
	int getLado();
	void Death();
	System::Drawing::Bitmap^ RotateImg(System::Drawing::Bitmap^ bmp, float angle, System::Drawing::Color bkColor);
};

