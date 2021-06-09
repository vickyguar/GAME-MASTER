///////////////////////////////////////////////////////////
//  cArquero.cpp
//  Implementation of the Class cArquero
//  Created on:      01-jun.-2021 20:42:39
//  Original author: vguar
///////////////////////////////////////////////////////////

#include "cArquero.h"


cArquero::cArquero():cGuerrero((rand() % 11) + 20,(rand() % 21) + 60L, (rand() % 21) + 60){

}

cArquero::~cArquero(){

}

bool cArquero::AtaqueAleatorio(){

	return false;
}

unsigned int cArquero::CondicionAtaque(cGuerrero* Atacado){

	return 0;
}

