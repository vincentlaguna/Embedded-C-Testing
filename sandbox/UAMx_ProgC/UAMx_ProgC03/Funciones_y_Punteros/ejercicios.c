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


/**************** Prueba 1.1 *****************/
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

int comprobar_alpha(char primera_letra, char segunda_letra)
{
  
}

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

#include  <stdio.h>

int main(void)
{
  // start here tomorrow
 
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