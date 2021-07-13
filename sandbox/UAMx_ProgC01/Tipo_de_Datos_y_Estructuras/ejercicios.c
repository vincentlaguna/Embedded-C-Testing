/*************** Ejercicio 1.3 ***************
// Piensa en una serie que hayas visto...
// ¿Cuántas temporadas tiene? 3
// ¿Cuántos capítulos de media cada temporada? 10
// ¿Cuántos minutos duran aproximadamente los capítulos? 22
// ¿Y su intro? 0.5
// ¡En total has invertido unas 10.75 horas en ver la serie!

#include <stdio.h>

int main(void)
{
  int   temporadas;
  int   capitulos;
  int   duracion;
  float intro;
  float total;

  printf("\nPiensa en una serie que hayas visto...\n\n");
  printf("¿Cuántas temporadas tiene?\n");
  printf("Entre numero: ");
  scanf("%d", &temporadas);
  printf("¿Cuántos capítulos de media cada temporada?\n");
  printf("Entre numero: ");
  scanf("%d", &capitulos);
  printf("¿Cuántos minutos duran aproximadamente los capítulos?\n");
  printf("Entre numero: ");
  scanf("%d", &duracion);
  printf("¿Y su intro?\n");
  printf("Entre numero: ");
  scanf("%f", &intro);
  
  printf("t = %d, c = %d, d = %d, i = %f\n", temporadas, capitulos, duracion, intro); // Debug
  
  total = ((duracion - intro) * capitulos * temporadas) / 60;
  
  printf("\n¡En total has invertido unas %.2f horas en ver la serie!\n", total);
  
  return(0);
}

/*********************************************/

/*********************************************

#include <stdio.h>

int main(void) 
{
  double euros;
  double dolares;
   
  printf("Introduzca cantidad en dólares: ");
  scanf("%o", &dolares);
   
  euros = dolares * 0.859;
  // printf("%.2lf dólares son %.2lf euros.\n", euros, dolares);
  printf("%o dólares son %o euros.\n", euros, dolares);
   
  return 0;
}

/*********************************************/


/*************** Ejercicio 1.4 ***************
// Ahora escribe un programa que pida al usuario el número de horas que ha pasado jugando en sus 
// últimos cinco videojuegos y cuánto le costaron para saber por cuánto le sale de media la hora jugada.
// Como puedes suponer, la fórmula para calcular dicho tiempo sería:
// total = (precio1/tiempo1 + precio2/tiempo2 + precio3/tiempo3 + precio4/tiempo4 + precio5/tiempo5) / 5
// Ten en cuenta que tienes que utilizar para leer y escribir las funciones que hemos visto hasta ahora: 
// printf() y scanf().
// Este sería un ejemplo de salida del programa pensando en BioShock Infinite, Life is Strange, Mass Effect 2, Portal 2 y The Witcher 3:

// Piensa en los últimos cinco juegos que has jugado.
// ¿Cuántas horas le has echado al primero de ellos? 21
// ¿Y cuánto te costó? 7.49
// ¿Cuántas horas le has echado al segundo? 15
// ¿Y cuánto te costó? 8.49
// ¿Cuántas horas le has echado al tercero? 28
// ¿Y cuánto te costó? 4.99
// ¿Cuántas horas le has echado al cuarto? 11
// ¿Y cuánto te costó? 1.67
// ¿Cuántas horas le has echado al quinto? 42
// ¿Y cuánto te costó? 14.99
// ¡Los últimos 5 juegos te han salido a 0.321921 euros la hora!

#include <stdio.h>

int main(void)
{
  int    tiempo1, tiempo2, tiempo3, tiempo4, tiempo5 = 0;
  double precio1, precio2, precio3, precio4, precio5 = 0;
  float  total = 0;
  
  printf("\nPiensa en los últimos cinco juegos que has jugado....\n\n");
  printf("¿Cuántas horas le has echado al primero de ellos?\n");
  printf("Entre numero: ");
  scanf("%d", &tiempo1);
  printf("¿Y cuánto te costó?\n");
  printf("Entre numero: ");
  scanf("%lf", &precio1);
  printf("¿Cuántas horas le has echado al segundo?\n");
  printf("Entre numero: ");
  scanf("%d", &tiempo2);
  printf("¿Y cuánto te costó?\n");
  printf("Entre numero: ");
  scanf("%lf", &precio2);
  printf("¿Cuántas horas le has echado al tercero?\n");
  printf("Entre numero: ");
  scanf("%d", &tiempo3);
  printf("¿Y cuánto te costó?\n");
  printf("Entre numero: ");
  scanf("%lf", &precio3);
  printf("¿Cuántas horas le has echado al cuarto?\n");
  printf("Entre numero: ");
  scanf("%d", &tiempo4);
  printf("¿Y cuánto te costó?\n");
  printf("Entre numero: ");
  scanf("%lf", &precio4);
  printf("¿Cuántas horas le has echado al quinto?\n");
  printf("Entre numero: ");
  scanf("%d", &tiempo5);
  printf("¿Y cuánto te costó?\n");
  printf("Entre numero: ");
  scanf("%lf", &precio5);
  
  total = (((precio1/tiempo1) + (precio2/tiempo2) + (precio3/tiempo3) + (precio4/tiempo4) + (precio5/tiempo5)) / 5);
  
  printf("\n¡Los últimos 5 juegos te han salido a %lf euros la hora!\n\n", total);
  
  return(0);
}

/*********************************************/ 


/*********************************************

#include <stdio.h>

int main(void) {
    int x=1, y=2;
    double x=3.5;
    char c='d';
   
    printf("%d %d\n", x, y);
    printf("%lf\n", x);
    printf("%c\n", c);
   
    return 0;
}

/*********************************************/ 


/*************** Ejercicio 2.1 ***************
// Escribe un programa que muestre por pantalla los siguientes datos de usuario en el mismo orden:
// Sexo: M
// CP: 2764
// HP: 159
// Peso: 183.0
// Altura: 2.32
// Caramelos: 266
// Para ello, declara las variables del tipo que consideres (int, double, etc.). 
// Ten en cuenta que debes inicializar las variables en su declaración, 
// no solicitar los valores al usuario.

#include <stdio.h>

int main(void) {
    char    Sexo      = 'M';
    int     CP        = 2764;
    int     HP        = 159;
    double  Peso      = 183.0;
    float   Altura    = 2.32;
    int     Caramelos = 266;
   
    printf("Sexo: %c, CP: %d, HP: %d, Peso: %.1lf, Altura: %.2lf, Caramelos: %d\n", 
            Sexo, CP, HP, Peso, Altura, Caramelos);
   
    return 0;
}

/*********************************************/  


/*************** Ejercicio 2.2 ***************
// Modifica ahora el programa anterior para que no inicialice el valor de las variables al declararlas, 
// sino que se soliciten al usuario de una en una y después las muestre por pantalla.
// Recuerda, hemos definido los siguientes atributos: sexo (M/F), CP, HP, peso, altura y caramelos.

#include <stdio.h>

int main(void) 
{
  int     CP, HP, Caramelos;
  char    Sexo;
  double  Altura;
  double  Peso;
    
  printf("Entre El Sexo: ");
  scanf("%c", &Sexo);
  printf("Entre CP: ");
  scanf("%d", &CP);
  printf("Entre HP: ");
  scanf("%d", &HP);
  printf("Entre El Peso: ");
  scanf("%lf", &Peso);
  printf("Entre La Altura: ");
  scanf("%lf", &Altura);
  printf("Entre Numero de Caramelos: ");
  scanf("%d", &Caramelos);
    
  printf("Sexo: %c, CP: %d, HP: %d, Peso: %.1lf, Altura: %.2lf, Caramelos: %d\n", 
            Sexo, CP, HP, Peso, Altura, Caramelos);
   
  return 0;
}

/*********************************************/ 


/*************** Ejercicio 2.3 ***************
// Vamos a cambiar el programa anterior para que muestre por pantalla el tamaño'
// de cada variable con el operador sizeof() en vez de su valor. 
// Con los datos del ejemplo que hemos ido utilizando, la salida del programa sería:
// Tamaño variable sexo: ...
// Tamaño variable CP: ...
// Tamaño variable HP: ...
// Tamaño variable peso: ...
// Tamaño variable altura: ...
// Tamaño variable caramelos: ...

#include <stdio.h>

int main(void) 
{
  int     CP, HP, Caramelos;
  char    Sexo;
  double  Altura;
  double  Peso;
    
  printf("Entre El Sexo: ");
  scanf("%c", &Sexo);
  printf("Entre CP: ");
  scanf("%d", &CP);
  printf("Entre HP: ");
  scanf("%d", &HP);
  printf("Entre El Peso: ");
  scanf("%lf", &Peso);
  printf("Entre La Altura: ");
  scanf("%lf", &Altura);
  printf("Entre Numero de Caramelos: ");
  scanf("%d", &Caramelos);
    
  printf("Tamaño de:\nSexo: %d, CP: %d, HP: %d, Peso: %d, Altura: %d, Caramelos: %d\n", 
            sizeof(char), sizeof(int), sizeof(int), sizeof(double), sizeof(double), sizeof(int));
   
  return 0;
}

/*********************************************/  

/*************** Ejercicio 2.4 ***************
// Vamos a escribir un programa que nos permita cifrar cinco letras mediante el cifrado César. 
// Este algoritmo de cifrado consiste en sustituir la letra original por la que corresponde 
// 3 posiciones después en el alfabeto; es decir, la letra 'a' se sustituye por la letra 'd'.
// De esta forma, si el programa codifica 'm', 'a', 'n', 'o', 's' tendrá esta salida:
// La palabra original es: manos
// La palabra cifrada es: pdqrv

#include <stdio.h>
#include <wchar.h>
#include <locale.h>

int main(void) 
{
  setlocale(LC_ALL, "es_SP");
  
  unsigned char uno     = 67+1;
  unsigned char dos     = 130+1;
  unsigned char tres    = 115+1;
  unsigned char cuatro  = 97+1;
  unsigned char cinco   = 114+1;
   
  printf("\n '%c' '%c' '%c' '%c' '%c' \n", uno, dos, tres, cuatro, cinco);
   
  return 0;
}

/*********************************************

#include <stdio.h>

int main() 
{
  char c1, c2;
  printf("Introduce una letra: ");
  scanf("%c", &c1);
  printf("Introduce otra letra: ");
  // scanf("%c", &c2); // El programa lee la segunda entrada como "\n"...
  scanf("\n%c", &c2); // Solucion
  printf("Has introducido las letras %c y %c\n", c1, c2);
  printf("Has introducido las letras con número %d y %d\n", c1, c2);
  
  return 0;
}

/*********************************************/


/*************** Ejercicio 2.5 ***************
// Ahora vamos a modificar el programa anterior para que nos permita cifrar 
// las cinco letras que introduzca el usuario, de una en una.
// Este sería un ejemplo de entrada y salida del programa:
// Introduce un carácter: H
// Introduce un segundo carácter: o
// Introduce un tercer carácter: m
// Introduce otro carácter: e
// Introduce el último carácter: r
// La palabra original es: Homer
// La palabra cifrada es: Krphu

#include <stdio.h>
#include <wchar.h>
#include <locale.h>

int main(void) 
{
  setlocale(LC_ALL, "es_SP");
  
  unsigned char c1, c2, c3, c4, c5 = 0;
  
  printf("\nIntroduce un carácter: ");
  scanf("%c", &c1);
  printf("Introduce un segundo carácter: ");
  scanf("\n%c", &c2);
  printf("Introduce un tercer carácter: ");
  scanf("\n%c", &c3);
  printf("Introduce un otro carácter: ");
  scanf("\n%c", &c4);
  printf("Introduce el último carácter: ");
  scanf("\n%c", &c5);
  
  printf("\nLa palabra original es: %c%c%c%c%c\n", c1, c2, c3, c4, c5);
  printf("La palabra cifrada es: %c%c%c%c%c\n\n", c1 - 2, c2 - 2, c3 - 2, c4 - 2, c5 - 2); 
  
  return 0;
}

/*********************************************/


/*************** Ejercicio 2.6 ***************
// Y por último, vamos a modificar el programa anterior para que nos permita 
// descifrar cinco letras que introduzca el usuario, de una en una.
// Este sería un ejemplo de entrada y salida del programa, utilizando 
// la palabra cifrada que hemos obtenido en el programa anterior:
// Introduce un carácter: K
// Introduce un segundo carácter: r
// Introduce un tercer carácter: p
// Introduce otro carácter: h
// Introduce el último carácter: u
// La palabra cifrada es: Krphu
// La palabra original es: Homer

#include <stdio.h>
#include <wchar.h>
#include <locale.h>

int main(void) 
{
  setlocale(LC_ALL, "es_SP");
  
  unsigned char c1, c2, c3, c4, c5 = 0;
  
  printf("\nIntroduce un carácter: ");
  scanf("%c", &c1);
  printf("Introduce un segundo carácter: ");
  scanf("\n%c", &c2);
  printf("Introduce un tercer carácter: ");
  scanf("\n%c", &c3);
  printf("Introduce un otro carácter: ");
  scanf("\n%c", &c4);
  printf("Introduce el último carácter: ");
  scanf("\n%c", &c5);
  
  printf("\nLa palabra cifrada es: %c%c%c%c%c\n", c1, c2, c3, c4, c5);
  printf("La palabra original es: %c%c%c%c%c\n\n", c1 - 3, c2 - 3, c3 - 3, c4 - 3, c5 - 3); 
  
  return 0;
}

/*********************************************/  


/*********************************************  
// Conversion de tipos

#include <stdio.h>

int main() {
  char c = 'c';
  short s = c;
  int i = s;
  long l = i;
  float f = l;
  double d = f;
  printf("char: %c; short: %hd; int: %d; long: %ld; float: %f; double: %lf\n", 
          c, s, i, l, f, d);   
   
  d = 123.45678987654321e+23;
  f = (float) d;
  l = (long) f;
  i = (int) l;
  s = (short) i;
  c = (char) s;
  printf("double: %lf; float: %f; long: %ld; int: %d; short: %hd; char: %c\n", 
          d, f, l, i, s, c);
  
  double x;
  x = 5.0 / 2; // = correct value assigned (2 gets promoted to double)
  // x = 5 / 2; // Incorrect value gets assigned as a double (5 nor 2 get promoted)
  printf("%lf\n", x);          
    

    return 0;
}

/*********************************************/  


/**************** Prueba 2.1 ****************
// Escribe un programa que solicite una altura en cm, 
// una edad en años y la inicial de un nombre. 
// El programa debe calcular el peso ideal de acuerdo con la fórmula de Perroult:

// peso = altura - 100 + (9*edad)/100.0

// La altura puede ser un número con decimales. La edad será un número entero. 
// Utiliza tres decimales para mostrar el peso y uno para mostrar la altura.
// Los mensajes se han de mostrar tal y como aparecen en el siguiente ejemplo 
// de ejecución y en el mismo orden (variando solo según los datos introducidos por el usuario).
// Lo que sigue es un ejemplo de ejecución del programa:

// Por favor, introduce la altura en cm: 175.5
// A continuación, introduce la edad en años: 18
// Por último, introduce la inicial del nombre: C
// El peso ideal de C, que mide 175.5 cm y tiene 18 años es de 77.120 kg.

#include <stdio.h>

int main(void) 
{
  int     edad;
  char    nombre;
  double  altura;
  double  peso;
    
  printf("\nPor favor, introduce la altura en cm: ");
  scanf("%lf", &altura);
  printf("A continuación, introduce la edad en años: ");
  scanf("%d", &edad);
  printf("Por último, introduce la inicial del nombre: ");
  scanf("\n%c", &nombre); // sin el "\n" prefijado; se salta la entrada de caracter
  
  peso = altura - 100 + (9 * edad) / 100.0;
    
  printf("\nEl peso ideal de %c, que mide %.2lf cm y tiene %d años es de %.3lf kg.\n\n",
          nombre, altura, edad, peso);
   
  return 0;
}

/********************************************/  



/**************** Prueba 2.2 ****************
// Escribe un programa que solicite uno a uno dos caracteres.
// El programa debe sumar el código ASCII de ambos caracteres y mostrar 
// el resultado, incluyendo el código ASCII de cada uno de ellos.
// Los mensajes se han de mostrar tal y como aparecen 
// en el siguiente ejemplo de ejecución y en el mismo orden 
// (variando solo según los datos introducidos por el usuario).
// Lo que sigue es un ejemplo de ejecución del programa:

// Por favor, introduce un carácter: A
// Por favor, introduce otro carácter: L
// Si sumamos el código ASCII del carácter A que es 65 
// con el código ASCII del carácter L que es 76 obtenemos el número 141

#include <stdio.h>

int main(void) 
{
  char caracter1, caracter2;
    
  printf("\nPor favor, introduce un carácter: ");
  scanf("\n%c", &caracter1);
  printf("Por favor, introduce otro carácter: ");
  scanf("\n%c", &caracter2);
  
  printf("\nSi sumamos el código ASCII del carácter %c que es %d con el código "
         "ASCII del carácter %c que es %d obtenemos el número %d\n\n",
          caracter1, caracter1, caracter2, caracter2, caracter1 + caracter2);
   
  return 0;
}

/********************************************/  


/********************************************
// Tablas y Cadenas - Macros y Constantes - #define

#include <stdio.h>

#define PIES_POR_CM 0.03

int main(void) 
{
  int ancho, largo;
  double ancho_p, largo_p;

  printf ("Introduce el ancho: ");
  scanf ("%d", &ancho);
  ancho_p = ancho * PIES_POR_CM;
   
  printf ("Introduce el largo: ");
  scanf ("%d", &largo);
  largo_p = largo * PIES_POR_CM;

  printf ("%d x %d cm son %.2lf x %.2lf pies.\n",
           ancho, largo, ancho_p, largo_p);

  return 0;
}

/*********************************************/  


/*************** Ejercicio 3.1 ***************
// Seguro que alguna vez te has preguntado cuán ligero serías en otros planetas.
// Gracias a la relación de peso de la Tierra con otros planetas que encontrarás 
// en muchas páginas web, como esta sobre el peso (Wikipedia), 
// ¡podemos calcularlo fácilmente!

// Nosotros te dejamos aquí algunos pesos relativos para diferentes cuerpos 
// celestes, utiliza varios de ellos para hacer un programa que muestre 
// el peso que introduzca el usuario en cada uno de ellos:

// Tu peso en la Tierra es 71.50
// Tu peso en la luna es 11.83
// Tu peso en Marte es 27.85
// Tu peso en Júpiter es 188.76
// Tu peso en el planeta Miller es 92.95
// Tu peso en Pandora es 57.20
// Tu peso en Vulcano es 100.10

// Esto sería un ejemplo de dicho programa:

// Introduce tu peso: 71.5

// Luna: 0.1655
// Marte: 0.3895 (pues Mark Watney debería haber ido un poquito más ligero en la película...)
// Júpiter: 2.640
// (Cuidado con las olas) Miller: 1.3
// Pandora: 0.8
// Vulcano: 1.4

#include <stdio.h>

#define  LUNA     0.1655
#define  MARTE    0.3895
#define  MILLER   1.3
#define  PANDORA  0.8
#define  JUPITER  2.640
#define  VULCANO  1.4


int main(void) 
{
  double peso;
  
  printf("\nIntroduce tu peso: ");
  scanf("%lf", &peso);
  printf("\nTu peso en la Tierra es %.2lf\n", peso);
  printf("Tu peso en la Luna es %.2lf\n", peso * LUNA);
  printf("Tu peso en Marte es %.2lf\n", peso * MARTE);
  printf("Tu peso en Júpiter es %.2lf\n", peso * JUPITER);
  printf("Tu peso en el planeta Miller es %.2lf\n", peso * MILLER);
  printf("Tu peso en Pandora es %.2lf\n", peso * PANDORA);
  printf("Tu peso en Vulcano es %.2lf\n\n", peso * VULCANO);

  return 0;
}

/*********************************************/  


/*********************************************  
// Tablas y Cadenas - Macros y Constantes - const

#include <stdio.h>

int main(void) 
{
  int ancho, largo;
  double ancho_p, largo_p;
  const double pies_por_cm = 0.0328;
   
  printf ("Introduce el ancho: ");
  scanf ("%d", &ancho);
  ancho_p = ancho * pies_por_cm;
  
  // pies_por_cm = 0.0327; // No compila porque pies_por_cm es "read-only"
  
  printf ("Introduce el largo: ");
  scanf ("%d", &largo);
  largo_p = largo * pies_por_cm;
  
  // printf ("Introduce pies for cm: "); // Si compila, pero el resultado puede ser
  // // impredicible y se debe evitar
  // scanf ("%d", &pies_por_cm);

  printf ("%d x %d cm son %.2lf x %.2lf pies.\n", ancho, largo, ancho_p, largo_p);

  return 0;
}

/*********************************************/


/*********************************************  
// Tablas y Cadenas - Macros y Constantes - const

#include <stdio.h>

int main(void) 
{
  int ancho, largo;
  double ancho_p, largo_p;
  const double pies_por_cm = 0.0328;
   
  printf ("Introduce el ancho: ");
  scanf ("%d", &ancho);
  ancho_p = ancho * pies_por_cm;
  
  // pies_por_cm = 0.0327; // No compila porque pies_por_cm es "read-only"
  
  printf ("Introduce el largo: ");
  scanf ("%d", &largo);
  largo_p = largo * pies_por_cm;
  
  // printf ("Introduce pies for cm: "); // Si compila, pero el resultado puede ser
  // // impredicible y se debe evitar
  // scanf ("%d", &pies_por_cm);

  printf ("%d x %d cm son %.2lf x %.2lf pies.\n", ancho, largo, ancho_p, largo_p);

  return 0;
}

/*********************************************/


/*********************************************
// Tablas y Cadenas - Macros y Constantes - Macros con Parametros
#include <stdio.h>

#define MULT(A, B) (A)*(B)

int main(void)
{
  printf("MULT(5,5): %d\n", MULT(5,5));
  printf("MULT(2+3,3+2): %d\n", MULT(2+3,3+2));
  printf("3 % 5 = %d\n", 3 % 5);
  
  return 0;
}

/*********************************************/


/**************** Prueba 3.1 ****************
// Escribe un programa en C que declare:

// Una tabla de seis enteros (utiliza una macro para el tamaño).
// Un entero para almacenar el resto de una división.
// Dos variables de tipo float a double para calcular unos valores medios.
// A continuación solicitará seis números enteros y los almacenará 
// en cada una de las posiciones de la tabla.

// Seguidamente calculará la media de las posiciones pares de la tabla 
// (incluida la posición cero) y la guardará en una variable.

// A continuación calculará la media de las posiciones impares 
// de la tabla y la guardará en otra variable.

// Por último, calculará el resto de la división de las 
// primeras y última posiciones de la tabla.

// Antes de terminar mostrará por pantalla tres mensajes 
// con toda la información calculada.

// Los mensajes se han de mostrar tal y como aparecen en 
// el siguiente ejemplo de ejecución y en el mismo orden 
// (variando solo según los datos introducidos por el usuario).

// Lo que sigue es un ejemplo de ejecución del programa:

// Introduce el primer número entero: 3
// Introduce el segundo número entero: 312
// Introduce el tercer número entero: -45
// Introduce el cuarto número entero: 129
// Introduce el quinto número entero: 81
// Introduce el sexto número entero: 17
// La media de los números 3, -45 y 81 es 13.000000
// La media de los números 312, 129 y 17 es 152.666667
// El resto de la divisón de 17 y 3 es 2

#include <stdio.h>

int main(void) 
{
  char caracter1, caracter2;
    
  printf("\nPor favor, introduce un carácter: ");
  scanf("\n%c", &caracter1);
  printf("Por favor, introduce otro carácter: ");
  scanf("\n%c", &caracter2);
  
  printf("\nSi sumamos el código ASCII del carácter %c que es %d con el código "
         "ASCII del carácter %c que es %d obtenemos el número %d\n\n",
          caracter1, caracter1, caracter2, caracter2, caracter1 + caracter2);
   
  return 0;
}

/********************************************/


/*********************************************
// Introduccion a las Tablas 0

#include <stdio.h>

#define DIM 3

int main(void) 
{
  int datos_a[DIM] = {8,7.5,9};   // 3 elementos
  int datos_b[] = {8,7,9,};      // 3 elementos
  int datos_c[DIM+2] = {8,7,9}; // 5 elementos
  int datos_d[DIM+22] = {0};    // 25 elementos
  
  for(int i = 0; i < sizeof(datos_b)/datos_b[0]; i++)
    printf("%d, %lf\n", datos_b[i], datos_b[i]);
    
  return 0;
}

/*********************************************/  


/*********************************************
// Introduccion a las Tablas 1

#include <stdio.h>

#define DIM 3

int main(void) 
{
  int datos[DIM];

  // datos[0] = 5;
  // printf("Introduce un número: ");
  // scanf("%d", &datos[1]);
  // datos[2] = (datos[0]+datos[1])*2;
  
  // printf("Los elementos de la tabla son %d\n", datos);
  
  printf("Introduce los números de la tabla: ");
  scanf("%d", datos);

  printf("Los elementos de la tabla son %d, %d y %d.\n", datos[0], datos[1], datos[2]);

  
  // for(int i = 0; i < sizeof(datos_b)/datos_b[0]; i++)
    // printf("%d, %lf\n", datos_b[i], datos_b[i]);
  
  return 0;
}

/*********************************************/  


/*************** Ejercicio 3.3 ***************/
// Vamos a escribir un programa que calcule la media de experiencia obtenida
// en las últimas 5 partidas al LoL con 3 de tus campeones más habituales.

// Para ello, declararemos 3 tablas y las inicializaremos con los valores que consideremos. 
// Después, mostraremos por pantalla la media de cada campeón.

// Por ejemplo, esta podría ser una salida de tu programa:

// Media experiencia últimas 5 partidas con Kassadin: 130.20
// Media experiencia últimas 5 partidas con Ahri: 115.40
// Media experiencia últimas 5 partidas con Jax: 98.80

#include <stdio.h>

#define DIM 5

int main(void) 
{
  double cuenta = 0;
  double kassadin[DIM];
  // double ahri[DIM];
  // double jax[DIM];
  double media_de_kassadin;
  // double media_de_ahri;
  // double jax;

  printf("\nIntroduce la experiencia obtenida en las últimas 5 partidas al LoL de Kassadin: ");
  scanf("%lf %lf %lf %lf %lf", &kassadin[0], &kassadin[1], &kassadin[2], &kassadin[3], &kassadin[4]);
  
  for(int i = 0; i < sizeof(kassadin)/kassadin[0]; i++)
  {
    cuenta += kassadin[i];
    printf("%lf\n");
  }
  media_de_kassadin = cuenta / 5; 
  
  // printf("Los elementos de la tabla son %d, %d y %d.\n", datos[0], datos[1], datos[2]);
  printf("\nMedia experiencia últimas 5 partidas con Kassadin: %lf\n", media_de_kassadin);
  
  
  return 0;
}

/*********************************************/  


/*********************************************/  



/*********************************************/

/*************** Ejercicio 3.3 ***************/

/*********************************************/  

/*************** Ejercicio 3.4 ***************/

/*********************************************/

/*********************************************/  

/*********************************************/

/*********************************************/

/*********************************************/


