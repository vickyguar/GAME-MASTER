///////////////////////////////////////////////////////////
//  cTropa.cpp
//  Implementation of the Class cTropa
//  Created on:      01-jun.-2021 20:42:40
//  Original author: vguar
///////////////////////////////////////////////////////////

#include "cTropa.h"


cTropa::cTropa(unsigned int _NumTropa,unsigned int _AT_Total){
	NumTropa = _NumTropa;
	AT_Total = _AT_Total;
	Guerreros = new cListaT<cGuerrero>();
}

cTropa::~cTropa(){
	if (Guerreros != NULL)
		delete Guerreros;
}


void cTropa::CalcularAT_Total() {
	AT_Total = 0;
	for (unsigned int i = 0; i < Guerreros->getCA(); i++) {
		AT_Total += (*Guerreros)[i]->getAT();
	}
	return;
}

void cTropa::RecibirDanio(unsigned int AT_Ataque) {

}