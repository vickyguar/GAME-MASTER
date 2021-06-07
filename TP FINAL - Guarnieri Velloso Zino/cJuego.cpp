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
	if (Rondas % (Jugadores->getCA()) == 0)
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
	FindeRondaEntera();
}

void cJuego::JugadorAtacando(unsigned int pos)
{
	unsigned int cant = 0;
	unsigned int pospais;
	do {
		//TODO:INFO PARA BATALLAR. VERIFICACIONES REDUCIR EN METODOS MINIS (RECURSIVIDAD)
		ImprimirEstados();
		/*cout << "\n ---- JUGADOR " << (*Jugadores)[pos]->getUsername() <<" ---- "<< endl;
		cout<<" Introduzca el numero pais desde el que quiere atacar: \n";
		cin >> pospais;
		cPais* paisAtaque = (*Jugadores)[pos]->(*getListaPaises())[pospais];

		cout << " Introduzca el numero pais al que quiere atacar: \n";
		cin >> pospais;
		//busca en la lista static, chequea limitrofes
		//cPais*paisAtacado=

		//TODO: METODO PARA ELEGIR TRES TROPAS QUE DEVUELVE cListaT TROPAS
		cout << " Introduzca el numero de tropas con las que quiere atacar: \n";
		cin >> pospais;
		cPais* paisAtaque = (*Jugadores)[pos]->(*getListaPaises())[pospais];

		Batallar((*Jugadores)[pos], paisAtaque, paisAtacado, Tropas);*/

		Reagrupar(pos);
		cant++;
		ImprimirEstados(); //en cada vuelta se imprimen los estados para saber que onda como viene el mundo
	} while (cant < 3 || !((*Jugadores)[pos]->RenunciarTurno()) || (*Jugadores)[pos]->getEstado() != eEstadoJugador::GANADOR);
}


void cJuego::Batallar(cJugador* Jugador1, cPais* PaisAtacado, cPais* PaisAtacante, cListaT<cTropa>* Tropas){

}


void cJuego::ImprimirEstados() const {

}


void cJuego::SetUp(unsigned int mundo){
	
	string str = "MUNDO " + to_string(mundo)+ ".txt"; //nombre del archivo
	const char* Filename = str.c_str();
	try
	{
		Mundo->LeerArchivo(Filename, &Mundo->GetLimitrofes());
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

void cJuego::Reagrupar(unsigned int pos)
{
	(*Jugadores)[pos]->Reagrupar();
}

void cJuego::FindeRondaEntera()
{
	for (unsigned int i = 0; i < Jugadores->getCA(); i++)
	{
		(*Jugadores)[i]->AgregarTropas();
	}
}

unsigned int cJuego::CalcularResiduo(int Num1, int Num2)
{
	if (Num2 != 0)
	{
		float Division = Num1 / Num2;
		int ParteEntera = Num1 / Num2;
		int Residuo = (Division - ParteEntera) * Num2;
		return Residuo;
	}
	else
		throw new exception(" --- Division por cero --- ");
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
