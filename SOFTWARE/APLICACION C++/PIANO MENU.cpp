#include<stdio.h>
#include <stdlib.h>
#include <locale.h>
void menu_ppal(void);
enum Estados { conectado, desconectado };
int main() {
	int opcion;
	setlocale(LC_ALL, "es-ES");
	do {
		menu_ppal();
		scanf_s("%d", &opcion);
	} while (opcion >2 && opcion != 2);
	return 0;
}
void menu_ppal(void) {
	int arduino,espacio;
	enum Estados arduino = desconectado;
	do
	{
		printf("Conecte el piano\n");
		if (arduino=conectado) {
		printf("Arduino esta conectado\n");
		printf("Introduzca una opción:\n");
		printf("1. Ver notas que se tocan\n");
		printf("2. No ver notas que se tocan\n");
		}
		else ("Conecte el piano");
	
	} while (espacio != ' ');
}
