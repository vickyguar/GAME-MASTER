///////////////////////////////////////////////////////////
//  cJuego.h
//  Implementation of the Class cJuego
//  Created on:      01-jun.-2021 20:42:39
//  Original author: vguar
///////////////////////////////////////////////////////////

#if !defined(EA_D34FED27_7152_41ec_81AD_94CE58A64212__INCLUDED_)
#define EA_D34FED27_7152_41ec_81AD_94CE58A64212__INCLUDED_

#include "cJugador.h"
#include "cListaT.h"
#include "cMundo.h"

class cJuego
{
private:
	cListaT<cJugador>* Jugadores; //lista de jugadores
	static unsigned int Rondas; //contador de la cantidad de rondas
	unsigned int TurnoPrevio; //el numero del turno previo
	cMundo* Mundo; //ptr a mundo

public:
#pragma region CONSTRUCTORES & DESTRUCTORES

	/**
	* cJuego
	* constructor de la clase cJuego
	*/
	cJuego(unsigned int cantjugadores);
	/**
	* ~cJuego
	* destructor de la clase cJuego
	*/
	~cJuego();

#pragma endregion

#pragma region METODOS DEL JUEGO

#pragma endregion

	void AsignarTurno();
	void JugadorAtacando(unsigned int pos);
	void Batallar(cJugador* Jugador1, cPais* PaisAtacado, cPais* PaisAtacante, cListaT<cTropa>* Tropas);
	
	void Reagrupar(unsigned int pos);
	void FindeRondaEntera();

#pragma region SETUP'S

	void SetUpMundo(unsigned int mundo);
	void SetUpJugadores(string username);

#pragma endregion

#pragma region GETTERS & SETTERS

	static int getRondas();
	cJugador* getJugadorAtacante();

#pragma endregion

#pragma region IMPRIMIR & TO STRING

	void ImprimirEstados() const;

#pragma endregion

	//int* ReparticionPaises();
	void AsignarPaisesRandom();
};

static unsigned int CalcularResiduo(int Num1, int Num2);
#endif // !defined(EA_D34FED27_7152_41ec_81AD_94CE58A64212__INCLUDED_)
