///////////////////////////////////////////////////////////
//  cTropa.h
//  Implementation of the Class cTropa
//  Created on:      01-jun.-2021 20:42:40
//  Original author: vguar
///////////////////////////////////////////////////////////

#if !defined(EA_48AC6C59_7B06_45a6_B915_81B52F35D200__INCLUDED_)
#define EA_48AC6C59_7B06_45a6_B915_81B52F35D200__INCLUDED_

#include "cGuerrero.h"

class cTropa
{

public:
	cTropa();
	virtual ~cTropa();
	cGuerrero *m_cGuerrero;

	unsigned int CalcularAT_Total();
	void RecibirDanio(unsigned int AT_Ataque);

private:
	unsigned int AT_Total;
	int NumTropa;

};
#endif // !defined(EA_48AC6C59_7B06_45a6_B915_81B52F35D200__INCLUDED_)
