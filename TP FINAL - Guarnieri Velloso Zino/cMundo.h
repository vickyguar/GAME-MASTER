#pragma once

#include <stdlib.h>
#include "cListaT.h"
#include "cPais.h"

class cMundo
{
private:
	cListaT<cPais>* ListaPaises;

#pragma region METODOS DE ARCHIVOS

	void LeerArchivo(const char* Filename);

#pragma endregion
	
public:
#pragma region CONSTRUCTORES & DESTRUCTORES

	cMundo(); //esta lista sale del archivo
	~cMundo();
#pragma endregion

#pragma region SET UP

	void PaisesLimitrofes(string& Limitrofes, string NombrePais); //Crear array de strings con nombres de paises limitrofes PARA 1 SOLO PAIS
	string BuscarNombrePais(string str, char separator, int* pos);
	void SetUp(const char* Filename);

#pragma endregion

#pragma region GETTERS & SETTERS

	cListaT<cPais>* GetLista();

#pragma endregion
};

