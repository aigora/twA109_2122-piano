#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <conio.h>
#include <string.h>
#include <malloc.h>
#include "SerialClass/SerialClass.h"

#define MAX_BUFFER 300
#define PAUSA_MS 500
#define DIM 200
#define TAM 50
#define MAX 10

typedef struct
{
	char nombre[TAM];
	int canciones;

}Usuario;

//funciones principales
void menu(int, Serial*);
int opciones(void);
void start(Serial*);
int obtener_notas(Serial*, char*);
//void tocar_piano(Serial*);
//char conv_a_notas(char[]);
void elegir_cancion(Serial*, Usuario[], int);

//funciones para guardar y leer ficheros de canciones
//int grabar_cancion(Serial*, Usuario[], int);


//funciones de usuarios
int buscar_usuarios(Usuario[], int, char const*);
int  alta_usuario(Usuario[], int);
void crear_fichero(Usuario[], int);
int leer_fichero(Usuario[]);
void listado_de_usuarios(Usuario[], int);


int main(void)
{
	Serial* Arduino;
	char puerto[] = "COM3"; // Puerto serie al que está conectado Arduino

	int opcion_menu=0;

	setlocale(LC_ALL, "es-ES");
	Arduino = new Serial((char*)puerto);

	menu(opcion_menu, Arduino);

	return 0;
}

void menu(int opc_menu, Serial* Arduino)
{
	char notasn, nombre_us[TAM];
	char tecla;
	int notas = 0, i, cancion = 1;
	int nusuarios, n_usuario;
	Usuario usuarios[MAX];

	nusuarios = leer_fichero(usuarios);

	do
	{
		opc_menu = opciones();

		switch (opc_menu)
		{

		case 1:
			/*do {
				printf("¿Que usuario eres?\n");
				scanf_s("%s", nombre_us, TAM);

				n_usuario = buscar_usuarios(usuarios, nusuarios, nombre_us);
			} while (n_usuario == 11);*/

			//tocar_piano(Arduino);
			if (Arduino->IsConnected())
			{
				printf("\nArduino conectado.\n");
				do
				{
					Arduino->ReadData(&notasn, sizeof(notasn));

					Sleep(20);
					if (notasn != 'a')
						printf("%c", notasn);
					else
						printf("XXX ");
					Sleep(100);

				} while (_kbhit() == 0);
			}
			else
				printf("\nNo se ha podido conectar con Arduino.\n");

			break;
		case 2:
			do {
				printf("¿Que usuario eres?\n");
				scanf_s("%s", nombre_us, TAM);

				n_usuario = buscar_usuarios(usuarios, nusuarios, nombre_us);
			} while (n_usuario == 11);

			//grabar(Arduino, usuarios, n_usuario, nusuarios);
			if (Arduino->IsConnected())
			{
				printf("\nArduino conectado.\n");
				do
				{
					Arduino->ReadData(&notasn, sizeof(notasn));

					Sleep(20);
					if (notasn != 'a')
						printf("%c", notasn);
					else
						printf("XXX ");
					Sleep(100);

				} while (_kbhit() == 0);
			}
			else
				printf("\nNo se ha podido conectar con Arduino.\n");
			break;
		case 3:
			elegir_cancion(Arduino, usuarios, notasn);
			break;
		case 4:
			nusuarios = alta_usuario(usuarios, nusuarios);
			crear_fichero(usuarios, nusuarios);
			break;
		case 5:
			listado_de_usuarios(usuarios, nusuarios);
			break;
		case 6:
			printf("\nPrograma finalizado\n");
			break;
		default: printf("\nOpción incorrecta. Elija una de las opciones.\n");
			break;
		}

	} while (opc_menu != 6);

	crear_fichero(usuarios, nusuarios);
}

/*void tocar_piano(Serial* Arduino)
{
	char tecla;
	int bytes = 0,notasn;
	char mens_recibido[MAX_BUFFER];

	if (!Arduino->IsConnected()){
		printf("\nNo se ha podido conectar con Arduino.\n");
		exit(1);
	}

	start(Arduino);
	
	do
	{
		bytes = obtener_notas(Arduino, mens_recibido);
		Sleep(PAUSA_MS);

		if (bytes == 3)
		{
			notasn=conv_a_notas(mens_recibido);
			printf("%c ", notasn);
		}
		else
			printf("Ha habido un error me thinks.");

		Sleep(100);

	} while (_kbhit() == 0);
	tecla = _getch();

	return;
}*/

int opciones(void)
{
	int opc_menu;
	char intro;

	printf("\n");
	printf("Menú Principal\n");
	printf("---------------\n");
	printf("1 - Tocar piano libremente.\n");
	printf("2 - Grabar melodia y reproducirla.\n");
	printf("3 - Ver canciones.\n");
	printf("4 - Dar de alta a un usuario.\n");
	printf("5 - Listado de Usuarios.\n");
	printf("6 - Salir de la aplicación\n");
	printf("Opción: ");
	scanf_s("%d", &opc_menu);
	scanf_s("%c", &intro, 1);

	return opc_menu;

}
/*char conv_a_notas(char mens_recibido[])
{
	char nota = ' ';

	if (mens_recibido == "0\r")
		nota = 'DO';
	else if (mens_recibido == "1\r")
		nota = 'RE';
	else if (mens_recibido == "2\r")
		nota = 'MI';
	else if (mens_recibido == "3\r")
		nota = 'FA';
	else if (mens_recibido == "4\r")
		nota='SOL';
	else if (mens_recibido == "5\r")
		nota = 'LA';
	else if (mens_recibido == "6\r")
		nota = 'SI';
	else if (mens_recibido == "7\r")
		nota = 'DOa';

	return nota;
}

int obtener_notas(Serial* Arduino, char* mens_recibido)
{
	int total = 0, bytes;

	while (!Arduino->WriteData((char*)"GET_NOTAS\n", MAX_BUFFER * sizeof(char))) {
		;
	}
	Sleep(PAUSA_MS);

	bytes = Arduino->ReadData(mens_recibido, sizeof(char) * MAX_BUFFER - 1);
	while (bytes > 0) {
		Sleep(TAM);
		total += bytes;
		bytes = Arduino->ReadData(mens_recibido + total, sizeof(char) * MAX_BUFFER - 1);
	}

	if (total > 0) {
		printf("\nbytes recibidos: %d\n", total);
		mens_recibido[total - 2] = '\0';
		printf("Mensaje recibido: %s\n", mens_recibido);
	}

	return total;
}*/

int alta_usuario(Usuario us[], int n)
{
	if (n < MAX)
	{
		printf("Usuario = ");
		scanf_s("%s", us[n].nombre, TAM);
		us[n].canciones = 11;
		n++;
	}
	else
		printf("No puede haber mas usuarios.\n");

	return n;
}

void elegir_cancion(Serial* Arduino, Usuario us[], int a)
{
	char notasn='n', cancion;
	int n=3;

	do 
	{
		printf("\nLista de canciones:\n");
		printf("1- He is a Pirate\n");
		printf("2- Himno de España\n");
		printf("3- Level Theme: Mario Underworld\n");
		printf("Elija opcion: ");

		scanf_s("%c", &cancion);
		if (cancion<1 && cancion>n)
			printf("\nElige una de las opciones");

	} while (cancion<1 && cancion>n);

	if (Arduino->IsConnected())
	{
		printf("\nArduino conectado.\n");
		do
		{
			Arduino->WriteData((char*)cancion, MAX_BUFFER * sizeof(char));

			Sleep(20);

			if (notasn != ',')
				printf("%c", notasn);
			else
				printf("XXX ");
			Sleep(100);

		} while (_kbhit() == 0);
	}
	else
		printf("\nNo se ha podido conectar con Arduino.\n");


}

void start(Serial* Arduino) 
{
	;
	while (!Arduino->WriteData((char*)"START\n", MAX_BUFFER * sizeof(char))) {
		;
	}
}


void crear_fichero(Usuario us[], int n)
{
	FILE* fichero;
	int i;
	errno_t e;
	e = fopen_s(&fichero, "Lista_usuarios.txt", "wt");
	if (fichero == NULL)
		printf("No se ha podido guardar la agenda\n");
	else
	{
		for (i = 0; i < n; i++)
		{
			fprintf(fichero, "%s ", us[i].nombre);
			fprintf(fichero, "\n%d\n", us[i].canciones);
		}
		fclose(fichero);
	}

}

int buscar_usuarios(Usuario us[], int n, char const* nombre)
{
	int i = 1, contador = 0, d = 0;
	int valor;

/*
	for (i = 0; i < n; i++)
	{
		while (*us[i].nombre != ' ')
		{


		}
	}*/
	
	for (i = 0; i < n; i++)
	{
		valor = strcmp(us[i].nombre, nombre);

		if (valor == 0)
			d = i;
		else
			contador++;
	}

	if (contador == i)
	{
		printf("No hay un usuario llamado: %s \n", nombre);
		d = 11;
	}

	return d;
}

int leer_fichero(Usuario us[])
{
	FILE* fichero;
	int n = 0;
	errno_t e;
	char* p;

	e = fopen_s(&fichero, "Lista_usuarios.txt", "rt");
	if (fichero == NULL)
		printf("La lista esta vacia\n");
	else
	{
		fgets(us[n].nombre, TAM, fichero);
		//fscanf_s(fichero, "%s", us[n].nombre, TAM);
		while (!feof(fichero))
		{
			p = strchr(us[n].nombre, '\n');
			*p = '\0';
			
			fscanf_s(fichero, "%d\n", &us[n].canciones);
			n++;
			
			//fscanf_s(fichero, "%s", us[n].nombre, TAM);
			
			//fscanf_s(fichero, "%s", us[n].nombre, TAM);
			fgets(us[n].nombre, TAM, fichero);
		}
		fclose(fichero);
	}
	return n;
}


void listado_de_usuarios(Usuario us[], int n)
{
	int i;

	printf("\nUSUARIOS:\n");
	printf("\n---------------\n");
	for (i = 0; i < n; i++)
	{
		printf("Usuario = %s\n", us[i].nombre);
		if(us[i].canciones==11)
			printf("Numero de canciones guardadas = Ninguna\n");
		else
			printf("Numero de canciones guardadas = %d\n", us[i].canciones);
		printf("---------------\n");
	}
}
