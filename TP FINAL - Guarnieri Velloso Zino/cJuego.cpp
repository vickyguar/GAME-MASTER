///////////////////////////////////////////////////////////
//  cJuego.cpp
//  Implementation of the Class cJuego
//  Created on:      01-jun.-2021 20:42:39
//  Original author: vguar
///////////////////////////////////////////////////////////

#include "cJuego.h"

unsigned int cJuego::Rondas = 0;

cJuego::cJuego(unsigned int cantjugadores)
{
	Jugadores = new cListaT<cJugador>[cantjugadores];
	Mundo = new cMundo(); 
	TurnoPrevio = 0;
}

cJuego::~cJuego(){

}

void cJuego::AsignarTurno(){
	if (Rondas % (Jugadores->getCA()) != 0)
	{
		if (Rondas == 0)
		{
			unsigned int pos = rand() % Jugadores->getCA();
			(*Jugadores)[pos]->setEstado();//TODO: try catch para operator
			TurnoPrevio = pos;
			JugadorAtacando(pos);
		}
		if (TurnoPrevio < Jugadores->getCA())
		{
			TurnoPrevio++;
			(*Jugadores)[TurnoPrevio]->setEstado();
			JugadorAtacando(TurnoPrevio);
		}
		else {
			TurnoPrevio = 0;
			(*Jugadores)[TurnoPrevio]->setEstado();
			JugadorAtacando(TurnoPrevio);
		}
		Rondas++; //ternimo la ronda, viene la siguente
		
	}
	else
		FindeRondaEntera();
}

void cJuego::JugadorAtacando(unsigned int pos)
{
	unsigned int cant = 0;
	unsigned int pospais;
	do {
		//TODO: METODO PARA ELEGIR TRES TROPAS QUE DEVUELVE cListaT TROPAS
		/* cout << " Introduzca el numero de tropas con las que quiere atacar: \n";
		cin >> pospais; */
		cPais* paisAtaque = PosPaisAtaque((*Jugadores)[pos]);
		cPais* paisAtacado = PosPaisAtacado((*Jugadores)[pos],paisAtaque);
		cListaT<cTropa>* MiniListaTropas = new cListaT<cTropa>(false);
		MiniListaTropas = TropasdeBatalla(paisAtaque);

		Batallar((*Jugadores)[pos], paisAtaque, paisAtacado, MiniListaTropas);

		Reagrupar(pos);
		cant++;
		ImprimirEstados(); //en cada vuelta se imprimen los estados para saber que onda como viene el mundo
	} while (cant < 3 || !((*Jugadores)[pos]->RenunciarTurno()) || (*Jugadores)[pos]->getEstado() != eEstadoJugador::GANADOR);
}






//TODO: VERIFICAR
void cJuego::Batallar(cJugador* JugadorAtacando, cPais* PaisAtacado, cPais* PaisAtacante, cListaT<cTropa>* Tropas){

}


void cJuego::ImprimirEstados() const {

}

void cJuego::SetUpMundo(unsigned int mundo){
	
	string str = "MUNDO " + to_string(mundo)+ ".txt"; //nombre del archivo
	const char* Filename = str.c_str();
	try
	{
		Mundo->SetUp(Filename);
	}
	catch (exception* ex)
	{
		throw ex; //TODO: cambiar ex
	}
}

void cJuego::SetUpJugadores(string nombre)
{
	Jugadores->Agregar(&cJugador(nombre));
	if (Mundo->GetLista()->getCA() % Jugadores->getCA());
	
}

void cJuego::Reagrupar(unsigned int pos)
{
	(*Jugadores)[pos]->Reagrupar();
}

void cJuego::FindeRondaEntera()
{
	for (unsigned int i = 0; i < Jugadores->getCA(); i++)
	{
		(*Jugadores)[i]->AgregarTropas();
	}
}

void cJuego::AsignarPaisesRandom()
{
	//listem
	float Division = Mundo->GetLista()->getCA() / Jugadores->getCA();
	cListaT<cPais>* Temporal = Mundo->GetLista(); //TODO: operador =

	for (unsigned int i = 0; i < (int)Division; i++)
	{
		//TODO: random
		//TODO: asignar tropas random pAIS[1]->AsignarTropa();
		//TODO: la agrego al jugador el pais con sus tropas (por copia)
	}

	if (Division - (int)Division != 0) //se reparten la misma cantidad para todos los jugadores
	{
		unsigned int PaisesSobrantes = CalcularResiduo(Mundo->GetLista()->getCA(), Jugadores->getCA()); //cantidad paises, cantidad jugadores
		//TODO: rando para ver quien se queda con paises
		//TODO: asigno paises
	}

}

int cJuego::getRondas()
{
	return Rondas;
}

cJugador* cJuego::getJugadorAtacante()
{
	//return Jugadores->BuscarEstado(eEstadoJugador::ATACANDO);
}


