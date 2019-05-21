# **Explicación de las funciones** 

Decidimos que para el mejor uso del programa era necesario tener una clara división de los distintos sectores que abarcaría nuestro trabajo. Por ello, utilizamos _switch case_ para que el usuario pudiese manejarse bien por el programa y conocer de una manera clara la  información que desease saber. Es decir, si le interesa saber el consumo de energía en un día específico, puede elegir directamente la  opción de gasto.

Por ejemplo, la funcion `float consumo_agua(int duracion, float aguah)`, nos sirve para obtener el consumo de agua dependiendo del periodo y, a su vez, lo traduce en el gasto monetario que supondría. Igual sucede con `float consumo_energia(int duracion, float energiah)`, pero para el consumo de energía.
Otra función que es utilizada para hacer el cómputo económico en la sección de gasto es `float elige_dia(float energiah)`. La función recorre los 365 dias del año para poder averiguar el precio por dia, tomando como referencia el primer día de cada mes. `float elige_mes(float energiah)` averigua el precio medio mensual a partir de la media entre todos los días del mes. Por último, `float anno(float energiah)` realiza una tarea idéntica, solo que con todos los días del año.
La función `void resumir()` permite obtener un resumen de precios mensuales y anual, los cuales se calculan como ya se ha explicado anteriormente.
_Todos los datos usados en esta sección son reales, correspondientes al año 2015 (Fuentes: INE y Red Eléctrica de España)._

También, la función `float contotal(float consumo, float ef)`, se utiliza para hacer el producto del dinero por hora y la pegatina de eficiencia de la maquinaria, ya que no es lo mismo que trabajen en horas punta o valle.
La siguiente estructura:
#`typedef struct {
	float superficie;
	float eficienciapv;
} panel;`
Se utiliza para calcular la potencia generada y la reducción de la huella de carbono al instalar paneles fotovoltaicos, cuyo tamaño y eficiencia introduce el usuario, recibiendo además el coste estimado de dicha instalación.
