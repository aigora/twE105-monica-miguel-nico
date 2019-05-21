# **Explicación de las funciones** 

Decidimos que para el mejor uso del programa era necesario tener una clara división de los distintos sectores que abarcaría nuestro
trabajo. Por ello, utilizamos switch case para que el usuario pudiese manejarse bien por el programa y conocer de una manera clara la 
información que desease saber. Es decir, si le interesa saber el consumo de agua en un día específico, puede elegir directamente la 
opción de gasto.

Por ejemplo, la funcion `float consumo_agua(int duracion, float aguah)`, nos sirve para obtener el consumo de agua dependiendo del periodo
y a su vez, lo traduce al gasto monetario que sería. También, la función `float contotal(float consumo, float ef)`, se utiliza para 
hacer el producto de el dinero por hora y la pegatina de eficiencia de la maquinaria, ya que no es lo mismo que trabajen en horas punta 
o valle. Otra función que es utilizada para hacer el cómputo económico en la sección de gasto es`float elige_dia(float energiah)`. 
La función recorre los 365 dias del año para poder averiguar el precio por dia, tomando como referencia el primer dia de cada mes.
