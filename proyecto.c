#include <stdio.h>
#include <stdlib.h>
float consumo(float dinh, float eficiencia);

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
				break;
			case 'g':
				{
					//Muestra el gasto por dia, mes, o anno de agua, energetico y materias primas
					char gasto, periodo;
                    int duracion;
                    float agua, energia, matprim;
                    float aguah, energiah, matprimh; //gasto por unidad de tiempo
                    float costea, costee, costemp;
                    float consumo_agua(int duracion, float aguah); //funcion para calcular el consumo de agua
	                do
		            {
		            printf("Elige si prefieres conocer el gasto de agua (a), energia (e) o materia prima (m). Pulsa (s) si quieres salir.\n");
		            scanf(" %c", &gasto);
		            switch (gasto) {
			            case 'a':
			            {
						char infoagua;
						printf("El precio del agua en la Comunidad de Madrid es de 1,55 eur/m3.\n");
						printf("Deseas conocer mas informacion sobre el consumo de agua? (s/n)\n");
						scanf(" %c", &infoagua);
						switch (infoagua) {
							case 's':
				    			{
								printf("El consumo medio de agua en la industria nacional es de unos 15 m3/hora,\npero estos datos varian considerablemente segun el tipo.\nPor ejemplo, mientras que en la industria quimica la cifra llega a los 390,\nen la de la madera y el corcho es de apenas 1,3. (Fuente: INE)\n");
								printf("Introduce los metros cubicos de agua consumidos por hora.\n");
								scanf("%f", &aguah);
								printf("Elige si prefieres calculcar el gasto diario (d), mensual (m) o anual (a).\n");
								scanf(" %c", &periodo);
								switch (periodo) {
									case 'd':
										duracion = 24; //horas en un dia
										break;
									case 'm':
				            			duracion = 720; //horas en un mes
				            			break;
			            			case 'a':
				            			duracion = 8760; //horas en un aÒo
				            			break;
								}
								consumo_agua(duracion,aguah);
								printf("%.2f\n",consumo_agua);
								}
								break;
							case 'n':
				    			{
								printf("Introduce los metros cubicos de agua consumidos por hora.\n");
								scanf("%f", &aguah);
								printf("Elige si prefieres calculcar el gasto diario (d), mensual (m) o anual (a).\n");
								scanf(" %c", &periodo);
								switch (periodo) {
									case 'd':
										duracion = 24; //horas en un dia
										break;
									case 'm':
				            			duracion = 720; //horas en un mes
				            			break;
			            			case 'a':
				            			duracion = 8760; //horas en un aÒo
				            			break;
									}
									consumo_agua(duracion,aguah);
									printf("%.2f\n",consumo_agua);
								}
								break;
			    			}
		    			}
			    			break;
						case 'e':
							//
							break;
						case 'm':
						//
							break;
					}			
				}
				while(gasto!='s');	
				}
				
				break;
			case 'a':
				//Calcula el ahorro dependiendo de la eficiencia, las horas (valle, supervalle, punta) y energias renovables
				//AHORRO
			{
				int hora;
				char eficiencia;
				float consumo,ef,contotal;
				printf("Introduce la clase energetica (A,B,C,D)\n");
				scanf (" %c", &eficiencia);
				switch (eficiencia)
					{	case 'A':
						ef=0.35;
						break;
						
						case 'B':
						ef=0.6;
						break;
						
						case 'C':
						ef=0.83;
						break;
						
						case 'D':
						ef=1;
						break;
						
						default:
						printf ("No existe esa clase energetica\n");
						break;	
						}	
				printf ("Escribe la hora\n");
				scanf (" %i", &hora);
				
				if (hora>13 && hora<24) 
				{	printf ("Es una hora punta\n"); 
					consumo=0.162;
					printf ("El consumo en euros por kilovatio hora es: %.3f kWh\n", consumo);  }	    
				
				else if ((hora>=0 && hora<=1) || (hora>7 && hora<13))
				{	printf("Es una hora valle\n");
					consumo=0.093;
				 	printf ("El consumo en euros por kilovatio hora es: %.3f kWh\n", consumo);  }
				
				if (hora>1 && hora<7)
				{	printf ("Es una hora supervalle\n"); 
					consumo=0.071;
				 	printf ("El consumo en euros por kilovatio hora es: %.3f kWh\n", consumo); }
				 	
				contotal=ef*consumo;
				printf ("El consumo total, teniendo en cuenta la eficiencia es: %.4f\n", contotal);
				
			}
				
					
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
}
	


float consumo_agua(int duracion, float aguah) {
	float agua, costea;
	agua = aguah * duracion;
	costea = agua * 1.55;
	printf("El consumo de agua es de %.2f metros cubicos.\nEl gasto en agua es de %.2f euros.\n\n", agua, costea);
}
float consumo(float dinh, float eficiencia)
{
	float consumo;
	consumo=dinh*eficiencia;
	return consumo;
}
