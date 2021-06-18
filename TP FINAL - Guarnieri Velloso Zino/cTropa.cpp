///////////////////////////////////////////////////////////
//  cTropa.cpp
//  Implementation of the Class cTropa
//  Created on:      01-jun.-2021 20:42:40
//  Original author: vguar
///////////////////////////////////////////////////////////

#include "cTropa.h"
#include "Enums.h"

class cMago;
class cCaballero;
class cArquero;
unsigned int cTropa::ContTropas = 0;

cTropa::cTropa(){
	ContTropas++;
	IDTropa = to_string(ContTropas);
	
	eTipoGuerrero random = eTipoGuerrero(rand() % 3);
	switch (random)
	{
	case eTipoGuerrero::CABALLERO:
		*Guerreros = new cListaT<cCaballero>(); break;
	case eTipoGuerrero::MAGO:
		*Guerreros = new cListaT<cMago>(); break;
	case eTipoGuerrero::ARQUERO:
		*Guerreros = new cListaT<cArquero>(); break;
	}
}

cTropa::~cTropa(){
	if (Guerreros != NULL)
		delete Guerreros;
}

unsigned int cTropa::CalcularAT_Total() {
	unsigned int AT_Total = 0;
	for (unsigned int i = 0; i < Guerreros->getCA(); i++) {
		AT_Total += (*Guerreros)[i]->getAT();
	}
	return AT_Total;
}

bool cTropa::operator>(cTropa* otra)
{
	//MAGO VS CABALLERO -> fuerte mago
	//ARQUERO VS MAGO -> fuerte arquero
	//CABALLERO VS ARQUERO -> fuerte caballero

	if (AnalizarTipo<cMago>(this) && AnalizarTipo<cCaballero>(otra))
		return true;
	if (AnalizarTipo<cArquero>(this) && AnalizarTipo<cMago>(otra))
		return true;
	if (AnalizarTipo<cCaballero>(this) && AnalizarTipo<cArquero>(otra))
		return true;

	return false;
}

cListaT<cGuerrero>* cTropa::OrdenarXHP()
{
	cGuerrero* aux = NULL;
	int cont_cambios = 0;
	for (unsigned int i = 0; i < Guerreros->getCA() - 1; i++)
	{
		for (unsigned int k = 0; k < Guerreros->getCA() - 1; k++)
		{
			if ((*Guerreros)[k]->getHP() < (*Guerreros)[k+1]->getHP())
			{
				aux = (*Guerreros)[k];
				Guerreros[k] = Guerreros[k+1];
				Guerreros[k + 1] = aux;
				cont_cambios++;
			}
		}
		if (cont_cambios == 0)
			break;
	}
}

void cTropa::RecibirDanio(unsigned int AT_Ataque) {

	Guerreros = OrdenarXHP(); //ordeno de más vida a menod vida
	int i = 0;
	do
	{
		int aux = (*Guerreros)[i]->getHP();
		(*(*Guerreros)[i]) -= AT_Ataque;
		if ((*Guerreros)[i]->VerificarVida())
		{
			Guerreros->Eliminar(i);
			--i;
		}
		AT_Ataque -= aux;
		i++;

	} while (AT_Ataque > 0 && i < Guerreros->getCA());
}
