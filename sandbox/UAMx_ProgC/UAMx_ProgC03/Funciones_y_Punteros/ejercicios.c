// UAMx ProgC03

// Introducción a la programación en C: 
// Funciones y Punteros

/*********************************************

#include  <stdio.h>

void menu(void)
{
  puts("\n");
  
  printf("Menú:\n\n  1. Empezar partida\n  2. Ajustes\n  3. Ayuda\n  4. Salir\n\n");
  printf("Selecciona una opción: ");
  
  return;
}

int main(void)
{
  int opcion;
  
  do
  {
    menu();
    scanf("%d", &opcion);
    
  } while (opcion < 1 || opcion > 4);
  
  switch (opcion)
  {
    case 1: 
      printf("Has elegido comenzar la partida.\n");
      break;
    
    case 2: 
      printf("Aquí estará el código para mostrar los ajustes del juego.\n");
      break;
    
    case 3:
      printf("Aquí estará el código para mostrar la ayuda.\n");
      break;
      
    case 4:
      printf("¡Hasta luego!\n");
      break;
  }
  
  puts("\n");
  
  return(0);
}

/*********************************************/


/*************** Ejercicio 1.1 ***************
// Escribe un programa con una función que 
// solicite la base y la altura de un triángulo
// y muestre por pantalla su área.

// La función main se encargará únicamente de 
// llamar a esta función, y no declarará ninguna
// variable ni tendrá ninguna otra instrucción.

// Este sería un ejemplo del programa:

// Introduce la base del triángulo: 12
// Introduce la altura del triángulo: 7
// El área del triángulo de base
// 12 y altura 7 es 42.00.

// Y otro:

// Introduce la base del triángulo: 37
// Introduce la altura del triángulo: 10
// El área del triángulo de base
// 37 y altura 10 es 185.00.

#include  <stdio.h>

void calcularAreaTriangulo(void)
{
  int    base;
  int    altura;
  double area;
  
  printf("\nIntroduce la base del triángulo: ");
  scanf("%d", &base);
  printf("\nIntroduce la altura del triángulo: ");
  scanf("%d", &altura);
  area = (base * altura) / 2;
  printf("\nEl área del triángulo de base %d y altura %d es %.2lf\n\n",
          base, altura, area);
  return;
}

int main(void)
{
  calcularAreaTriangulo();
  return(0);
}

/*********************************************/


/*********************************************

#include  <stdio.h>

void media(int a, int b)
{
  double res;
  
  res = 0.5 * (a + b);
  
  printf("La media de %d y %d es %.1lf.", a, b, res);
  
  return;
}


int main(void)
{
  puts("\n");
  
  int x = 2;
  int y = 3;
  
  media(x, y);
  
  puts("\n");
  
  return(0);
}

/*********************************************/


/*************** Ejercicio 1.2 ***************
// Modifica la función del ejercicio anterior
// para que sea el programa principal el que 
// solicite la base y la altura y le pase estos
// datos a la función. La función debe calcular 
// el área y mostrar un mensaje por 
// pantalla con el valor calculado.

// Ten en cuenta que la salida del programa 
// continuará siendo la misma a la del 
// ejercicio 1.1. Este era un ejemplo:

// Introduce la base del triángulo: 12
// Introduce la altura del triángulo: 7
// El área del triángulo de base
// 12 y altura 7 es 42.00.

// Y este, otro:

// Introduce la base del triángulo: 37
// Introduce la altura del triángulo: 10
// El área del triángulo de base
// 37 y altura 10 es 185.00.

#include  <stdio.h>

void calcularAreaTriangulo(int x, int y)
{
  double area;
  
  area = (x * y) / 2;
  
  printf("\nEl área del triángulo de base %d y altura %d es %.2lf\n\n",
          x, y, area);
  return;
}

int main(void)
{
  int    base;
  int    altura;
  
  printf("\nIntroduce la base del triángulo: ");
  scanf("%d", &base);
  printf("\nIntroduce la altura del triángulo: ");
  scanf("%d", &altura);
  
  calcularAreaTriangulo(base, altura);
  
  return(0);
}

/*********************************************/


/*********************************************
// Funciones con Retorno
#include  <stdio.h>

double media(int a, int b)
{
  double res = 0.5 * (a + b);
  
  return res;
  // return;
}

int main(void)
{
  int x = 2, y = 3;
  // media(x, y);
  double res = media(x, y);
  
  printf("La media de %d y %d es %.1lf.\n\n", x, y, res);
 
  return(0);
}

/*********************************************/


/*************** Ejercicio 1.3 ***************
// Modifica el ejercicio anterior para que la 
// función devuelva el valor del área calculado, 
// sin solicitar por teclado ni 
// mostrar por pantalla ningún dato 
// (no debe contener ningún printf() ni scanf()).

// La función main(), por tanto, 
// ha de solicitar por teclado el valor 
// de la base y altura y mostrar por pantalla
// el resultado calculado por la función.

// Ten en cuenta que la salida del programa 
// continuará siendo la misma a la de los 
// ejercicios 1.1 y 1.2. Este era un ejemplo:

// Introduce la base del triángulo: 12
// Introduce la altura del triángulo: 7
// El área del triángulo de 
// base 12 y altura 7 es 42.00.

// Y este, otro:

// Introduce la base del triángulo: 37
// Introduce la altura del triángulo: 10
// El área del triángulo de 
// base 37 y altura 10 es 185.00.

#include  <stdio.h>

double calcularAreaTriangulo(int x, int y)
{
  double area = (x * y) / 2;
  
  return area;
}

int main(void)
{
  int    base;
  int    altura;
  
  printf("\nIntroduce la base del triángulo: ");
  scanf("%d", &base);
  printf("\nIntroduce la altura del triángulo: ");
  scanf("%d", &altura);
  
  printf("\nEl área del triángulo de base %d y altura %d es %.2lf\n\n",
          base, altura, calcularAreaTriangulo(base, altura));
  
  return(0);
}

/*********************************************/


/*************** Ejercicio 1.4 ***************
// Una de las principales utilidades de las 
// funciones es que se puedan reutilizar en
// programas diferentes. Esto es lo que ocurre
// por ejemplo con las funciones scanf(), printf() 
// o strcmp(), que realizan una tarea concreta 
// que se invoca en muchos programas distintos.

// Lo mismo puede ocurrir con cualquiera de 
// las funciones que estás escribiendo. 
// Intenta pensar siempre en ellas como 
// funciones reutilizables que pueden ser 
// utilizadas en otros programas 
// main() diferentes. Pueden ser programas que 
// hagan tareas completamente distintas pero 
// necesiten resolver el problema concreto que 
// resuelve esa función y la utilicen en un punto
// determinado. Muy comúnmente pueden ser 
// programas escritos por otras personas.

// Utiliza la función esPrimo() que te hemos 
// mostrado, sin modificarla, para crear un 
// programa que la llame para imprimir en 
// pantalla todos los números primos desde 
// el 2 hasta un número solicitado al 
// usuario por teclado. De esta forma puedes 
// comprobar que la misma función esPrimo()
// se puede utilizar en otro programa que 
// realice y muestre resultados distintos.

// Este sería un ejemplo del programa:

// Intruduce un número entero positivo: 7
// El número 2 es primo.
// El número 3 es primo.
// El número 4 no es primo.
// El número 5 es primo.
// El número 6 no es primo.
// El número 7 es primo.

// Y otro:

// Intruduce un número entero positivo: 18
// El número 2 es primo.
// El número 3 es primo.
// El número 4 no es primo.
// El número 5 es primo.
// El número 6 no es primo.
// El número 7 es primo.
// El número 8 no es primo.
// El número 9 no es primo.
// El número 10 no es primo.
// El número 11 es primo.
// El número 12 no es primo.
// El número 13 es primo.
// El número 14 no es primo.
// El número 15 no es primo.
// El número 16 no es primo.
// El número 17 es primo.
// El número 18 no es primo.

// *Para usar la libreria <math.h>, gcc 
// necesita compilar con el argumento "-lm"

#include <stdio.h>
#include <math.h>

int esPrimo(int num)
{
  int i;
  
  for (i = 2; i <= sqrt(num); i++)
  {
    if (num % i == 0) 
    {
      return(0);
    }
  }

  return(1);
  
}

int main()
{
  int num, i = 2;
  printf("\nIntroduce un número entero positivo: ");
  scanf("%d", &num);
  
  while (i <= num)
  {
    if (esPrimo(i))
      printf("El número %d es primo.\n", i);
    else
      printf("El número %d no es primo\n", i);
    
    i++;
  }
  
  puts("\n");
  
  return(0);
}

/*********************************************/


/*************** Ejercicio 1.5 ***************
// Dos números primos son primos gemelos si están
// separados por una distancia de dos. Esto es, 
// si x e y son primos, x ha de ser igual a y+2. 
// Por ejemplo, 3 y 5, 5 y 7, 11 y 13, 17 y 19 
// son primos gemelos.

// Escribe un programa que solicite un número 
// entero superior a tres, compruebe si es primo y
// en ese caso informe de si tiene un primo gemelo. 
// Utiliza para ello la función esPrimo(), 
// nuevamente sin modificarla.

// Estas son las posibles salidas del programa, 
// habiéndose introducido por 
// teclado el primer número:

// El número 4 no es primo.
// El número 23 es primo pero no tiene un primo gemelo.
// El número 11 es primo y el 13 es primo gemelo.
// El número 13 es primo y el 11 es primo gemelo.
// El número 5 es primo y los números 3 y 7 son primos gemelos.

// *Para usar la libreria <math.h>, gcc 
// necesita compilar con el argumento "-lm"

#include <stdio.h>
#include <math.h>

int esPrimo(int num)
{
  int i;
  
  for (i = 2; i <= sqrt(num); i++)
  {
    if (num % i == 0) 
    {
      return(0);
    }
  }

  return(1);
  
}

int main()
{
  int num;
  
  printf("\nIntroduce un número entero positivo superior a 3: ");
  scanf("%d", &num);
  
  if (esPrimo(num) && (esPrimo(num-2) && esPrimo(num+2)))
  {
    printf("\nEl número %d es primo y los números %d y %d son primos gemelos.\n",
            num, num-2, num+2);
  }
  else if (esPrimo(num) && esPrimo(num+2))
  {
    printf("\nEl número %d es primo y el %d es primo gemelo.\n", num, num+2);
  }
  else if (esPrimo(num) && esPrimo(num-2))
  {
    printf("\nEl número %d es primo y el %d es primo gemelo.\n", num, num-2);
  }
  else if (esPrimo(num) && !(esPrimo(num+2)))
  {
    printf("\nEl número %d es primo pero no tiene un primo gemelo.\n", num);
  }
  else
  {
    printf("\nEl número %d no es primo.\n", num); 
  }
    
  puts("\n");
  
  return(0);
}

/*********************************************/


/*************** Ejercicio 1.6 ***************
// Escribe una función con el siguiente prototipo:
// int primoMayor(int num). La función recibe un 
// número en la variable num y ha de devolver el 
// mayor de los primos comprendido entre 2 y 
// el valor de num. Esta función ha de valerse
// para esto de llamadas a la función esPrimo(). 
// Recuerda que la función no ha de solicitar
// ningún valor por teclado ni mostrar 
// ningún valor por pantalla.

// Despues, escribe un programa principal que 
// solicite un número mayor o igual a 2, llame 
// a la función primoMayor() y muestre el 
// valor que devuelva por pantalla.

// Este sería un ejemplo del programa:

// Introduce un número superior a 1: 7
// El mayor primo comprendido entre 2 y 7 es 7.

// Otro ejemplo:

// Intruduce un número superior a 1: -2
// Intruduce un número superior a 1: 20
// El mayor primo comprendido entre 2 y 20 es 19.

// Y otro:

// Intruduce un número superior a 1: 2
// El mayor primo comprendido entre 2 y 2 es 2.

// *Para usar la libreria <math.h>, gcc 
// necesita compilar con el argumento "-lm"

#include <stdio.h>
#include <math.h>

int esPrimo(int num)
{
  int i;
  
  for (i = 2; i <= sqrt(num); i++)
  {
    if (num % i == 0) 
    {
      return(0);
    }
  }

  return(1);
  
}

int primoMayor(int num)
{
  int i, j, x, res = 0;
  int primos[num];
  
  for (i = 0; i <= num; i++)
  {
    if (esPrimo(i))
    {
      primos[i] = i;
    }
  }
  
  for (j = 0; j <= num; j++)
  {
    for (x = 0; x <= num; x++)
    {
      if (primos[x] > primos[i])
      {
        res = primos[x];
      }
    }
  }
  
  return res;
}

int main()
{
  int num, base = 2, res = 0;
  
  do
  {
    printf("\nIntroduce un número entero positivo superior a 1: ");
    scanf("%d", &num);
    
  } while (num < 1);
  
  res = primoMayor(num);
  
  printf("\nEl mayor primo comprendido entre %d y %d es %d.", base, num, res);
  
  puts("\n");
  
  return(0);
}

/*********************************************/


/**************** Prueba 1.1 *****************
// Codifica una función de tipo entero llamada 
// diferencia() que reciba dos argumentos de 
// tipo char y compruebe que están entre la 
// A y la Z o entre la a y la z.

// La función ha de devolver la diferencia en
// caracteres que hay entre las dos letras, 
// sin tener en cuenta minúsculas y mayúsculas
// y siempre retornando un número positivo.
// Si no lo están devolverá -1. Por ejemplo:

// Para los caracteres & y a devolverá -1.
// Para los caracteres a y b devolverá 1.
// Para los caracteres A y b devolverá 1.
// Para los caracteres b y a devolverá 1.
// Para los caracteres D y b devolverá 2.

// Escribe un programa principal que solicite 
// dos caracteres y llame a la función diferencia.
// Dependiendo del retorno de la función
// podrá mostrar tres mensajes posibles:

// Un mensaje de error informando de que alguno 
// de los caracteres introducidos no es una letra.
// Un mensaje informando de que la diferencia 
// entre ambas letras es de un carácter.
// Un mensaje informando de que la diferencia 
// entre ambas letras es de x caracteres (para x>1).
// Si se ha mostrado el mensaje de error, 
// el programa debe volver a solicitar las 
// letras, llamar a la función y 
// mostrar el mensaje hasta que se
// introduzcan valores válidos.

// Lo que sigue es un ejemplo
// de ejecución del programa:

// Introduce una letra de del abecedario en 
// mayúsculas o minúsculas (excepto la ñ): d

// Introduce otra letra de del abecedario en
// mayúsculas o minúsculas (excepto la ñ): +

// Error, solo puedes introducir letras del abecedario.
// Introduce una letra de del abecedario en mayúsculas
// o minúsculas (excepto la ñ): -

// Introduce otra letra de del abecedario en mayúsculas
// o minúsculas (excepto la ñ): R

// Error, solo puedes introducir letras del abecedario.
// Introduce una letra de del abecedario en mayúsculas
// o minúsculas (excepto la ñ): F

// Introduce otra letra de del abecedario en mayúsculas
// o minúsculas (excepto la ñ): s

// La diferencia entre la F y la s es de 13 caracteres.

// Esto es otro ejemplo:

// Introduce una letra de del abecedario en mayúsculas
// o minúsculas (excepto la ñ): t

// Introduce otra letra de del abecedario en mayúsculas
// o minúsculas (excepto la ñ): m

// La diferencia entre la t y la m es de 7 caracteres.

// Otro:

// Introduce una letra de del abecedario en mayúsculas
// o minúsculas (excepto la ñ): T

// Introduce otra letra de del abecedario en mayúsculas
// o minúsculas (excepto la ñ): m

// La diferencia entre la T y la m es de 7 caracteres.

// Otro:

// Introduce una letra de del abecedario en mayúsculas
// o minúsculas (excepto la ñ): a

// Introduce otra letra de del abecedario en mayúsculas
// o minúsculas (excepto la ñ): A

// La diferencia entre la a y la A es de 0 caracteres.

// Y otro:

// Introduce una letra de del abecedario en mayúsculas
// o minúsculas (excepto la ñ): c

// Introduce otra letra de del abecedario en mayúsculas
// o minúsculas (excepto la ñ): D

// La diferencia entre la c y la D es de un carácter.

// NOTA1: Fíjate que este último mensaje es diferente a los anteriores, al haber solo un carácter de diferencia.

// NOTA2: La función no debe solicitar ningún valor por teclado ni mostrar ningún mensaje por pantalla.

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int diferencia(char primera_letra, char segunda_letra)
{
  int diferencia;
  unsigned char primera = primera_letra;
  unsigned char segunda = segunda_letra;

  // if ((primera < 65) || (primera > 90))
  // {
  //   if ((primera < 97) || (primera) > 122)
  //     return(-1);
  // }

  if (!isalpha(primera))
    return(-1);

  // if ((segunda < 65) || (segunda > 90))
  // {
  //   if ((segunda < 97) || (segunda) > 122)
  //     return(-1);
  // }

  if (!isalpha(segunda))
  {
    return(-1);
  }

  if (isupper((unsigned char) primera_letra))
    primera = tolower((unsigned char)primera);
  if (isupper((unsigned char) segunda_letra))
    segunda = tolower((unsigned char)segunda);
  
  diferencia = primera - segunda;
  
  if (diferencia <= 0)
    diferencia *= -1;
  
  return diferencia;

}


int main(void)
{

  int  resultado;
  char primera; 
  char segunda;
  
  do
  {
    printf("\nIntroduce una letra de del abecedario en mayúsculas o minúsculas (excepto la ñ): ");
    scanf("\n%c", &primera);
    
    printf("\nIntroduce una letra de del abecedario en mayúsculas o minúsculas (excepto la ñ): ");
    scanf("\n%c", &segunda);

    if ((diferencia(primera, segunda)) == -1)
    {
      printf("\nError, solo puedes introducir letras del abecedario.\n");   
    }

  } while ((diferencia(primera, segunda)) == -1);
  
  resultado = diferencia(primera, segunda);

  if (resultado == 1)
  {
    printf("\nLa diferencia entre la %c y la %c es de un carácter.\n\n",
            primera, segunda);
  }
  else
  {
    printf("\nLa diferencia entre %c y %c es de %d caracteres.\n\n",
            primera, segunda, resultado);
  }
  
  return(0);
}

/*********************************************/


/*********************************************
// Practica de punteros
#include  <stdio.h>

int main(void)
{
  // int i = 10, j, *p;
  int i, *p;
  // j = ;
  // p = i;
  // i = 5;
  i = 1000000;

  printf("\nLa variable i vale = %d\n\n", i);    

  p  = &i;
  *p = 10;

  printf("\nLa variable i vale = %d\n\n", i);
  // printf("\ni = %d, j = %d, *p = %d\n\n", i, j, *p);
  return(0);
}

/*********************************************/


/*************** Ejercicio 2.1 ***************
// Escribe un programa que calcule la media de 
// dos enteros introducidos por teclado y la 
// muestre por pantalla, pero utilizando 
// punteros en vez de variables.

// Obligatoriamente tienes que utilizar dos
// variables enteras y sus correspondientes
// punteros, así como otra variable de tipo
// double para la media, y su 
// correspondiente puntero.

// Desde el momento de la asignación, 
// únicamente puede trabajarse con punteros.

// Recomendación: si crees que te va a resultar
// difícil trabajar directamente con los
// punteros, puedes hacer el programa con 
// variables normales y después sustituir 
// según lo que te hemos explicado.

// Este sería un ejemplo del programa:

// Introduce un número: 4
// Introduce otro número: 13
// media = 8.50

// Y otro:

// Introduce un número: 345
// Introduce otro número: 76
// media = 210.50

#include  <stdio.h>

int main(void)
{
  int    num_0, num_1, *p_0, *p_1;
  double media, *p_media;
  
  p_0     = &num_0;
  p_1     = &num_1;
  p_media = &media;

  printf("\nIntroduce un número: ");
  scanf("%d", p_0);

  printf("Introduce otro número: ");
  scanf("%d", p_1);

  *p_media = ((double)*p_0 + (double)*p_1) / 2;

  printf("media = %.2lf\n\n", *p_media);

  return(0);
}

/*********************************************/


/*************** Ejercicio 2.2 ***************
// Escribe una función llamada niParesniNones que
// reciba dos enteros y modifique el segundo 
// incrementándole en uno en el caso de que ambos
// sean pares o impares, de forma que las 
// variables dejarán de ser pares o 
// impares a la vez.

// El programa principal solicitará ambos 
// números al usuario, llamará a la función y 
// volverá a mostrar los números por pantalla tras
// la llamada, por lo que dentro de la función 
// no debe haber ningún printf() ni scanf().

// Este sería un ejemplo del programa:

// Introduce un número entero: 4
// Introduce otro número entero: 9
// Los números tras llamar a la función son:
// 4 y 9.

// Y otro:

// Introduce un número entero: 5
// Introduce otro número entero: 7
// Los números tras llamar a la función son:
// 5 y 8.

void niParesniNones(int *num_0, int *num_1)
{
  if (((*num_0 % 2 == 0) && (*num_1 % 2 == 0))
     || ((*num_0 % 2 != 0) && (*num_1 % 2 != 0)))
      (*num_1)++;
}

#include  <stdio.h>

int main(void)
{
  int num_0, num_1;
  
  printf("\nIntroduce un número entero: ");
  scanf("%d", &num_0);

  printf("\nIntroduce otro número entero: ");
  scanf("%d", &num_1);

  niParesniNones(&num_0, &num_1);

  printf("\nLos números tras llamar a la función son: %d y %d.\n\n",
          num_0, num_1);
  
  return(0);
}

/*********************************************/


/*************** Ejercicio 2.3 ***************
// Vamos a escribir un programa que calcule la
// media y la varianza de dos números enteros
// utilizando una función con el siguiente prototipo:

// void estadistica (int x, int y, double *pMedia, double *pVar);

// En los parámetros pMedia y pVar deberán guardarse
// los valores que calculemos. De esta forma,
// conseguiremosque una función devuelva dos cálculos, 
// lo cual no puede hacerse mediante la instrucción return.

// La fórmula de la media es: (x+y)/2
// La fórmula de la varianza es: ((x-media)*(x-media) + (y-media)*(y-media)) /2

// El main ha de solicitar los dos números por 
// teclado y, tras llamar a la función, mostrar
// la media y la varianza por pantalla, pues la
// función no debe tener ningún printf() ni scanf().

// Este sería un ejemplo del programa:

// Introduce un número: 17
// Introduce otro número: 31
// Media = 24.00
// Varianza = 49.00

// Y otro:

// Introduce un número: 182
// Introduce otro número: 56
// Media = 119.00
// Varianza = 3969.00

#include  <stdio.h>

void estadistica (int x, int y, double *pMedia, double *pVar)
{
  *pMedia = ((x + y) / 2);
  *pVar = (((x-(*pMedia)) * (x-(*pMedia))) + ((y-(*pMedia)) * (y-(*pMedia)))) / 2;
}

int main(void)
{
  int num_0, num_1;
  double media, varianza = 0;
  double *p_0 = NULL;
  double *p_1 = NULL;
  p_0 = &media;
  p_1 = &varianza;

  printf("\nIntroduce un número: ");
  scanf("%d", &num_0);

  printf("\nIntroduce otro número: ");
  scanf("%d", &num_1);

  estadistica(num_0, num_1, p_0, p_1);

  printf("\nMedia: %.2lf\nVarianza: %.2lf.\n\n", *p_0, *p_1);
  
  return(0);
}

/*********************************************/


/*********************************************
// Paso de argumentos por valor o referencia
#include  <stdio.h>

void incrementarC(int *z)
{
  (*z)++;
}

void incrementarB(int *y)
{
  (*y)++;
  incrementarC(y);
}

void incrementarA(int *x)
{
  (*x)++;
  incrementarB(x);
}

int main(void)
{
  int i = 1;

  incrementarA(&i);

  printf("\nEl valor final de i = %d\n\n", i);
 
  return(0);
}

/*********************************************/


/*********************************************
// Paso de argumento de tipo estructura #0
#include  <stdio.h>

typedef struct
{
  
  int dia;
  int mes;
  int anyo;

} Fecha;

void escribir_fecha(Fecha fecha)
{
  printf("\n%d/%d/%d\n\n", fecha.dia,
          fecha.mes, fecha.anyo);
}

void inicializar_fecha(Fecha *pFecha)
{
  // (*pFecha).dia  = 1;
  // (*pFecha).mes  = 1;
  // (*pFecha).anyo = 2000;

  pFecha->dia  = 1;
  pFecha->mes  = 1;
  pFecha->anyo = 2000;

}

int main(void)
{
  Fecha fecha = {10, 03, 1989};

  escribir_fecha(fecha);

  inicializar_fecha(&fecha);

  escribir_fecha(fecha);
 
  return(0);
}

/*********************************************/


/*********************************************
// Paso de argumento de tipo estructura #1
#include  <stdio.h>

#define   TAM 10000

typedef struct
{
  
  int datos[TAM];
  int ocupadas;

} Tabla;

void inicializar_tabla(Tabla *tabla)
{
  tabla->ocupadas = 0;
}

double media_tabla(Tabla *tabla)
{
  int i, suma;

  for (i = suma = 0; i < tabla->ocupadas; i++)
    suma += tabla->datos[i];
  return (double)suma / tabla->ocupadas;
}

int main(void)
{
  Tabla  tabla;
  int i, num;
  double med;
 
  inicializar_tabla(&tabla);

  do
  {
    printf("Cuantos valores vas a leer (entre 1 y %d)?: ", TAM);
    scanf("%d", &num);

    if (num < 1 || num > TAM)
      printf("\nError, tienes que introducir un numero entre el 1 y el %d\n", TAM);

  } while (num < 1 || num > TAM);
  
  for (i = 0; i < num; i++)
  {
    printf("Introduce el dato %d: ", i + 1);
    scanf("%d", &tabla.datos[i]);
    tabla.ocupadas++;
  }

  med = media_tabla(&tabla);

  printf("\nLa media de los datos leidos es: %.2lf\n\n", med);

  return(0);
}

/*********************************************/


/*************** Ejercicio 1.4 ***************
// Escribe una función llamada incrementaDia que 
// reciba como argumento una estructura Fecha 
// (como la vista en la explicación del vídeo) 
// y la aumente en un día.

// NOTA: Para simplificar, no tengas en cuenta 
// los años bisiestos y considera que todos 
// los meses tienen 30 días.

// Este sería un ejemplo del programa:

// Introduce un día: 19
// Introduce un mes: 09
// Introduce un año: 2028
// El día siguiente al introducido es: 20/09/2028.

// Y otro:

// Introduce un día: 31
// Introduce un mes: 12
// Introduce un año: 2018
// El día siguiente al introducido es: 1/1/2019.

#include  <stdio.h>
#include  <stdlib.h>

typedef struct
{
  
  int dia;
  int mes;
  int anyo;

} Fecha;

void incrementaDia(Fecha *fecha)
{
  if ((fecha->dia == 31) || (fecha->mes == 12))
  {  
    if ((fecha->dia == 31) && (fecha->mes == 12))
    {
      fecha->dia  = 1;
      fecha->mes  = 1;
      fecha->anyo++;
    }
    else if (fecha->dia == 31)
    {
      fecha->dia = 1;
      fecha->mes++;
    }
    else
      fecha->dia++;
  }
  else
    fecha->dia++;
    
  printf("\nl día siguiente al introducido es: %d/%d/%d\n\n",
          fecha->dia, fecha->mes, fecha->anyo);
}

int main(void)
{
  Fecha *fecha;
  fecha = (Fecha *)malloc(1 * sizeof(Fecha));

  printf("Introduce un día: ");
  scanf("%d", &fecha->dia);

  printf("Introduce un mes: ");
  scanf("%d", &fecha->mes);

  printf("Introduce un año: ");
  scanf("%d", &fecha->anyo);
  
  incrementaDia(fecha);
 
  return(0);
}

/*********************************************/


/**************** Prueba 2.1 *****************
// Escribe una función que calcule el menor y el
// mayor de los divisores de un número. 
// Este sería su prototipo:

// int menorMayorDivisor(int num, int *menor, int *mayor);

// Los posibles divisores no tendrán en cuenta 
// el 1 ni el propio número. Si el número no 
// tiene divisores, tanto en menor como en mayor
// almacenarán el número 0. Asimismo, la función
// ha de devolver 0 si el número recibido es
// inferior a 2, y por lo tanto no se pueden 
// calcular sus divisores. En caso contrario, 
// acabará devolviendo 1.

// El programa principal solicitará un número y, 
// según los valores obtenidos, realizará una de 
// las siguientes operaciones:

// Informe de que el número introducido es 
// incorrecto y vuelva a solicitarlo.

// Informe de que el número no tiene divisores.
// Informe del divisor menor y mayor.

// Lo que sigue es un ejemplo de ejecución del programa:

// Introduce un número: 1
// Error. Debes introducir un número mayor o igual a 2.
// Introduce un número: -4
// Error. Debes introducir un número mayor o igual a 2.
// Introduce un número: 10
// El menor divisor de 10 es 2 y su mayor divisor es 5 
// (sin contar la unidad y él mismo).

// Otro ejemplo:

// Introduce un número: 155
// El menor divisor de 155 es 5 y su mayor divisor es 31 
// (sin contar la unidad y él mismo).

// Otro:

// Introduce un número: 11
// El número 11 no tiene divisores menores ni mayores
// (sin contar la unidad y él mismo).

// Y otro:

// Introduce un número: 9
// El menor divisor de 9 es 3 y su mayor divisor es 3 
// (sin contar la unidad y él mismo).

#include  <stdio.h>

int menorMayorDivisor(int num, int *menor, int *mayor)
{
  int i, menor_res, res = 0;
  int mayor_res = num;

  for (i = num -1; i >= 2; --i)
  {
    if (num % i == 0)
    {
      mayor_res = i;
      res = 1;
      break;
    }
  }

  for (i = 2; i <= mayor_res; i++)
  {
    if ((num % i == 0))
    {
      menor_res = i;
      res = 1;
      break;
    }
  }

  if ((mayor_res == menor_res) && ((mayor_res) && (menor_res) == num))
    res = 1;

  *menor = menor_res;
  *mayor = mayor_res;

  return(res);
}

int main()
{
  int num, num_a, num_b, res = 0;
  int *p_num_a = NULL;
  int *p_num_b = NULL;
  p_num_a = &num_a;
  p_num_b = &num_b;

  do
  {
    printf("\nIntroduce un número: ");
    scanf("%d", &num);
    
    if (num < 2)
    { 
      printf("Error. Debes introducir un número mayor o igual a 2.\n");
    }

    menorMayorDivisor(num, p_num_a, p_num_b);
    
    if (*p_num_a == *p_num_b && *p_num_a == num)
    {
      printf("\nEl número %d no tiene divisores menores ni mayores.\n\n", num);
      break;  
    }

  } while (!(res = menorMayorDivisor(num, p_num_a, p_num_b)));

  res = menorMayorDivisor(num, p_num_a, p_num_b);
  
  if ((res) && (num != *p_num_a))
    
    printf("\nEl menor divisor de %d es %d y su mayor divisor es %d\n"
           "(sin contar la unidad y él mismo).\n\n", num, *p_num_a, *p_num_b);

  return(0);
}

/*********************************************/


/**************** Prueba 2.2 *****************
// Escribe una función con el siguiente prototipo:

// La función recibe un número entero en la variable
// num y ha de calcular los siguientes valores:

// La primera cifra del número, que guardará 
// en primera.
// La última cifra del número, que guardrá 
// en ultima.
// La cantidad de cifras del número, que retornará 
// al finalizar.

// Por ejemplo, para el número 468 la primera cifra
// es el 4, la última el 8 y la cantidad de cifras 3.

// NOTA: La función ha de trabajar siempre con el
// número en formato entero, sin considerarlo o 
// convertirlo a caracteres o cadena de caracteres
// y sin utilizar funciones como itoa o sprintf.

// Escribe un programa que solicite el número por
// teclado, llame a la función y muestre el 
// resultado obtenido por pantalla. Los mensajes 
// se han de mostrar tal y como aparecen en el 
// siguiente ejemplo de ejecución y en el mismo 
// orden (variando solo según los números 
// introducidos por el usuario).
 
// Lo que sigue es un ejemplo de 
// ejecución del programa:

// Introduce un número entero: 578913
// El número 578913 tiene 6 cifras. Su primera 
// cifra es el 5 y su última cifra es el 3.

// Otro ejemplo:

// Introduce un número entero: 75
// El número 75 tiene 2 cifras. Su primera 
// cifra es el 7 y su última cifra es el 5.

// Otro:

// Introduce un número entero: -289
// El número -289 tiene 3 cifras. Su primera 
// cifra es el 2 y su última cifra es el 9.

// Y otro:

// Introduce un número entero: -4
// El número -4 tiene 1 cifras. Su primera 
// cifra es el 4 y su última cifra es el 4.

#include  <stdio.h>
#include  <stdlib.h>
#include  <math.h>

int cifras(unsigned int num, int *primera, int *ultima)
{
  int res = 0;
  int prim = 0;
  int ult = 0;
  int temp = (int)num;
  
  if (temp < 0)
  {
    temp *= -1;
  }

  ult = temp % 10;
  
  if (ult < 0)
  {
    ult *= -1;
  }

  res = log10(temp);
  prim = temp / pow(10, res);
  
  if (prim < 0)
  {
    prim *= -1;
  }

  if ((temp / 10) < 10)
  {
    res++;
  }
  else
  {
    res += 1;
  }
  
  *ultima = (int)ult;
  *primera = (int)prim;
  
  return(res);
}


int main(void)
{
  int num = 0;
  int cantidad = 0;
  int p = 0;
  int u = 0;
  int *p_primera = malloc(sizeof(int));
  int *p_ultima  = malloc(sizeof(int));
  p_primera      = &p;
  p_ultima       = &u;

  printf("\nIntroduce un número entero: ");
  scanf("%d", &num);

  cantidad = cifras(num, p_primera, p_ultima);

  printf("\nEl número %d tiene %d cifras."
         "\nSu primera cifra es el %d y su última cifra es el %d\n\n.",
          num, cantidad, *(p_primera), *(p_ultima));

  return(0);
}

/*********************************************/


/*************** Ejercicio 3.1 ***************
// Escribe un programa que calcule la longitud de 
// una cadena de caracteres leída del teclado 
// utilizando un puntero a char para recorrer los 
// caracteres de la cadena. Fíjate en que con ella 
// vamos a imitar la funcionalidad de strlen().

// Recuerda que, si p apunta a un carácter de la 
// cadena, *p es el carácter y p++ apunta al 
// siguiente carácter.

// Este sería un ejemplo del programa:

// Introduce una cadena: supercalifragilisticoespialidoso
// supercalifragilisticoespialidoso tiene 32 caracteres.

// Y otro:

// Introduce una cadena: Recuerda que no puedes 
// guardar más de una palabra con scanf().
// Recuerda tiene 8 caracteres.

#include  <stdio.h>

#define   TAM 128

int main(void)
{
  char cadena[TAM];
  char *c;
  int cuenta = 0;

  printf("\nIntroduce una cadena: ");
  scanf("%s", cadena);
  printf("\n");

  for (c = cadena; *c != '\0'; cuenta++, c++)
  {
    printf("%c", *c);
  }

  printf(" ");
  printf("tiene %d caracteres.\n\n", cuenta);

  return(0);
}

/*********************************************/


/*************** Ejercicio 3.2 ***************
// Completa el siguiente programa para que 
// escriba en la pantalla el valor de los elementos 
// de cada una de las tablas (a y b) sin usar su 
// nombre, solo los punteros p y q. Para ello 
// necesitarás incrementar estos punteros.

// Esta sería la salida del programa:

// Lista a: 1 | Lista b: 1.20
// Lista a: 2 | Lista b: 3.10
// Lista a: 3 | Lista b: 2.50

#include <stdio.h>

#define TAM 3

int main(void) 
{
  int i, a[TAM]={1,2,3}, *p;
  double b[TAM]={1.2,3.1,2.5}, *q; 

  printf("\n");

  for (i = 0, p = a, q = b; i < TAM; p++, q++, i++)
  {
    printf("\nLista a: %d | Lista b: %.2lf\n", *p, *q);
  }
  
  printf("\n");

  return(0);

}

/*********************************************/


/*************** Ejercicio 3.3 ***************
// Escribe una función que incremente los elementos 
// de una tabla de enteros en una cierta cantidad 
// pasada como argumento pero fijado como macro. 
// En total la función ha de tener tres argumentos: 
// la tabla, la dimensión de la tabla y 
// el valor del incremento.

// En main declara e inicializa la tabla, muestra 
// el contenido de la tabla por pantalla, llama a 
// la función y vuelve a mostrar el contenido 
// de la tabla por pantalla.

// Este sería un ejemplo del programa con la macro 5:

// El contenido de la tabla es: 2 4 7
// El nuevo contenido de la tabla es: 7 9 12

// Otro ejemplo con la macro 42:

// El contenido de la tabla es 8 24 65
// El nuevo contenido de la tabla es: 50 66 107

#include  <stdio.h>

#define   DIM 3
// #define   INCREMENTO 5
#define   INCREMENTO 42

void incrementarTabla(int *pTabla, int dim, int incremento)
{
  for (int i = 0; i < dim; i++, pTabla++)
  {
    *pTabla += incremento;
  }
}

int main(void)
{
  int *p;
  // int tabla[DIM] = {2, 4, 7};
  int tabla[DIM] = {8, 24, 65};
  p = tabla;

  printf("\nEl contenido de la tabla es: %d %d %d\n", tabla[0], tabla[1], tabla[2]);

  incrementarTabla(p, DIM, INCREMENTO);

  printf("\nEl nuevo contenido de la tabla es: %d %d %d\n\n", tabla[0], tabla[1], tabla[2]);

  return(0);
}

/*********************************************/


/*********************************************
// Incrementa datos[i] por uno

#include <stdio.h>

#define DIM 3

void incrementa(int *p, int num) 
{
  int i;
  
  for (i=0; i<num; i++)
    p[i]++;
}

int main(void) 
{
  int i, datos[DIM] = {2,3,5};

  incrementa(datos+1, DIM-1);

  for (i=0; i<DIM; i++)
    printf("%d ", datos[i]);

  return(0);

}

/*********************************************/


/*********************************************
// Apendiendo caracteres al final de cadena

#include <stdio.h>
#include <string.h>

#define DIM 10

void agregar_txt(char *cadena) 
{
  int i = strlen(cadena);

  cadena[i] = '.';
  i++;
  cadena[i] = 't';
  i++;
  cadena[i] = 'x';
  i++;
  cadena[i] = 't';
  i++;
  cadena[i] = 0;

}

void minu_a_mayu(char *p) 
{
  for (; *p!= 0; p++)
    *p += 'A'-'a';
    // *p += 'a'+'A'; // Nope...
}

int main(void) 
{
  char nombre[DIM] = "data";

  // agregar_txt(nombre);
  minu_a_mayu(nombre);
  printf("\n%s\n\n", nombre+1);

  return(0);

}

/*********************************************/


/*************** Ejercicio 3.4 ***************
// Escribe una función que pase una cadena de 
// caracteres de minúsculas a mayúsculas, 
// devolviendo el tamaño de la cadena.

// El programa principal debe solicitar una 
// cadena al usuario, llamar a la función y 
// mostrar la cadena convertida por 
// pantalla junto con su tamaño.

// Puedes suponer que los usuarios 
// siempre introducirán por teclado 
// una cadena en minúsculas.

// Este sería un ejemplo del programa:

// Introduce una cadena de caracteres en 
// minúsculas: supercalifragilisticoespialidoso

// La cadena en mayúsculas 
// es SUPERCALIFRAGILISTICOESPIALIDOSO 
// y su tamaño 32.

// Y otro:

// Introduce una cadena: recuerda que no 
// puedes guardar más de una palabra con scanf()

// La cadena en mayúsculas es RECUERDA y su tamaño 8. 

#include <stdio.h>
#include <string.h>

#define DIM 128

int minu_a_mayu(char *cadena) 
{
  int res = strlen(cadena);

  for (; *cadena != 0; cadena++)
    *cadena += 'A'-'a';

  return(res);
}

int main(void)
{
  int  res = 0;
  char cadena[DIM];

  printf("\nIntroduce una cadena de caracteres en minúsculas: ");
  scanf("%s",cadena);

  res = minu_a_mayu(cadena);

  printf("\nLa cadena en mayúsculas es %s y su tamaño %d\n\n.",
          cadena, res);
          
  return(0);
}

/*********************************************/


/**************** Prueba 3.1 *****************/
// Escribe un programa con las 
// siguientes estructuras:

// Una estructura llamada Contacto con un campo 
// llamado nombre y otro llamado apellido.

// Una estructura llamada Agenda con un campo 
// para una tabla de hasta 100 contactos y otro 
// campo para un entero que almacene el número 
// de contactos guardados en la agenda.

// A continuación, escribe las siguientes funciones:

// La función con prototipo 
// void iniciarAgenda(Agenda *ag); 
// que inicialice a cero la variable que contiene 
// el número de contactos de la agenda.

// La función con prototipo 
// void addContacto(Agenda *ag, char *nom, char *apell); 
// que añada un nuevo contacto a la agenda.

// La función con prototipo 
// void mostrarAgenda(Agenda ag); 
// que muestre todos los contactos de la agenda por pantalla.

// En el programa principal declara una variable 
// de tipo Agenda llamada agenda, una cadena 
// de caracteres llamada nombre, una cadena de 
// caracteres llamada apellido, un entero llamado 
// i y un entero llamado num. 
// Después, realiza los siguietnes pasos:

// Llama a la función iniciarAgenda() 
// para inicializar el número de contactos a cero.

// Pregunta cuántos contactos se han de añadir 
// a la agenda (guardando el número en la variable num).

// Léelos (utilizando las variables nombre y apellido) 
// y guárdalos en la agenda mediante la función addContacto().

// Muestra todos los contactos introducidos por 
// pantalla utilizando la función mostrarAgenda().

// Lo que sigue es un ejemplo de ejecución del programa:

// ¿Cuántos contactos quieres guardar en la agenda?: 0
// ERROR: el valor debe estar entre 1 y 100.
// ¿Cuántos contactos quieres guardar en la agenda?: 102
// ERROR: el valor debe estar entre 1 y 100.
// ¿Cuántos contactos quieres guardar en la agenda?: 3
// Introduce el nombre del contacto 1: Daenerys
// Introduce el apellido del contacto 1: Targaryen
// Introduce el nombre del contacto 2: Jon
// Introduce el apellido del contacto 2: Snow
// Introduce el nombre del contacto 3: Cersei
// Introduce el apellido del contacto 3: Lannister

// Hay 3 contactos en la agenda:
// Contacto 1: Daenerys Targaryen
// Contacto 2: Jon Snow
// Contacto 3: Cersei Lannister

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


/*************** Ejercicio 0.0 ***************

#include  <stdio.h>

int main(void)
{
 
  return(0);
}

/*********************************************/


/**************** Prueba 0.0 *****************

#include  <stdio.h>

int main(void)
{
 
  return(0);
}

/*********************************************/


/*********************************************
// Simple Hash Map example
#include  <stdio.h>
#include  <stdlib.h>
#include  <stdint.h>
#include  <stdbool.h>
#include  <string.h>

#define   MAX_LEN     256
#define   TABLE_SIZE  10

typedef   struct
{
   char   name[MAX_LEN];
   int    age;
 
} Person;

void         init_hash_table(void);
void         print_table(void);
bool         ht_insert(Person *person);
Person       *ht_lookup(char *person);
unsigned int hash(char *person);

Person *hash_table[TABLE_SIZE];

int main(void)
{
  init_hash_table();
  
  Person person_0 = {"Name_A", 30};
  Person person_1 = {"Name_B", 40};
  Person person_2 = {"Name_C", 50};

  ht_insert(&person_0);
  ht_insert(&person_1);
  ht_insert(&person_2);
  
  print_table();
  
  Person *tmp = ht_lookup("Name_D");

  if (tmp == NULL)
  {
    printf("\nNot Found...\n");
  }
  else
  {
    printf("\nFound %s.\n\n", tmp->name);
  }

  tmp = ht_lookup("Name_B");

  if (tmp == NULL)
  {
    printf("\nNot Found...\n");
  }
  else
  {
    // printf("\nFound %s.\n\n", tmp->name);
  }


  return(0);
}

unsigned int hash(char *person)
{
  unsigned int hs;
  int length = strnlen(person, MAX_LEN);

  for (int i = 0; i < length; i++)
  {
    hs += person[i];
    hs = (hs * person[i]) % TABLE_SIZE;
  }

  return hs;
}

bool ht_insert(Person *person)
{
  if (person == NULL)
  {
    return false;
  }
  
  int index = hash(person->name);

  for (int i = 0; i < TABLE_SIZE; i++)
  {
    int try = (i + index) % TABLE_SIZE;
    
    if (hash_table[try] == NULL)
    {
      hash_table[try] = person;
      return true;
    }
  }

  return false;

}

void init_hash_table(void)
{
  for (int i = 0; i < TABLE_SIZE; i++)
  {
    hash_table[i] = NULL;
  }
}

void print_table(void)
{
  printf("Start->\n");
  for (int i = 0; i < TABLE_SIZE; i++)
  {
    if (hash_table[i] == NULL)
    {
      printf("\t%i\t-----\n", i);
    }
    else
    {
      printf("\t%i\t%s\n", i, hash_table[i]->name);
    }
  }
  printf("<-End\n");
}

Person  *ht_lookup(char *person)
{

  int index = hash(person);

  for (int i = 0; i < TABLE_SIZE; i++)
  {
    int attempt = (index + 1) % TABLE_SIZE;
    // continue here please
  }
}

Person  *ht_delete(char *person)
{

  int index = hash(person);

  if (hash_table[index] != NULL && strncmp(hash_table[index]->name, person, TABLE_SIZE) == 0)
  {
    return hash_table[index];
  }
  else
  {
    return NULL;
  }
}

/*********************************************/


/*********************************************
//Decimal to Binary

#include  <stdio.h>

int main(void)
{
  int a[10], i, j;
  printf("\n Please Enter the Number You want to Convert:  ");
  scanf("%d", &number);
    
  for (i = 0; num > 0; i++)
  {
    a[i] = num % 2;
    num = num / 2;
  }
    
  printf("\n Binary Number of a Given Number =  ");
  
  for (j = i - 1; j >= 0; j--)  
  {
    printf(" %d ", a[j]);
  }
  
  printf("\n");

  return(0);
}

/*********************************************/