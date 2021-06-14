///////////////////////////////////////////////////////////
//  cTropa.cpp
//  Implementation of the Class cTropa
//  Created on:      01-jun.-2021 20:42:40
//  Original author: vguar
///////////////////////////////////////////////////////////

#include "cTropa.h"
#include "cMago.h"
#include "cArquero.h"
#include "cCaballero.h"

#define MAGO 1
#define ARQUERO 2
#define CABALLERO 3

unsigned int cTropa::ContTropas = 0;

cTropa::cTropa(){
	ContTropas++;
	NumTropa = ContTropas;
	
	int random = (rand() % 3) + 1;
	if (random == MAGO)
		*Guerreros = new cListaT<cMago>();
	if (random == ARQUERO)
		*Guerreros = new cListaT<cArquero>();
	if (random == CABALLERO)
		*Guerreros = new cListaT<cCaballero>();
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