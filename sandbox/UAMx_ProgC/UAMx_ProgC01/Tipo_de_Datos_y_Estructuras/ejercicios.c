/*********************************************

#include  <stdio.h>

int main(void)
{
  printf("\033[31m!Hola, \033[34mmundo!\n");
  return(0);
}

/*********************************************/

/*********************************************

#include  <stdio.h>

int main(void)
{
  
  printf("\n");
  printf("\033[33m// ºº--.._\n");
  printf("||  \033[31m(_)\033[33m  _ º-._\n");
  printf("||    _ \033[31m(_)\033[33m    º-..\n");
  printf("||   \033[31m(_)\033[33m   __..-º\n");
  printf("\\\\__..--ºº\n");
  printf("\n");
  
  printf("\n");
  printf("\033[33m// ºº--.._\n||  \033[31m(_)\033[33m  _ º-._\n||    _ \033[31m(_)\033[33m    º-..\n||   \033[31m(_)\033[33m   __..-º\n\\\\__..--ºº\n");
  printf("\n");
  
  return(0);
}

/*********************************************/


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


/*************** Ejercicio 3.3 ***************
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
  double kassadin[DIM];
  double cuenta_de_kassadin;
  double media_de_kassadin;
  
  double ahri[DIM];
  double cuenta_de_ahri;
  double media_de_ahri;
  
  double jax[DIM];
  double cuenta_de_jax;
  double media_de_jax;

  printf("\nIntroduce la experiencia obtenida en las últimas 5 partidas al LoL de Kassadin: ");
  scanf("\n%lf %lf %lf %lf %lf", &kassadin[0], &kassadin[1], &kassadin[2], &kassadin[3], &kassadin[4]);
  
  for(int i = 0; i < DIM; i++)
  {
    cuenta_de_kassadin += kassadin[i];
  }
  media_de_kassadin = cuenta_de_kassadin / 5;
  
  printf("\nIntroduce la experiencia obtenida en las últimas 5 partidas al LoL de Ahri: ");
  scanf("\n%lf %lf %lf %lf %lf", &ahri[0], &ahri[1], &ahri[2], &ahri[3], &ahri[4]);
  
  for(int i = 0; i < DIM; i++)
  {
    cuenta_de_ahri += ahri[i];
  }
  media_de_ahri = cuenta_de_ahri / 5; 
  
  printf("\nIntroduce la experiencia obtenida en las últimas 5 partidas al LoL de Jax: ");
  scanf("\n%lf %lf %lf %lf %lf", &jax[0], &jax[1], &jax[2], &jax[3], &jax[4]);
  
  for(int i = 0; i < DIM; i++)
  {
    cuenta_de_jax += jax[i];
  }
  media_de_jax = cuenta_de_jax / 5; 
  
  printf("\nMedia experiencia últimas 5 partidas con Kassadin: %.2lf\n", media_de_kassadin);
  printf("\nMedia experiencia últimas 5 partidas con Ahri: %.2lf\n", media_de_ahri);
  printf("\nMedia experiencia últimas 5 partidas con Jax: %.2lf\n\n", media_de_jax);
  
  return 0;
}

/*********************************************
// Introduccion a las Tablas Bidimensionales

#include <stdio.h>

#define DIM 2

int main (void) 
{
  int num[DIM][DIM] = {{1, 3}, {5, 3}};
  int deter = 0;
   
  deter = num[0][0] * num[1][1] - num[1][0] * num[0][1];

  printf ("\nEl determinante es: %d \n\n", deter);

  return 0;
}

/*********************************************/  



/*************** Ejercicio 3.4 ***************
// Vamos a modificar el programa anterior, que calcula la media
// de experiencia obtenida en las últimas 5 partidas al 
// LoL con 3 de tus campeones más habituales.

// Ahora, en vez de declarar 3 tablas, vamos a declarar una matriz 
// (tabla bidimensional), donde cada fila corresponderá a un campeón. 
// Al igual que ocurría en el programa anterior, será necesario 
// inicializar la matriz con los valores que consideremos y 
// después mostrar por pantalla la media de cada campeón.

// La salida del programa debería ser la misma que la del programa 
// anterior si utilizas los mismos datos de inicialización. 
// En nuestro ejemplo, guardaremos en la primera fila los datos de 
// nuestro campeón Kassadin, después los de Ahri y por último los de Jax:

// Media experiencia últimas 5 partidas con Kassadin: 130.20
// Media experiencia últimas 5 partidas con Ahri: 115.40
// Media experiencia últimas 5 partidas con Jax: 98.80

#include  <stdio.h>

#define   JUGADORES  3
#define   JUGADAS    6

enum      { kassadin, ahri, jax };
enum      { partida1, partida2, partida3,
            partida4, partida5, media };
          

int main(void) 
{
  double matriz[JUGADORES][JUGADAS];
  double cuenta_de_kassadin;
  double cuenta_de_ahri;
  double cuenta_de_jax;

  printf("\nIntroduce la experiencia obtenida en las últimas 5 partidas al LoL de Kassadin: ");
  scanf("\n%lf %lf %lf %lf %lf", &matriz[kassadin][partida1], &matriz[kassadin][partida2],
         &matriz[kassadin][partida3], &matriz[kassadin][partida4], &matriz[kassadin][partida5]);
  
  for(int i = 0; i < JUGADAS - 1; i++)
  {
    cuenta_de_kassadin += matriz[kassadin][i];
  }
  matriz[kassadin][media] = cuenta_de_kassadin / 5;
  
  printf("\nIntroduce la experiencia obtenida en las últimas 5 partidas al LoL de Ahri: ");
  scanf("\n%lf %lf %lf %lf %lf", &matriz[ahri][partida1], &matriz[ahri][partida2],
         &matriz[ahri][partida3], &matriz[ahri][partida4], &matriz[ahri][partida5]);
  
  for(int i = 0; i < JUGADAS - 1; i++)
  {
    cuenta_de_ahri += matriz[ahri][i];
  }
  matriz[ahri][media] = cuenta_de_ahri / 5;
  
  printf("\nIntroduce la experiencia obtenida en las últimas 5 partidas al LoL de Jax: ");
  scanf("\n%lf %lf %lf %lf %lf", &matriz[jax][partida1], &matriz[jax][partida2],
         &matriz[jax][partida3], &matriz[jax][partida4], &matriz[jax][partida5]);
  
  for(int i = 0; i < JUGADAS - 1; i++)
  {
    cuenta_de_jax += matriz[jax][i];
  }
  matriz[jax][media] = cuenta_de_ahri / 5;
  
  printf("\nMedia experiencia últimas 5 partidas con Kassadin: %.2lf\n", matriz[kassadin][media]);
  printf("\nMedia experiencia últimas 5 partidas con Ahri: %.2lf\n", matriz[ahri][media]);
  printf("\nMedia experiencia últimas 5 partidas con Jax: %.2lf\n\n", matriz[jax][media]);
  
  return 0;
}

/*********************************************


/*************** Ejercicio 3.5 ***************
// Vamos a descansar un poco del LoL. Ahora toca escribir un programa 
// que permita a un usuario jugar a hundir la flota de forma muuuy simple.
// Partimos de una tabla bidimensional de 3 filas y 2 columnas a la que 
// inicializamos con dos 'O' en donde consideremos,
// y todo lo demás con 'X'. Por ejemplo:

// |_X_|_O_|
// |_O_|_X_|
// |_X_|_X_|

// El jugador tendrá 2 oportunidades para adivinar la posición de los barcos,
// y en cada intento se informará si en la posición seleccionada se ha 
// encontrado una 'O' o una 'X'.
// Un ejemplo de programa sería:

// Introduce una fila: 1
// Introduce una columna: 2
// En la fila 1, columna 2 encontramos: O
// Introduce una fila: 3
// Introduce una columna: 1
// En la fila 3, columna 1 encontramos: X

#include <stdio.h>

#define   FILA 3
#define   COL  2

int main (void) 
{
  char flota[FILA][COL] = 
  {
    {'O', 'X'},
    {'X', 'X'},
    {'X', 'O'},
  };
  
  int  entradaFila1, entradaFila2, entradaCol1, entradaCol2 = 0;
  
  printf("\nIntroduce una fila: ");
  scanf("%d", &entradaFila1);
  if (entradaFila1 > 2) entradaFila1 = 2;
  printf("\nIntroduce una columna: ");
  scanf("%d", &entradaCol1);
  if (entradaCol1 > 1) entradaCol1 = 1;
  
  printf("\nEn la fila %d, columna %d encontramos: %c\n\n",
          entradaFila1+1, entradaCol1+1, flota[entradaFila1][entradaCol1]);
  
  printf("\nIntroduce una fila: ");
  scanf("%d", &entradaFila2);
  if (entradaFila2 > 2) entradaFila2 = 2;
  printf("\nIntroduce una columna: ");
  scanf("%d", &entradaCol2);
  if (entradaCol2 > 1) entradaCol2 = 1;
  
  printf("\nEn la fila %d, columna %d encontramos: %c\n\n",
          entradaFila2+1, entradaCol2+1, flota[entradaFila2][entradaCol2]);

  return 0;
}

/*********************************************
// Analizando strlen()

#include <stdio.h>
#include <string.h>

#define DIM 20

int main(void)
{
  char nombre1[DIM] = "Ana";
  char nombre2[DIM] = "Anacleto";
  char nombre3[DIM] = "Anastasia";
  
  printf("La longitud de nombre1 es %d\n", strlen(nombre1));
  printf("La longitud de nombre2 es %d\n", strlen(nombre2));
  printf("La longitud de nombre3 es %d\n", strlen(nombre3));
  
  return 0;
}

/*********************************************/


/*************** Ejercicio 3.6 ***************
// Escribe un programa que muestre la longitud de una palabra.
// Este sería un ejemplo del mismo, inicializando la variable 
// con la palabra supercalifragilisticoespialidoso:
// La longitud de la cadena es: 32.

#include <stdio.h>
#include <string.h>

int main(void)
{
  char palabra[] = "supercalifragilisticoespialidoso";
  
  printf("\nLa longitud de la palabra \"supercalifragilisticoespialidoso\" es: %d\n\n",
          strlen(palabra));
          
  return(0);
}

/*********************************************/


/*********************************************

#include <stdio.h>
#include <string.h>

int main(void) 
{
  char variable = "A";
  
  printf("\n%d\n\n", strlen(variable));
  
  return 0;
}

/*********************************************/  


/*************** Ejercicio 3.7 ***************

// Vamos a escribir un programa que pida una palabra 
// y después un número inferior al tamaño de dicha palabra.
// El programa introducirá el valor ASCII 0 en la posición 
// indicada por el usuario y mostrará la cadena resultante.
// Nota: Puedes asumir que el usuario siempre va a intrudcir
// un número inferior al tamaño de la palabra.
// Este sería un ejemplo del mismo:

// Escribe una palabra: supercalifragilisticoespialidoso
// La longitud de dicha palabra es: 32.
// Indica un número menor a dicha longitud: 23
// La palabra cortada en la letra 23 es: supercalifragilisticoes.

#include  <stdio.h>
#include  <string.h>
#define   DIM  32

int main(void)
{
  char  numero      = 0;
  char  palabra[32] = "\0";
  
  printf("\nEscribe una palabra: ");
  scanf("%s", palabra);
  printf("\nLa longitud de la palabra es: %d\n\n", strlen(palabra));
  
  printf("Indica un número menor a dicha longitud: ");
  scanf("%d", &numero);
  palabra[numero] = '\0';
  
  printf("\nLa palabra cortada en la letra %d es: %s\n\n", numero, palabra);
  
  
  return(0);
}

/*********************************************/


/*********************************************
// Analizando gets()

#include <stdio.h>

#define TAM 16

int main(void)
{
  char nombre[TAM];

  printf("\nIntroduce tu nombre: ");
  gets(nombre);

  printf("\nHola, %s.\n\n", nombre);

  return 0;
}

/*********************************************/


/*********************************************
// Analizando getchar()

#include <stdio.h>

#define TAM 16

int main(void)
{
  char nombre[TAM], ciudad[TAM];

  printf("\nIntroduce tu nombre: ");
  scanf("%s", nombre);
  getchar();

  printf("Introduce tu ciudad de residencia: ");
  gets(ciudad);

  printf("Hola, %s. Vives en %s.\n\n", nombre, ciudad);
  
  return(0);
}

/*********************************************/


/*********************************************
// Analizando gets()

#include <stdio.h>

#define DIM 128

int main(void)
{
  // int  edad;
  char nombre[DIM];
  char ciudad[DIM];
  // printf("\nIntroduce tu edad: ");
  printf("\nIntroduce tu nombre: ");
  // scanf("%s", &nombre);
  gets(nombre);
  // gets(edad);
  
  printf("Introduce tu ciudad de residencia: ");
  // gets(ciudad);
  scanf("%s", ciudad);

  printf("\nHola, %s. Vives en %s.\n\n", nombre, ciudad);
  // printf("\nHola, tienes %d años.\n\n", edad);
  
  return(0);
}

/*********************************************/


/*********************************************
// Analizando strcmp()

#include <stdio.h>
#include <string.h>

#define DIM 8

int main(void)
{
  char nombre1[DIM] = "Anais";
  char nombre2[DIM] = "Anabel";

  printf("\nAnais vs. Anabel: %d\n", strcmp(nombre1, nombre2));
  printf("Anais vs. Anais: %d\n", strcmp(nombre1, nombre1));
  printf("Anabel vs. Anais: %d\n\n", strcmp(nombre2, nombre1));
  
  return(0);
}

/*********************************************/


/*************** Ejercicio 3.8 ***************
// Escribe un programa que solicite dos cadenas por teclado
// y escriba por pantalla el valor numérico devuelto por strcmp().
// Para poder utilizar esta función debes incluir la biblioteca 
// string.h al principio del programa.
// Lo que sigue es un ejemplo de ejecución del programa:

// Introduce una cadena: Hola caracola
// Introduce otra cadena: Hasta luego cocodrilo
// El valor devuelto por la comparación de las cadenas es: 14

#include <stdio.h>
#include <string.h>

#define DIM 32

int main(void)
{
  char cadena1[DIM];
  char cadena2[DIM];
  signed int  valor;
  
  printf("\nIntroduce una cadena: ");
  gets(cadena1);
  
  printf("Introduce otra cadena: ");
  scanf("%s", cadena2);
  
  valor = strcmp(cadena1, cadena2);

  printf("\nEl valor devuelto por la comparación de las cadenas es: %d\n\n", valor);

  
  return(0);
}

/*********************************************
// Analizando strcpy()
#include <stdio.h>
#include <string.h>

#define DIM 8

int main(void)
{
  int x = 3, y;
  char nombre1[DIM] = Pedro, nombre2[DIM] = "Luis";

  y = x;
  // nombre2 = nombre1;
  strcpy(nombre2, nombre1);

  printf("\nx = %d, y = %d\n", x, y);
  printf("nombre1 = %s, nombre2 = %s\n\n", nombre1, nombre2);

  return(0);
}

/*********************************************/


/*************** Ejercicio 3.8 ***************
// Por último, vamos a escribir un programa más 
// complejo que nos permita jugar con cadenas de caracteres. 
// Para ello, vamos a solicitar al usuario una cadena de 
// caracteres, que vamos a copiar en otra variable, para después 
// comparar ambas variables. Te recomendamos que muestres por 
// pantalla la cadena de caracteres que se ha copiado en la 
// segunda variable, así como el valor numérico de la comparación pues, 
// si todas las operaciones se han realizado correctamente, debería ser 0.
// Este sería un ejemplo del mismo:

// Introduce una cadena de caracteres: La respuesta de la vida, 
// el universo y todo lo demás es... 42
// La cadena de caracteres copiada es: La respuesta de la vida, 
// el universo y todo lo demás es... 42
// El resultado de comparar ambas cadenas es: 0

#include <stdio.h>
#include <string.h>

#define DIM 128

int main(void)
{
  char cadena[DIM];
  char copia[DIM];
  signed int valor;
  
  printf("\nIntroduce una cadena de caracteres: ");
  gets(cadena);
  
  printf("\nLa cadena de caracteres copiada es: %s = %d\n",
          cadena, strlen(cadena));
  
  strcpy(copia, cadena);
  valor = strcmp(cadena, copia);

  printf("\nEl valor devuelto por la comparación de las cadenas es: %d\n\n", valor);

  return(0);
}

/*********************************************/


/**************** Prueba 3.1 ****************
// Escribe un programa en C que declare:
// Una tabla de seis enteros (utiliza una macro para el tamaño).
// Un entero para almacenar el resto de una división.
// Dos variables de tipo float a double para calcular unos valores medios.
// A continuación solicitará seis números enteros y los almacenará en 
// cada una de las posiciones de la tabla.

// Seguidamente calculará la media de las posiciones pares de la tabla 
// (incluida la posición cero) y la guardará en una variable.

// A continuación calculará la media de las posiciones impares 
// de la tabla y la guardará en otra variable.

// Por último, calculará el resto de la división de las primeras 
// y última posiciones de la tabla.

// Antes de terminar mostrará por pantalla tres mensajes 
// con toda la información calculada.

// Los mensajes se han de mostrar tal y como aparecen en el 
// siguiente ejemplo de ejecución y en el mismo orden 
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

#define DIM 6

int main(void)
{
  double      mediaPar;
  double      mediaImpar;
  signed int  cadena[DIM];
  signed int  resto;
  
  printf("\nIntroduce el primer número entero: ");
  scanf("%d", &cadena[0]);
  printf("Introduce el segundo número entero: ");
  scanf("%d", &cadena[1]);
  printf("Introduce el tercer número entero: ");
  scanf("%d", &cadena[2]);
  printf("Introduce el cuarto número entero: ");
  scanf("%d", &cadena[3]);
  printf("Introduce el quinto número entero: ");
  scanf("%d", &cadena[4]);
  printf("Introduce el sexto número entero: ");
  scanf("%d", &cadena[5]);
  
  for (int i = 0; i < DIM; i++)
  {
    if (i % 2 == 0)
    {
      mediaPar += cadena[i];
    }
    else
    {
      mediaImpar += cadena[i];
    }
  }
  
  mediaPar   /= 3;
  mediaImpar /= 3;
  resto      = cadena[5] % cadena[0];
  
  printf("\nLa media de los números %d, %d y %d es %lf\n\n", 
          cadena[0], cadena[2], cadena[4], mediaPar);
          
  printf("La media de los números %d, %d y %d es %lf\n\n", 
          cadena[1], cadena[3], cadena[5], mediaImpar);
          
  printf("El resto de la divisón de %d y %d es %d\n\n", 
          cadena[5], cadena[0], resto);
          
  return(0);
}

/*********************************************/


/**************** Prueba 3.2 ****************
// Escribe un programa en C que solicite una cadena de caracteres
// y muestre por pantalla la cadena original, su tamaño y la 
// cadena con el primer y último carácter intercambiados.

// Para esto tendrá que declarar las variables y realizar las 
// operaciones adecuadas.

// Los mensajes se han de mostrar tal y como aparecen en el 
// siguiente ejemplo de ejecución y en el mismo orden 
// (variando sólo según los datos introducidos por el usuario).

// Lo que sigue es un ejemplo de ejecución del programa:

// Introduce una palabra: universidad
// Si a la palabra universidad, que tiene 11 caracteres, 
// le intercambiamos el primer y último carácter obtenemos 
// la palabra dniversidau

#include <stdio.h>
#include <string.h>

#define DIM 32

int main(void)
{
  int   tam;
  char  primer;
  char  ultimo;
  char  palabra[DIM];
  char  palabraMod[DIM];
  
  printf("\nIntroduce una palabra: ");
  gets(palabra);
  
  strcpy(palabraMod, palabra);
  
  tam        = strlen(palabra);
  primer     = palabraMod[0];
  ultimo     = palabraMod[strlen(palabraMod)-1];
  palabraMod[strlen(palabraMod)-1] = primer;
  palabraMod[0] = ultimo;
  
  printf("Largura: %d\n", strlen(palabraMod));
  printf("Primer carácter: %c\n", primer);
  printf("último carácter: %c\n", ultimo);
  
  printf("\nSi a la palabra %s, que tiene %d caracteres, le intercambiamos "
         "el primer y último carácter, obtenemos la palabra: %s\n\n",
          palabra, tam, palabraMod);
 
  return(0);
}

/*********************************************/


/*********************************************
// Introduccion a las Estructuras

#include  <stdio.h>
#include  <string.h>

#define   MAX_STR   128 

typedef struct
{
  char   autor[MAX_STR]; // = "Mario Vargas Llosa";
  char  titulo[MAX_STR]; // = "El héroe discreto";
  int   year; // = 2013;
} Libro; // = { "Mario Vargas Llosa", "El héroe discreto", 2013 };

int main(void)
{
  
  Libro novela = { "Mario Vargas Llosa", "El héroe discreto", 2013 };
  
  // printf("Introduzca el autor del libro: ");
  // scanf("%s", Libro.autor);
  // printf("Introduzca el título del libro: ");
  // scanf("%s", Libro.titulo);
  // printf("Introduzca el año de publicación: ");
  // scanf("%d", &Libro.anyo);
  
  // printf("\nIntroduzca el año de publicación de %s, de %s: ",
  //         novela.titulo, novela.autor);
  // scanf("%d", &novela.year);
  
  printf("\n%s fue escrito por %s en el %d\n\n",
          novela.titulo, novela.autor, novela.year);
          
  return(0);
}

/*********************************************/


/*************** Ejercicio 4.1 ***************
// Vamos a hacer un programa que solicite al usuario datos
// sobre su última partida al LoL y muestre el ratio 
// KDA por pantalla, que se calcula con la fórmula: 
// (K+A)/D, sea K Kills, A Assists y D Deaths.

// Para ello, será necesario almacenarlos en una estructura, 
// que al menos deberá contener: nombre de usuario, 
// nivel del usuario, experiencia, nombre del campeón, 
// asesinatos, muertes y asistencias.

// Este sería un ejemplo de programa:

// ¿Cuál es tu nombre de invocador? asdfg
// ¿Cuál es tu nivel? 67
// ¿Cuánta experiencia has adquirido ya en dicho nivel? 2651
// ¿Con qué campeón has jugado tu última partida? Soraka
// ¿Cuántos asesinatos has hecho? 1
// ¿Cuántas veces has muerto? 3
// ¿Y cuántas asistencias has hecho? 18
// asdfg, de nivel 67 y experiencia 2651, tu KDA ratio con Soraka ha sido 6.33.

#include  <stdio.h>
#include  <string.h>

#define   MAX_STR   128 

typedef   struct
{
  char    nombre[MAX_STR];
  char    ultCampeon[MAX_STR];
  int     nivel;
  int     experiencia;
  int     asesinatos;
  int     muerto;
  int     assists;
  double  ratioKDA;
} _Datos;

int main(void)
{
  _Datos datos;
  
  printf("\n¿Cuál es tu nombre de invocador?: ");
  scanf("%s", datos.nombre);
  
  printf("¿Cuál es tu nivel?: ");
  scanf("%d", &datos.nivel);
 
  printf("¿Cuánta experiencia has adquirido ya en dicho nivel?: ");
  scanf("%d", &datos.experiencia);
  
  printf("¿Con qué campeón has jugado tu última partida?: ");
  scanf("%s", datos.ultCampeon);
  
  printf("¿Cuántos asesinatos has hecho?: ");
  scanf("%d", &datos.asesinatos);
  
  printf("¿Cuántas veces has muerto?: ");
  scanf("%d", &datos.muerto);
  
  printf("¿Y cuántas asistencias has hecho?: ");
  scanf("%d", &datos.assists);
  
  // KDA Ratio = (K+A) / Max(1,D)

  if (!datos.muerto >= 1)
    datos.muerto = 1;
  
  datos.ratioKDA = (datos.asesinatos + datos.assists) / (double)datos.muerto;
  
  printf("\n%s, de nivel %d y experiencia %d, "
         "tu KDA ratio con %s ha sido %.2lf.\n\n", 
          datos.nombre, datos.nivel, datos.experiencia,
          datos.ultCampeon, datos.ratioKDA);
  
  return(0);
}

/*********************************************/


/*********************************************
// Estructuras con Tablas

#include  <stdio.h>
#include  <string.h>

#define   MAX_STR       128
#define   MAX_EDICIONES 10

typedef struct
{
  char  autor[MAX_STR];
  char  titulo[MAX_STR]; 
  int   fechas_ediciones[MAX_EDICIONES];
} Libro;

int main(void)
{
  
  Libro novela = { "Mario Vargas Llosa", 
                   "El héroe discreto", 
                   {2013, 2014, 2016}
                  };
  
  novela.fechas_ediciones[1] = 2015;
  
  printf("\n\%s fue escrito por %s y publicado en %d, %d y %d.\n\n",
          novela.titulo, novela.autor, novela.fechas_ediciones[0], 
          novela.fechas_ediciones[1], novela.fechas_ediciones[2]);
          
  return(0);
}

/*********************************************/


/*************** Ejercicio 4.2 ***************
// Vamos a cambiar el programa anterior para que almacene los 
// datos de asesinatos, muertes y asistencias en una tabla de enteros.
// La salida debe ser la misma que en el programa anterior:

// ¿Cuál es tu nombre de invocador? asdfg
// ¿Cuál es tu nivel? 67
// ¿Cuánta experiencia has adquirido ya en dicho nivel? 2651
// ¿Con qué campeón has jugado tu última partida? Soraka
// ¿Cuántos asesinatos has hecho? 1
// ¿Cuántas veces has muerto? 3
// ¿Y cuántas asistencias has hecho? 18
// asdfg, de nivel 67 y experiencia 2651, tu KDA ratio con Soraka ha sido 6.33.

#include  <stdio.h>
#include  <string.h>

#define   MAX_STR   128
#define   KDA       3

enum { asesinatos, muertes, assists };

typedef   struct
{
  char    nombre[MAX_STR];
  char    ultCampeon[MAX_STR];
  int     nivel;
  int     experiencia;
  int     kda[KDA]; // Una tabla
  double  ratioKDA;
} _Datos;

int main(void)
{
  _Datos datos;
  
  printf("\n¿Cuál es tu nombre de invocador?: ");
  scanf("%s", datos.nombre);
  
  printf("¿Cuál es tu nivel?: ");
  scanf("%d", &datos.nivel);
 
  printf("¿Cuánta experiencia has adquirido ya en dicho nivel?: ");
  scanf("%d", &datos.experiencia);
  
  printf("¿Con qué campeón has jugado tu última partida?: ");
  scanf("%s", datos.ultCampeon);
  
  printf("¿Cuántos asesinatos has hecho?: ");
  scanf("%d", &datos.kda[asesinatos]);
  
  printf("¿Cuántas veces has muerto?: ");
  scanf("%d", &datos.kda[muertes]);
  
  printf("¿Y cuántas asistencias has hecho?: ");
  scanf("%d", &datos.kda[assists]);
  
  // KDA Ratio = (K+A) / Max(1,D)

  if (!datos.kda[muertes] >= 1) { datos.kda[muertes] = 1; }
  
  datos.ratioKDA = (datos.kda[asesinatos] + datos.kda[assists]) / (double)datos.kda[muertes];
  
  printf("\n%s, de nivel %d y experiencia %d, "
         "tu KDA ratio con %s ha sido %.2lf.\n\n", 
          datos.nombre, datos.nivel, datos.experiencia,
          datos.ultCampeon, datos.ratioKDA);
  
  return(0);
}

/*********************************************/


/*********************************************
// Estructuras Anidadas
#include    <stdio.h>

#define     MAX_STR 128

typedef     struct
{
  char      nombre[MAX_STR];
  char      primer_apellido[MAX_STR];
  char      segundo_apellido[MAX_STR];
} Escritor;

typedef     struct
{
  Escritor  escritor;
  char      titulo[MAX_STR];
  int       anyo;
} Libro;

int main(void)
{
  Libro     novela;

  printf("Introduce el nombre del autor: ");
  gets(novela.escritor.nombre);
    
  printf("Introduce el primer apellido del autor: ");
  gets(novela.escritor.primer_apellido);
  
  printf("Introduce el segundo apellido del autor: ");
  gets(novela.escritor.segundo_apellido);
  
  printf("Introduce el título del libro: ");
  gets(novela.titulo);
  
  printf("Introduce el año de publicación del libro: ");
  scanf("\n%d", &novela.anyo);

  printf("\n%s fue escrito en %d por %s %s %s.\n\n",
          novela.titulo, novela.anyo, novela.escritor.nombre,
          novela.escritor.primer_apellido, novela.escritor.segundo_apellido);
  
  return(0);
}

/*********************************************/


/*************** Ejercicio 4.3 ***************
// Ahora vamos a cambiar el programa anterior para que utilice 
// estructuras anidadas. Para ello, añadiremos una nueva estructura, 
// juego, en la que guardaremos algunas de las variables que teníamos 
// antes como parte del invocador. Es decir, tendremos dos estructuras:

// - invocador, que contiene: el nombre usuario, su nivel, la experiencia 
// que lleva adquirida en dicho nivel y un juego (variable de tipo estructurado).

// - juego, que contiene: el nombre de invocador del campeón 
// y su KDA (como tabla de enteros).

// La salida será la misma que la de los programas anteriores:

// ¿Cuál es tu nombre de invocador? asdfg
// ¿Cuál es tu nivel? 67
// ¿Cuánta experiencia has adquirido ya en dicho nivel? 2651
// ¿Con qué campeón has jugado tu última partida? Soraka
// ¿Cuántos asesinatos has hecho? 1
// ¿Cuántas veces has muerto? 3
// ¿Y cuántas asistencias has hecho? 18
// asdfg, de nivel 67 y experiencia 2651, tu KDA ratio con Soraka ha sido 6.33.

#include  <stdio.h>
#include  <string.h>

#define   MAX_STR   128
#define   KDA       3

enum 
{ 
  asesinatos, 
  muertes, 
  assists
};

typedef   struct
{
  char    ultCampeon[MAX_STR];
  int     kda[KDA];
  double  ratioKDA;
} _Juego;

typedef   struct
{
  char    nombre[MAX_STR];
  int     nivel;
  int     experiencia;
  _Juego  juego;
} _Invocador;

int main(void)
{
  _Invocador  invocador;
  
  printf("\n¿Cuál es tu nombre de invocador?: ");
  scanf("%s", invocador.nombre);
  
  printf("¿Cuál es tu nivel?: ");
  scanf("%d", &invocador.nivel);
 
  printf("¿Cuánta experiencia has adquirido ya en dicho nivel?: ");
  scanf("%d", &invocador.experiencia);
  
  printf("¿Con qué campeón has jugado tu última partida?: ");
  scanf("%s", invocador.juego.ultCampeon);
  
  printf("¿Cuántos asesinatos has hecho?: ");
  scanf("%d", &invocador.juego.kda[asesinatos]);
  
  printf("¿Cuántas veces has muerto?: ");
  scanf("%d", &invocador.juego.kda[muertes]);
  
  printf("¿Y cuántas asistencias has hecho?: ");
  scanf("%d", &invocador.juego.kda[assists]);
  
  // KDA Ratio = (K+A) / Max(1,D)

  if (!invocador.juego.kda[muertes] >= 1) { invocador.juego.kda[muertes] = 1; }
  
  invocador.juego.ratioKDA = (invocador.juego.kda[asesinatos] + 
  invocador.juego.kda[assists]) / (double)invocador.juego.kda[muertes];
  
  printf("\n%s, de nivel %d y experiencia %d, "
         "tu KDA ratio con %s ha sido %.2lf.\n\n", 
          invocador.nombre, invocador.nivel, invocador.experiencia,
          invocador.juego.ultCampeon, invocador.juego.ratioKDA);
  
  return(0);
}

/*********************************************/


/*********************************************
// Tablas de Estructuras 0
#include    <stdio.h>

#define     MAX_STR     128
#define     DIM_NOVELAS 4

typedef     struct
{
  char      nombre[MAX_STR];
  char      primer_apellido[MAX_STR];
  char      segundo_apellido[MAX_STR];
} Escritor;

typedef     struct
{
  Escritor  autor;
  char      titulo[MAX_STR];
  int       anyo;
} Libro;

int main(void)
{
  Libro novelas[DIM_NOVELAS];

  // Primer libro
  printf("\nIntroduce el nombre del autor del primer libro: ");
  gets(novelas.autor.nombre);
  printf("Introduce el título del primer libro: ");
  gets(novelas[0].titulo);

  // Segundo libro
  printf("Introduce el nombre del autor del segundo libro: ");
  gets(novelas[1].autor.nombre);
  printf("Introduce el título del segundo libro: ");
  gets(novelas[1].titulo);

  printf("\n%s fue escrito por %s.\n", novelas[0].titulo, novelas[0].autor.nombre);
  printf("%s fue escrito por %s.\n\n", novelas[1].titulo, novelas[1].autor.nombre);
  
  return(0);
}

/*********************************************/


/*************** Ejercicio 4.4 ***************
// Vamos a modificar el programa anterior para trabajar con tablas de 
// estructuras, de forma que calculemos el KDA total de los cinco 
// jugadores que han participado en la partida.

// Para obtener dicho dato es necesario sumar por un lado los 
// asesinatos de los cinco jugadores, por otro las muertes y finalmente 
// las asistencias. Asimismo, calcularemos el ratio de ese KDA total.

// La salida será muy similar a la de los programas anteriores, pero en 
// este programa no vamos a solicitar la experiencia ni el nivel del usuario:

// DATOS JUGADOR 1
// ¿Cuál es tu nombre de invocador? j1
// ¿Con qué campeón has jugado tu última partida? Zoe
// ¿Cuántos asesinatos has hecho? 1
// ¿Cuántas veces has muerto? 6
// ¿Y cuántas asistencias has hecho? 3
// j1, tu KDA ratio con Zoe ha sido 0.67.

// DATOS JUGADOR 2
// ¿Cuál es tu nombre de invocador? j2
// ¿Con qué campeón has jugado tu última partida? Udyr
// ¿Cuántos asesinatos has hecho? 5
// ¿Cuántas veces has muerto? 6
// ¿Y cuántas asistencias has hecho? 3
// j2, tu KDA ratio con Udyr ha sido 1.33.

// DATOS JUGADOR 3
// ¿Cuál es tu nombre de invocador? j3
// ¿Con qué campeón has jugado tu última partida? Morgana
// ¿Cuántos asesinatos has hecho? 3
// ¿Cuántas veces has muerto? 7
// ¿Y cuántas asistencias has hecho? 18
// j3, tu KDA ratio con Morgana ha sido 3.00.

// DATOS JUGADOR 4
// ¿Cuál es tu nombre de invocador? j4
// ¿Con qué campeón has jugado tu última partida? Olaf
// ¿Cuántos asesinatos has hecho? 26
// ¿Cuántas veces has muerto? 3
// ¿Y cuántas asistencias has hecho? 3
// j4, tu KDA ratio con Olaf ha sido 9.67.

// DATOS JUGADOR 5
// ¿Cuál es tu nombre de invocador? j5
// ¿Con qué campeón has jugado tu última partida? Jhin
// ¿Cuántos asesinatos has hecho? 3
// ¿Cuántas veces has muerto? 6
// ¿Y cuántas asistencias has hecho? 10
// j5, tu KDA ratio con Jhin ha sido 2.17.

// Usuarios j1, j2, j3, j4 y j5, el KDA de vuestra partida ha sido 38/28/37 y su ratio 2.68.

#include  <stdio.h>
#include  <string.h>

#define   MAX_STR   128
#define   JUGADORES 5
#define   KDA       3

enum 
{ 
  asesinatos, 
  muertes, 
  assists
};

enum 
{ 
  jugador1, 
  jugador2, 
  jugador3,
  jugador4,
  jugador5,
};


typedef   struct
{
  char    ultCampeon[MAX_STR];
  int     kda[KDA];
  double  ratioKDA;
} _Juego;

typedef   struct
{
  char    nombre[MAX_STR];
  // int     nivel;
  // int     experiencia;
  _Juego  juego;
} _Invocador;

int main(void)
{
  static int     mediaUsuarios[KDA];
  static double  mediaTotal;
  _Invocador     invocador[JUGADORES];
  
  for (int i = 0; i < JUGADORES; i++)
  {
    printf("\nDATOS JUGADOR %d\n", i+1);
    printf("\n¿Cuál es tu nombre de invocador?: ");
    scanf("%s", invocador[i].nombre);
  
    // printf("¿Cuál es tu nivel?: ");
    // scanf("%d", &invocador[i].nivel);
 
    // printf("¿Cuánta experiencia has adquirido ya en dicho nivel?: ");
    // scanf("%d", &invocador.experiencia);
  
    printf("¿Con qué campeón has jugado tu última partida?: ");
    scanf("%s", invocador[i].juego.ultCampeon);
  
    printf("¿Cuántos asesinatos has hecho?: ");
    scanf("%d", &invocador[i].juego.kda[asesinatos]);
  
    printf("¿Cuántas veces has muerto?: ");
    scanf("%d", &invocador[i].juego.kda[muertes]);
  
    printf("¿Y cuántas asistencias has hecho?: ");
    scanf("%d", &invocador[i].juego.kda[assists]);
    
    // KDA Ratio = (K+A) / Max(1,D)
    if (!invocador[i].juego.kda[muertes] >= 1) { invocador[i].juego.kda[muertes] = 1; }
  
    invocador[i].juego.ratioKDA = (invocador[i].juego.kda[asesinatos] + 
    invocador[i].juego.kda[assists]) / (double)invocador[i].juego.kda[muertes];
    
    mediaUsuarios[asesinatos] += invocador[i].juego.kda[asesinatos];
    mediaUsuarios[muertes]    += invocador[i].juego.kda[muertes];
    mediaUsuarios[assists]    += invocador[i].juego.kda[assists];
    
    // printf("\nCuenta = mediaUsuarios[asesinatos]: %d, mediaUsuarios[muertes]: %d, "
    //       "mediaUsuarios[assists]: %d.\n\n", 
    //         mediaUsuarios[asesinatos], 
    //         mediaUsuarios[muertes],
    //         mediaUsuarios[assists]);
  
    printf("\nJugador %d: %s, tu KDA ratio con %s ha sido %.2lf.\n\n", 
            i+1, invocador[i].nombre, 
            invocador[i].juego.ultCampeon,
            invocador[i].juego.ratioKDA);
  }
    // KDA Ratio = (K+A) / Max(1,D)
    if (!mediaUsuarios[muertes] >= 1) { mediaUsuarios[muertes] = 1; }
  
    mediaTotal = (mediaUsuarios[asesinatos] + 
    mediaUsuarios[assists]) / (double)mediaUsuarios[muertes];
    
    printf("\nUsuarios %s, %s, %s, %s y %s, el KDA de vuestra partida ha sido "
           "%d/%d/%d y su ratio %.2lf.\n\n", 
            invocador[jugador1].nombre, 
            invocador[jugador2].nombre, 
            invocador[jugador3].nombre,
            invocador[jugador4].nombre,
            invocador[jugador5].nombre,
            mediaUsuarios[asesinatos],
            mediaUsuarios[muertes],
            mediaUsuarios[assists],
            mediaTotal);
  
  return(0);
}

/*********************************************/


/*********************************************
// Tablas de Estructuras 1
#include    <stdio.h>

#define     MAX_STR     128
#define     DIM_NOVELAS 4
#define     DIM_AUTORES 3

typedef     struct
{
  char      nombre[MAX_STR];
  char      primer_apellido[MAX_STR];
  char      segundo_apellido[MAX_STR];
} Escritor;

typedef     struct
{
  Escritor  autores[DIM_AUTORES];
  char      titulo[MAX_STR];
  int       anyo;
} Libro;

int main(void)
{
  Libro     novelas[DIM_NOVELAS];
  
  // Primer libro
  printf("\nIntroduce el nombre del primer autor del primer libro: ");
  gets(novelas[0].autores[0].nombre);
  printf("Introduce el nombre del segundo autor del primer libro: ");
  gets(novelas[0].autores[1].nombre);
  printf("Introduce el título del primer libro: ");
  gets(novelas[0].titulo);

  // Segundo libro
  printf("Introduce el nombre del autor del segundo libro: ");
  gets(novelas[1].autores[0].nombre);
  printf("Introduce el título del segundo libro: ");
  gets(novelas[1].titulo);

  printf("%s fue escrito por %s y %s.\n", novelas[0].titulo, novelas[0].autores[0].nombre, novelas[0].autores[1].nombre);
  printf("%s fue escrito por %s.\n", novelas[1].titulo, novelas[1].autores[0].nombre);
  
  return(0);
}

/*********************************************/


/*************** Ejercicio 4.5 ***************
// Vamos a hacer un último programa, el más complejo de los 
// que hemos hecho hasta ahora, en el que queremos trabajar 
// con tablas de estructuras que contienen como atributo 
// tablas de otra estructura. Para ello, vamos a convertir la 
// variable partida del invocador, que era de tipo juego, 
// en una tabla de estructuras; de esta forma podremos 
// guardar varias partidas que ha hecho un usuario.

// Con esta estructura en mente, tenemos que solicitar los datos
// de 3 partidas a 2 jugadores para calcular la media de KDA ratio
// que han hecho en las últimas 3 partidas, de forma individual.

// Para obtener dicho dato es necesario calcular el KDA ratio de 
// cada partida y hacer la media de dichos 3 ratios para cada jugador.

// a salida seguirá siendo ligeramente similar a los programas anteriores:

// DATOS JUGADOR 1
// ¿Cuál es tu nombre de invocador? j1
// ¿Con qué campeón has jugado tu última partida? Malzahar
// ¿Cuántos asesinatos has hecho? 8
// ¿Cuántas veces has muerto? 4
// ¿Y cuántas asistencias has hecho? 6 ...3.5

// ¿Con qué campeón jugaste tu penúltima partida? Alistar
// ¿Cuántos asesinatos hiciste? 2
// ¿Cuántas veces te mataron? 5
// ¿Y cuántas asistencias hiciste? 12 ...2.8

// ¿Con qué campeón jugaste tu antepenúltima partida? Thresh
// ¿Cuántos asesinatos hiciste? 4
// ¿Cuántas veces te mataron? 9
// ¿Y cuántas asistencias hiciste? 13 ...1.8

// j1, la media de tu KDA ratio de las 3 últimas partidas ha sido 2.73.

// DATOS JUGADOR 2
// ¿Cuál es tu nombre de invocador? j2
// ¿Con qué campeón has jugado tu última partida? Udyr
// ¿Cuántos asesinatos has hecho? 5
// ¿Cuántas veces has muerto? 6
// ¿Y cuántas asistencias has hecho? 3 ...1.33

// ¿Con qué campeón jugaste tu penúltima partida? Zyra
// ¿Cuántos asesinatos hiciste? 3
// ¿Cuántas veces te mataron? 6
// ¿Y cuántas asistencias hiciste? 10 ...2.17

// ¿Con qué campeón jugaste tu antepenúltima partida? Galio
// ¿Cuántos asesinatos hiciste? 5
// ¿Cuántas veces te mataron? 6
// ¿Y cuántas asistencias hiciste? 10 ...2.50

// j2, la media de tu KDA ratio de las 3 últimas partidas ha sido 2.00.

#include  <stdio.h>
#include  <string.h>

#define   KDA       3
#define   MAX_STR   128
#define   PARTIDAS  3
#define   JUGADORES 2

static const char *const adj0[] =
{
  "",
  "pen",
  "antepen"
};

static const char *const adj1[] =
{
  "has jugado",
  "jugaste",
  "jugaste"
};

enum 
{ 
  asesinatos, 
  muertes, 
  assists
};

typedef   struct
{
  char    ultCampeon[MAX_STR];
  int     kda[KDA];
  double  ratioKDA;
} _Juego;

typedef   struct
{
  char    nombre[MAX_STR];
  _Juego  partida[3];
  double  mediaRatioKDA;
} _Invocador;

int main(void)
{
  double         sumaMediaRatioKDA[JUGADORES];
  _Invocador     invocador[JUGADORES];
  
  for (int i = 0; i < JUGADORES; i++)
  {
    printf("\nDATOS JUGADOR %d\n", i+1);
    printf("\n¿Cuál es tu nombre de invocador?: ");
    scanf("%s", invocador[i].nombre);
    
    for (int j = 0; j < PARTIDAS; j++)
    {
      printf("¿Con qué campeón %s tu %súltima partida?: ",
              *(adj1+j), *(adj0+j));
      scanf("%s", invocador[i].partida[j].ultCampeon);
    
      printf("¿Cuántos asesinatos has hecho?: ");
      scanf("%d", &invocador[i].partida[j].kda[asesinatos]);
    
      printf("¿Cuántas veces has muerto?: ");
      scanf("%d", &invocador[i].partida[j].kda[muertes]);
    
      printf("¿Y cuántas asistencias has hecho?: ");
      scanf("%d", &invocador[i].partida[j].kda[assists]);
      
      putchar('\n');
      // KDA Ratio = (K+A) / Max(1,D)
      if (!invocador[i].partida[j].kda[muertes] >= 1) { invocador[i].partida[j].kda[muertes] = 1; }
    
      invocador[i].partida[j].ratioKDA = (invocador[i].partida[j].kda[asesinatos] +
      invocador[i].partida[j].kda[assists]) / (double)invocador[i].partida[j].kda[muertes];
      // Debug
      // printf("\n%s, la KDA ratio de esta partida es: %.2lf.\n\n",
      //       invocador[i].nombre, invocador[i].partida[j].ratioKDA);
    }
    
    for (int x = 0; x < PARTIDAS; x++)
    {
      sumaMediaRatioKDA[i] += invocador[i].partida[x].ratioKDA;
    }
    
    invocador[i].mediaRatioKDA = sumaMediaRatioKDA[i] / (double)PARTIDAS;
    
    printf("%s, la media de tu KDA ratio de las " 
           "3 últimas partidas ha sido %.2lf.\n\n",
            invocador[i].nombre, invocador[i].mediaRatioKDA);
  }
  
  return(0);
  
}

/*********************************************/


/**************** Prueba 4.1 *****************/
// Escribe un programa en C que:

// Declare una estructura llamada Suma con una tabla de tres enteros
// (utiliza una macro para definir su tamaño) y un entero para almacenar
// la suma de los elementos de la tabla.

// Declare otra estructura llamada Resto con una tabla de dos elementos 
// de tipo Suma (utiliza una macro para definir su tamaño) y un entero 
// para almacenar el módulo de la división de las dos sumas.

// El programa declarará una variable estructurada 
// a partir de la estructura Resto.

// A continuación solicitará los tres enteros de la primera tabla
// y los guardará en los miembros correspondientes de la variable estructurada.

// A continuación calculará la suma de los tres números leídos
// y los guardará en el miembro correspondiente de la variable estructurada.

// A continuación solicitará los tres enteros de la segunda tabla
// y los guardará en los miembros correspondientes de la variable estructurada.

// A continuación calculará la suma de los tres números leídos
// y los guardará en el miembro correspondiente de la variable estructurada.

// A continuación calculará el resto de la división de las dos sumas
// y lo guardará en el miembro correspondiente de la variable estructurada.

// Por último mostrará la información de las sumas y restos por pantalla
// de la forma que se especifica en el ejemplo más abajo.

// Los mensajes se han de mostrar tal y como aparecen en 
// el siguiente ejemplo de ejecución y en el mismo orden 
// (variando sólo según los datos introducidos por el usuario).

// Lo que sigue es un ejemplo de ejecución del programa:

// Introduce el primer entero de la primera tabla: 14
// Introduce el segundo entero de la primera tabla: 19
// Introduce el tercer entero de la primera tabla: 8
// Introduce el primer entero de la segunda tabla: 4
// Introduce el segundo entero de la segunda tabla: 11
// Introduce el tercer entero de la segunda tabla: 3
// La suma de los elementos de la primera tabla es 41.
// La suma de los elementos de la segunda tabla es 18.
// El resto de la división de ambas sumas es 5.

#define TAM_M 3
#define TAM_S 2

static const char *const posicion[] =
{
  "primer",
  "segundo",
  "tercer"
};

static const char *const posicionT[] =
{
  "primera",
  "segunda"
};

typedef struct
{
  int tabla_suma[TAM_M];
  int suma_elementos;
} Suma;

typedef struct
{
  Suma tabla_Sumas[TAM_S];
  int _resto;
} Resto;

#include  <stdio.h>

int main(void)
{
  Resto resto;
  
  int resto_div;
  
  static int entrada[TAM_S][TAM_M];
  
  putchar('\n');
  
  for (int i = 0; i < TAM_S; i++)
  {
    for (int j = 0; j < TAM_M; j++)
    {
      printf("Introduce el %s entero de la %s tabla: ",
              *(posicion+j), *(posicionT+i));
      scanf("%d", &entrada[i][j]);
      resto.tabla_Sumas[i].tabla_suma[j] = entrada[i][j];
      resto.tabla_Sumas[i].suma_elementos += entrada[i][j];
    }
  }
  
  resto_div = resto.tabla_Sumas[0].suma_elementos % resto.tabla_Sumas[1].suma_elementos;
  
  printf("\nLa suma de los elementos de la primera tabla es %d.\n",
          resto.tabla_Sumas[0].suma_elementos);
  printf("La suma de los elementos de la segunda tabla es %d.\n",
          resto.tabla_Sumas[1].suma_elementos);
  printf("El resto de la división de ambas sumas es %d.\n",
          resto_div);
          
  putchar('\n');        
          
  return(0);
}

/*********************************************/

Final del primer trimeste

/*************** Ejercicio 4.2 ***************

#include  <stdio.h>

int main(void)
{
 
  return(0);
}

/*********************************************/


/*********************************************

#include  <stdio.h>

int main(void)
{
 
  return(0);
}

/*********************************************/