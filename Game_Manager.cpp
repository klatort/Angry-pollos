#include "Game_Manager.h"



Game_Manager::Game_Manager()
{
	N_Tiles = new int;
	N_Pollos = new int;
	*N_Pollos = 0;
	*N_Tiles = 0;
	bolita = new Pollo*[*N_Pollos];
	T = new Tile*[*N_Tiles];
}

Game_Manager::~Game_Manager()
{
	delete N_Tiles;
}

bool Game_Manager::Colision(Figura * a, Figura * b)
{
	System::Drawing::Rectangle rectangleA;
	rectangleA.X = a->getx();
	rectangleA.Y = a->gety();
	rectangleA.Width = a->getL1();
	rectangleA.Height = a->getL2();
	System::Drawing::Rectangle rectangleB;
	rectangleB.X = b->getx();
	rectangleB.Y = b->gety();
	rectangleB.Width = b->getL1();
	rectangleB.Height = b->getL2();

	return rectangleA.IntersectsWith(rectangleB);
}


void Game_Manager::CheckImpact()
{
	for (int i = 0; i < *N_Tiles; i++)
	{
		Tile *a = T[i];

		for (int j = 0; j < *N_Pollos; j++)
		{
			Pollo *b = bolita[j];
			if (Colision(a, b))
			{
				bolita[j]->dx *= -1;
				a->Damage(bolita[j]->dx);

			}
		}
	}
}

void Game_Manager::Pollo_desaparece(System::Drawing::Graphics ^ g)
{
	for (int i = 0; i < *N_Pollos; i++) {
		if (bolita[i]->getx() > g->VisibleClipBounds.Right)
			Eliminar_Pollo(i);
	}
}

void Game_Manager::CheckColision()
{
	for (int i = 0; i < *N_Tiles; i++)
	{
		Tile *a = T[i];
		for (int j = i + 1; j < *N_Tiles; j++)
		{
			Tile *b = T[j];

			if (Colision(a, b))
			{
				a->Gravedad(0);
				b->Gravedad(0);
			}
			else
			{
				a->Gravedad(10);
				b->Gravedad(10);
			}
		}
	}
}

void Game_Manager::Insertar_Tile(Tile * nuevo)
{
	Tile ** Aux = new Tile*[*N_Tiles + 1];
	for (int i = 0; i < *N_Tiles; i++)
	{
		Aux[i] = T[i];
	}
	Aux[*N_Tiles] = nuevo;
	*N_Tiles += 1;
	T = Aux;
}
void Game_Manager::Insertar_Pollo(Pollo * nuevo)
{
	Pollo ** Aux = new Pollo*[*N_Pollos + 1];
	for (int i = 0; i < *N_Pollos; i++)
	{
		Aux[i] = bolita[i];
	}
	Aux[*N_Pollos] = nuevo;
	*N_Pollos += 1;
	bolita = Aux;
}

void Game_Manager::Eliminar_Tile(int pos)
{
	Tile ** Aux = new Tile*[*N_Tiles - 1];
	for (int i = 0; i < pos; i++)
	{
		Aux[i] = T[i];
	}
	for (int i = pos + 1; i < *N_Tiles; i++)
	{
		Aux[i] = T[i];
	}
	*N_Tiles -= 1;
	T = Aux;
}
void Game_Manager::Eliminar_Pollo(int pos)
{
	Pollo ** Aux = new Pollo*[*N_Pollos - 1];
	for (int i = 0; i < pos; i++)
	{
		Aux[i] = bolita[i];
	}
	for (int i = pos + 1; i < *N_Pollos; i++)
	{
		Aux[i] = bolita[i];
	}
	*N_Pollos -= 1;
	bolita = Aux;
}

void Game_Manager::Mover_pollos(System::Drawing::Graphics ^ g)
{
	for (int i = 0; i < *N_Pollos; i++)
		bolita[i]->Mover(g);
}
