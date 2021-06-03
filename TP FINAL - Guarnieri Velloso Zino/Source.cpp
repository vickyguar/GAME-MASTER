//Source
#include <iostream>
#include "cJuego.h"
#include "Menu.h"
#include <random>
#include<ctime>

#define CANT 3
//TODO: COSASA A CAMBIAR EN EL UML
// - agregar clase Mundo
// - agregar metodos nuevos <3

int main()
{
	srand(time(NULL));
	bool ListoXaJugar = Menu();
	cJuego* GAME_MASTER;
	//TODO: EL MAIN PASA EL ARCHIVO A ABRIR
	if (ListoXaJugar)
	{
		unsigned int Mundo = ElegirMundo();
		//abrir el archivo con el mundo
		//me creo una lista de strings con (1) los paises del mundo (2) los paises limitrofes para cada pais
		//construyo el mundo con sus correspondientes paises y sus limitrofes
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