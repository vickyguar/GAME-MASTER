//Source
#include <iostream>
#include "cJuego.h"
#include "Menu.h"
#include <random>
#include<ctime>

#define CANT 2
//TODO: COSASA A CAMBIAR EN EL UML
// - agregar clase Mundo
// - agregar metodos nuevos <3

//TODO: sobre carga del ++
//TODO: >= -> para tropa
//TODO: == -> para las claves
//TODO:

int main()
{
	srand(time(NULL));
	bool ListoXaJugar = Menu();
	cJuego* GAME_MASTER;
	//int CantidadJugadores = 0;

	if (ListoXaJugar)
	{
		unsigned int Mundo = ElegirMundo();
		
		GAME_MASTER = new cJuego(CANT); 
		//abro archivo y creo el mundo
		GAME_MASTER->SetUp(Mundo); //a esta altura ya tenemos la cantidad de paises

		//pregunto cantidad de jugadores -> por ahora es de a 2 :)
		//cout << "Ingrese cantidad de jugadores: " << endl;
		//cin >> CantidadJugadores;

		for (int i = 0; i < CANT; i++)
		{
			string username;
			cout << "Jugador " << (i + 1) << " ingrese su nombre de usuario: "; //pregunto nombre de usuario
			cin >> username;
			GAME_MASTER->SetUpJugadores(username); //construyo el jugador
		}
		GAME_MASTER->AsignarPaisesRandom(); //asigno paises para cada jugador con sus respectivas tropas random
	}
	else { return 0; }

	GAME_MASTER->ImprimirEstados(); //lo que tiene cada jugador (osea sus paises)

	do
	{
		GAME_MASTER->AsignarTurno(); //elijo el jugador que empieza

	} while (GAME_MASTER->getRondas() < 10 || GAME_MASTER->getJugadorAtacante()->getEstado() != eEstadoJugador::GANADOR); //TODO: las condiciones ser�an: que haya un ganador o supere un maximo de 10 turnos

	//se juega mientras que el numero de ronda sea < a 10 o que haya un jugador que haya conquistado el MUNDOOOO!

	if (GAME_MASTER->getJugadorAtacante()->getEstado() == eEstadoJugador::GANADOR)
		cout << GAME_MASTER->getJugadorAtacante()->getUsername() << " has logrado conquistar el MUNDO :)" << endl;

	delete GAME_MASTER; //supongo que aca se borra todo lo creado (paises, jugadores, tropas, etc)
	return 0;
}