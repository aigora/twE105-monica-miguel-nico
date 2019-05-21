#include <stdio.h>
#include <stdlib.h>


int main()
{
	char menu;
	
	do {
		printf("Bienvenid@ a nuestro software con el que podras hacer calculos sobre tu empresa.\nPor favor, elige una opcion:\n \
		Consumo (c)\n \
		Gasto (g)\n \
		Ahorro (a)\n \
		Salir (s)\n");
		scanf(" %c", &menu);
		
		switch (menu) {
			case 'c':
				//Calcula el consumo de maquinaria,iluminacion
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
						case 'm': //Calcula el precio por tipos de maquinas
							{
								int tip, i, *nmaq;
								float *precio, total=0.0;
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
								for(i=0;i<tip;i++)
								{
									total=total+nmaq[i]*precio[i];
								}
								printf("El precio total de las maquinas es: %.2f\n",total);
								break;
							}
						case 'i': //Calcula el precio total por bombillas
							{
								int bomb;
								float pb,pt;
								printf("Introduce el numero de bombillas compradas:\n");
								scanf("%i",&bomb);
								printf("Introduce el precio por bombilla:\n");
								scanf("%f",&pb);
								pt=bomb*pb;
								printf("El coste total es: %.2f\n", pt);
							}
							break;
					}
					
				} 
				while (cons!= 's');
					}
				break;
				
				
				
			case 'g': // GASTO
				{
					char gasto, periodo;
    				int duracion;
    				float aguah, energiah; //gasto por hora
    				char infoagua, infoenergia, resumen;
    				void resumir(); // funcion que permite hacer un resumen de los precios de la electricidad
    				float consumo_agua(int duracion, float aguah); //funcion para calcular el consumo de agua
    				float consumo_energia(int duracion, float energiah); //funcion para calcular el consumo de de energia
    				float elige_dia(float energiah), elige_mes(float energiah); // funciones para elegir un dia/mes concreto (para el gasto economico)
					float anno(float energiah); // funcion para hacer la media anual (para el gasto economico)
    
    

	    do
		{
		//Muestra el gasto por dia, mes, o año de agua y energia
		printf("\nElige si prefieres conocer el gasto de agua (a) o de energia (e). Pulsa (s) si quieres salir.\n");
		scanf(" %c", &gasto);
		switch (gasto) {
			
			
			case 'a': //Gasto de agua
			{
			printf("\nEl precio del agua en la Comunidad de Madrid es de 1,55 eur/m3.\n");
			printf("Deseas conocer mas informacion sobre el consumo de agua? (s/n)\n"); //Posibilidad de obtener info. útil para tomar la próxima decisión
			scanf(" %c", &infoagua);
			switch (infoagua) {
				case 's':
				    {
					printf("\nEl consumo medio de agua en la industria nacional es de unos 15 m3/hora,\npero estos datos varian considerablemente segun el tipo.\nPor ejemplo, mientras que en la industria quimica la cifra llega a los 390,\nen la de la madera y el corcho es de apenas 1,3. (Fuente: INE)\n");
					printf("Introduce los metros cubicos de agua consumidos por hora.\n"); // pedimos el consumo
					scanf("%f", &aguah);
					printf("\nElige si prefieres calculcar el gasto diario (d), mensual (m) o anual (a).\n"); // preguntamos por el periodo a calcular
					scanf(" %c", &periodo);
					switch (periodo) {
						case 'd':
							duracion = 24; //horas en un dia
							break;
						case 'm':
				            duracion = 720; //horas en un mes
				            break;
			            case 'a':
				            duracion = 8760; //horas en un año
				            break;
					}
					consumo_agua(duracion,aguah); // calculamos el gasto tanto hidrico como economico
					}
					break;
					
				case 'n':
				    {
					printf("\nIntroduce los metros cubicos de agua consumidos por hora.\n"); // pedimos el consumo
					scanf("%f", &aguah);
					printf("\nElige si prefieres calculcar el gasto diario (d), mensual (m) o anual (a).\n"); // preguntamos por el periodo
					scanf(" %c", &periodo);
					switch (periodo) {
						case 'd':
							duracion = 24; //horas en un dia
							break;
						case 'm':
				            duracion = 720; //horas en un mes
				            break;
			            case 'a':
				            duracion = 8760; //horas en un año
				            break;
					}
					consumo_agua(duracion,aguah); // calculamos el gasto tanto hidrico como economico
					}
					break;
			    }
		    }
			    break;
			    
			    
			case 'e': //Gasto de energía
				{
					printf("\nEl consumo energetico medio de una fabrica en nuestro pais es de 0,113 MWh.\n");
					printf("Deseas conocer mas informacion sobre el consumo de energia? (s/n)\n"); //Posibilidad de obtener info. útil para tomar la próxima decisión
					scanf(" %c", &infoenergia);
					switch (infoenergia) {
						case 's':
				    {
					printf("\nLa industria nacional consume algo mas de 20 GWh, lo que supone una parte\nmuy considerable de la energia que producimos.\nLa cifra media que te hemos proporcionado antes esta sujeta a muchos factores:\npor ejemplo, mientras que en industrias como la textil o la de los muebles\nel consumo energetico esta hasta hasta 20 veces por debajo de la media,\nla metelargia o las industrias quimica o mineral la llegan a cuadriplicar. (Fuente: INE)\n");
					printf("Introduce la potencia consumida en megavatios hora.\n"); // pedimos el consumo
					scanf("%f", &energiah);  
    				printf("\nElige si prefieres calculcar el gasto diario (d), mensual (m) o anual (a).\n"); // preguntamos por el periodo
					scanf(" %c", &periodo);
					switch (periodo) {
						case 'd':
							duracion = 24; //horas en un dia
							printf("\nEl gasto diario en energia es de %.2f euros.\n", elige_dia(energiah)); // damos a elegir el dia concreto para el gasto economico
							break;
						case 'm':
							duracion = 720; //horas en un mes
				            printf("\nEl gasto mensual en energia es de %.2f euros.\n", elige_mes(energiah)); // damos a elegir el mes concreto para el gasto economico
				            break;
			            case 'a':
			            	duracion = 8760; //horas en un año
				            printf("\nEl gasto anual en energia es de %.2f euros.\n", anno(energiah)); // calculamos el gasto economico
				            break;
					}
					consumo_energia(duracion,energiah); // calculamos el gasto energetico
					}
					break;
					
				case 'n':
				    {
					printf("\nIntroduce la potencia consumida en megavatios hora.\n"); // pedimos el consumo
					scanf("%f", &energiah);  
    				printf("\nElige si prefieres calculcar el gasto diario (d), mensual (m) o anual (a).\n"); // preguntamos por el periodo
					scanf(" %c", &periodo);
					switch (periodo) {
						case 'd':
							duracion = 24; //horas en un dia
							printf("\nEl gasto diario en energia es de %.2f euros.\n", elige_dia(energiah)); // damos a elegir el dia concreto para el gasto economico
							break;
						case 'm':
							duracion = 720; //horas en un mes
				            printf("\nEl gasto mensual en energia es de %.2f euros.\n", elige_mes(energiah)); // damos a elegir el mes concreto para el gasto economico
				            break;
			            case 'a':
			            	duracion = 8760; //horas en un año
				            printf("\nEl gasto anual en energia es de %.2f euros.\n", anno(energiah)); // calculamos el gasto economico
				            break;
					}
					consumo_energia(duracion,energiah); // calculamos el gasto energetico
					}
					break;
					}
					
					printf("\nQuieres ver un resumen de los precios medios de la electricidad? (s/n)\n"); // ofrecemos la posibilidad de conocer un resumen de precios
					scanf(" %c", &resumen);
					switch (resumen) {
						case 's':
							resumir();
							break;
						case 'n':
							printf("\nGracias de todos modos.\n");
							break;
					}
				}
				break;
			}			
			}
			while(gasto != 's'); // para salir de la seccion de gasto	
				}
				
				break;
			case 'a':
				//Calcula el ahorro dependiendo de la eficiencia, las horas (valle, supervalle, punta) y energias renovables
				//AHORRO
			{
				float contotal(float consumo, float ef);
				int hora;
				float consumo,A,B,C,D,ef,dinh,con;
				char eficiencia;
				printf ("Escribe la hora y la clase energetica(A,B,C,D)\n");
				scanf ("%i %c", &hora, &eficiencia );

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
 		
					con=contotal(consumo,ef);
					printf ("El consumo total, teniendo en cuenta la eficiencia es: %.4f", con);

					return 0;

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
	float agua, costea; // variables para el consumo de agua por periodo y para el gasto economico
	agua = aguah * duracion;
	costea = agua * 1.55;
	printf("\nEl consumo de agua es de %.2f metros cubicos.\nEl gasto en agua es de %.2f euros.\n\n", agua, costea);
}

float consumo_energia(int duracion, float energiah) {
	float energia; // variable para el gasto energetico en MWh
	energia = energiah * duracion;
	switch (duracion) {
		case 24:
			printf("\nEl consumo de energia es de %.2f megavatios hora por dia.\n\n", energia);
			break;
		case 720:
			printf("\nEl consumo de energia es de %.2f megavatios hora por mes.\n\n", energia);
			break;
		case 8760:
			printf("\nEl consumo de energia es de %.2f megavatios hora por anno.\n\n", energia);
			break;
	}
}

float elige_dia(float energiah) {
	FILE *pf;
	int i=0, j=0;
	int k=0;
	int mes, dia;
	float p_dia;
	float precio[365];
	
	pf = fopen("precioselectricidad.txt", "r");
  if (pf == NULL)
    {
      printf("Error al abrir el fichero");
      return -1;
    }
  else
    { // leemos cada línea del fichero
      for (i = 0; i < 365; i++)
	{
	  fscanf(pf, "%f", &precio[i]);
	}
	/*for (i = 0; i < 365; i++) {
		printf("%.2f\n", precio[i]);
		}*/
      fclose(pf); // cerramos el fichero
	}
	
	printf("\nEscoge un mes del anno:\n\t(1)enero\t(2)febrero\t(3)marzo\t(4)abril\n\
\t(5)mayo\t        (6)junio\t(7)julio\t(8)agosto\n\
\t(9)septiembre\t(10)octubre\t(11)noviembre\t(12)diciembre\n"); // primero damos a escoger el mes
	scanf(" %i", &mes);
	switch (mes) {
		case 1: // explicamos el funcionamiento con el primer caso:
			j=0; // damos el valor inicial a la variable correspondiente al primer dia del mes elegido
			printf("Elige un dia del mes\n"); // damos a elegir el dia concreto
			scanf("%i", &dia);
			k = j + dia - 1; // sumamos el numero (restamos 1 por el elemento 0 del vector) para llegar al dia escogido
			p_dia = precio[k];
			break;
		case 2:
			j=31;
			printf("Elige un dia del mes\n");
			scanf("%i", &dia);
			k = j + dia - 1;
			p_dia = precio[k];
			break;
		case 3:
			j=59;
			printf("Elige un dia del mes\n");
			scanf("%i", &dia);
			k = j + dia - 1;
			p_dia = precio[k];
			break;
		case 4:
			j=90;
			printf("Elige un dia del mes\n");
			scanf("%i", &dia);
			k = j + dia - 1;
			p_dia = precio[k];
			break;
		case 5:
			j=120;
			printf("Elige un dia del mes\n");
			scanf("%i", &dia);
			k = j + dia - 1;
			p_dia = precio[k];
			break;
		case 6:
			j=151;
			printf("Elige un dia del mes\n");
			scanf("%i", &dia);
			k = j + dia - 1;
			p_dia = precio[k];
			break;
		case 7:
			j=181;
			printf("Elige un dia del mes\n");
			scanf("%i", &dia);
			k = j + dia - 1;
			p_dia = precio[k];
			break;
		case 8:
			j=212;
			printf("Elige un dia del mes\n");
			scanf("%i", &dia);
			k = j + dia - 1;
			p_dia = precio[k];
			break;
		case 9:
			j=243;
			printf("Elige un dia del mes\n");
			scanf("%i", &dia);
			k = j + dia - 1;
			p_dia = precio[k];
			break;
		case 10:
			j=273;
			printf("Elige un dia del mes\n");
			scanf("%i", &dia);
			k = j + dia - 1;
			p_dia = precio[k];
			break;
		case 11:
			j=304;
			printf("Elige un dia del mes\n");
			scanf("%i", &dia);
			k = j + dia - 1;
			p_dia = precio[k];
			break;
		case 12:
			j=334;
			printf("Elige un dia del mes\n");
			scanf("%i", &dia);
			k = j + dia - 1;
			p_dia = precio[k];
			break;
		default:
			printf("El anno tiene solo 12 meses");
			break;
	}
	return p_dia*energiah*24; // gasto economico 
}

float elige_mes(float energiah) {
	int i=0, j=0, mes;
	float sumaprecio, p_medio, resultado;
	float precio[365]; // vector donde almacenaremos los precios diarios de la electricidad
	FILE *pf;
	
	pf = fopen("precioselectricidad.txt", "r");
  if (pf == NULL)
    {
      printf("Error al abrir el fichero");
      return -1;
    }
  else
    { // leemos cada línea del fichero
      for (i = 0; i < 365; i++)
	{
	  fscanf(pf, "%f", &precio[i]);
	}
	/*for (i = 0; i < 365; i++) {
		printf("%.2f\n", precio[i]);
		}*/
      fclose(pf); // cerramos el fichero
	}
	
	printf("\nEscoge un mes del anno:\n\t(1)enero\t(2)febrero\t(3)marzo\t(4)abril\n\
\t(5)mayo\t        (6)junio\t(7)julio\t(8)agosto\n\
\t(9)septiembre\t(10)octubre\t(11)noviembre\t(12)diciembre\n"); // damos a elegir el mes
	scanf("%i", &mes);
	switch (mes) {
		case 1: // explicamos el funcionamiento con el primer caso
			for (j=0;j<31;j++) {
				sumaprecio += precio[j];} // hacemos el sumatorio del precio media de cada dia del mes
				p_medio = sumaprecio/31.0; // y lo dividimos entre el numero de dias
				resultado = p_medio*energiah*24.0*31.0; // devolvemos el precio por el consumo por la duracion del periodo
			break;
		case 2:
			for (j=31;j<59;j++) {
				sumaprecio += precio[j];}
				p_medio = sumaprecio/28.0;
				resultado = p_medio*energiah*24.0*28.0;
			break;
		case 3:
			for (j=59;j<90;j++) {
				sumaprecio += precio[j];}
				p_medio = sumaprecio/31.0;
				resultado = p_medio*energiah*24.0*31.0;
			break;
		case 4:
			for (j=90;j<120;j++) {
				sumaprecio += precio[j];}
				p_medio = sumaprecio/30.0;
				resultado = p_medio*energiah*24.0*30.0;
			break;
		case 5:
			for (j=120;j<151;j++) {
				sumaprecio += precio[j];}
				p_medio = sumaprecio/31.0;
				resultado = p_medio*energiah*24.0*31.0;
			break;
		case 6:
			for (j=151;j<181;j++) {
				sumaprecio += precio[j];}
				p_medio = sumaprecio/30.0;
				resultado = p_medio*energiah*24.0*30.0;
			break;
		case 7:
			for (j=181;j<212;j++) {
				sumaprecio += precio[j];}
				p_medio = sumaprecio/31.0;
				resultado = p_medio*energiah*24.0*31.0;
			break;
		case 8:
			for (j=212;j<243;j++) {
				sumaprecio += precio[j];}
				p_medio = sumaprecio/31.0;
				resultado = p_medio*energiah*24.0*31.0;
			break;
		case 9:
			for (j=243;j<273;j++) {
				sumaprecio += precio[j];}
				p_medio = sumaprecio/30.0;
				resultado = p_medio*energiah*24.0*30.0;
			break;
		case 10:
			for (j=273;j<304;j++) {
				sumaprecio += precio[j];}
				p_medio = sumaprecio/31.0;
				resultado = p_medio*energiah*24.0*31.0;
			break;
		case 11:
			for (j=304;j<334;j++) {
				sumaprecio += precio[j];}
				p_medio = sumaprecio/30.0;
				resultado = p_medio*energiah*24.0*30.0;
			break;
		case 12:
			for (j=334;j<365;j++) {
				sumaprecio += precio[j];}
				p_medio = sumaprecio/31.0;
				resultado = p_medio*energiah*24.0*31.0;
			break;
		default:
			printf("El anno tiene solo 12 meses");
			break;
	}
	return resultado;
}

float anno(float energiah) {
	FILE *pf;
	int i=0, j=0;
	float sumaprecio, p_medio;
	float precio[365]; // vector donde almacenaremos los precios diarios
	
	pf = fopen("precioselectricidad.txt", "r");
  if (pf == NULL)
    {
      printf("Error al abrir el fichero");
      return -1;
    }
  else
    { // leemos cada línea del fichero
      for (i = 0; i < 365; i++)
	{
	  fscanf(pf, "%f", &precio[i]);
	}
	/*for (i = 0; i < 365; i++) {
		printf("%.2f\n", precio[i]);
		}*/
      fclose(pf); // cerramos el fichero
	}
	
	for (j=0;j<365;j++) {
		sumaprecio += precio[j];
	}
	p_medio = sumaprecio/365.0; // calculamos el precio medio anual
	
	return p_medio*energiah*24.0*365.0;
}

void resumir() {
	FILE *pf, *wf;
	int i=0, j=0;
	float suma[13], media[13];
	float precio[365]; // vector donde almacenaremos los precios diarios
	
	pf = fopen("precioselectricidad.txt", "r");
  /*if (pf == NULL)
    {
      printf("Error al abrir el fichero");
      return -1;
    }*/
  //else
    { // leemos cada línea del fichero
      for (i = 0; i < 365; i++)
	{
	  fscanf(pf, "%f", &precio[i]);
	}
	/*for (i = 0; i < 365; i++) {
		printf("%.2f\n", precio[i]);
		}*/
      fclose(pf); // cerramos el fichero
	}
	
	// calculamos los precios medios de cada mes
	for (j=0;j<31;j++) {
	suma[0] += precio[j];
	}
	media[0] = suma[0]/31.0; //enero
	
	for (j=31;j<59;j++) {
	suma[1] += precio[j];
	}
	media[1] = suma[1]/28.0; //febrero
	
	for (j=59;j<90;j++) {
	suma[2] += precio[j];
	}
	media[2] = suma[2]/31.0; //marzo
	
	for (j=90;j<120;j++) {
	suma[3] += precio[j];
	}
	media[3] = suma[3]/30.0; //abril
	
	for (j=120;j<151;j++) {
	suma[4] += precio[j];
	}
	media[4] = suma[4]/31.0; //mayo
	
	for (j=151;j<181;j++) {
	suma[5] += precio[j];
	}
	media[5] = suma[5]/30.0; //junio
	
	for (j=181;j<212;j++) {
	suma[6] += precio[j];
	}
	media[6] = suma[6]/31.0; //julio
	
	for (j=212;j<243;j++) {
	suma[7] += precio[j];
	}
	media[7] = suma[7]/31.0; //agosto
	
	for (j=243;j<273;j++) {
	suma[8] += precio[j];
	}
	media[8] = suma[8]/30.0; //septiembre
	
	for (j=273;j<304;j++) {
	suma[9] += precio[j];
	}
	media[9] = suma[9]/31.0; //octubre
	
	for (j=304;j<334;j++) {
	suma[10] += precio[j];
	}
	media[10] = suma[10]/30.0; //noviembre
	
	for (j=334;j<365;j++) {
	suma[11] += precio[j];
	}
	media[11] = suma[11]/31.0; //diciembre
	
	for (j=0;j<365;j++) {
	suma[13] += precio[j];
	}
	media[13] = suma[13]/365.0; // media anual

	
	wf = fopen("resumen.txt", "w"); // escribimos el resumen -> precios mensuales, anual + 2 curiosidades ;)
    fprintf(wf, "Precios medios de la electricidad (en euros por MWh):\n\
\tEnero: %.2f\n\
\tFebrero: %.2f\n\
\tMarzo: %.2f\n\
\tAbril: %.2f\n\
\tMayo: %.2f\n\
\tJunio: %.2f\n\
\tJulio: %.2f\n\
\tAgosto: %.2f\n\
\tSeptiembre: %.2f\n\
\tOctubre: %.2f\n\
\tNoviembre: %.2f\n\
\tDiciembre: %.2f\n\n", media[0], media[1], media[2], media[3], media[4], media[5], media[6], media[7], media[8], media[9], media[10], media[11]);
    fprintf(wf, "Precio medio anual:\n\t%.2f eur/MWh\n\n\n", media[13]);
	fprintf(wf, "Sabias que...?\nEl 24 de febrero fue el dia con la electricidad mas barata (25,38eur); mas de la mitad se produjo con renovables.\n\
En cambio, el 19 de julio fue la mas cara (76,38eur); donde las renovables apenas llegaron a la cuarta parte.\n");
	fclose(wf);
}

float contotal(float consumo, float ef) {
	float con;
	con=consumo*ef;
	return con;
}
