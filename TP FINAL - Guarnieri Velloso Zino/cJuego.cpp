///////////////////////////////////////////////////////////
//  cJuego.cpp
//  Implementation of the Class cJuego
//  Created on:      01-jun.-2021 20:42:39
//  Original author: vguar
///////////////////////////////////////////////////////////

#include "cJuego.h"


cJuego::cJuego(unsigned int cantjugadores)
{
	Jugadores = new cListaT<cJugador>[cantjugadores];
	Rondas = 0;
	TurnoPrevio = 0;
}

cJuego::~cJuego(){

}

void cJuego::AsignarTurno(){
	
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

}

void cJuego::JugadorAtacando(unsigned int pos)
{
	unsigned int cant = 0;
	do {
		//TODO:INFO PARA BATALLAR
		cant++;
	} while (cant < 3 || !((*Jugadores)[pos]->RenunciarTurno()));
}


void cJuego::Batallar(cJugador* Jugador1, cPais* PaisAtacado, cPais* PaisAtacante, cTropa*** Tropas){

}


void cJuego::ImprimirEstados(){

}


void cJuego::SetUp(unsigned int mundo){
	
	//TODO:
}
void cJuego::SetUpJugadores(string nombre)
{
	Jugadores->Agregar(&cJugador(nombre));
}