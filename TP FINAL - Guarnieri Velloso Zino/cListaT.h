#pragma once

#include <iostream>
#include <string>
#include <ostream>

#define NMAX 50
using namespace std;

template<class T>
class cListaT
{
protected:
	T** Lista;
	unsigned int CA,TAM;
	bool Delete;
public:
#pragma region CONSTRUCTORES Y DESTRUCTORES
	cListaT(bool _Delete = true, unsigned int _TAM = NMAX);
	cListaT(cListaT<T>& ListaCopia);
	virtual ~cListaT();
#pragma endregion
#pragma region AGREGAR,QUITAR,ELIMINAR
	void Agregar(T* newItem);
	T* Quitar(const string Key);
	void Eliminar(const string Key);
#pragma endregion
	void Redimensionar();
#pragma region BUSCAR
	template<class C>
	T* BuscarItem(const C Key);
	T* BuscarXPos(unsigned int Index);
#pragma endregion
#pragma region GETTERS
	template<class C>
	unsigned int getIndex(const C Key)const;
	unsigned int getCA() const;
	unsigned int getTAM() const;
#pragma endregion

	void Listar()const;

#pragma region SOBRECARGA
	T* operator[](unsigned int pos);
	void operator+(T* newItem);
	void operator=(cListaT<T>* Copia); //ESTO CREA POR COPIA
#pragma endregion

};

template <class T>
cListaT<T>::cListaT(bool _Delete, unsigned int _TAM)
{
	TAM = _TAM;
	Delete = _Delete;
	CA = 0;

	Lista = new T * [TAM];
	//Creo la lista dinamica
	for (unsigned int i = 0; i < TAM; i++)
	{
		Lista[i] = NULL;
	}
}
template<class T>
inline cListaT<T>::cListaT(cListaT<T>& ListaCopia)
{
	TAM = ListaCopia.TAM;
	Delete = ListaCopia.Delete;
	CA = 0;

	Lista = new T * [ListaCopia.TAM];
	//Creo la lista dinamica
	for (unsigned int i = 0; i < TAM; i++)
	{
		Lista[i] = NULL;
	}
	for (unsigned int i = 0; i < ListaCopia.CA; i++)
	{
		(*Lista)+(*ListaCopia)[i];
	}
}
template <class T>
cListaT<T>::~cListaT()
{
	if (Lista != NULL)
	{
		if (Delete)
		{
			for (unsigned int i = 0; i < CA; i++)
			{
				if (Lista[i] != NULL)
					delete Lista[i];
			}
		}
		delete[] Lista;
	}
}

template<class T>
void cListaT<T>::Agregar(T* newItem)
{
	if (newItem != NULL)
	{
		if (CA == TAM) //si la cant actual es igual al tamanio max
			Redimensionar(); //redimensiono la lista
		try {
			int pos = getIndex(newItem->getClave()); //busco el elemento en la lista
		}
		catch (exception* ex) { //si el elemento no existe
			delete ex;
			Lista[CA] = newItem; //lo agrego a la lista
			CA++;
			return;
		}
		throw new exception("El item ya esta en la lista");
	}
	throw new exception("El nuevo item que se desea agregar a la lista es NULL");
}

template<class T>
T* cListaT<T>::Quitar(const string Key)
{
	int pos = -1;
	try { pos = getIndex(Key); } //busco el elemento
	catch (exception* ex) {
		string error = ex->what();
		delete ex;
		ex = new exception(("No se puede quitar el item: " + error).c_str());
		throw ex;
	}
	T* aux = Lista[pos]; // si lo encuentra lo guardo
	for (int i = pos; i < CA - 1; i++)
	{
		Lista[i] = Lista[i + 1]; //corro todo una posicion para arriba 
	}
	Lista[--CA] = NULL;
	return aux;
}

template<class T>
void cListaT<T>::Eliminar(const string Key)
{
	T* aux = NULL;
	if (Lista != NULL)
	{
		try { aux = Quitar(Key); }
		catch (exception* ex) {
			string error = ex->what();
			delete ex;
			ex = new exception(("No se puede eliminar el item: " + error).c_str());
			throw ex;
		}
		delete aux;
	}
	throw new exception("Error al eliminar: la lista es NULL");
}

template<class T>
void cListaT<T>::Redimensionar()
{
	unsigned int n = 2 * TAM;
	T** aux = new T * [n]; //se redimensiona al doble del tam original
	
	//---------
	for (unsigned int i = 0; i < TAM * 2; i++)
	{
		aux[i] = NULL;
	}
	for (unsigned int i = 0; i < TAM; i++)
	{
		aux[i] = Lista[i];
	}
	//----------

	delete[]Lista;
	Lista = aux;
	TAM += TAM;

}

template<class T>
template<class C>
T* cListaT<T>::BuscarItem(const C Key)
{
	int pos = -1;
	if (Lista != NULL)
	{
		
		try { pos = getIndex(Key); }
		catch (exception* ex) {
			string error = ex->what();
			delete ex;
			ex = new exception(("Error al buscar item: " + error).c_str());
			throw ex;
		}
		return Lista[pos];
		
	}
	throw new exception("Error al buscar el item");
}

template<class T>
T* cListaT<T>::BuscarXPos(unsigned int Index)
{
	if (Index > CA)
		throw new exception(("La posicion " + to_string(Index) + " no existe en la lista").c_str());
	return Lista[Index];
}
template<class C>
template<class T>
unsigned int cListaT<T>::getIndex(const C Key) const
{
	for (unsigned int i = 0; i < CA; i++)
	{
		if (Lista[i]->getClave() == Key)
			return i;
	}
	throw new exception((Key + " el item no existe").c_str());
}

template<class T>
unsigned int cListaT<T>::getCA() const
{
	return CA;
}

template<class T>
unsigned int cListaT<T>::getTAM() const
{
	return TAM;
}

template<class T>
void cListaT<T>::Listar() const
{
	for (unsigned int i = 0; i < CA; i++)
	{
		cout << "\n\t# " << i + 1 << endl;
		cout << Lista[i]->To_String();
	}
}

template<class T>
T* cListaT<T>::operator[](unsigned int pos)
{
	if (pos >= 0 && pos < CA)
		return Lista[pos];
	return NULL;
}

template<class T>
inline void cListaT<T>::operator+(T* newItem)
{
	try { Agregar(newItem); }
	catch (exception* ex) {
		string error = ex->what();
		delete ex;
		ex = new exception(("Error al usar operator+: " + error).c_str());
		throw ex;
	}
	return;
}

template<class T>
inline void cListaT<T>::operator=(cListaT<T>* ListaB)
{
	for (int i = 0; i < ListaB->CA; i++)
	{
		Lista[i] = ListaB[i]; //SUPONEMOS QUE EL COMPILADOR CREA POR DEFECTO EL DE CLASE T
	}
}

template<class T>
void operator<<(ostream& o, cListaT<T>& obj)
{
	for (unsigned int i = 0; i < obj.getCA(); i++)
	{
		o << obj[i]->To_string();
	}
}