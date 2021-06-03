///////////////////////////////////////////////////////////
//  cGuerrero.cpp
//  Implementation of the Class cGuerrero
//  Created on:      01-jun.-2021 20:42:39
//  Original author: vguar
///////////////////////////////////////////////////////////

#include "cGuerrero.h"




cGuerrero::cGuerrero(unsigned int _AT, unsigned int _AT_Especial, unsigned int _HP_Actual, unsigned int _HP_Inicial, unsigned int _LimiteVida)
{
	AT = _AT;
	AT_Especial = _AT_Especial;
	HP_Actual = _HP_Actual;
	HP_Inicial = _HP_Inicial;
	LimiteVida = _LimiteVida;
}

cGuerrero::~cGuerrero(){

}





unsigned int cGuerrero::CondicionAtaque(cGuerrero* Atacado){

	return 0;
}


unsigned int cGuerrero::GenerarAT(){

	return 0;
}


unsigned int cGuerrero::GenerarHP(){

	return 0;
}