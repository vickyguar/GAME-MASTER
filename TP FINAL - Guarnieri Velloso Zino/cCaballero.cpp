///////////////////////////////////////////////////////////
//  cCaballero.cpp
//  Implementation of the Class cCaballero
//  Created on:      01-jun.-2021 20:42:39
//  Original author: vguar
///////////////////////////////////////////////////////////

#include "cCaballero.h"

cCaballero::cCaballero():cGuerrero((rand() % 11) + 30, (rand() % 21) + 80, (rand() % 21) + 80){
	//Los caballeros tienen un ataque (AT) entre 30-40 y entre 80 y 100 de vida(HP).
}

cCaballero::~cCaballero(){

}

unsigned int cCaballero::CondicionAtaque(cGuerrero* Atacado){

	return 0;
}

void cCaballero::Contrataque(){

}

unsigned int cCaballero::GenerarAT(){

	return 0;
}
