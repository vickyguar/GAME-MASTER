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
	Guerreros = new cListaT<cGuerrero>();
	AsignarGuerreros();
}

cTropa::~cTropa(){
	if (Guerreros != NULL)
		delete Guerreros;
}

void cTropa::AsignarGuerreros()
{
	int i = 0;
	eTipoGuerrero random = eTipoGuerrero(rand() % 3);
	switch (random)
	{
	case eTipoGuerrero::CABALLERO:
		for(i=0;i<(rand()%11)+10;i++)
			Guerreros->Agregar(new cCaballero());
		break;
	case eTipoGuerrero::MAGO:
		for (i = 0; i < (rand() % 21) + 20; i++)
			Guerreros->Agregar(new cMago());
		break;
	case eTipoGuerrero::ARQUERO:
		for (i = 0; i < (rand() % 16) + 15; i++)
			Guerreros->Agregar(new cArquero());
		break;
	}

}

unsigned int cTropa::CalcularAT_Total(cTropa* otra) {

	unsigned int AT_Total = 0;

	for (unsigned int i = 0; i < Guerreros->getCA(); i++)
		AT_Total += (*Guerreros)[i]->Ataque(otra->Guerreros->BuscarXPos(i));
	
	return AT_Total;
}

bool cTropa::operator>(cTropa* otra)
{
	//MAGO VS CABALLERO -> fuerte mago
	//ARQUERO VS MAGO -> fuerte arquero
	//CABALLERO VS ARQUERO -> fuerte caballero

	if (AnalizarTipo<cMago>(this->Guerreros) && AnalizarTipo<cCaballero>(otra->Guerreros))
		return true;
	if (AnalizarTipo<cArquero>(this->Guerreros) && AnalizarTipo<cMago>(otra->Guerreros))
		return true;
	if (AnalizarTipo<cCaballero>(this->Guerreros) && AnalizarTipo<cArquero>(otra->Guerreros))
		return true;

	return false;
}

void cTropa::OrdenarXHP()
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

string cTropa::To_string() 
{
	string output = "\t\t" + to_string(Guerreros->getCA());

	if (AnalizarTipo<cCaballero>(Guerreros))
		output += " Caballeros\n";
	else if (AnalizarTipo<cMago>(Guerreros))
		output += " Magos\n";
	else if (AnalizarTipo<cArquero>(Guerreros))
		output += " Arqueros\n";

	return output;
}

void cTropa::RecibirDanio(unsigned int AT_Ataque) {

	OrdenarXHP(); //ordeno de m�s vida a menod vida
	int i = 0;
	do
	{
		int aux = (*Guerreros)[i]->getHP(); //me fijo cuanta vida tengo
		(*(*Guerreros)[i]) -= AT_Ataque; //le resto el AT con el que me atacaron
		if ((*Guerreros)[i]->VerificarVida()) //me fijo si estoy vivo
		{
			Guerreros->Eliminar(i); //si no lo estoy paso a mejor vida
			--i; //menos guerreros 
		}
		AT_Ataque -= aux; //el AT con el que me atacaron disminuye
		i++;

	} while (AT_Ataque > 0 && i < Guerreros->getCA()); //esto se repite hasta que el AT que me mandaron sea 0 o se elimine toda la tropa
	if (Guerreros->getCA() == 0) //me quede sin guerreros en la tropa
		delete Guerreros;
}
