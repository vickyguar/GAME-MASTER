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

cJugador::cJugador(string _Username, eEstadoJugador _Estado):Username(_Username)
{
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
	if (Destino != NULL) 
		pos = cPais::getListaPaises()->getIndex(Destino->getClave());

	cout << "Queres pasar topas desde " << PaisOrigen->getClave();
	if(Destino==NULL)
		cout<< " a algun pais limitrofe?" << endl;
	else
		cout << " a " << Destino->getClave()<<endl;

	cout << "1: SI" << endl << "0: NO" << endl;
	cin >> opcion;

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

		unsigned int rand1 = rand() % (PaisOrigen->getTropas()->getCA() - opcion);//Que se genere un n�mero random que no incluya los extremos

		for (unsigned int i = 0; i < opcion; i++)
		{
			cTropa* aux = PaisOrigen->getTropas()->QuitarXPos(rand1 + i); //lo quito del pais de origen
			(*(*Paises)[pos]->getTropas()) + aux; //TODO: fijarse de que siga existiendo el obj (lo estoy agregando a la lista del pais limitrofe)
			if (rand1 >= PaisOrigen->getTropas()->getCA())
				rand1 = 0;
		}
	}
	else
	{
		return;
	}
}

bool cJugador::RenunciarTurno(){

	return false;
}

void cJugador::setEstado(eEstadoJugador _Estado)
{
	Estado = _Estado;
}

void cJugador::AgregarTropas()
{
	unsigned int pos = 0;
	unsigned int aux = Paises->getCA() / 2; // la cantidad de tropas que voy a agregar (las extras)

	cout << Username << " tenes " << aux << " TROPA/S NUEVAS PARA AGREGAR yey!" << endl;

	for (unsigned int i = 0; i < aux; i++)
	{
		do
		{
			cout << "Ingrese el numero del pais en donde quiere agregar la tropa #" << i + 1 << ": ";
			cin >> pos;
		} while ((pos < 0 || pos >cPais::getListaPaises()->getCA()) || !((*this) == (*cPais::getListaPaises())[pos])); //TODO: funcion verificar
		
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
		output += (*Paises)[i]->getTropas()->To_String();
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
		delete ex; //no lo encontr�
		return false;
	}
	
	return true; //lo encontr� :)
}

bool cJugador::VerficarAtaque(cPais* Pais)
{
	cListaT<cPais>* CopiaLista = new cListaT<cPais>(Pais->GetListaLimitrofes()); //me copio los paises limitrofes a una lista para no perderlos

	for (unsigned int i = 0; i < Paises->getCA(); i++) //recorro mi lista de paises
	{
		for (unsigned int k = 0; k < CopiaLista->getCA(); k++) //recorro los limitrofes
		{
			if ((*CopiaLista)[k]->getClave() == (*Paises)[i]->getClave()) //si tengo un limitrofe
				*CopiaLista - (*CopiaLista)[k]; //lo saco de la lista
		}
	}
	if (CopiaLista->getCA() == 0) //si la lista de limitrofes esta vacia (o sea que tengo todos los limitrofes de ese pais)
		return false; //no puedo atacar desde el pais que me llego por parametro
	else
		return true; //puedo atacar yey :)
}

bool cJugador::VerifcarPaisDispo(cPais* Pais)
{
	{
		for (unsigned int i = 0; i < Paises->getCA(); i++) //recorro la lista de mis paises
		{
			if (((*Paises)[i]->getTropas()->getCA() > 1) && Pais->getClave() != (*Paises)[i]->getClave()) //tengo otro pais que tiene m�s de una tropa (puede atacar)
				return true;
		}
		return false; //no tengo otro pais para atacar (F) :(
	}
}


