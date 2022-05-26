#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <conio.h>
#include "SerialClass/SerialClass.h"

#define MAX_BUFFER 200
#define PAUSA_MS 200

// Funciones prototipo del piano beta (no estan todas las funciones)
int menu(void);
void tocar_piano(Serial*);
void comprobar_mensajes(Serial*);
void grabar_notas(Serial*);
void ver_canciones(Serial*);
void comprobar_mensajes(Serial*);
int leer_notas(Serial*);
int Enviar_y_Recibir(Serial*, const char*, char*);
int Nnotas(char* cadena);

int main(void)
{
	Serial* Arduino;
	char puerto[] = "COM6"; // Puerto serie al que está conectado Arduino
	int opcion_menu;

	setlocale(LC_ALL, "es-ES");
	Arduino = new Serial((char*)puerto);
	do
	{
		comprobar_mensajes(Arduino);
		opcion_menu = menu();
		switch (opcion_menu)
		{
		case 0: break;
		case 1:
			tocar_piano(Arduino);
			break;
		case 2:
			grabar_notas(Arduino);
			break;
		case 3:
			ver_canciones(Arduino);
			break;
		case 4:
			break;
		default: printf("\nOpción incorrecta\n");
		}
	} while (opcion_menu != 4);
	return 0;
}


// La función menú muestra las funciones del piano en pantalla

int menu(void)
{
	static int opcion = -1;

	if (opcion != 0)
	{
		printf("\n");
		printf("Menú Principal\n");
		printf("==============\n");
		printf("1 - Tocar piano libremente.\n");
		printf("2 - Grabar melodia y reproducirla.\n");
		printf("3 - Ver canciones.\n");
		printf("4 - Salir de la aplicación\n");
		printf("Opción: ");
	}
	if (_kbhit())
	{
		opcion = (int)_getch() - '0';
		printf("%d\n", opcion);
	}
	else
		opcion = 0;
	return opcion;
}

void comprobar_mensajes(Serial* Arduino)
{
	int bytesRecibidos, total = 0;
	char mensaje_recibido[MAX_BUFFER];

	bytesRecibidos = Arduino->ReadData(mensaje_recibido, sizeof(char) * MAX_BUFFER - 1);
	while (bytesRecibidos > 0)
	{
		Sleep(PAUSA_MS);
		total += bytesRecibidos;
		bytesRecibidos = Arduino->ReadData(mensaje_recibido + total, sizeof(char) * MAX_BUFFER - 1);
	}
	if (total > 0)
	{
		mensaje_recibido[total - 1] = '\0';
		printf("\nMensaje recibido: %s\n", mensaje_recibido);
	}
}

void tocar_piano(Serial* Arduino)
{
	int notas;
	char notasn[200];
	char tecla;


	printf("Pulse una tecla para finalizar de tocar el piano\n");
	do
	{
		if (Arduino->IsConnected())
		{
			Arduino->ReadData(notasn, sizeof(notasn) - 1);
			notas = leer_notas(Arduino);

			if (notas != -1)
				printf("%d ", notas);
			else
				printf("XXX ");
		}
		else
			printf("\nNo se ha podido conectar con Arduino.\n");

	} while (_kbhit() == 0);
	tecla = _getch();
	return;


}

int leer_notas(Serial* Arduino)
{
	int notas;
	int bytesRecibidos;
	char mensaje_recibido[MAX_BUFFER];

	bytesRecibidos = Enviar_y_Recibir(Arduino, "GET_NOTAS\n", mensaje_recibido);

	if (bytesRecibidos <= 0)
		notas = -1;
	else
		notas = Nnotas(mensaje_recibido);
	return notas;
}

int Enviar_y_Recibir(Serial* Arduino, const char* mensaje_enviar, char* mensaje_recibir)
{
	int bytes_recibidos = 0, total = 0;
	int intentos = 0, fin_linea = 0;


	Arduino->WriteData((char*)mensaje_enviar, strlen(mensaje_enviar));
	Sleep(PAUSA_MS);

	bytes_recibidos = Arduino->ReadData(mensaje_recibir, sizeof(char) * MAX_BUFFER - 1);

	while ((bytes_recibidos > 0 || intentos < 5) && fin_linea == 0)
	{
		if (bytes_recibidos > 0)
		{
			total += bytes_recibidos;
			if (mensaje_recibir[total - 1] == 13 || mensaje_recibir[total - 1] == 10)
				fin_linea = 1;
		}
		else
			intentos++;
		Sleep(PAUSA_MS);
		bytes_recibidos = Arduino->ReadData(mensaje_recibir + total, sizeof(char) * MAX_BUFFER - 1);
	}
	if (total > 0)
		mensaje_recibir[total - 1] = '\0';

	//printf("LOG: %d bytes -> %s\nIntentos=%d - EOLN=%d\n", total, mensaje_recibir,intentos,fin_linea);
	return total;
}



int Nnotas(char* cadena)
{
	int numero = 0;
	int i, divisor = 10, estado = 0;


	for (i = 0; cadena[i] != '\0'  && i < MAX_BUFFER; i++)
		switch (estado)
		{
		case 0:// Antes del número
			if (cadena[i] >= '0' && cadena[i] <= '9')
			{
				numero = cadena[i] - '0';
				estado = 1;
			}
			break;
		case 1:// Durante el número
			if (cadena[i] >= '0' && cadena[i] <= '9')
				numero = numero * 10 + cadena[i] - '0';
		}
	return numero;
}

void grabar_notas(Serial* Arduino)
{
	int notas,j=0;
	char notasn[200];
	char tecla;


	printf("Pulse una tecla para finalizar de tocar el piano\n");
	do
	{
		if (Arduino->IsConnected())
		{
			Arduino->ReadData(notasn, sizeof(notasn) - 1);
			notasn = leer_notas(Arduino);

			if (notans != '\0')
				printf("%s ", notasn);
			else
				printf("XXX ");
		}
		else
			printf("\nNo se ha podido conectar con Arduino.\n");

	} while (_kbhit() == 0);
	tecla = _getch();
	
	 for(j=0;j<i;j++)
	 {
		 Arduino->WriteData((char*)notasn, strlen(notasn));
	         Sleep(PAUSA_MS);
	 }
	
	return;
}

void ver_canciones(Serial*)
{
	int i=0,opcion=0;
	
	printf("Lista de canciones:\n");
	printf("1- He is a Pirate\n");
	printf("2- Crazy Frog\n");
	printf("3- Level Theme: Mario Underworld\n");
	printf("Elija opcion: ");
	
	while(opcion > 0 && opcion <4)
	{
		scanf_s("%d",&opcion);
		if(opcion > 0 && opcion <4)
			printf("Elija una opcion entre 1 y 3: \n");
	}
	
	Arduino->WriteData((int)opcion);
	Sleep(PAUSA_MS);
	
	return;
}
