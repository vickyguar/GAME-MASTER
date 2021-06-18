///////////////////////////////////////////////////////////
//  cArquero.cpp
//  Implementation of the Class cArquero
//  Created on:      01-jun.-2021 20:42:39
//  Original author: vguar
///////////////////////////////////////////////////////////

#include "cArquero.h"
#include "cMago.h"

cArquero::cArquero():cGuerrero((rand() % 11) + 20,(rand() % 21) + 60L, (rand() % 21) + 60){

}

cArquero::~cArquero(){

}

bool cArquero::AtaqueAleatorio(){

	int random = rand() % 101; //numero random entre 0 y 100
	if (random % 2 == 0)
		return true; //si el random es par, ataco 2 veces
	else
		return false; //si es impar, solo ataco una vez
}

unsigned int cArquero::AtaquePorSegunda(cGuerrero* Atacado)
{
	return (AT * 1.50);
}

unsigned int cArquero::CondicionAtaque(cGuerrero* Atacado){
	
	bool condicion = AtaqueAleatorio();

	if (dynamic_cast<cMago*>(Atacado) != NULL)
		AT = AT * 1.25; //su ataque aumenta en 0,25

	if (condicion) //si ataco por segunda vez
		AT += AtaquePorSegunda(Atacado); //volveré a atacar con AT + 50%

	return AT;
}

