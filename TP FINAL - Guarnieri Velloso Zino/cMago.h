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

	cMago();
	~cMago();

#pragma endregion

	unsigned int CondicionAtaque(cGuerrero* Atacado);
	/**
	* GenerarAT
	* devuelve un numero random entre .Este es la fuerza de ataque de una sola unidad
	* @return unsigned int
	*/
	unsigned int GenerarAT();

};
#endif // !defined(EA_DDB78A6D_FFB6_43b8_9A90_EB602687C8BF__INCLUDED_)
