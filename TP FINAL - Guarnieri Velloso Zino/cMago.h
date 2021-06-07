///////////////////////////////////////////////////////////
//  cMago.h
//  Implementation of the Class cMago
//  Created on:      01-jun.-2021 20:42:40
//  Original author: vguar
///////////////////////////////////////////////////////////

#if !defined(EA_DDB78A6D_FFB6_43b8_9A90_EB602687C8BF__INCLUDED_)
#define EA_DDB78A6D_FFB6_43b8_9A90_EB602687C8BF__INCLUDED_

#include "cGuerrero.h"

class cMago : public cGuerrero
{

public:
#pragma region CONSTRUCTORES & DESTRUCTORES

	cMago(unsigned int _AT, unsigned int _HP_ACTUAL, unsigned int _HP_INICIAL);
	~cMago();

#pragma endregion

	

	unsigned int CondicionAtaque(cGuerrero* Atacado);
	unsigned int GenerarAT();

};
#endif // !defined(EA_DDB78A6D_FFB6_43b8_9A90_EB602687C8BF__INCLUDED_)
