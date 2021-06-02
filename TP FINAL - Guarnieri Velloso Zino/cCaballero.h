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

public:
	cCaballero();
	~cCaballero();

	unsigned int CondicionAtaque(cGuerrero* Atacado);
	void Contrataque();
	unsigned int GenerarAT();
	unsigned int GenerarHP();

private:
	/**
	 * 0.25% AT
	 */
	unsigned int AT_Contrataque;

};
#endif // !defined(EA_9AC6C449_ED7E_4e46_8F84_741DAFDA5EC4__INCLUDED_)
