#pragma once
class Tile_glass :
	public Tile
{
public:
	Tile_glass();
	void Mostrar(System::Drawing::Graphics ^g, System::Drawing::Bitmap ^bmp);
	void Mover();
	~Tile_glass();
};

