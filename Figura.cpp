#include "Figura.h"

using namespace System;

Figura::Figura()
{
	Vivo = true;
}


Figura::~Figura()
{
}

int Figura::getLado()
{
	return l;
}

void Figura::Death()
{
	Vivo = false;
}
System::Drawing::Bitmap^ Figura::RotateImg(System::Drawing::Bitmap^ bmp, float angle, System::Drawing::Color bkColor)
{
	int w = bmp->Width;
	int h = bmp->Height;
	System::Drawing::Imaging::PixelFormat  pf ;
	if (bkColor == System::Drawing::Color::Transparent)
	{
		pf = System::Drawing::Imaging::PixelFormat::Format32bppArgb;
	}
	else
	{
		pf = bmp->PixelFormat;
	}

	System::Drawing::Bitmap ^tempImg = gcnew System::Drawing::Bitmap(w, h, pf);
	System::Drawing::Graphics ^g = System::Drawing::Graphics::FromImage(tempImg);
	g->Clear(bkColor);
	g->DrawImageUnscaled(bmp, 1, 1);
	delete g;

	System::Drawing::Drawing2D::GraphicsPath ^path = gcnew System::Drawing::Drawing2D::GraphicsPath();
	path->AddRectangle(System::Drawing::RectangleF(0.0, 0.0, w, h));
	System::Drawing::Drawing2D::Matrix ^mtrx = gcnew System::Drawing::Drawing2D::Matrix();
	mtrx->Rotate(angle);
	System::Drawing::RectangleF rct = path->GetBounds(mtrx);
	System::Drawing::Bitmap ^newImg = gcnew System::Drawing::Bitmap(System::Convert::ToInt32(rct.Width), System::Convert::ToInt32(rct.Height), pf);
	g = System::Drawing::Graphics::FromImage(newImg);
	g->Clear(bkColor);
	g->TranslateTransform(-rct.X, -rct.Y);
	g->RotateTransform(angle);
	g->InterpolationMode = System::Drawing::Drawing2D::InterpolationMode::HighQualityBilinear;
	g->DrawImageUnscaled(tempImg, 0, 0);
	delete g;
	delete tempImg;
	return newImg;
}