#include "cMundo.h"

cMundo::cMundo()
{
	ListaPaises = new cListaT<cPais>[]; //TODO: cantidad de lista?
}

void cMundo::SetUpMundo(string** NombresPaises)
{
	for (unsigned int i = 0; i < ListaPaises->getTAM(); i++)
		ListaPaises->Agregar(&cPais(NombresPaises[i]));
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

void LeerArchivo(const char* Filename)
{
	FILE* fp = NULL; //file pointer
	fp = fopen(Filename, "r"); //Abrir archivo
	char buffer[200] = "";
	if (fp == NULL)
		throw new exception(" --- Error al abrir el archivo ---");
	
	fgets(buffer, 199, fp); //leo la primera linea del txt (son los paises que tiene el mapa)
	string Cadena = buffer;
	for (int i = 0; i < Cadena.length(); i++)
	{
		int pos = Cadena.find("-", i);
		string subCadena = Cadena.substr(0, pos); //me copio el primer elemento 
		//TODO: NOMBRES DE PAISES (crear pais)
		i = pos;
	}
	while (!feof(fp))
	{

	}

	fclose(fp);
	return;
}
int Escribir_Archivo(Usuarios* lista, int cant, const char* nombre)
{
	FILE* fp = NULL; //file pointer
	fp = fopen(nombre, "w+b"); //abro para escribir en el archivo
	if (fp == NULL)
		return -1; //error al abrir
	fwrite(lista, sizeof(Usuarios), cant, fp);
	fclose(fp);
	return NULL;//todo ok!
}
int Cantidad_Jugadores(const char* nombre)
{
	FILE* fp = NULL; //file pointer

	fp = fopen(nombre, "r+");
	if (fp == NULL)
		return -1; //Error al abrir

	fseek(fp, 0, SEEK_END); //Manda el fp al final del archivo
	long int idx = ftell(fp);
	fclose(fp);
	//Calcular cantidad de registros
	int cant = idx / sizeof(Usuarios);

	return cant;
}
void ImprimirUsuarios(Usuarios* lista, int* cant)
{
	system("cls");
	if (*cant == 0)
		printf("No hay usuarios todavia, se el primero!");
	else
	{
		printf("\n\t------ PERFILES ------");
		printf("\n Nombre de usuario\tPartidas ganadas\t\tPartidas perdidas");
		for (int i = 0; i < (*cant); i++)
			printf("\n %-30.20s %-30d\t%d", lista[i].username, lista[i].partidas_ganadas, lista[i].partidas_perdidas);
	}

	printf("\n\nPulse una tecla para volver al menu\n");
	getchar();
	return;
}
