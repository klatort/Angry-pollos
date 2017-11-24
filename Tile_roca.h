#pragma once
class Tile_roca :
	public Tile
{
public:
	Tile_roca();
	void Mostrar(System::Drawing::Graphics ^g, System::Drawing::Bitmap ^bmp);
	void Mover();
	~Tile_roca();
};

