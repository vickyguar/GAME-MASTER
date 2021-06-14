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

void cPais::AsignarTropas(cTropa* Tropa)
{
	if(Tropa != NULL)
		*Tropas + Tropa;
	//TODO: falta hacer la parte random
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

cListaT<cTropa>* cPais::CrearMiniListaRandom()
{
	cListaT<cTropa>* aux = new cListaT<cTropa>(false, 3);

	if (Tropas->getCA() > 3) {
		unsigned int rand1 = 1 + rand() % (Tropas->getCA() - 2);//Que se genere un número random que no incluya los extremos
		
		*aux + (*Tropas)[rand1 - 1];
		*aux + (*Tropas)[rand1];
		*aux + (*Tropas)[rand1 + 1];
	}
	else {
		for (unsigned int i = 0; i < Tropas->getCA(); i++)
			*aux + (*Tropas)[i];
	}
	
	return aux;
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
