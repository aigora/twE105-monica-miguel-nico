#include <stdio.h>

int main()
{
	char menu;
	
	do {
		printf("Bienvenid@.\nPor favor, elige una opcion:\n \
		Consumo (c)\n \
		Gasto (g)\n \
		Ahorro (a)\n \
		Salir (s)\n");
		scanf("%c", &menu);
		
		switch (menu) {
			case 'c':
				//Calcula el consumo de maquinaria,iluminación
				{
					char cons;
					do 
					{
					printf("Seleccione una opcion:\n");
					printf("Consumo de maquinaria (m)\n");
					printf("Consumo de iluminacion (i)\n");
					printf("Salir (s)\n");
					scanf("%c",&cons);
					switch (cons)
					{
						case 'm':
							{
								int tip, i, *nmaq;
								float *precio;
								printf("Introduzca cuantos tipos de maquina ha comprado:\n");
								scanf("%i",&tip);
								precio = malloc(sizeof(double)*(tip+1));
								nmaq = malloc(sizeof(int) * (tip+1));
								//Comprueba si malloc ha funcionado
								if (precio == NULL) {
								printf("Error: memoria no disponible.\n");
								exit(-1.0);
								}
								if (nmaq == NULL) {
								printf("Error: memoria no disponible.\n");
								exit(-1);
								}
								printf("Introduce el precio por maquina\n");
								for (i=0;i<=tip;i++)
								{
									scanf("%f", precio[i+1]);
									printf(" %.2f \t", *(precio + i));
									free(precio);
								}
								printf("Introduce el numero de maquinas de cada tipo");
								for (i=0;i<=tip;i++)
								{
									scanf("%i", nmaq[i+1]);
									printf(" %i \t", *(nmaq + i));
									free(nmaq);		
								}
								for (i=0;i<=tip;i++)
								{
								printf("El coste en total por tipo de maquina es:\n");
								printf("%.2f",nmaq[i]*precio[i]);
								}
								break;


							}
							break;
						case 'i':
							{
								int bomb;
								float pb=0.25,pt;
								printf("Introduce el numero de bombillas compradas:\n");
								scanf("%i",&bomb);
								pt=bomb*pb;
								printf("El coste total es: %.2f", pt);
							}
							break;
					}
					
				}
				while (cons!= 's');
					}

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
				printf("Elige una opcion valida, por favor.\n");
				break;
		}
	}
	while (menu != 's');
	
  return 0;
}
