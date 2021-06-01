///////////////////////////////////////////////////////////
//  cPais.h
//  Implementation of the Class cPais
//  Created on:      01-jun.-2021 20:42:40
//  Original author: vguar
///////////////////////////////////////////////////////////

#if !defined(EA_B1B84F12_99FE_46f8_81E7_71FAB22C81F1__INCLUDED_)
#define EA_B1B84F12_99FE_46f8_81E7_71FAB22C81F1__INCLUDED_

#include <string>
#include "cTropa.h"
#include "cLimítrofes.h"

class cPais
{

public:
	cPais();
	virtual ~cPais();
	cTropa *m_cTropa;
	cLimítrofes *m_cLimítrofes;
	cPais *m_cPais;

	unsigned int CalcularAT_Tropas(cTropa*** Tropas);
	void ModificarTropa(cTropa* NumTropa1, bool Unificar, cTropa* NumeroTropa2);
	void VerificarLimitrofes(cPais* PaisLimitrofe);

private:
	const string Continente;
	string Nombre;

};
#endif // !defined(EA_B1B84F12_99FE_46f8_81E7_71FAB22C81F1__INCLUDED_)
