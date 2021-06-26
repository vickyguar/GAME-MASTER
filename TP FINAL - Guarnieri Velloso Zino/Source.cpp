//Source
#pragma comment(lib, "winmm.lib")
#include <iostream>
#include "cJuego.h"
#include "cJugador.h"
#include "Menu.h"
#include <random>
#include <ctime>

#define CANT 2
#define RONDAS_MAX 10

int main()
{
	PlaySound(TEXT("Cancion.wav"), NULL, SND_FILENAME | SND_ASYNC);
	srand(time(NULL));

	system("color 0C");
	cout << Caratula("CARATULA.txt") << endl << endl;
	cout << "PRESS A KEY TO START " << endl;
	getchar();
	
	system("cls");
	system("color 07");

	bool ListoXaJugar = Menu();
	bool SeguirJugando = false;
	cJuego* GAME_MASTER;

	if (ListoXaJugar)
	{
		unsigned int Mundo = ElegirMundo();
		system("cls");
		
		GAME_MASTER = new cJuego(CANT); 
		//abro archivo y creo el mundo
		try { GAME_MASTER->SetUpMundo(Mundo); }
		catch (exception* ex) { 
			cout << ex->what(); 
			delete ex; 
		}//a esta altura ya tenemos la cantidad de paises

		GAME_MASTER->getMundo()->Imprimir();

		//pregunto cantidad de jugadores -> por ahora es de a 2 :)

		/*cout << "Ingrese cantidad de jugadores: " << endl;
		cin >> CantidadJugadores;*/

		for (int i = 0; i < CANT; i++)
		{
			string username;
			cout << "Jugador " << (i + 1);
			++(*GAME_MASTER);
		}
		GAME_MASTER->AsignarPaisesRandom(); //asigno paises para cada jugador con sus respectivas tropas random
	}
	else { return 0; }

	GAME_MASTER->ImprimirEstados(); //lo que tiene cada jugador (osea sus paises)
	do
	{
		GAME_MASTER->AsignarTurno(); //Se asigna el turno, y se envía alusuario a jugar. 

	} while (GAME_MASTER->getRondas() <= RONDAS_MAX); //las condiciones serían: que haya un ganador o supere un maximo de 10 turnos (cuando hay un ganador se supera el nuemro de rondas)

	//se juega mientras que el numero de ronda sea < a 10 o que haya un jugador que haya conquistado el MUNDOOOO!
	try
	{
		if (GAME_MASTER->BuscarXEstado(eEstadoJugador::GANADOR) != NULL)
		{
			PlaySound(TEXT("We Are The Champion.wav"), NULL, SND_FILENAME | SND_ASYNC);
			system("color E4");
			cout << "\t"<< GAME_MASTER->BuscarXEstado(eEstadoJugador::GANADOR)->getClave() << endl;
			cout << GANASTE();
			cout << "\n\t has logrado conquistar el MUNDO :)" << endl;
			Sleep(8000);
		}
	}
	catch (runtime_error* ex)
	{
		delete ex;
		system("color E5");
		cout << "Ningun jugador tuvo el potencial para conquistar el mundo" << endl;
	}
	
	delete GAME_MASTER; //aca se borra todo lo creado (paises, jugadores, tropas, etc)
	return 0;
}