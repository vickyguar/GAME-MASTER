///////////////////////////////////////////////////////////
//  cCaballero.cpp
//  Implementation of the Class cCaballero
//  Created on:      01-jun.-2021 20:42:39
//  Original author: vguar
///////////////////////////////////////////////////////////

#include "cCaballero.h"


cCaballero::cCaballero(unsigned int _AT, unsigned int _AT_ESPECIAL, unsigned int _HP_ACTUAL, unsigned int _HP_INICIAL, unsigned int _LimiteVida):cGuerrero(_AT,_AT_ESPECIAL,_HP_ACTUAL,_HP_INICIAL,_LimiteVida){
	//Los caballeros tienen un ataque (AT) entre 30-40 y entre 80 y 100 de vida(HP).
	HP_Inicial = (rand() % 21) + 80;
	HP_Actual = HP_Inicial;
	AT = (rand() % 11) + 30;
	AT_Especial = AT;
	LimiteVida = HP_Inicial - (0.05 * HP_Inicial);
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


unsigned int cCaballero::GenerarHP(){

	return 0;
}