///////////////////////////////////////////////////////////
//  cMago.cpp
//  Implementation of the Class cMago
//  Created on:      01-jun.-2021 20:42:40
//  Original author: vguar
///////////////////////////////////////////////////////////

#include "cMago.h"


cMago::cMago(unsigned int _AT, unsigned int _AT_ESPECIAL, unsigned int _HP_ACTUAL, unsigned int _HP_INICIAL, unsigned int _LimiteVida):cGuerrero(_AT, _AT_ESPECIAL, _HP_ACTUAL, _HP_INICIAL, _LimiteVida){
	//10 - 20 y entre 40 y 60 de vida
	AT = (rand() % 11) + 10;
	AT_Especial = AT;
	HP_Inicial = (rand() % 21) + 40;
	HP_Actual = HP_Inicial;
	LimiteVida = HP_Inicial - (0.05 * HP_Inicial);
}



cMago::~cMago(){

}





/**
 * Lo que dijo el Pampa: reparte su ataque en toda la tropa
 */
unsigned int cMago::CondicionAtaque(cGuerrero* Atacado){

	return 0;
}


unsigned int cMago::GenerarAT(){

	return 0;
}


unsigned int cMago::GenerarHP(){

	return 0;
}