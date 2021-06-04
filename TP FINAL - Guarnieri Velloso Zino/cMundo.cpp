#include "cMundo.h"

cMundo::cMundo()
{
	ListaPaises = new cListaT<cPais>();//TODO: cantidad de lista?
	this->Limitrofes = ""; //lo construyo vacio
}

cMundo::~cMundo()
{
}

bool cMundo::Divisible(int Num1, int Num2)
{
	return false;
}

void cMundo::SetUpMundo(string** NombresPaises)
{
}

cListaT<cPais>* cMundo::GetLista()
{
	return ListaPaises;
}


//TODO: crear archivos usuarios (lo ultiomo que
//void CreArchivo(const char* nombre)
//{ //SE INVOCA SOLO SI EL ARCHIVO NO EXISTE AL EJECUTAR POR PRIMERA VEZ EL PROGRAMA
//	FILE* fp; //file pointer
//	fp = fopen(nombre, "w+b"); //escribir archivo binario
//	if (fp == NULL)
//		return; //hubo un error
//	fclose(fp);
//	return;
//}

void cMundo::LeerArchivo(const char* Filename, string* Limitrofes)
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

	//sigo recorriendo el archivo de texto para los paises limitrofes
	while (!feof(fp)) 
	{
		fgets(buffer, 199, fp); //leo por linea
		*Limitrofes += buffer; //me guardo la linea
	}

	do
	{
		//pos = Cadena.find('-'); //busco los separadores
		//string subCadena = Cadena.substr(0, pos); //me copio el elemento 
		string NombrePais = BuscarNombrePais(Cadena, '-', &pos); //busco el nombre del pais que quiero crear
		PaisesLimitrofes(Limitrofes, NombrePais); //creo la lista de limitrofes + el pais correspondiente
		Cadena.erase(0, (pos + 1)); //borro el nombre que había encontrado

	} while (pos != Cadena.npos);

	*Limitrofes += '\n'; //para que el ultimo tambien lo tenga

	fclose(fp); //cierro el archivo
	return;
}


void cMundo::PaisesLimitrofes(string*& Limitrofes, string nombre) {

	int i = 0, pos = 0;

	//primero divido por linea
	vector<string> ListaLimitrofes; //lista con size 0
	pos = Limitrofes->find('\n'); //busco los separadores
	string subCadena = Limitrofes->substr(0, pos); //me copio el elemento 
	*Limitrofes = Limitrofes->erase(0, pos + 1); //borro el elemento

	pos = 0;
	//segundo divido por separador
	while (pos != subCadena.npos)
	{
		//pos = subCadena.find("-"); //busco los separadores
		//string NombrePais = subCadena.substr(0, pos); //me guardo el nombre del pais
		string NombrePais = BuscarNombrePais(subCadena, '-', &pos);
		ListaLimitrofes.push_back(NombrePais); //agrego pais limitrofe
		subCadena.erase(0, pos + 1); //+1 para que me borre el \n
	}

	*ListaPaises + new cPais(nombre, ListaLimitrofes);
	
	return; 
}

//void cMundo::PaisesLimitrofes_plural(string* Limitrofes_str) { //TODO: la lista limitrofes 
//
//	unsigned int size = LineCount(*Limitrofes_str);
//		for (unsigned int i = 0; i < size; i++)
//			PaisesLimitrofes_singular(Limitrofes_str, );
//}

unsigned int cMundo::LineCount(string str) const
{
	unsigned int cont = 0;
	unsigned int pos = 0;
	do
	{
		pos = Limitrofes.find('\n', pos); //busco los espacios
		pos++;
		cont++;

	} while (pos != Limitrofes.npos); //mientras que no llegue al final

	return --cont; //le descuento el \n del final
}

string cMundo::BuscarNombrePais(string str, char separator, int* pos)
{

	*pos = str.find(separator); //busco los separadores
	string word = str.substr(0, *pos); //me guardo el nombre del string

	return word;
}
//int Escribir_Archivo(Usuarios* lista, int cant, const char* nombre)
//{
//	FILE* fp = NULL; //file pointer
//	fp = fopen(nombre, "w+b"); //abro para escribir en el archivo
//	if (fp == NULL)
//		return -1; //error al abrir
//	fwrite(lista, sizeof(Usuarios), cant, fp);
//	fclose(fp);
//	return NULL;//todo ok!
//}
//int Cantidad_Jugadores(const char* nombre)
//{
//	FILE* fp = NULL; //file pointer
//
//	fp = fopen(nombre, "r+");
//	if (fp == NULL)
//		return -1; //Error al abrir
//
//	fseek(fp, 0, SEEK_END); //Manda el fp al final del archivo
//	long int idx = ftell(fp);
//	fclose(fp);
//	//Calcular cantidad de registros
//	int cant = idx / sizeof(Usuarios);
//
//	return cant;
//}
//void ImprimirUsuarios(Usuarios* lista, int* cant)
//{
//	system("cls");
//	if (*cant == 0)
//		printf("No hay usuarios todavia, se el primero!");
//	else
//	{
//		printf("\n\t------ PERFILES ------");
//		printf("\n Nombre de usuario\tPartidas ganadas\t\tPartidas perdidas");
//		for (int i = 0; i < (*cant); i++)
//			printf("\n %-30.20s %-30d\t%d", lista[i].username, lista[i].partidas_ganadas, lista[i].partidas_perdidas);
//	}
//
//	cout << "\n\nPulse una tecla para volver al menu" << endl;
//	getchar();
//	return;
//}
