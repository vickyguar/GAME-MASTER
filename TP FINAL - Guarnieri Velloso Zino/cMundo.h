#pragma once
#include "cListaT.h"
#include "cPais.h"
#include <stdlib.h>

class cMundo
{
private:
	cListaT<cPais>* ListaPaises;
	void LeerArchivo(const char* Filename);

public:
#pragma region CONSTRUCTORES & DESTRUCTORES

	cMundo(); //esta lista sale del archivo
	~cMundo();
#pragma endregion


	bool Divisible(int Num1, int Num2);

	void PaisesLimitrofes(string& Limitrofes, string nombre); //Crear array de strings con nombres de paises limitrofes PARA 1 SOLO PAIS
	string BuscarNombrePais(string str, char separator, int* pos);
	void SetUpMundo(const char* Filename);
	cListaT<cPais>* GetLista();
#pragma region METODOS DE ARCHIVOS


#pragma endregion

};

