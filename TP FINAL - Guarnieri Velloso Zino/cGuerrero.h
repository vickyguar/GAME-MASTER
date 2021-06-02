///////////////////////////////////////////////////////////
//  cGuerrero.h
//  Implementation of the Class cGuerrero
//  Created on:      01-jun.-2021 20:42:39
//  Original author: vguar
///////////////////////////////////////////////////////////

#if !defined(EA_86F03F75_F4B2_4011_AD66_663180BE8617__INCLUDED_)
#define EA_86F03F75_F4B2_4011_AD66_663180BE8617__INCLUDED_

#include <string>
#include <iostream>

using namespace std;

class cGuerrero
{

public:
	cGuerrero();
	virtual ~cGuerrero();

	virtual unsigned int CondicionAtaque(cGuerrero* Atacado); //Podemos hacerlo como los chicos con un template
	virtual unsigned int GenerarAT();
	virtual unsigned int GenerarHP();

protected:
	unsigned int AT;
	unsigned int AT_Especial;
	unsigned int HP_Actual;
	unsigned int HP_Inicial;
	unsigned int LimiteVida;

};
#endif // !defined(EA_86F03F75_F4B2_4011_AD66_663180BE8617__INCLUDED_)
