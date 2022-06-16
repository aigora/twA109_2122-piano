#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <conio.h>
#include <string.h>
#include <malloc.h>
#include "SerialClass/SerialClass.h"

#define MAX_BUFFER 300
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
//void tocar_piano(Serial*, Usuario[], int, int);
//void grabar(Serial*, Usuario[], int, int);
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
			do {
				printf("¿Que usuario eres?\n");
				scanf_s("%s", nombre_us, TAM);

				n_usuario = buscar_usuarios(usuarios, nusuarios, nombre_us);
			} while (n_usuario == 11);

			//tocar_piano(Arduino, usuarios, n_usuario, nusuarios);

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

	} while (opc_menu != 5);

	crear_fichero(usuarios, nusuarios);
}

void tocar_piano(Serial* Arduino, Usuario us, int n_usuario, int nusuarios)
{
	char notasn, tecla;
	if (Arduino->IsConnected())
	{
		printf("\nArduino conectado.\n");
		do
		{
			Arduino->ReadData(&notasn, sizeof(notasn));

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


	tecla = _getch();
}

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
	int i = 0, contador = 0, d = 0;
	int valor;

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
	char* po;
	e = fopen_s(&fichero, "Lista_usuarios.txt", "rt");
	if (fichero == NULL)
		printf("La lista esta vacia\n");
	else
	{
		fgets(us[n].nombre, TAM, fichero);
		while (!feof(fichero))
		{
			po = strchr(us[n].nombre, '\n'); 
			*po = '\0';                   

			fscanf_s(fichero, "%d\n", &us[n].canciones);
			n++;
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

