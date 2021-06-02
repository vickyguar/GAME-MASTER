//Source
#include <iostream>
#include "cJuego.h"
#include "Menu.h"

int main()
{
	cJuego* GAME_MASTER = new cJuego();
	bool ListoXaJugar = Menu();

	if (ListoXaJugar)
	{
	unsigned int Mundo=ElegirMundo();
	cJugador* Jugador_1 = GAME_MASTER.setUp(Mundo);
	}
	else { return 0; }
	GAME_MASTER.ImprimirEstados();
	GAME_MASTER.AsignarTurno(Jugador_1);




	delete GAME_MASTER;
	return 0;
}