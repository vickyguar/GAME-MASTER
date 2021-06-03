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

using namespace std;

class cPais
{

private:
	//const string Continente;
	string Nombre;
	cListaT<cTropa>* cTropas;
	cListaT<cPais>* Limitrofes;

public:
	cPais(string Nombre);
	cPais(cPais &Pais);
	~cPais();

	unsigned int CalcularAT_Tropas(cTropa*** Tropas);
	void ModificarTropa(cTropa* NumTropa1, bool Unificar, cTropa* NumeroTropa2);
	void VerificarLimitrofes(cPais* PaisLimitrofe);

	void setLimitrofes(cPais* Limitrofe);

};
#endif // !defined(EA_B1B84F12_99FE_46f8_81E7_71FAB22C81F1__INCLUDED_)
