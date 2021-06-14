///////////////////////////////////////////////////////////
//  cJuego.cpp
//  Implementation of the Class cJuego
//  Created on:      01-jun.-2021 20:42:39
//  Original author: vguar
///////////////////////////////////////////////////////////

#include "cJuego.h"

unsigned int cJuego::Rondas = 0;

cJuego::cJuego(unsigned int cantjugadores)
{
	Jugadores = new cListaT<cJugador>[cantjugadores];
	Mundo = new cMundo(); 
	TurnoPrevio = 0;
}

cJuego::~cJuego(){

}

void cJuego::AsignarTurno(){
	if (Rondas % (Jugadores->getCA()) != 0)
	{
		if (Rondas == 0)
		{
			unsigned int pos = rand() % Jugadores->getCA();
			(*Jugadores)[pos]->setEstado();//TODO: try catch para operator
			TurnoPrevio = pos;
			JugadorAtacando(pos);
		}
		if (TurnoPrevio < Jugadores->getCA())
		{
			TurnoPrevio++;
			(*Jugadores)[TurnoPrevio]->setEstado();
			JugadorAtacando(TurnoPrevio);
		}
		else {
			TurnoPrevio = 0;
			(*Jugadores)[TurnoPrevio]->setEstado();
			JugadorAtacando(TurnoPrevio);
		}
		Rondas++; //ternimo la ronda, viene la siguente
	}
	else
		FindeRondaEntera();
}

void cJuego::JugadorAtacando(unsigned int pos)
{
	unsigned int cant = 0;
	unsigned int pospais = 0;
	do {
	
		cPais* paisAtaque = PosPaisAtaque((*Jugadores)[pos]);
		cPais* paisAtacado = PosPaisAtacado((*Jugadores)[pos],paisAtaque);
		cListaT<cTropa>* MiniListaTropas = new cListaT<cTropa>(false, 3); //le pusimos false :)
		TropasdeBatalla(paisAtaque,MiniListaTropas);

		Batallar((*Jugadores)[pos], paisAtaque, paisAtacado, MiniListaTropas); //Todo lo que le pasamos a batallar est� chequeado

		Reagrupar(pos, paisAtaque, paisAtacado);
		cant++;
		ImprimirEstados(); //en cada vuelta se imprimen los estados para saber que onda como viene el mundo
		delete MiniListaTropas;

	} while (cant < 3 || !((*Jugadores)[pos]->RenunciarTurno()) || (*Jugadores)[pos]->getEstado() != eEstadoJugador::GANADOR);

}


//TODO: BATALLAR
void cJuego::Batallar(cJugador* JugadorAtacando, cPais* PaisAtacado, cPais* PaisAtacante, cListaT<cTropa>* Tropas) {
	
	cListaT<cTropa>* ListaTropaAux = PaisAtacado->CrearMiniListaRandom();


	unsigned int AT_Efectivo = JugadorAtacando->AtaqueEfectivo(PaisAtacante, Tropas, ListaTropaAux);
	cJugador* JugadorAtacado = DuenioPais(PaisAtacado); //Buscamos el due�o del pais atacado

	if (JugadorAtacado == NULL)
		throw new exception("El pais no tiene duenio"); //si esto pasa es porque algo hicimos mal
	
	

	unsigned int AT_Defensa = JugadorAtacado->AtaqueEfectivo(PaisAtacado, ListaTropaAux);

	JugadorAtacado->RecibirDanio(AT_Efectivo);
	JugadorAtacando->RecibirDanio(AT_Defensa);

}



cJugador* cJuego::DuenioPais(cPais *Pais) {
	for (unsigned int i; i < Jugadores->getCA(); i++)
		if (*(*Jugadores)[i] == Pais)
			return (*Jugadores)[i];
	
	return NULL;
}


//TODO: IMPRIMIRESTADOS
void cJuego::ImprimirEstados() const {

}

void cJuego::SetUpMundo(unsigned int mundo){
	
	string str = "MUNDO " + to_string(mundo)+ ".txt"; //nombre del archivo
	const char* Filename = str.c_str();
	try
	{
		Mundo->SetUp(Filename);
	}
	catch (exception* ex)
	{
		throw ex; //TODO: cambiar ex
	}
}

void cJuego::SetUpJugadores(string nombre)
{
	Jugadores->Agregar(&cJugador(nombre));
	if (Mundo->GetLista()->getCA() % Jugadores->getCA());
	
}

void cJuego::Reagrupar(unsigned int pos, cPais* PaisAtacado, cPais* PaisAtacante)
{
	(*Jugadores)[pos]->Reagrupar(PaisAtacante);
}

void cJuego::FindeRondaEntera()
{
	for (unsigned int i = 0; i < Jugadores->getCA(); i++)
	{
		(*Jugadores)[i]->AgregarTropas();
	}
}

void cJuego::AsignarPaisesRandom()
{
	//listem
	float Division = Mundo->GetLista()->getCA() / Jugadores->getCA();
	cListaT<cPais>* Temporal = Mundo->GetLista(); //TODO: operador =

	for (unsigned int i = 0; i < (int)Division; i++)
	{
		//TODO: random
		//TODO: asignar tropas random pAIS[1]->AsignarTropa();
		//TODO: la agrego al jugador el pais con sus tropas (por copia)
	}

	if (Division - (int)Division != 0) //se reparten la misma cantidad para todos los jugadores
	{
		unsigned int PaisesSobrantes = CalcularResiduo(Mundo->GetLista()->getCA(), Jugadores->getCA()); //cantidad paises, cantidad jugadores
		//TODO: rando para ver quien se queda con paises
		//TODO: asigno paises
	}

}

int cJuego::getRondas()
{
	return Rondas;
}

cJugador* cJuego::getJugadorAtacante()
{
	//return Jugadores->BuscarEstado(eEstadoJugador::ATACANDO);
}


