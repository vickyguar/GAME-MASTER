//Source
#include <iostream>
#include "cJuego.h"
#include "cJugador.h"
#include "Menu.h"
#include <random>
#include <ctime>

#define CANT 2
//TODO: COSASA A CAMBIAR EN EL UML
// - agregar clase Mundo
// - agregar metodos nuevos <3

//TODO: sobre carga del ++
//TODO: >= -> para tropa
//TODO: == -> para las claves
//TODO: constructores y destructores

int main()
{


	srand(time(NULL));
	bool ListoXaJugar = Menu();
	cJuego* GAME_MASTER;
	//int CantidadJugadores = 0;

	if (ListoXaJugar)
	{
		unsigned int Mundo = ElegirMundo();
		system("cls");
		
		GAME_MASTER = new cJuego(CANT); 
		//abro archivo y creo el mundo
		GAME_MASTER->SetUpMundo(Mundo); //a esta altura ya tenemos la cantidad de paises

		GAME_MASTER->getMundo()->Imprimir();

		//pregunto cantidad de jugadores -> por ahora es de a 2 :)

		/*cout << "Ingrese cantidad de jugadores: " << endl;
		cin >> CantidadJugadores;*/

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
		GAME_MASTER->AsignarTurno(); //Se asigna el turno, y se envía alusuario a jugar. 

	} while (GAME_MASTER->getRondas() < 10 || GAME_MASTER->BuscarXEstado(eEstadoJugador::ATACANDO) != NULL); //las condiciones serían: que haya un ganador o supere un maximo de 10 turnos

	//se juega mientras que el numero de ronda sea < a 10 o que haya un jugador que haya conquistado el MUNDOOOO!

	if (GAME_MASTER->BuscarXEstado(eEstadoJugador::GANADOR) != NULL)
	{
		system("color E4");
		cout << GAME_MASTER->BuscarXEstado(eEstadoJugador::GANADOR)->getClave() << " has logrado conquistar el MUNDO :)" << endl;
	}
		

	delete GAME_MASTER; //supongo que aca se borra todo lo creado (paises, jugadores, tropas, etc)
	return 0;
}