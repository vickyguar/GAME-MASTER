///////////////////////////////////////////////////////////
//  cPais.cpp
//  Implementation of the Class cPais
//  Created on:      01-jun.-2021 20:42:40
//  Original author: vguar
///////////////////////////////////////////////////////////

#include "cPais.h"

cListaT<cPais>* cPais::ListaPaises = new cListaT<cPais>();

cPais::cPais(string Nombre, vector<string> Limitrofes): ListaLimitrofes(Limitrofes)
{
	this->Nombre = Nombre;
	this->Tropas = new cListaT<cTropa>();

	*ListaPaises + this; //lo agrego a la lista
}

cPais::cPais(cPais& Pais) :ListaLimitrofes(Pais.ListaLimitrofes)
{
	this->Nombre = Pais.Nombre;
	this->Tropas = Pais.Tropas;
}

cPais::~cPais(){

	if (Tropas != NULL)
		delete Tropas;
}


unsigned int cPais::CalcularAT_Tropas(cListaT<cTropa>* Tropas)
{
	return 0;
}

bool cPais::VerificarLimitrofes(cPais* PaisLimitrofe) {

	for (unsigned int i = 0; i < ListaLimitrofes.size(); i++) //recorro los limitrofes (las claves)
		if (PaisLimitrofe->Nombre == ListaLimitrofes[i]) //son limitrofes?
			return true; //son limitrofes.

	return false;
}

void cPais::AsignarTropas(cTropa* Tropa)
{
	if(Tropa != NULL)
		*Tropas + Tropa; //esto es para cuando muevo tropas de un pais al otro
	else {
		Tropas->Agregar(new cTropa());//agrego una tropa random nueva
	}
}


void cPais::JuntarTropas() { //Pregunto aca las tropas!

	/*bool Valido = true;
	int opcion;
	string ID1, ID2;
	do {
		cout << "\n\tDesea juntar dos tropas de " << this->getClave() << "?" << endl;
		cout << "\t1: SI" << endl << "\t0: NO" << endl;
		cin >> opcion;

	} while (opcion != 1 && opcion != 0);

	if (opcion == 0)
		return;

	cout << "\n\tIngrese el ID de las tropas que desea juntar: \n";


	cout << "\tID Tropa #1: ";
	cin >> ID1;

	cout << "\n\tID Tropa #2: ";
	cin >> ID2;

	Valido = true;

	try { this->ValidarTropas(ID1, ID2); }
	catch (exception* ex) {
		cout << ex->what();
		delete ex;
		Valido = false;
	}

	if (!Valido)
		JuntarTropas();
	else {

		try
		{
			(*Tropas->BuscarItem(ID1)) += Tropas->BuscarItem(ID2);
		}
		catch (exception* ex)
		{
			delete ex;
			return;
		}


		delete Tropas->BuscarItem(ID2);
	}*/
}


void cPais::ValidarTropas(string ID1, string ID2) {
	try {
		Tropas->BuscarItem(ID1);
		Tropas->BuscarItem(ID2);
	}
	catch (exception* ex) {
		delete ex;
		ex = new exception("Algun numero de tropa ingresado no pertenece al pais :(");
		throw ex;
	}

	if (!MismoTipo((*Tropas->BuscarItem(ID1)->getGuerreros())[0], (*Tropas->BuscarItem(ID2)->getGuerreros())[0]))
		throw new exception(("Las tropas " + ID1 + " y " + ID2 + " no son del mismo tipo").c_str());

	return;
}

bool cPais::MismoTipo(cGuerrero* Guerrero1, cGuerrero* Guerrero2)
{
	if (dynamic_cast<cMago*>(Guerrero1) != NULL && dynamic_cast<cMago*>(Guerrero2) != NULL)
		return true;

	if (dynamic_cast<cCaballero*>(Guerrero1) != NULL && dynamic_cast<cCaballero*>(Guerrero2) != NULL)
			return true;

	if (dynamic_cast<cArquero*>(Guerrero1) != NULL && dynamic_cast<cArquero*>(Guerrero2) != NULL)
		return true;

	return false;
}

cTropa* cPais::VerificarTropa(unsigned int NTropa)
{
	cTropa* aux = NULL;

	try { 
		aux = Tropas->BuscarItem(to_string(NTropa)); //EL NUMERO ES EL ID DE LA TROPA
	} 
	catch(exception*ex){
		delete ex;
	}
	return aux;
}

cListaT<cPais>* cPais::getListaPaises()
{
	return ListaPaises;
}

cListaT<cTropa>* cPais::CrearMiniListaRandom()
{
	cListaT<cTropa>* aux = new cListaT<cTropa>(true, 3);

	if (Tropas->getCA() > 3) {
		unsigned int rand1 = 1 + rand() % (Tropas->getCA() - 2);//Que se genere un número random que no incluya los extremos
		
		*aux + (*Tropas)[rand1 - 1];
		*aux + (*Tropas)[rand1];
		*aux + (*Tropas)[rand1 + 1];
	}
	else {
		for (unsigned int i = 0; i < Tropas->getCA(); i++)
			*aux + (*Tropas)[i];
	}
	
	return aux;
}

void cPais::RecibirDanio(unsigned int Daño, unsigned int AT_ZONA, cListaT<cTropa>* miTropa)
{
	for (unsigned int i = 0; i < miTropa->getCA(); i++) //recorro las tropas que mandan a combatir
	{
		if(AT_ZONA != 0)
		{
			if ((*miTropa)[i]->RecibirDanioXZona(AT_ZONA))
			{
				cTropa* aux = miTropa->QuitarXPos(i); //saco la tropa que murio de la minilista (la que llega por param)
				Tropas->Quitar(aux->getClave()); //saco la tropa del pais porque murió en el campo
				//delete aux;
			}
		}
		if ((*miTropa)[i]->RecibirDanio(Daño)) //recibo el daño y si se muere toda la tropa
		{
			cTropa* aux = miTropa->QuitarXPos(i); //saco la tropa que murio de la minilista (la que llega por param)
			Tropas->Quitar(aux->getClave()); //saco la tropa del pais porque murió en el campo
		}
	}
	if (miTropa->getCA() == 0 && Tropas->getCA() == 0) //si ya no tengo tropas (las que mande se murieron y en el pais tapoco tengo)
		throw new exception(("\nGanaste el dominio del pais: " + Nombre + " :)").c_str());
	return;
}

cListaT<cPais>* cPais::GetListaLimitrofes()
{
	cListaT<cPais>* ListaLimitrofesAux = new cListaT<cPais>(false);
	for (unsigned int i = 0; i < ListaLimitrofes.size(); i++)
	{
		for (unsigned int j = 0; j < ListaPaises->getCA(); j++)
		{
			if ((*ListaPaises)[j]->getClave()==ListaLimitrofes[i])
				(*ListaLimitrofesAux) + (*ListaPaises)[j];
		}
	}
	return ListaLimitrofesAux;

}

string cPais::To_string() const
{
	return Nombre;
}

bool cPais::operator==(string Nombre)
{
	return (Nombre == this->Nombre);
}


