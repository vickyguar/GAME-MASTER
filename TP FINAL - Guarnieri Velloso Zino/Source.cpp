//Source
#include <iostream>
#include "cJuego.h"
#include "Menu.h"



int main()
{
	cJuego* GAME_MASTER = new cJuego();
	bool ListoXaJugar = Menu();
	cJugador* Jugador_1;

	if (ListoXaJugar)
	{
	unsigned int Mundo=ElegirMundo();
	Jugador_1 = GAME_MASTER->SetUp(Mundo);
	}
	else { return 0; }
	GAME_MASTER->ImprimirEstados();
	GAME_MASTER->AsignarTurno(Jugador_1);




	delete GAME_MASTER;
	return 0;
}