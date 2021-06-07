///////////////////////////////////////////////////////////
//  cPais.h
//  Implementation of the Class cPais
//  Created on:      01-jun.-2021 20:42:40
//  Original author: vguar
///////////////////////////////////////////////////////////

#if !defined(EA_B1B84F12_99FE_46f8_81E7_71FAB22C81F1__INCLUDED_)
#define EA_B1B84F12_99FE_46f8_81E7_71FAB22C81F1__INCLUDED_

#include <string>
#include <vector>
#include "Enums.h"
#include "cTropa.h"

using namespace std;

class cPais
{

private:
	string Nombre;
	cListaT<cTropa>* cTropas;
	const vector<string> ListaLimitrofes;
	static cListaT<cPais> ListaPaises;

public:
#pragma region CONSTRUCTORES & DESTRUCTORES

	cPais(string Nombre, vector<string> Limitrofes);
	cPais(cPais& Pais);
	~cPais();

#pragma endregion

	unsigned int CalcularAT_Tropas(cListaT<cTropa>* Tropas);
	void ModificarTropa(cTropa* NumTropa1, cTropa* NumeroTropa2);
	void VerificarLimitrofes(cPais* PaisLimitrofe);
	void AsignarTropasRandom(); //es random

#pragma region GETTERS & SETTERS

	vector<string> GetListaLimitrofes();

#pragma endregion

};
#endif // !defined(EA_B1B84F12_99FE_46f8_81E7_71FAB22C81F1__INCLUDED_)
