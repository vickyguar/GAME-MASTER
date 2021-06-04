#pragma once
#include "cListaT.h"
#include "cPais.h"
#include <stdlib.h>

class cMundo
{
private:
	cListaT<cPais>* ListaPaises;
	string Limitrofes; //se usa solo para leer el archivo

public:
#pragma region CONSTRUCTORES & DESTRUCTORES

	cMundo(); //esta lista sale del archivo
	~cMundo();
#pragma endregion


	bool Divisible(int Num1, int Num2);
	void SetUpMundo(string** NombresPaises);
	cListaT<cPais>* GetLista(); 

	void PaisesLimitrofes(string*& Limitrofes, string nombre); //Crear array de strings con nombres de paises limitrofes PARA 1 SOLO PAIS
	unsigned int LineCount(string str) const; //BUSCAR LA CANTIDAD DE LINEAS
	string BuscarNombrePais(string str, char separator, int* pos);
	//void PaisesLimitrofes_plural(string* Limitrofes);

	string GetLimitrofes() { return Limitrofes; }
#pragma region METODOS DE ARCHIVOS
	//20) Crear un archivo vacio (Usuarios.dat), en el caso que no exista
	//void CreArchivo(const char* nombre);
	//21) Leer los jugadores cargados en el archivo
	void LeerArchivo(const char* Filename, string* Limitrofes);
	//22) Calcula la cantidad de usuarios cargados en el archivo
	//int Cantidad_Jugadores(const char* nombre);
	//23) Guardar los cambios en los jugadores en el archivo
	//int Escribir_Archivo(Usuarios* lista, int cant, const char* nombre);
	//24) Imprime la lista de usuarios junto con la cantidad de partidas ganadas/perdidas
	//void ImprimirUsuarios(Usuarios* lista, int* cant);
#pragma endregion

};

