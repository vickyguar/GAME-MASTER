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
	eEstadoJugador Estado; //si esta atacando, defendiendo, esperando, etc...
	const string Username; //nombre de usuario
	cListaT<cPais>* Paises; //lista de paises en su dominio

public:
#pragma region CONSTRUCTORES & DESTRUCTORES
	/**
	* cJugador
	* constructor de la clase cJugador
	*/
	cJugador(string _Username, eEstadoJugador _Estado = eEstadoJugador::ESPERANDO);
	/**
	* cJugador
	* constructor de la clase cJugador
	*/
	~cJugador();

#pragma endregion
	/**
	* AtaqueEfectivo 
	* calcula la fuerza total con la que va a tacar las tropas que se mandan a batallar
	* @param pais que ataca, unidad de ataque
	* @return int
	*/
	unsigned int AtaqueEfectivo(cPais* PaisAtacante, cListaT<cTropa>* Tropas);
	/**
	* Defender
	* el pais atacado se defiende, y recibe el AT del contrincante (el daño que le hace)
	* @param pais atacado, daño
	*/
	void Defender(cPais* PaisAtacado, unsigned int AT_Contrincante);
	/**
	* Reagrupar
	* reordena las tropas. Es decir que se pueden juntar, en el caso de que queden pocas unidades
	* o se pueden separar (para tener más unidades)
	*/
	void Reagrupar();
	/**
	* RenunciarTurno
	* le pregunta al usuario si quiere seguir jugando o si termina su turno
	* (puede atacar hasta 3 veces)
	* @return bool
	*/
	bool RenunciarTurno();
	/**
	* AgregarTropas
	* recibe la cantidad de tropas que le corresponde poner al jugador, dependiendo de la cantidad de paises que tenga
	* se agregan esas tropas a un pais aleatorio (este pais debe pertenecer a la lista que tiene el jugador de paiese 
	* en su dominio). TODO: terminar de decidir si es ramdom o no
	* @param int num
	*/
	void AgregarTropas();

#pragma region SETTES & GETTERS

	void setEstado(eEstadoJugador _Estado = eEstadoJugador::ATACANDO);
	eEstadoJugador getEstado();
	string getUsername();

#pragma endregion
	bool VerificarPais(int pospais);

};
#endif // !defined(EA_B34E5789_D7AB_47b3_BFBB_ABFA2C7A92ED__INCLUDED_)
