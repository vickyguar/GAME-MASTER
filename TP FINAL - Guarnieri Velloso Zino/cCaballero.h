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

	cCaballero(unsigned int _AT, unsigned int _HP_ACTUAL, unsigned int _HP_INICIAL);
	~cCaballero();

#pragma endregion

#pragma region GENERADORES

	unsigned int GenerarAT();

#pragma endregion

	unsigned int CondicionAtaque(cGuerrero* Atacado);
	void Contrataque();

};
#endif // !defined(EA_9AC6C449_ED7E_4e46_8F84_741DAFDA5EC4__INCLUDED_)
