///////////////////////////////////////////////////////////
//  cJugador.h
//  Implementation of the Class cJugador
//  Created on:      01-jun.-2021 20:42:40
//  Original author: vguar
///////////////////////////////////////////////////////////

#if !defined(EA_B34E5789_D7AB_47b3_BFBB_ABFA2C7A92ED__INCLUDED_)
#define EA_B34E5789_D7AB_47b3_BFBB_ABFA2C7A92ED__INCLUDED_

#include "string.h"
#include "cPais.h"

class cJugador
{

public:
	cJugador();
	virtual ~cJugador();
	cPais *m_cPais;

	unsigned int AtaqueEfectivo(cPais* PaisAtacante, cTropa*** Tropas);
	void Defender(cPais* PaisAtacado, unsigned int AT_Contrincante);
	void Reagrupar(cPais* PaisOrigen, cPais* PaisDestino, unsigned int CantTropas, unsigned int NumTropa);
	bool RenunciarTurno();

private:
	eEstadoJugador Estado;
	const string Username;

};
#endif // !defined(EA_B34E5789_D7AB_47b3_BFBB_ABFA2C7A92ED__INCLUDED_)
