///////////////////////////////////////////////////////////
//  cJugador.h
//  Implementation of the Class cJugador
//  Created on:      01-jun.-2021 20:42:40
//  Original author: vguar
///////////////////////////////////////////////////////////

#if !defined(EA_B34E5789_D7AB_47b3_BFBB_ABFA2C7A92ED__INCLUDED_)
#define EA_B34E5789_D7AB_47b3_BFBB_ABFA2C7A92ED__INCLUDED_


#include "cPais.h"
#include "Enums.h"
class cJugador
{

private:
	eEstadoJugador Estado;
	const string Username;
	cListaT<cPais>* Paises;

public:
	cJugador(string _Username,eEstadoJugador _Estado=eEstadoJugador::ESPERANDO);
	~cJugador();


	unsigned int AtaqueEfectivo(cPais* PaisAtacante, cTropa*** Tropas);
	void Defender(cPais* PaisAtacado, unsigned int AT_Contrincante);
	void Reagrupar();
	bool RenunciarTurno();
	void setEstado(eEstadoJugador _Estado=eEstadoJugador::ATACANDO);
	void AgregarTropas();
	eEstadoJugador getEstado();
	string getUsername();

};
#endif // !defined(EA_B34E5789_D7AB_47b3_BFBB_ABFA2C7A92ED__INCLUDED_)
