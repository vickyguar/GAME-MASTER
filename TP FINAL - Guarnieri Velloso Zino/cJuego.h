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
	cListaT<cJugador>* Jugadores;
	static unsigned int Rondas;
	unsigned int TurnoPrevio;
	cMundo* Mundo;

public:
	cJuego(unsigned int cantjugadores);
	~cJuego();

	void AsignarTurno();
	void JugadorAtacando(unsigned int pos);
	void Batallar(cJugador* Jugador1, cPais* PaisAtacado, cPais* PaisAtacante, cTropa*** Tropas);
	void ImprimirEstados() const;
	void SetUp(unsigned int mundo);
	void SetUpJugadores(string nombre);

	unsigned int CalcularResiduo(int Num1, int Num2);
	//int* ReparticionPaises();
	void AsignarPaisesRandom();
	static int getRondas();
	cJugador* getJugadorAtacante();
};
#endif // !defined(EA_D34FED27_7152_41ec_81AD_94CE58A64212__INCLUDED_)
