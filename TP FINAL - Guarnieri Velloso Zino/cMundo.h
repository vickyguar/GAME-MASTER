#pragma once
#include "cListaT.h"
#include "cPais.h"
#include <stdlib.h>

class cMundo
{
private:
	cListaT<cPais>* ListaPaises;

public:
#pragma region CONSTRUCTORES & DESTRUCTORES

	cMundo(); //esta lista sale del archivo
	~cMundo();
#pragma endregion


	bool Divisible(int Num1, int Num2);
	void SetUpMundo(string** NombresPaises);
	unsigned int CalcularResiduo(int Num1, int Num2);
	int* ReparticionPaises();
	void AsignarPaisesRandom(int CantPaises);

#pragma region METODOS DE ARCHIVOS
	//TODO: FILE OPEN (etc)
	//20) Crear un archivo vacio (Usuarios.dat), en el caso que no exista
	void CreArchivo(const char* nombre);
	//21) Leer los jugadores cargados en el archivo
	void LeerArchivo(const char* nombre, Usuarios*& lista, int cant);
	//22) Calcula la cantidad de usuarios cargados en el archivo
	int Cantidad_Jugadores(const char* nombre);
	//23) Guardar los cambios en los jugadores en el archivo
	int Escribir_Archivo(Usuarios* lista, int cant, const char* nombre);
	//24) Imprime la lista de usuarios junto con la cantidad de partidas ganadas/perdidas
	void ImprimirUsuarios(Usuarios* lista, int* cant);
#pragma endregion

};

