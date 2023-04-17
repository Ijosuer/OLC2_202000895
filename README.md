# OLC2_N
---

**Universidad de San Carlos de Guatemala**

**Facultad de Ingenieria**

**Escuela de Ciencias y Sistemas**

**Organización de Lenguajes y Compiladores 2**

**Ing. Edgar Ruben Saban Raxon**

**Aux. Jose Andres Rodas Arrecis**

| Carné     | Nombre                              |
| --------- | ----------------------------------- |
| 202000895 | Josue Rolando Gramajo Roldan        |
---

## Documentación

# MANUAL DE USUARIO
## _Mini OL🅒_ 
Mini OL🅒 IDE es un entorno de desarrollo que provee las herramientas para la escritura de
programas en lenguaje mini OL🅒. Este IDE nos da la posibilidad de visualizar tanto la
salida en consola de la ejecución del archivo fuente como los diversos reportes de la
aplicación que se explican más adelante.

## Características de la infertaz

- Numero de línea y columna 
- Botón para interpretar
- Reporte de errores
- Reporte de tabla de simbolos
- Reporte de AST
- Consola especial

![](https://live.staticflickr.com/65535/52821671162_73106decbb_c.jpg)
<center>Imagen 1</center>

## Flujo de la aplicación

> 1. Interpreta: Esta opción nos va a permitir interpretar una entrada. El programa recibe un archivo de entrada de código de alto nivel y ejecuta las instrucciones.
> 2. Reportes: Esta opcion nos va a permitir visualizar los reportes generados despues de intepretar una entrada.
La aplicación tendra una sintaxis, la cual debera ser respetada o de lo contrario tendra como resultado una salida con errores.
## Sintaxis de Mini OL🅒

La aplicación tendra una sintaxis, la cual debera ser respetada o de lo contrario tendra como resultado una salida con errores.

- Tipos: Mini OL🅒 aceptará distintos tipos de datos con los que cuenta Java y C. Entre ellos se aceptarán:

| Tipo     | Ejemplo |
| -------- | -------- |
| Int      | 3,2,-1,100     |
| Float   | 3.1415, 2.782,0.5 |
| Bool  | True o False     |
| String   | "Hola", "Mundo"     |
| Arreglos | {10, 20, 30, 40} |
| Struct   |   Estos pueden contener cualquier tipo de dato en su interior, incluso otros struct, arreglos o arreglos de structs   |

- Expresiones: Mini OL🅒 acepta operaciones aritmeticas, relacionales y logicas de la siguiente forma:


|  Expresion | Descripcion | Tipo |
| -------- | -------- |--------|
| Suma     | La suma de dos expresiones se define por el símbolo +    |Aritmetica|
| Resta | La resta de dos expresiones y la negación de una expresión aritmetica se define por el símbolo - |Aritmetica|
| Multiplicación     |  La multiplicación de dos expresiones se define por el símbolo *     |Aritmetica|
| División | La división de dos expresiones se define por el símbolo / |Aritmetica|
| Modulo     | El modulo entre dos expresiones se define por el símbolo %     |Aritmetica|
| Nativas | Mini OL🅒 posee 3 funciones nativas para la resolución de expresiones con vectores, entre ellas se encuentran: |Aritmetica|
| push_back     |  Agrega al final de un vector la expresion recibida     |Aritmetica|
| push_front     |  Agrega al inicio de un vector la expresion recibida     |Aritmetica|
| size     | Devuelve el tamaño de un vector    |Aritmetica|
| Embebidas | Mini OL🅒 posee 6 funciones nativas para la resolución de expresiones, entre ellas se encuentran: |Aritmetica|
| media | Resuelve la función media del vector recibido |Aritmetica|
| mediana     |  Resuelve la función mediana del vector recibido     |Aritmetica|
| moda     |  Resuelve la función moda del vector recibido     |Aritmetica|
| iota     |  Toma como parámetro un valor numérico y retorna una cadena de tipo string     |Aritmetica|
| atof     |  Convierte una cadena de caracteres en una variable de tipo float.     |Aritmetica|
| atoi     |  Conveirte una cadena de caracteres en una variable de tipo int     |Aritmetica|
| Igualdad | Esta se define por el símbolo == |Relacional|
| Diferenciación | Esta se define por el símbolo != |Relacional|
| Mayor que | Esta se define por el símbolo > |Relacional|
| Menor que | Esta se define por el símbolo < |Relacional|
| Mayor o igual que | Esta se define por el símbolo >= |Relacional|
| Menor o igual que | Esta se define por el símbolo <= |Relacional|
| AND | Esta se define por el símbolo && |Lógica|
| OR | Esta se define por el símbolo |Lógica|
| NOT | Esta se define por el símbolo ! |Lógica|

- Instrucciones: Mini OL🅒 contará con varias instrucciones para su ejecución, cada instrucción deber terminar con un punto y coma (;) siempre. Las instrucciones que Mini OL🅒 acepta son:
1. Impresion: Mini OL🅒 cuenta con 2 distintas formas de imprimir.
![](https://live.staticflickr.com/65535/52825637055_709c50ee95_c.jpg)


- Declaraciones y Asignaciones: Mini OL🅒 permite la declaración y asignación de variables, las NO variables pueden cambiar su tipo de dato en cualquier momento.
1. Declaracion:

![](https://live.staticflickr.com/65535/52825423069_936ccc63a7_c.jpg)

2. Asignación:

![](https://live.staticflickr.com/65535/52825249951_d8d831aed3_c.jpg)



- Llamada a funciones: Una llamada a función es como un desvío en el flujo de la ejecución. En lugar de pasar a la siguiente sentencia, el flujo salta al cuerpo de la función, ejecuta esta y regresa para continuar después de la llamada a la función:

![](https://live.staticflickr.com/65535/52825435414_74e6ffa5ce_c.jpg)

- Distintas Funciones Nativas: Mini OL🅒 utiliza diversas funciones nativas para sus expresiones, estas son:

![](https://live.staticflickr.com/65535/52825450179_85a5a965cc_c.jpg)

- Distintas Funciones Embebidas: Mini OL🅒 utiliza diversas funciones embebidas para sus expresiones, estas son:

![](https://live.staticflickr.com/65535/52825461724_16666b660c_c.jpg)

- Funciones:  Las funciones son secuencias de sentencias que ejecuta una operación que nosotros deseamos. Cuando se crea una función se especifica su nombre y secuencia de sentencias. Luego, ya se puede llamar a estas usando su nombre y los parámetros solicitados. Se definen las funciones en Mini OL🅒 así:

![](https://live.staticflickr.com/65535/52825698250_df3bc1a33d_c.jpg)

- Condicionales: Mini OL🅒 cuenta con sentencias condicionales, lo que permite que un bloque de codigo pueda ser o no ejecutado. Estas se definen por if,if...else y if...else if. Su estructura es la siguiente:

![](https://live.staticflickr.com/65535/52825486279_3c465b8a6a_c.jpg)

- Loops: Mini OL🅒 cuenta con sentencias iterativas, lo que permite ejecutar repetidamente un bloque de sentencias. Existen 2 de estas, el ciclo while, el ciclo do while y el ciclo for.

1. While: 

![](https://live.staticflickr.com/65535/52825719570_09ac94056a_c.jpg)

2. For:

![](https://live.staticflickr.com/65535/52825507114_80ae49bddb_c.jpg)


- STructs : Como se menciono en secciones anteriores, Mini OL🅒 cuenta con tipos compuestos que los desarrolladores podrán definir mediante una sintaxis. Para la declaración de estos se utiliza la siguiente sintaxis:

![](https://live.staticflickr.com/65535/52825749290_ff92b69f1f_c.jpg)

 
