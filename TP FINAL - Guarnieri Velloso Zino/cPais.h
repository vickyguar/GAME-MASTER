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
	string Nombre; //nombre del pais
	cListaT<cTropa>* Tropas; //lista de tropas que tiene el pais
	const vector<string> ListaLimitrofes; //lista de nombres de los paises limitrofes
	static cListaT<cPais>* ListaPaises; //lista estatica de paises

public:
#pragma region CONSTRUCTORES & DESTRUCTORES

	/**
	*cPais
	* constructor de la clase cPais (por parametro)
	* @param nombre, lista limitrofes
	*/
	cPais(string Nombre, vector<string> Limitrofes);
	/**
	*cPais
	* constructor de la clase cPais (por copia)
	*/
	cPais(cPais& Pais);
	/**
	* ~cPais
	* destructor de la clase cPais
	*/
	~cPais();

#pragma endregion

	/**
	* CalcularAT_Tropas
	* recibe una lista de tropas (lista peque�a de unidad de ataque), 
	* la recorre y acumula los AT de cada unidad en particular. Retorna el acumulador
	* @param Lista Torpa
	* @return int
	*/
	unsigned int CalcularAT_Tropas(cListaT<cTropa>* Tropas);
	/**
	* VerificarLimitrofes 
	* verifica que 2 paises sean limitrofes. Se recorre la lista estatica y se la compara con la lista de limitrofes
	* que tiene el pais
	* @param cPais*
	*/
	bool VerificarLimitrofes(cPais* PaisLimitrofe);
	/**
	* AsignarTropasRandom 
	* al principio del juego, se le asigna a cada jugador un numero random de tropas en sus paises
	*/
	void AsignarTropas(cTropa* Tropa = NULL);
	/**
	* JuntarTropas
	* transfiere unidades de una tropa a la otra 
	*
	* @param tropa1, tropa2
	*/
	void JuntarTropas();
	/**
	*  ValidarTropas 
	*  verifica que ambas sean del jugador e igual tipo
	*/
	void ValidarTropas(string ID1, string ID2);

	//si no le paso nada es porque lo estoy llamando para comenzar el juego
	cTropa* VerificarTropa(unsigned int NTropa);

	cListaT<cTropa>* CrearMiniListaRandom();
	void RecibirDanio(unsigned int Da�o, unsigned int AT_ZONA, cListaT<cTropa>* miTropa);


#pragma region GETTERS & SETTERS

	cListaT<cPais>* GetListaLimitrofes();
	string getClave() { return Nombre; }
	cListaT<cTropa>* getTropas() { return Tropas; }
	static cListaT<cPais>* getListaPaises();

#pragma endregion

	string To_string()const;

	bool operator==(string Nombre);

	bool MismoTipo(cGuerrero* Guerrero1, cGuerrero* cGuerrero2);

};
#endif // !defined(EA_B1B84F12_99FE_46f8_81E7_71FAB22C81F1__INCLUDED_)


