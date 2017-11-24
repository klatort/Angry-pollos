#include "Juego.h"



void Juego::Insertar_Nivel(Game_Manager * nuevo)
{
	Game_Manager ** Aux = new Game_Manager*[*N_Niveles + 1];
	for (int i = 0; i < *N_Niveles; i++)
	{
		Aux[i] = Niveles[i];
	}
	Aux[*N_Niveles] = nuevo;
	*N_Niveles += 1;
	Niveles = Aux;
}

Game_Manager ** Juego::GetNivel()
{
	return Niveles;
}

void Juego::Pasar_Nivel(int * Nivel)
{
	*Nivel += 1;
}

Juego::Juego()
{
	N_Niveles= new int;
	*N_Niveles = 0;
	Niveles = new Game_Manager*[*N_Niveles];
}


Juego::~Juego()
{
}
