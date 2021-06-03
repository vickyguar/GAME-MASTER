///////////////////////////////////////////////////////////
//  cArquero.cpp
//  Implementation of the Class cArquero
//  Created on:      01-jun.-2021 20:42:39
//  Original author: vguar
///////////////////////////////////////////////////////////

#include "cArquero.h"


cArquero::cArquero(unsigned int _AT, unsigned int _AT_ESPECIAL, unsigned int _HP_ACTUAL, unsigned int _HP_INICIAL, unsigned int _LimiteVida):cGuerrero(_AT,_AT_ESPECIAL,_HP_ACTUAL,_HP_INICIAL,_LimiteVida){
	HP_Inicial = (rand() % 21) + 60;
	HP_Actual = HP_Inicial;
	AT = (rand() % 11) + 20;
	AT_Especial = AT;
	LimiteVida = HP_Inicial-(0.05 * HP_Inicial);
	//TODO: PREGUNTA PAMPA ES NECESARIO LLAMAR AL CONSTRUCTOR SI DESPUES MODIFICO TODOS LOS VALORES???
}



cArquero::~cArquero(){

}





bool cArquero::AtaqueAleatorio(){

	return false;
}


unsigned int cArquero::CondicionAtaque(cGuerrero* Atacado){

	return 0;
}


unsigned int cArquero::GenerarAT(){

	return 0;
}


unsigned int cArquero::GenerarHP(){

	return 0;
}