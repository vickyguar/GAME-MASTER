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
	cGuerrero(unsigned int _AT, unsigned int _AT_Especial, unsigned int _HP_Actual, unsigned int _HP_Inicial, unsigned int _LimiteVide);
	virtual ~cGuerrero();

	virtual unsigned int CondicionAtaque(cGuerrero* Atacado) = 0; //Podemos hacerlo como los chicos con un template
	unsigned int getAT() const;

protected:
	unsigned int AT;
	unsigned int HP_Actual;
	unsigned int HP_Inicial;

};
#endif // !defined(EA_86F03F75_F4B2_4011_AD66_663180BE8617__INCLUDED_)
