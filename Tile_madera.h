#pragma once
class Tile_madera :
	public Tile
{
public:
	Tile_madera();
	void Mostrar(System::Drawing::Graphics ^g, System::Drawing::Bitmap ^bmp);
	void Mover();
	~Tile_madera();
};

