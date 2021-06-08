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

unsigned int cJugador::AtaqueEfectivo(cPais* PaisAtacante, cListaT<cTropa>* Tropas){

	return 0;
}

void cJugador::Defender(cPais* PaisAtacado, unsigned int AT_Contrincante){

}

void cJugador::Reagrupar(){
	//cPais* PaisOrigen, cPais* PaisDestino, unsigned int CantTropas, unsigned int NumTropa
	
	
}

bool cJugador::RenunciarTurno(){

	return false;
}

void cJugador::setEstado(eEstadoJugador _Estado)
{
	Estado = _Estado;
}

void cJugador::AgregarTropas()
{
	unsigned int aux = Paises->getCA() / 2;
	cListaT<cTropa>* auxTropas = new cListaT<cTropa>[aux];
	cout << Username << " tenes " << aux << "TROPAS NUEVAS PARA AGREGAR A TU EJERCITO";
	for (unsigned int i = 0; i < aux; i++)
		(*auxTropas) + (new cTropa());

	//TODO:QUE HACEMOS CON LAS CREADAS


}

eEstadoJugador cJugador::getEstado()
{
	return Estado;
}

string cJugador::getUsername()
{
	return Username;
}
