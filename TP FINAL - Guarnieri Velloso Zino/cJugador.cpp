///////////////////////////////////////////////////////////
//  cJugador.cpp
//  Implementation of the Class cJugador
//  Created on:      01-jun.-2021 20:42:40
//  Original author: vguar
///////////////////////////////////////////////////////////

#include "cJugador.h"
#include "cMago.h"
#include "cCaballero.h"
#include "cArquero.h"

cJugador::cJugador(eEstadoJugador _Estado)
{
	cin >> *this; //Uso sobrecarga del cin
	Estado = _Estado;
	Paises = new cListaT<cPais>();
}


cJugador::~cJugador(){
	if (Paises!= NULL)
	{

	}
}

unsigned int cJugador::AtaqueEfectivo(cListaT<cTropa>* miTropa, cListaT<cTropa>* TropaEnemiga){

	unsigned int Fuerza = 0;
	unsigned int FuerzaExtra=0;
	for (int i = 0; i < miTropa->getCA(); i++)
	{
		if (dynamic_cast<cCaballero*>((*miTropa)[i]->getGuerreros()) != NULL && Estado == eEstadoJugador::DEFENDIENDO) //si mi tropa son caballeros
			dynamic_cast<cCaballero*>((*miTropa)[i]->getGuerreros())->Contrataque();

		for (int k = 0; k < TropaEnemiga->getCA(); k++)
		{
			FuerzaExtra += (*miTropa)[i]->AT_Extra((*TropaEnemiga)[k]);
			
		}
		Fuerza += (*miTropa)[i]->CalcularAT() + FuerzaExtra; //voy acumulando los aumentos que tengo que realizar a la hora del ataque.
	}
	return Fuerza;
}


void cJugador::Reagrupar(cPais* PaisOrigen,cPais*Destino) //este pais es desde el ultio que ataque
{
	int opcion = 0;
	unsigned int pos = 0;
	//si me pasan un pais busco su posicion en la lista global para poder usar el mismo algoritmo
	if (Destino != NULL) {
		pos = cPais::getListaPaises()->getIndex(Destino->getClave());
		opcion = 1;
	}

	if (Destino == NULL) {
		do {
			cout << "Queres pasar tropas desde " << PaisOrigen->getClave();
			cout << " a algun pais limitrofe?" << endl;

			cout << "1: SI" << endl << "0: NO" << endl; //TODO: la opcion de no se la tiramos no cuando gana un pais sino cuando termina su turno
			cin >> opcion; 
		} while (opcion != 0 && opcion != 1);
	}

	if (opcion)
	{
		if (Destino == NULL)
		{
			do
			{
				system("cls");
				//cout << *this << endl;
				cout << "Ingrese el numero de un pais limitrofe de " << PaisOrigen->getClave() << ":";
				cin >> pos; //es la posicion de la lista del jugador
			} while (Paises->BuscarXPos(pos) != NULL && !(PaisOrigen->VerificarLimitrofes((*Paises)[pos])));
		}

		do
		{
			cout << "Cuantas tropas quiere pasar? Debe quedar 1 tropa en el pais de origen" << endl;
			cin >> opcion; //cantidad de tropas que voy a pasar
		} while (opcion >= PaisOrigen->getTropas()->getCA() || opcion < 0);

		unsigned int rand1 = rand() % (PaisOrigen->getTropas()->getCA() - opcion);//Que se genere un número random que no incluya los extremos

		for (unsigned int i = 0; i < opcion; i++)
		{
			cTropa* aux = PaisOrigen->getTropas()->QuitarXPos(rand1 + i); //lo quito del pais de origen
			(*((*PaisOrigen->getListaPaises())[pos]->getTropas())) + aux;
			if (rand1 >= PaisOrigen->getTropas()->getCA()) // Si llegamos al final de la lista de tropas y aun tenemos que quitar, agarramos desde el principio
				rand1 = 0;
		}

	}
	else
	{
		return;
	}
}

bool cJugador::RenunciarTurno(){
	int aux;
	cout << "Ingrese 0 para seguir atacando, 1 para terminar el turno: ";
	cin >> aux;
	return (aux==0)? false:true;
}

void cJugador::setEstado(eEstadoJugador _Estado)
{
	Estado = _Estado;
}

void cJugador::AgregarTropas()
{
	unsigned int pos = 0;
	unsigned int aux = Paises->getCA() / 2; // la cantidad de tropas que voy a agregar (las extras)
	bool Dominio = true;
	cout << Username << " tenes " << aux << " TROPA/S NUEVAS PARA AGREGAR yey!" << endl;

	for (unsigned int i = 0; i < aux; i++)
	{
		do
		{
			cout << "Ingrese el numero del pais en donde quiere agregar la tropa #" << i + 1 << ": ";
			cin >> pos;
			if (pos < cPais::getListaPaises()->getCA())
				Dominio = VerificarMiPais((*cPais::getListaPaises())[pos]);
		} while ((pos < 0 || pos >cPais::getListaPaises()->getCA()) || !Dominio); //TODO: funcion verificar
		
	 //si es true es porque es un pais mio y agrego las tropas (SOBRECARGA DEL == porque nunca ibamos a igualar 2 jugadores)
		(*cPais::getListaPaises())[pos]->AsignarTropas(); //le agrego una nueva tropa al pais elegido
	}
}

void cJugador::GanarPais(cPais* Pais)
{
	try { Paises->Agregar(Pais); } //AGREGO EL PAIS A LA LISTA DE JUGADOR
	catch (exception* ex) { delete ex; }//TODO: ATENCION
}

void cJugador::PerderPais(cPais* Pais)
{
	Paises->Quitar(Pais->getClave());
}

string cJugador::To_string() const
{
	string output;
	output += "\t" + this->Username + "\n";
	output += "\t\tPaises que posee: \n";
	for (unsigned int i = 0; i < this->Paises->getCA(); i++) {
		output += "\t\t Pais " + to_string(cPais::getListaPaises()->getIndex((*Paises)[i]->getClave())) + ':' + (*Paises)[i]->getClave() + "\n";
		if ((*Paises)[i]->getTropas() != NULL)
		{
			output += (*Paises)[i]->getTropas()->To_String();
		}
	}

	return output;
}

eEstadoJugador cJugador::getEstado()
{
	return Estado;
}

string cJugador::getClave()
{
	return Username;
}

bool cJugador::VerificarMiPais(cPais*ptr)
{
	try
	{
		cPais* aux = Paises->BuscarItem(ptr->getClave()); //busco el item en mi lista de paises
	}
	catch (exception* ex)
	{
		delete ex; //no lo encontré
		return false;
	}
	
	return true; //lo encontré :)
}

bool cJugador::VerficarAtaque(cPais* Pais)
{
	cListaT<cPais> CopiaLista(*Pais->GetListaLimitrofes()); //me copio los paises limitrofes a una lista para no perderlos

	for (unsigned int i = 0; i < Paises->getCA(); i++) //recorro mi lista de paises
	{
		for (unsigned int k = 0; k < CopiaLista.getCA(); k++) //recorro los limitrofes
		{
			if (VerificarMiPais((CopiaLista)[k]))//si tengo un limitrofe
				CopiaLista - (CopiaLista)[k]; //lo saco de la lista
		}
	}
	if (CopiaLista.getCA() == 0) //si la lista de limitrofes esta vacia (o sea que tengo todos los limitrofes de ese pais)
		return false; //no puedo atacar desde el pais que me llego por parametro
	else
		return true; //puedo atacar yey :)
}

bool cJugador::VerifcarPaisDispo()
{
	{
		for (unsigned int i = 0; i < Paises->getCA(); i++) //recorro la lista de mis paises
		{
			if (((*Paises)[i]->getTropas()->getCA() > 1)) //tengo otro pais que tiene más de una tropa (puede atacar)
				return true;
		}
		return false; //no tengo otro pais para atacar (F) :(
	}
}


