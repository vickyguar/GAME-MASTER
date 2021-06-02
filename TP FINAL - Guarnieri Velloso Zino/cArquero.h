///////////////////////////////////////////////////////////
//  cArquero.h
//  Implementation of the Class cArquero
//  Created on:      01-jun.-2021 20:42:39
//  Original author: vguar
///////////////////////////////////////////////////////////

#if !defined(EA_1D30E1A9_0ECE_4a1f_8499_7609DA9E69C2__INCLUDED_)
#define EA_1D30E1A9_0ECE_4a1f_8499_7609DA9E69C2__INCLUDED_

#include "cGuerrero.h"

class cArquero : public cGuerrero
{

public:
	cArquero();
	~cArquero();

	bool AtaqueAleatorio();
	unsigned int CondicionAtaque(cGuerrero* Atacado);
	unsigned int GenerarAT();
	unsigned int GenerarHP();

};
#endif // !defined(EA_1D30E1A9_0ECE_4a1f_8499_7609DA9E69C2__INCLUDED_)
