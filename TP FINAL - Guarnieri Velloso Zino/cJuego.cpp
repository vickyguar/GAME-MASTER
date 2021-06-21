﻿///////////////////////////////////////////////////////////
//  cJuego.cpp
//  Implementation of the Class cJuego
//  Created on:      01-jun.-2021 20:42:39
//  Original author: vguar
///////////////////////////////////////////////////////////

#include "cJuego.h"
#include "cJugador.h"

unsigned int cJuego::Rondas = 0;

bool VerificarPaisOrigen(cJugador* Jugador, unsigned int pospais) {

	if (pospais < 0 || pospais > cPais::getListaPaises()->getCA())
	{
		cout << "El pais de donde quiere atacar es invalido." << endl;
		return true;
	}
	else if (!Jugador->VerificarMiPais((*cPais::getListaPaises())[pospais]))
	{
		cout << "El pais seleccionado no te pertenece." << endl;
		return true;
	}
	else if ((*cPais::getListaPaises())[pospais]->getTropas()->getCA() <= 1) 
	{
		cout << "El pais no tiene limitrofes a los cuales puedas atacar." << endl;
		return true;
	}
	return false;
}

cPais* PosPaisAtaque(cJugador* Jugador) {
	unsigned int pospais = -1;
	do {
		cout << "\n ---- JUGADOR " << Jugador->getClave() << " ---- " << endl;
		cout << " Introduzca el numero pais desde el que quiere atacar: ";
		cin >> pospais;
	} while (VerificarPaisOrigen(Jugador, pospais));
	
	if (!(Jugador->VerficarAtaque((*cPais::getListaPaises())[pospais])) && Jugador->VerifcarPaisDispo((*cPais::getListaPaises())[pospais]))
	{
		throw new exception("PERDES EL TURNO POR NO SABER JUGAR, MALISIMA TU ESTRATEGIA");
		return NULL;
	}
	return (*cPais::getListaPaises())[pospais];
}

cPais* PosPaisAtacado(cJugador* Jugador, cPais* Pais) {
	unsigned int pospais = -1;

	do {
		cout << " Introduzca el numero pais al que quiere atacar: ";
		cin >> pospais;

	} while ((pospais>cPais::getListaPaises()->getCA()) || (Jugador->VerificarMiPais((*cPais::getListaPaises())[pospais]))||
		!Pais->VerificarLimitrofes((*cPais::getListaPaises())[pospais]) || pospais < 0);

	return (*cPais::getListaPaises())[pospais];
}

void TropasdeBatalla(cPais* PaisAtaque, cListaT<cTropa>* TropasBatalla)
{
	unsigned int canttropas = 0;
	unsigned int nTropa = 0;
	cTropa* aux = NULL;
	do {
		cout << " Introduzca la cantidad de tropas con las que quiere atacar. (MAXIMO DE 3): ";
		cin >> canttropas;
	} while (canttropas > 3 || canttropas < 1 || PaisAtaque->getTropas()->getCA() - 1 < canttropas);

	for (unsigned int i = 0; i < canttropas; i++)
	{
		do
		{
			cout << " Introduzca el numero de tropa #" << i+1 << " :";
			cin >> nTropa;
			aux = PaisAtaque->VerificarTropa(nTropa);
		} while (aux == NULL);
		try { (*TropasBatalla) + aux; }
		catch (exception* ex)
		{
			cout<<ex->what();
			delete ex;
			cout << "INGRESE LOS DATOS NUEVAMENTE"<< endl;
			Sleep(1500); 
			TropasdeBatalla(PaisAtaque, TropasBatalla);
		}
	}
}

cJuego::cJuego(unsigned int cantjugadores)
{
	Jugadores = new cListaT<cJugador>[cantjugadores];
	Mundo = new cMundo(); 
	TurnoPrevio = 0;
}

cJuego::~cJuego(){

}

void cJuego::AsignarTurno(){
	if (Rondas % (Jugadores->getCA())== 0)
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
			TurnoPrevio++; //TODO: aca no imprime y debe imprimir
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
	bool renunciar = false;
	(*Jugadores)[pos]->setEstado(eEstadoJugador::ATACANDO);
	cPais* paisAtaque = NULL;
	do {
		try
		{
			paisAtaque = PosPaisAtaque((*Jugadores)[pos]);
		}
		catch (exception* ex)
		{
			cout << ex->what() << endl;
			delete ex;
			break; //para que rompa el do-while ya que el jugador no puede atacar con nada
		}

		cPais* paisAtacado = PosPaisAtacado((*Jugadores)[pos], paisAtaque);
		cListaT<cTropa>* MiniListaTropas = new cListaT<cTropa>(false, 3); //le pusimos false :)
		TropasdeBatalla(paisAtaque, MiniListaTropas);

		Batallar((*Jugadores)[pos], paisAtacado, paisAtaque, MiniListaTropas); //Todo lo que le pasamos a batallar est� chequeado

		cant++;
		ImprimirEstados(); //en cada vuelta se imprimen los estados para saber que onda como viene el mundo
		delete MiniListaTropas;
		renunciar=(*Jugadores)[pos]->RenunciarTurno();
		if ((*Jugadores)[pos]->getEstado() != eEstadoJugador::GANADOR)
			cant = 4;
	} while (cant < 3 || !renunciar);
	
	if ((*Jugadores)[pos]->getEstado() != eEstadoJugador::GANADOR && paisAtaque != NULL)
	{
		Reagrupar(pos, paisAtaque);// le permitimos a los jugadores reagrupar al final del turno independientemente de si gano o no al pais al que batallo (desde el ultimo pais que atacaron a limitrofes de su posesion)
		(*Jugadores)[pos]->setEstado(eEstadoJugador::ESPERANDO);
	}
}

void cJuego::Batallar(cJugador* JugadorAtacante, cPais* PaisAtacado, cPais* PaisAtacante, cListaT<cTropa>* Tropas) {
	
	cListaT<cTropa>* ListaTropaDef = PaisAtacado->CrearMiniListaRandom();
	cJugador* JugadorAtacado = DuenioPais(PaisAtacado); //Buscamos el due�o del pais atacado
	JugadorAtacado->setEstado(eEstadoJugador::DEFENDIENDO);
	unsigned int AT_Efectivo = JugadorAtacante->AtaqueEfectivo(Tropas, ListaTropaDef); //calcula el da�o base que se va a realizar
	
	if (JugadorAtacado == NULL)
		throw new exception("El pais no tiene duenio"); //si esto pasa es porque algo hicimos mal
	
	unsigned int AT_Defensa_Base = JugadorAtacado->AtaqueEfectivo(ListaTropaDef, Tropas);

	try
	{
		PaisAtacante->RecibirDanio(AT_Defensa_Base, Tropas);
		PaisAtacado->RecibirDanio(AT_Efectivo, ListaTropaDef); 
		//TODO: NO ESTA ENTRANDO AL CATCH
	}
	catch (exception* ex)
	{
		cout << ex->what() << endl; //SI ENTRA ES PORQUE PERDIO EL ATACADO DOMINIO DEL PAIS
		JugadorAtacado->PerderPais(PaisAtacado);
		JugadorAtacante->GanarPais(PaisAtacado);
		JugadorAtacante->Reagrupar(PaisAtacante, PaisAtacado);
		if (JugadorAtacado->getCantPaises() == 0)
			(*Jugadores) - JugadorAtacado; //BORRAMOS AL JUGADOR SI NO TIENE PAISES
		if (JugadorAtacante->getCantPaises() == cPais::getListaPaises()->getCA())
			JugadorAtacante->setEstado(eEstadoJugador::GANADOR); //PARA VER SI GANO EL ATACANTE VER QUE TENGA TODOS LOS PAISES DEL MUNDO
	}	
}

cJugador* cJuego::DuenioPais(cPais *Pais) {
	for (unsigned int i = 0; i < Jugadores->getCA(); i++)
		if (*(*Jugadores)[i] == Pais)
			return (*Jugadores)[i];
	
	return NULL;
}

void cJuego::ImprimirEstados() const {
	
	cout << *Jugadores;
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
		string error = ex->what();
		delete ex;
		ex = new exception(("Error en SetUpMundo: " + error).c_str());
		throw ex;
	}
}

void cJuego::SetUpJugadores()
{
	Jugadores->Agregar(new cJugador());
}

void cJuego::Reagrupar(unsigned int pos, cPais* PaisAtacante)
{
	(*Jugadores)[pos]->Reagrupar(PaisAtacante);
}

void cJuego::FindeRondaEntera()
{
	for (unsigned int i = 0; i < Jugadores->getCA(); i++)
		(*Jugadores)[i]->AgregarTropas();
}

cJugador* cJuego::BuscarXEstado(eEstadoJugador estado) const
{
	for (unsigned int i = 0; i < Jugadores->getCA(); i++)
		if ((*Jugadores)[i]->getEstado() == estado)
			return (*Jugadores)[i];
	throw new runtime_error("Error en BuscarXEstado");
}

void cJuego::AsignarPaisesRandom()
{
	float Division = (float)Mundo->GetLista()->getCA() / Jugadores->getCA(); //divido paises por cant jugadores

	cListaT<cPais>* CopiaLista = new cListaT<cPais>(*(cPais::getListaPaises())); //me copio a los paises para dsp repartirlos

	unsigned int PaisesSobrantes = CalcularResiduo(Mundo->GetLista()->getCA(), Jugadores->getCA()); //calculo los que sobran con cantidad paises, cantidad jugadores

	for (unsigned int k = 0; k < Jugadores->getCA(); k++) { //recorro la lista de jugadores

		for (unsigned int i = 0; i < (unsigned int)Division; i++) //lo repito para la cantidad de pais que le toca al jugador
		{ 
			unsigned int random = rand() % CopiaLista->getCA(); //elijo el pais que voy a repartir

			(*CopiaLista)[random]->AsignarTropas(); //asigno una tropa para cada pais

			(*Jugadores)[k]->GanarPais(CopiaLista->QuitarXPos(random)); //Aca estamos asignando el pais al jugador
		}

		if (PaisesSobrantes > 0) { //si sobran paises se los doy a los primeros :)
			unsigned int random = rand() % CopiaLista->getCA(); //elijo pais random
			(*CopiaLista)[random]->AsignarTropas(); //le asigno una tropa
			(*Jugadores)[k]->GanarPais(CopiaLista->QuitarXPos(random)); //Aca estamos asignando el pais al jugador
			PaisesSobrantes--; //quedan menos paises sobrantes
		}
	}

	for (int k = 0; k < Jugadores->getCA(); k++) //recorro lista de jugadores
	{
		system("cls");
		ImprimirEstados();
		(*Jugadores)[k]->AgregarTropas(); //asigno las tropas extras para dsp poder empezar el juego
	}

	delete CopiaLista;
}

int cJuego::getRondas() 
{
	return Rondas;
}

cMundo* cJuego::getMundo() const
{
	return Mundo;
}
