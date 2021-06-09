///////////////////////////////////////////////////////////
//  cJuego.h
//  Implementation of the Class cJuego
//  Created on:      01-jun.-2021 20:42:39
//  Original author: vguar
///////////////////////////////////////////////////////////

#if !defined(EA_D34FED27_7152_41ec_81AD_94CE58A64212__INCLUDED_)
#define EA_D34FED27_7152_41ec_81AD_94CE58A64212__INCLUDED_

#include "cJugador.h"
#include "cListaT.h"
#include "cMundo.h"

class cJuego
{
private:
	cListaT<cJugador>* Jugadores; //lista de jugadores
	static unsigned int Rondas; //contador de la cantidad de rondas
	unsigned int TurnoPrevio; //el numero del turno previo
	cMundo* Mundo; //ptr a mundo

public:
#pragma region CONSTRUCTORES & DESTRUCTORES

	/**
	* cJuego
	* constructor de la clase cJuego
	*/
	cJuego(unsigned int cantjugadores);
	/**
	* ~cJuego
	* destructor de la clase cJuego
	*/
	~cJuego();

#pragma endregion

#pragma region METODOS DEL JUEGO

#pragma endregion

	void AsignarTurno();
	void JugadorAtacando(unsigned int pos);
	void Batallar(cJugador* JugadorAtacando, cPais* PaisAtacado, cPais* PaisAtacante, cListaT<cTropa>* Tropas);
	
	void Reagrupar(unsigned int pos);
	void FindeRondaEntera();

#pragma region SETUP'S

	void SetUpMundo(unsigned int mundo);
	void SetUpJugadores(string username);

#pragma endregion

#pragma region GETTERS & SETTERS

	static int getRondas();
	cJugador* getJugadorAtacante();

#pragma endregion

#pragma region IMPRIMIR & TO STRING

	void ImprimirEstados() const;

#pragma endregion

	//int* ReparticionPaises();
	void AsignarPaisesRandom();

	
};
//istream& operator>>(istream& in, cJugador* Jugador)
//{
//	int pospais = -1; //para inicializar
//	unsigned int cont = 0;
//	if (cont % 2 == 0) {
//		cout << "\n ---- JUGADOR " << Jugador->getUsername() << " ---- " << endl;
//		cout << " Introduzca el numero pais al que quiere atacar: \n";
//		in >> pospais;
//	}
//	else {
//		cout << "\n ---- JUGADOR " << Jugador->getUsername() << " ---- " << endl;
//		cout << " Introduzca el numero pais desde el que quiere atacar: \n";
//		in >> pospais;
//	}
//
//	return in;
//}

static unsigned int CalcularResiduo(int Num1, int Num2)
{
	if (Num2 != 0)
	{
		float Division = (float)Num1 / Num2;
		int ParteEntera = Num1 / Num2;
		int Residuo = (Division - ParteEntera) * Num2;
		return Residuo;
	}
	else
		throw new exception(" --- Division por cero --- ");
}

//Funciones

//Ingreso de datos
cPais* PosPaisAtaque(cJugador* Jugador) {
	int pospais = -1;
	do {
		cout << "\n ---- JUGADOR " << Jugador->getUsername() << " ---- " << endl;
		cout << " Introduzca el numero pais desde el que quiere atacar: \n";
		cin >> pospais;
	} while (pospais <0 || pospais>cPais::getListaPaises()->getCA() || !Jugador->VerificarPais(pospais));

	return (*cPais::getListaPaises())[pospais];
}

cPais* PosPaisAtacado(cJugador* Jugador, cPais* Pais) {
	int pospais = -1;
	do {
		cout << " Introduzca el numero pais al que quiere atacar: \n";
		cin >> pospais;



	} while (pospais <0 || pospais>cPais::getListaPaises()->getCA() || Jugador->VerificarPais(pospais)||
		!Pais->VerificarLimitrofes((*cPais::getListaPaises())[pospais]));

	

	return (*cPais::getListaPaises())[pospais];
}

cListaT<cTropa>* TropasdeBatalla(cPais* PaisAtaque)
{
	int canttropas = 0;
	do {
		cout << " Introduzca la cantidad de tropas con las que quiere atacar. MAXIMO DE 3 : \n";
		cin >> canttropas;
	} while (canttropas > 3||canttropas<1);
	cListaT<cTropa>* ListaAux = new cListaT<cTropa>(false,canttropas);

	do {
		cout << " Introduzca la cantidad de tropas con las que quiere atacar. MAXIMO DE 3 : \n";
		cin >> canttropas;



	} while (pospais <0 || pospais>cPais::getListaPaises()->getCA() || Jugador->VerificarPais(pospais) ||
		!Pais->VerificarLimitrofes((*cPais::getListaPaises())[pospais]));

	return ListaAux;
}

//Verificación de datos ingresados



		/*cout << "\n ---- JUGADOR " << (*Jugadores)[pos]->getUsername() <<" ---- "<< endl;
				cout<<" Introduzca el numero pais desde el que quiere atacar: \n";
				cin >> pospais;
				cPais* paisAtaque = (*Jugadores)[pos]->(*getListaPaises())[pospais];

				cout << " Introduzca el numero pais al que quiere atacar: \n";
				cin >> pospais;
				//busca en la lista static, chequea limitrofes
				//cPais*paisAtacado=

				//TODO: METODO PARA ELEGIR TRES TROPAS QUE DEVUELVE cListaT TROPAS
				cout << " Introduzca el numero de tropas con las que quiere atacar: \n";
				cin >> pospais;
				cPais* paisAtaque = (*Jugadores)[pos]->(*getListaPaises())[pospais];*/





#endif // !defined(EA_D34FED27_7152_41ec_81AD_94CE58A64212__INCLUDED_)


