#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include "windows.h"

using namespace std;

enum class eOpcion {
	SALIR = 0,
	JUGAR,
	IMPRIMIR_REGLAS,
	IMPRIMIR_PERFILES
};

enum class eMundo {

	AGENTINA = 0,
	AMERICA_LATINA
	//NARNIA,
};

string To_StringMenu();
eOpcion ElegirOpcion();
void Instrucciones();

string To_StringMenu() {
	string output = "\t----- MENU -----\n";
	output += "\t1. JUGAR\n";
	output += "\t2. IMPRIMIR REGLAS\n";
	output += "\t3. IMPRIMIR PERFILES\n";
	output += "\t0. SALIR\n";

	return output;
}

eOpcion ElegirOpcion() {

	eOpcion opcion = eOpcion::SALIR;
	
	cout << To_StringMenu() << endl;
	scanf_s("%d", &opcion);  //TODO: Despues pasar a CIN
	
	if(opcion < eOpcion::SALIR || opcion > eOpcion::IMPRIMIR_PERFILES)
	{
		cout << "Opcion invalida\n";
		Sleep(2000); //TODO: es esta la función?
		system("cls");
		opcion = ElegirOpcion();
	}

	return opcion;
	
}

bool Menu() {
	eOpcion opcion = ElegirOpcion();
	switch (opcion)
	{
	case eOpcion::JUGAR:
		return true;

	case eOpcion::IMPRIMIR_REGLAS:
		Instrucciones();
		cout << " Presione cualquier tecla para volver al menu\n";
		getchar();//TODO: jaja no me gusta el getchar
		system("cls");
		Menu();
		break;
		
	case eOpcion::IMPRIMIR_PERFILES: break;

	case eOpcion::SALIR:
		return false;
	}
	return false;
}

unsigned int ElegirMundo()
{
	unsigned int Mundo = (unsigned int)eMundo::AMERICA_LATINA;
	cout << "\t\n---- MUNDOS -----" << endl;
	cout << "1. ARGENTINA Y LIMITROFES" << endl;
	cout << "2. AMERICA LATINA" << endl;
	cout << "3. NARNIA" << endl;
	cout << "Ingrese opcion: "; 
	cin >> Mundo;

	if (Mundo < (unsigned int)eMundo::AGENTINA || Mundo > (unsigned int)eMundo::AMERICA_LATINA)
		Mundo = ElegirMundo();

	return Mundo;
}

string ConvertMundoString(unsigned int mundo) {

	mundo--;
	switch ((eMundo)mundo)
	{
	case eMundo::AGENTINA: return "Argentina"; break;
	case eMundo::AMERICA_LATINA: return "America Latina"; break;
	}
}

void Instrucciones() { 
	cout << "\t\n----- INSTRUCCIONES -----" << endl;
	cout<< "El objetivo del juego es CONQUISTAR EL MUNDO ocupando con tus tropas todos los paises de los oponentes" << endl;
	cout<<"\n Cada jugador comenzara la partida con 5 paises y 10 tropas de algun tipo de guerreros"<<endl;
	cout << "\n El maximo de tropas que pueden ser enviadas a batallar es de 3. SOLO se puede atacar a paises limitrofes" << endl;
	cout << "\n CADA TIPO DE GUERRERO TIENE ATRIBUTOS ESPECIALES!" << endl;

	cout <<"\n YA ESTAN LISTOS PARA JUGAR! El primer turno le sera asignado al jugador que responda bien un acetrijo" << endl;

}