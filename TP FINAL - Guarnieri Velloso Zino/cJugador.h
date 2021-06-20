///////////////////////////////////////////////////////////
//  cJugador.h
//  Implementation of the Class cJugador
//  Created on:      01-jun.-2021 20:42:40
//  Original author: vguar
///////////////////////////////////////////////////////////

#if !defined(EA_B34E5789_D7AB_47b3_BFBB_ABFA2C7A92ED__INCLUDED_)
#define EA_B34E5789_D7AB_47b3_BFBB_ABFA2C7A92ED__INCLUDED_


#include "cPais.h"
class cJuego;
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
	unsigned int AtaqueEfectivo(cListaT<cTropa>* TropasAt, cListaT<cTropa>* TropasDef);
	/**
	* Defender
	* el pais atacado se defiende, y recibe el AT del contrincante (el daño que le hace)
	* @param pais atacado, daño
	*/
	//void Defender(cPais* PaisAtacado, unsigned int AT_Contrincante);
	/**
	* Reagrupar
	* reordena las tropas. Es decir que se pueden juntar, en el caso de que queden pocas unidades
	* o se pueden separar (para tener más unidades)
	*/
	void Reagrupar(cPais* PaisOrigen,cPais*Destino=NULL);
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
	* en su dominio). 
	* @param int num
	*/
	void AgregarTropas();

	void GanarPais(cPais* Pais);

	void PerderPais(cPais* Pais);

	string To_string()const;

#pragma region SETTES & GETTERS

	void setEstado(eEstadoJugador _Estado = eEstadoJugador::ATACANDO);
	eEstadoJugador getEstado();
	string getClave();
	unsigned int getCantPaises() { return Paises->getCA(); }
#pragma endregion
	bool VerificarMiPais(cPais*ptr); //verifica si el pais es mio

	bool operator==(cPais* Pais) { //Esto no es para comparar, es para ver si existe en la lista de paises del jugador
		return VerificarMiPais(Pais);
	}
	bool operator!=(cPais* Pais) {
		return !(*this == Pais);
	}
	//TODO: sobrecarga cout (IMPRIME EL NUMERO DEL PAIS CORRESPONDIENTE AL NUMERO DEL JUGADOR)
	/*
	* VerificarAtaque 
	* me fijo si hay limitrofes a los cuales atacar (recordar lo que paso con Chile)
	* @param: Pais
	* @return bool (true si hay limitrofes)
	*/
	bool VerficarAtaque(cPais* Pais);
	/*
	* VerificarAtaque
	* verifico que tengo otro pais para atacar (debe cumplir con condiciones)
	* @param: Pais
	* @return bool
	*/
	bool VerifcarPaisDispo(cPais* Pais); //
};

#endif // !defined(EA_B34E5789_D7AB_47b3_BFBB_ABFA2C7A92ED__INCLUDED_)
