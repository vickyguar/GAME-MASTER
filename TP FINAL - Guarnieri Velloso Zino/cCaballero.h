///////////////////////////////////////////////////////////
//  cCaballero.h
//  Implementation of the Class cCaballero
//  Created on:      01-jun.-2021 20:42:39
//  Original author: vguar
///////////////////////////////////////////////////////////

#if !defined(EA_9AC6C449_ED7E_4e46_8F84_741DAFDA5EC4__INCLUDED_)
#define EA_9AC6C449_ED7E_4e46_8F84_741DAFDA5EC4__INCLUDED_

#include "cGuerrero.h"

class cCaballero : public cGuerrero
{

private:

	unsigned int AT_Contrataque; //0.25% AT

public:
#pragma region CONSTRUCTORES & DESTRUCTORES
	/**
	* cCaballero
	* constructor de la clase cCaballero
	*/
	cCaballero();
	/**
	* ~cCaballero
	* destructor de la clase cCaballero
	*/
	~cCaballero();

#pragma endregion

#pragma region GENERADORES
	/**
	* GenerarAT
	* devuelve un numero random entre .Este es la fuerza de ataque de una sola unidad
	* @return unsigned int
	*/
	unsigned int GenerarAT();

#pragma endregion
	
	unsigned int CondicionAtaque(cGuerrero* Atacado);
	/**
	* Contrataque //TODO: terminar comentario
	*/
	void Contrataque();
};
#endif // !defined(EA_9AC6C449_ED7E_4e46_8F84_741DAFDA5EC4__INCLUDED_)
