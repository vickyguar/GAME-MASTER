///////////////////////////////////////////////////////////
//  cPais.cpp
//  Implementation of the Class cPais
//  Created on:      01-jun.-2021 20:42:40
//  Original author: vguar
///////////////////////////////////////////////////////////

#include "cPais.h"

cListaT<cPais>* cPais::ListaPaises = new cListaT<cPais>();

cPais::cPais(string Nombre, vector<string> Limitrofes): ListaLimitrofes(Limitrofes)
{
	this->Nombre = Nombre;
	this->Tropas = new cListaT<cTropa>();

	*ListaPaises + this; //lo agrego a la lista
}

cPais::cPais(cPais& Pais)
{
}

cPais::~cPais(){

	if (Tropas != NULL)
		delete Tropas;
}

/**
 * No unsigned porque puede recibir de menos :)
 * Es para unificar dos tropas o reagrupar
 */
void cPais::ModificarTropa(cTropa* NumTropa1, cTropa* NumeroTropa2){

}

unsigned int cPais::CalcularAT_Tropas(cListaT<cTropa>* Tropas)
{
	return 0;
}

bool cPais::VerificarLimitrofes(cPais* PaisLimitrofe) {
	try
	{
		cPais*aux=GetListaLimitrofes()->BuscarItem(PaisLimitrofe->Nombre);
	}
	catch (exception* ex)
	{
		delete ex;
		return false;
	}
	return true;
}

void cPais::AsignarTropasRandom()
{
	//TODO: ASIGNAR TROPAS RANDOM
}

cTropa* cPais::VerificarTropa(unsigned int NTropa)
{
	cTropa* aux = NULL;
	try { aux=Tropas->BuscarItem(NTropa); }
	catch(exception*ex){delete ex; }
	return aux;
}

cListaT<cPais>* cPais::getListaPaises()
{
	return ListaPaises;
}

cListaT<cPais>* cPais::GetListaLimitrofes()
{
	cListaT<cPais>* ListaLimitrofesAux = new cListaT<cPais>();
	for (int i = 0; i < ListaLimitrofes.size(); i++)
	{
		for (int j = 0; j < ListaPaises->getCA(); j++)
		{
			if ((*(*ListaPaises)[j])==ListaLimitrofes[i])
				(*ListaLimitrofesAux) + (*ListaPaises)[j];
		}
	}
	return ListaLimitrofesAux;

}

bool cPais::operator==(string Nombre)
{
	return (Nombre == this->Nombre);
}
