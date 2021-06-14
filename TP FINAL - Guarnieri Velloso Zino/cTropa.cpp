///////////////////////////////////////////////////////////
//  cTropa.cpp
//  Implementation of the Class cTropa
//  Created on:      01-jun.-2021 20:42:40
//  Original author: vguar
///////////////////////////////////////////////////////////

#include "cTropa.h"
unsigned int cTropa::ContTropas = 0;

cTropa::cTropa(){
	ContTropas++;
	NumTropa = ContTropas;
	
	Guerreros = new cListaT<cGuerrero>();
}


cTropa::~cTropa(){
	if (Guerreros != NULL)
		delete Guerreros;
}


unsigned int cTropa::CalcularAT_Total() {
	unsigned int AT_Total = 0;
	for (unsigned int i = 0; i < Guerreros->getCA(); i++) {
		AT_Total += (*Guerreros)[i]->getAT();
	}
	return AT_Total;
}

void cTropa::RecibirDanio(unsigned int AT_Ataque) {

}