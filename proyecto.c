#include <stdio.h>
#include <stdlib.h>

int main()
{
	char menu;
	
	do {
		printf("Bienvenid@.\nPor favor, elige una opcion:\n \
		Consumo (c)\n \
		Gasto (g)\n \
		Ahorro (a)\n \
		Salir (s)\n");
		scanf(" %c", &menu);
		
		switch (menu) {
			case 'c':
				//Calcula el consumo de maquinaria,iluminaci√≥n
				{
					char cons;
					do 
					{
					printf("Seleccione una opcion:\n");
					printf("Consumo de maquinaria (m)\n");
					printf("Consumo de iluminacion (i)\n");
					printf("Salir (s)\n");
					scanf(" %c",&cons);
					switch (cons)
					{
						case 'm':
							{
								int tip, i, *nmaq;
								float *precio;
								printf("Introduzca cuantos tipos de maquina ha comprado:\n");
								scanf("%i",&tip); //Da la dimension de los vectores
								precio = malloc(sizeof(float)*tip);
								nmaq = malloc(sizeof(int) *tip);
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
								for (i=0;i<tip;i++)
								{
									scanf("%f", &precio[i]);
								}
								printf("Introduce el numero de maquinas de cada tipo\n");
								for (i=0;i<tip;i++)
								{
									scanf("%i", &nmaq[i]);
								}
								printf("El coste en total por tipo de maquina es:\n");
								for (i=0;i<tip;i++) //Calcula el precio total
								{
								printf("Tipo %i: %.2f\n",(i+1), nmaq[i]*precio[i]);
								}
								break;
							}
						case 'i':
							{
								int bomb;
								float pb=0.25,pt;
								printf("Introduce el numero de bombillas compradas:\n");
								scanf("%i",&bomb);
								pt=bomb*pb;
								printf("El coste total es: %.2f\n", pt);
							}
							break;
					}
					
				} 
				while (cons!= 's');
					}

				;
				break;
			case 'g':
				//Muestra el gasto por dia, mes, o a√±o de agua, energ√©tico y materias primas
				char periodo, infoagua, s;
				int duracion;
				float agua, energia, matprim;
				float aguah, energiah, matprimh;
				float costea, costee, costemp;
				printf("Elige si prefieres conocer el gasto de un dia (d), un mes (m) o un anno (a)\n");
				scanf("%c", &periodo);
				switch (periodo) {
					case 'd':
						duracion = 24; //horas en un dia
						printf("El precio del agua en la Comunidad de Madrid es de 1,55Ä/m3.\n");
						printf("Deseas conocer m·s informacion sobre el consumo de agua? (s/n)\n");
						scanf("%c", &infoagua);
						if (infoagua = s) {
							printf("El consumo medio de agua en la industria nacional es de unos 15 m3/hora,\
							pero estos datos varian considerablemente segun el tipo. Por ejemplo, mientras que\
							en la industria quimica la cifra llega a los 390, en la de la madera y el corcho \
							es de apena 1,3. (Fuente: INE)\n");
						}
						printf("Introduce los metros cubicos de agua consumidos por hora.\n");
						scanf("%f", &aguah);
						agua = aguah * 24;
						costea = agua * 1.55;
						printf("El consumo diario de agua es de %.2f metros cubicos.\n\
						El gasto diario en agua es de %.2f Ä.\n", agua, costea);
						break;
					case 'm':
						duracion = 720; //horas en un mes
						break;
					case 'a':
						duracion = 8760; //horas en un aÒo
						break;
					default:
						printf("Elige una opciÛn v·lida, por favor.\n");
						break;
				}
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
