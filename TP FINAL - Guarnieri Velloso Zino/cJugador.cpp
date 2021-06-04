///////////////////////////////////////////////////////////
//  cJugador.cpp
//  Implementation of the Class cJugador
//  Created on:      01-jun.-2021 20:42:40
//  Original author: vguar
///////////////////////////////////////////////////////////

#include "cJugador.h"


cJugador::cJugador(string _Username, eEstadoJugador _Estado):Username(_Username)
{
	Estado = _Estado;
	Paises = new cListaT<cPais>[]; //TODO: cantidad de paises inciales para jugar??
}

cJugador::~cJugador(){

}


/**
 * puntero a lista template o puntero triple?
 */
unsigned int cJugador::AtaqueEfectivo(cPais* PaisAtacante, cTropa*** Tropas){

	return 0;
}


void cJugador::Defender(cPais* PaisAtacado, unsigned int AT_Contrincante){

}


void cJugador::Reagrupar(cPais* PaisOrigen, cPais* PaisDestino, unsigned int CantTropas, unsigned int NumTropa){

}


bool cJugador::RenunciarTurno(){

	return false;
}

void cJugador::setEstado(eEstadoJugador _Estado)
{
	Estado = _Estado;
}

eEstadoJugador cJugador::getEstado()
{
	return Estado;
}

string cJugador::getUsername()
{
	return Username;
}
