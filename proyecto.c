#include <stdio.h>

int main()
{
	char menu;
	
	do {
		printf("Bienvenid@.\nPor favor, elige una opci�n:\n \
		Consumo (c)\n \
		Gasto (g)\n \
		Ahorro (a)\n \
		Salir (s)\n");
		scanf("%c", &menu);
		
		switch (menu) {
			case 'c':
				;
				break;
			case 'g':
				;
				break;
			case 'a':
				;
				break;
			case 's':
				printf("Gracias por participar.\n");
				break;
			default:
				printf("Elige una opci�n v�lida, por favor.\n");
				break;
		}
	}
	while (menu != 's');
	
  return 0;
}
