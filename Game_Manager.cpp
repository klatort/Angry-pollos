#include "Game_Manager.h"



Game_Manager::Game_Manager()
{
	N_Tiles = new int;
	N_Pollos = new int;
	N_Cerdos = new int;
	*N_Cerdos = 0;
	*N_Pollos = 0;
	*N_Tiles = 0;
	C = new Cerdo*[*N_Cerdos];
	bolita = new Pollo*[*N_Pollos];
	T = new Tile*[*N_Tiles];
	resortera = new Resortera;
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
				bolita[j]->Setbounce(-1/2);
				if (bolita[j]->dy < 0)
				{
					bolita[j]->dy = bolita[j]->dy * -1;
				}
				a->Damage(bolita[j]->dx);
				a->Impulso(bolita[j]->dx);
			}
		}
	}
}

void Game_Manager::KillEnemy()
{
	for (int i = 0; i < *N_Cerdos; i++)
	{
		Cerdo *a = C[i];

		for (int j = 0; j < *N_Pollos; j++)
		{
			Pollo *b = bolita[j];
			if (Colision(a, b))
			{
				bolita[j]->Setbounce(-1 / 2);
				a->Damage(bolita[j]->dx);
				a->Impulso(bolita[j]->dx,bolita[j]->getd());
			}
		}
	}
}

void Game_Manager::Mostrar_pollos(System::Drawing::Graphics ^g, System::Drawing::Bitmap ^bmp1, System::Drawing::Bitmap ^bmp2, System::Drawing::Bitmap ^bmp3)
{
	 for (int i = 0; i < *N_Pollos; i++)
	{
		if (dynamic_cast<Pollo_rojo*>(bolita[i]))
			bolita[i]->Mostrar_pollo(g, bmp1);
		if (dynamic_cast<Pollo_amarillo*>(bolita[i]))
			bolita[i]->Mostrar_pollo(g, bmp2);
		if (dynamic_cast<Pollo_azul*>(bolita[i]))
			bolita[i]->Mostrar_pollo(g, bmp3);
	}
}

bool Game_Manager::Pollo_desaparece(System::Drawing::Graphics ^ g,int i)
{

		if (bolita[i]->getx() > g->VisibleClipBounds.Right|| bolita[i]->getx() + bolita[i]->getL1() < g->VisibleClipBounds.Left)
			return true;

}
void Game_Manager::Fin_turno(int i)
{
	if (bolita[i]->habilidad == false)
		Eliminar_test();
}
void Game_Manager::Mover_pollos(double t, double distancia)
{
	bolita[*N_Pollos - 1]->Mover(t, distancia);
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

void Game_Manager::CheckDeath()
{
}

void Game_Manager::NextLevel()
{
}

void Game_Manager::CheckColisionC()
{
	for (int i = 0; i < *N_Tiles; i++)
	{
		Tile *a = T[i];
		for (int j = 0; j < *N_Cerdos; j++)
		{
			Cerdo *b = C[j];

			if (Colision(a, b))
			{
				b->Gravedad(0);
			}
			else
				b->Gravedad(10);
		}
	}
}

void Game_Manager::Insertar_Cerdos(Cerdo * nuevo)
{
	Cerdo ** Aux = new Cerdo*[*N_Cerdos + 1];
	for (int i = 0; i < *N_Cerdos; i++)
	{
		Aux[i] = C[i];
	}
	Aux[*N_Cerdos] = nuevo;
	*N_Cerdos =*N_Cerdos+ 1;
	C = Aux;
}

void Game_Manager::Insertar_Tile(Tile * nuevo)
{
	Tile ** Aux = new Tile*[*N_Tiles + 1];
	for (int i = 0; i < *N_Tiles; i++)
	{
		Aux[i] = T[i];
	}
	Aux[*N_Tiles] = nuevo;
	*N_Tiles = *N_Tiles+ 1;
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
	*N_Pollos =*N_Pollos + 1;
	bolita = Aux;
}
void Game_Manager::Eliminar_test()
{
	Pollo ** Aux = new Pollo*[*N_Pollos - 1];
	for (int i = 0; i < *N_Pollos - 1; i++)
	{
		Aux[i] = bolita[i];
	}
	*N_Pollos =*N_Pollos- 1;
	bolita = Aux;
}

void Game_Manager::Eliminar_Tile(int pos)
{
	if (pos < *N_Tiles && pos >= 0) {
		for (int i = pos; i < *N_Tiles - 1; i++)
			T[i] = T[i + 1];
		*N_Tiles = *N_Tiles - 1;
	}
}

void Game_Manager::Eliminar_Cerdo(int pos)
{
	if (pos < *N_Cerdos && pos >= 0) {
		for (int i = pos; i < *N_Cerdos- 1; i++)
			C[i] = C[i + 1];
		*N_Cerdos = *N_Cerdos- 1;
	}
}

void Game_Manager::Eliminar_Pollo(int pos)
{
	if (pos < *N_Pollos && pos >= 0) {
		for (int i = 0; i < pos-1; i++)
			bolita[i] = bolita[i+1];
		*N_Pollos = *N_Pollos - 1;
	}
}

double Game_Manager::Calcular_angulo(double px, double py)
{
	return resortera->Calcular_Angulo(px, py);
}
double Game_Manager::Calcular_distancia(double px, double py)
{
	return resortera->Calcular_Distancia(px, py);
}
int Game_Manager::getPolloy(int i)
{

	return bolita[i]->gety();
}
double Game_Manager::getPollody(int i)
{

	return bolita[i]->dy;
}
double Game_Manager::getPollodx(int i)
{

	return bolita[i]->dx;
}
int Game_Manager::getN_Pollos()
{
	return *N_Pollos;
}

void Game_Manager::Mostrar_resortera(System::Drawing::Graphics ^g, System::Drawing::Bitmap ^bmp)
{
	resortera->Mostrar_resortera(g,bmp);
}

void Game_Manager::Pollo_en_resortera(int px, int py)
{
	bolita[*N_Pollos - 1]->Mostrar_pollo_resortera(px, py);
}

void Game_Manager::Mostrar_resortera_liga(Graphics ^ g, int px, int py)
{
	resortera->Mostrar_liga(g, px, py);
}
void Game_Manager::Nuevo_angulo(double t, double distancia)
{
	bolita[*N_Pollos - 1]->Nuevo_angulo(t, distancia);
}
void Game_Manager::Habilidad_pollo()
{
	if (dynamic_cast<Pollo_rojo*>(bolita[*N_Pollos - 1])) {

		bolita[*N_Pollos - 1]->habilidad = true;
	}
	if (dynamic_cast<Pollo_amarillo*>(bolita[*N_Pollos - 1])) {

		bolita[*N_Pollos - 1]->habilidad = false;

	}
	if (dynamic_cast<Pollo_azul*>(bolita[*N_Pollos - 1]))
	{
		bolita[*N_Pollos - 1]->habilidad = false;
		Pollo_azul* polloaux1 = new Pollo_azul(bolita[*N_Pollos - 1]->getx(), bolita[*N_Pollos - 1]->gety(), bolita[*N_Pollos - 1]->getd(), bolita[*N_Pollos - 1]->angulo);
		Pollo_azul* polloaux2 = new Pollo_azul(bolita[*N_Pollos - 1]->getx(), bolita[*N_Pollos - 1]->gety(), bolita[*N_Pollos - 1]->getd(), bolita[*N_Pollos - 1]->angulo);

		Insertar_Pollo(polloaux1);
		Insertar_Pollo(polloaux2);
	}

}
void Game_Manager::Habilidad_pollo2()
{
	if (dynamic_cast<Pollo_rojo*>(bolita[*N_Pollos - 1])) {
		bolita[*N_Pollos - 1]->Habilidad_Pollo(0);
	}
	if (dynamic_cast<Pollo_amarillo*>(bolita[*N_Pollos - 1])) {

		bolita[*N_Pollos - 1]->Habilidad_Pollo(0);
		bolita[*N_Pollos - 1]->habilidad = false;

	}
	if (dynamic_cast<Pollo_azul*>(bolita[*N_Pollos - 1]))
	{
		int cont = 0;
		for (int i = *N_Pollos - 1; i >= 0; i--)
		{

			bolita[i]->Habilidad_Pollo(cont);
			cont++;
		}
		bolita[*N_Pollos - 1]->habilidad = false;
	}

}
void Game_Manager::SetpolloAngulo(double angulo)
{
	bolita[*N_Pollos - 1]->SetpolloAngulo(angulo);
}
bool Game_Manager::getpolloHabilidad(int i)
{
	return bolita[i]->habilidad;
}
bool Game_Manager::getpolloHabilidad_ultimo()
{
	return bolita[*N_Pollos -1]->habilidad;
}
void Game_Manager::setpolloHabilidad(int i)
{

		bolita[i]->habilidad = false;
}

void Game_Manager::Mover_Tiles()
{
	for (int i = 0; i < *N_Tiles; i++)
	{
		T[i]->Mover();
	}
}

void Game_Manager::Mover_Cerdos()
{
	for (int i = 0; i < *N_Cerdos; i++)
	{
		C[i]->Mover();
	}
}

void Game_Manager::Mostrar_Cerdos(Graphics ^ g, System::Drawing::Bitmap ^bmp1,System::Drawing::Bitmap ^bmp2)
{
	for (int i = 0; i < *N_Cerdos; i++)
	{
		if (dynamic_cast<Cerdo_desnudo*>(bolita[i]))
			bolita[i]->Mostrar_cerdo(g, bmp1);
		if (dynamic_cast<Cerdo_casco*>(bolita[i]))
			bolita[i]->Mostrar_cerdo(g, bmp2);
	}
}

void Game_Manager::Mostrar_Tiles(Graphics ^ g,Bitmap ^bmp1,Bitmap^bmp2, System::Drawing::Bitmap ^bmp3)
{
	for (int i = 0; i < *N_Tiles; i++)
	{
		if (dynamic_cast<Tile_madera*>(bolita[i]))
			bolita[i]->Mostrar_cerdo(g, bmp1);
		if (dynamic_cast<Tile_glass*>(bolita[i]))
			bolita[i]->Mostrar_cerdo(g, bmp2);
		if (dynamic_cast<Tile_roca*>(bolita[i]))
			bolita[i]->Mostrar_cerdo(g, bmp3);
	}
}
