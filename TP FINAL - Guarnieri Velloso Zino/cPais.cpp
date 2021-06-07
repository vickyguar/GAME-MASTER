///////////////////////////////////////////////////////////
//  cPais.cpp
//  Implementation of the Class cPais
//  Created on:      01-jun.-2021 20:42:40
//  Original author: vguar
///////////////////////////////////////////////////////////

#include "cPais.h"


cPais::cPais(string Nombre, vector<string> Limitrofes): ListaLimitrofes(Limitrofes)
{
	this->Nombre = Nombre;
}

cPais::cPais(cPais& Pais)
{
}

cPais::~cPais(){

}

unsigned int cPais::CalcularAT_Tropas(cTropa*** Tropas){

	return 0;
}


/**
 * No unsigned porque puede recibir de menos :)
 * Es para unificar dos tropas o reagrupar
 */
void cPais::ModificarTropa(cTropa* NumTropa1, bool Unificar, cTropa* NumeroTropa2){

}


void cPais::VerificarLimitrofes(cPais* PaisLimitrofe){

}

vector<string> cPais::GetListaLimitrofes()
{
	return ListaLimitrofes;
}
