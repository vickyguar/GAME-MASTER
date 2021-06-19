#include "cMundo.h"
#pragma warning(disable : 4996)

cMundo::cMundo()
{
	ListaPaises = new cListaT<cPais>();
}

cMundo::~cMundo()
{
}

void cMundo::LeerArchivo(const char* Filename)
{

	FILE* fp = NULL; //file pointer
	fp = fopen(Filename, "r"); //Abrir archivo
	char buffer[200] = "";
	int pos = 0;

	if (fp == NULL)
		throw new exception(" --- Error al abrir el archivo ---");

	//leo primera linea (son los paises que tiene el mapa)
	fgets(buffer, 199, fp);
	string Cadena = buffer; //me guardo lo que lei

	string Limitrofes;
	//sigo recorriendo el archivo de texto para los paises limitrofes
	while (!feof(fp))
	{
		fgets(buffer, 199, fp); //leo por linea
		Limitrofes += buffer; //me guardo la linea
	}

	do
	{
		string NombrePais = BuscarNombrePais(Cadena, '-', &pos); //busco el nombre del pais que quiero crear
		PaisesLimitrofes(Limitrofes, NombrePais); //creo la lista de limitrofes + el pais correspondiente
		Cadena.erase(0, (pos + 1)); //borro el nombre que había encontrado

	} while (pos != Cadena.npos);

	//Limitrofes += '\n'; //para que el ultimo tambien lo tenga

	fclose(fp); //cierro el archivo
	
	SetNombreMundo(Filename); 

	return;
}

void cMundo::SetNombreMundo(string str) {
	if (str == "MUNDO 1.txt")
		this->setNombre("Argentina y sus limitrofes");
	else if (str == "MUNDO 2.txt")
		this->setNombre("America Latina");
}


void cMundo::PaisesLimitrofes(string& Limitrofes, string nombre) {

	int i = 0, pos = 0;

	//primero divido por linea
	vector<string> ListaLimitrofes; //lista con size 0
	pos = Limitrofes.find('\n'); //busco los separadores
	string subCadena = Limitrofes.substr(0, pos-2); //me copio el elemento 
	Limitrofes = Limitrofes.erase(0, pos + 1); //borro el elemento

	pos = 0;
	//segundo divido por separador
	while (pos != subCadena.npos)
	{
		string NombrePais = BuscarNombrePais(subCadena, '-', &pos);
		ListaLimitrofes.push_back(NombrePais); //agrego pais limitrofe
		subCadena.erase(0, pos + 1); //+1 para que me borre el \n
	}

	*ListaPaises + new cPais(nombre, ListaLimitrofes);
	
	return; 
}

string cMundo::BuscarNombrePais(string str, char separator, int* pos)
{

	*pos = str.find(separator); //busco los separadores
	string word = str.substr(0, *pos); //me guardo el nombre del string

	return word;
}

cListaT<cPais>* cMundo::GetLista()
{
	return ListaPaises;
}

void cMundo::setNombre(string nombre)
{
	this->Nombre = nombre;
}

void cMundo::Imprimir() const
{
	cout << "\tEnhorabuena! Combatiran en " << Nombre << endl << endl;
	cout << "\tLos paises disponibles en este mundo son: " << endl;
	cout << *ListaPaises << endl; //imprimo la lista de paises

	Sleep(1000); //TODO: aca quiero el mapaa :)
	system("cls");

}

void cMundo::SetUp(const char* Filename)
{
	try
	{
		LeerArchivo(Filename);
	}
	catch (exception* ex)
	{
		delete ex;
		//TODO: hacer algo con la excepcion
	}
}
