///////////////////////////////////////////////////////////
//  cJugador.cpp
//  Implementation of the Class cJugador
//  Created on:      01-jun.-2021 20:42:40
//  Original author: vguar
///////////////////////////////////////////////////////////

#include "cJugador.h"


cJugador::cJugador(string _Username, eEstadoJugador _Estado):Username(_Username)
{
	Estado = _Estado;
	Paises = new cListaT<cPais>(); 
}

cJugador::~cJugador(){

}

unsigned int cJugador::AtaqueEfectivo(cPais* PaisAtacante, cListaT<cTropa>* TropasAt, cListaT<cTropa>* TropasDef){

	//Dynamic_cast
	return 0;
}

//void cJugador::Defender(cPais* PaisAtacado, unsigned int AT_Contrincante){
//
//}

void cJugador::Reagrupar(cPais* Pais) //este pais es desde el ultio que ataque
{
	int opcion = 0;
	unsigned int pos = 0;
	cout << "Queres pasar topas desde " << Pais->getNombre() << " a algun pais limitrofe?" << endl;
	cout << "1: SI" << endl << "0: NO" << endl;
	cin >> opcion;
	if (opcion)
	{
		do
		{
			system("cls");
			//cout << *this << endl;
			cout << "Ingrese el numero de un pais limitrofe de " << Pais->getNombre() << ":";
			cin >> pos; //es la posicion de la lista del jugador
		} while (!(Pais->VerificarLimitrofes((*Paises)[pos])));

		do
		{
			cout << "Cuantas tropas quiere pasar? " << endl;
			cin >> opcion;
		} while (opcion >= Pais->getTropas()->getCA() || opcion < 0);
		
		for (unsigned int i = 0; i < opcion; i++)
		{
			//(*Paises)[pos]->CrearMiniListaRandom();
		}

		(*Paises)[pos]->AsignarTropas();

		//PEDIR NUMERO TROPAS
		//LO QUITO DE LA LISTA DEL PAIS DE ORIGEN (sobrecarga -)
		//PARA AGREGARLO A LA DEL PAIS LIMITROFE (sobrecarga del +)

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
	unsigned int aux = Paises->getCA() / 2; // la cantidad de tropas que voy a agregar

	cout << Username << " tenes " << aux << "TROPAS NUEVAS PARA AGREGAR yey!";

	for (unsigned int i = 0; i < aux; i++)
	{
		//cout << *this << endl; //sobrecarga cout
		do
		{
			cout << "Ingrese el numero del pais en donde quiere agregar la tropa #" << i + 1 << ":";
			cin >> pos;

			if (*this == Paises->BuscarXPos(pos)) //si es true es porque es un pais mio y agrego las tropas 
				Paises->BuscarXPos(pos)->AsignarTropas(new cTropa()); //le agrego una nueva tropa al pais elegido

		} while ((pos < 0 || pos >cPais::getListaPaises()->getCA()) && !(*this == Paises->BuscarXPos(pos)));
	}
}

eEstadoJugador cJugador::getEstado()
{
	return Estado;
}

string cJugador::getUsername()
{
	return Username;
}

bool cJugador::VerificarPais(int pospais)
{
	return ((*Paises)[pospais] == NULL)? false : true;
}


