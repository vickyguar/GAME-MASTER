//Source
#include <iostream>
#include "cJuego.h"
#include "Menu.h"
#include <random>
#include<ctime>

#define CANT 3

int main()
{
	srand(time(NULL));
	bool ListoXaJugar = Menu();
	cJuego* GAME_MASTER;
	if (ListoXaJugar)
	{
		unsigned int Mundo=ElegirMundo();
		GAME_MASTER = new cJuego(CANT);
		GAME_MASTER->SetUp(Mundo);
		for (int i = 0; i < CANT; i++)
		{
			string username;
			cout << "Jugador " << (i + 1) << " ingrese su nombre de usuario: ";
			cin >> username;
			GAME_MASTER->SetUpJugadores(username);
		}

	}
	else { return 0; }
	GAME_MASTER->ImprimirEstados();
	GAME_MASTER->AsignarTurno();




	delete GAME_MASTER;
	return 0;
}