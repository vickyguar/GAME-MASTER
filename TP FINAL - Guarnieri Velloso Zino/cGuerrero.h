///////////////////////////////////////////////////////////
//  cGuerrero.h
//  Implementation of the Class cGuerrero
//  Created on:      01-jun.-2021 20:42:39
//  Original author: vguar
///////////////////////////////////////////////////////////

#if !defined(EA_86F03F75_F4B2_4011_AD66_663180BE8617__INCLUDED_)
#define EA_86F03F75_F4B2_4011_AD66_663180BE8617__INCLUDED_

#include <string>
#include <iostream>

using namespace std;

class cGuerrero
{
protected:
	unsigned int AT;
	unsigned int HP_Actual;
	unsigned int HP_Inicial;
	string ID;
	static unsigned int cantGuerreros;
public:
#pragma region CONSTRUCTORES & DESTRUCTORES
	/**
	* cGuerrero
	* constructor de la clase cGuerrero
	*/
	cGuerrero(unsigned int _AT, unsigned int _HP_Actual, unsigned int _HP_Inicial);
	/**
	* ~cGuerrero
	* destructor de la clase cGuerrero
	*/
	virtual ~cGuerrero();

#pragma endregion

#pragma region GETTERS & SETTERS

	unsigned int getAT() const;

#pragma endregion

	/**
	* CondicionAtaque: 
	* evalua si es fuerte contra el otro -> Caballero es fuerte contra el arquero
	* @param cGuerrro*
	* @return int
	*/
	virtual unsigned int Ataque(cGuerrero* Atacado) = 0; //Podemos hacerlo como los chicos con un template
	/**
	* CalcularDanio
	* calcula el numero de daño que genera la unidad
	* @return int
	*/
	/*virtual unsigned int CalcularDanio() const = 0;*/
	unsigned int getHP() { return HP_Actual; }
	inline void setHP(unsigned int Daño) { HP_Actual -= Daño; }
	void operator-=(unsigned int daño) { setHP(daño); }
	bool VerificarVida() { return (HP_Actual <= HP_Inicial * 0.1); }
	string getClave() const { return ID; }
};
#endif // !defined(EA_86F03F75_F4B2_4011_AD66_663180BE8617__INCLUDED_)
