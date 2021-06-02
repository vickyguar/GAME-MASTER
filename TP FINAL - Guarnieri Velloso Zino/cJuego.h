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

class cJuego
{
private:
	cListaT<cJugador>* Jugadores;
public:
	cJuego();
	~cJuego();

	void AsignarTurno(cJugador* Jugador);
	void Batalla(cJugador* Jugador1, cPais* PaisAtacado, cPais* PaisAtacante, cTropa*** Tropas);
	void ImprimirEstados() const;
	cJugador* SetUp();

};
#endif // !defined(EA_D34FED27_7152_41ec_81AD_94CE58A64212__INCLUDED_)
