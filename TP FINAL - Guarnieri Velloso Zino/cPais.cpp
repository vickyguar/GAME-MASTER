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

	for (unsigned int i = 0; i < ListaLimitrofes.size(); i++)
		if (PaisLimitrofe->Nombre == ListaLimitrofes[i])
			return true;

	return false;
}

void cPais::AsignarTropas(cTropa* Tropa)
{
	if(Tropa != NULL)
		*Tropas + Tropa; //esto es para cuando muevo tropas de un pais al otro
	else {
		Tropas->Agregar(new cTropa());//agrego una tropa random nueva
	}
}

cTropa* cPais::VerificarTropa(unsigned int NTropa)
{
	cTropa* aux = NULL;

	try { 
		aux = Tropas->BuscarItem(to_string(NTropa)); //EL NUMERO ES EL ID DE LA TROPA
	} 
	catch(exception*ex){
		delete ex;
	}
	return aux;
}

cListaT<cPais>* cPais::getListaPaises()
{
	return ListaPaises;
}

cListaT<cTropa>* cPais::CrearMiniListaRandom()
{
	cListaT<cTropa>* aux = new cListaT<cTropa>(true, 3);

	if (Tropas->getCA() > 3) {
		unsigned int rand1 = 1 + rand() % (Tropas->getCA() - 2);//Que se genere un n�mero random que no incluya los extremos
		
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

void cPais::RecibirDanio(unsigned int Da�o, cListaT<cTropa>* miTropa)
{
	for (int i = 0; i < miTropa->getCA(); i++)
	{
		(*miTropa)[i]->RecibirDanio(Da�o);
		if ((*miTropa)[i]->getGuerreros()->getCA() == 0) //murio toda la tropa
			miTropa->Eliminar(i); //borro la tropa
	}
	if (miTropa->getCA() == 0 && Tropas->getCA() == 0) //si ya no tengo tropas (las que mande se murieron y en el pais tapoco tengo)
		throw new exception(("Perdiste el dominio del pais: " + Nombre).c_str());
	return;
}

cListaT<cPais>* cPais::GetListaLimitrofes()
{
	cListaT<cPais>* ListaLimitrofesAux = new cListaT<cPais>(false);
	for (int i = 0; i < ListaLimitrofes.size(); i++)
	{
		for (int j = 0; j < ListaPaises->getCA(); j++)
		{
			if ((*ListaPaises)[j]->getClave()==ListaLimitrofes[i])
				(*ListaLimitrofesAux) + (*ListaPaises)[j];
		}
	}
	return ListaLimitrofesAux;

}

string cPais::To_string() const
{
	return Nombre;
}

bool cPais::operator==(string Nombre)
{
	return (Nombre == this->Nombre);
}


