#include <stdio.h>

int main()
{
	char menu;
	
	do {
		printf("Bienvenid@.\nPor favor, elige una opción:\n \
		Consumo (c)\n \
		Gasto (g)\n \
		Ahorro (a)\n \
		Salir (s)\n");
		scanf("%c", &menu);
		
		switch (menu) {
			case 'c':
				//Calcula el consumo de maquinaria,iluminación y otros servicios
				;
				break;
			case 'g':
				//Muestra el gasto por dia, mes, o año de agua, energético y materias primas
				;
				break;
			case 'a':
				//Calcula el ahorro dependiendo de la eficiencia, las horas (valle, supervalle, punta) y energias renovables
				;
				break;
			case 's':
				printf("Gracias por usar nuestro software.\n");
				break;
			default:
				printf("Elige una opción válida, por favor.\n");
				break;
		}
	}
	while (menu != 's');
	
  return 0;
}
