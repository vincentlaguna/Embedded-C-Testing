// UAMx ProgC02

// Introducción a la programación en C: 
// Instrucciones de control y ficheros de texto

/*********************************************
// Operadores Logicos AND y OR

#include  <stdio.h>

int main(void)
{
  int x=3;
  
  printf("Recuerda: la operación devuelve 1 si se cumple (true) y 0 si no se cumple (false)\n");
  
  printf("El resultado de evaluar x>2 && x<=5 es: %d\n", x>2 && x<=5);

  printf("El resultado de evaluar x!=2 && x>4 es: %d\n", x!=2 && x>4);
   
  printf("El resultado de evaluar x>=2 || x>5 es: %d\n", x>=2 || x>5);   
   
  printf("El resultado de evaluar x>3 || x==2 es: %d\n", x>3 || x==2);
 
  return(0);
}

/*********************************************/


/*********************************************
// Operadores lógicos: múltiples condiciones

#include  <stdio.h>

int main(void)
{
  int x=3;
  
  printf("\nRecuerda: la operación devuelve 1 si se cumple (true) y 0 si no se cumple (false)\n");
  
  printf("El resultado de evaluar x==3 && x<2 && x%2==1 es: %d\n",
          x==3 && x<2 && x%2==1);

  printf("El resultado de evaluar x>=3 || (x<2 && x%2==0) es: %d\n",
          x>=3 || (x<2 && x%2==0));
  
  printf("El resultado de evaluar (x>=3 || x<2) && x%2==0 es: %d\n\n",
          (x>=3 || x<2) && x%2==0);
  
  return(0);
}

/*********************************************/


/************** Ejercicio 1.1/2 **************
// Escribe un programa que solicite tu edad y muestre 
// un 1 por pantalla si eres mayor de edad (18 años o más)
// o tu edad no es múltiplo de tres. En caso contrario,
// el programa mostrará un 0.

// Prueba qué se muestra si introduces los valores 15, 17, 20 y 21.

#include  <stdio.h>

int main(void)
{
  int edad;
  
  printf("\nQue edad tienes: ");
  scanf("%d", &edad);
  
  // printf("\nMayor de edad o no multiplo de 3:? (si=1, no=0): %d\n\n",
  //         edad >= 18 || (edad % 3 != 0));
  printf("\nMayor de edad y no es multiplo de 3:? (si=1, no=0): %d\n\n",
          edad >= 18 && (edad % 3 != 0));
  
  return(0);
}

/*********************************************/


/*********************************************

#include  <stdio.h>

int main(void)
{
  int altura;
  double peso, indice;
 
  printf("Introduce tu peso (kg): ");
  scanf("%lf", &peso);
  printf("Introduce tu altura (cm): ");
  scanf("%d", &altura);

  indice = 10000 * peso / (altura * altura);
  printf("Tu índice de masa corporal es %.2lf\n", indice);

  if (indice < 18.5)
    printf("Tienes bajo peso\n");
  else if (indice >= 25)
    printf("Tienes sobrepeso\n");
  else
    printf("Tienes sobrepeso\n");
  
  return(0);
}

/*********************************************/


/*************** Ejercicio 1.3 ***************
// Escribe un programa que compruebe si eres menor de edad y, 
// si es cierto, muestre el mensaje "Eres menor de edad".

// En caso de que seas mayor de edad, comprobará si tu edad 
// es múltiplo de tres y mostrará el mensaje 
// "Eres mayor de edad y tu edad es múltiplo de tres" o 
// "Eres mayor de edad y tu edad no es múltiplo de tres" 
// dependiendo de ello.

// Este sería un ejemplo del programa, escribiendo 15 como edad:

// Introduce tu edad: 15
// Eres menor de edad

// Otro ejemplo, escribiendo como edad 31:

// Introduce tu edad: 31
// Eres mayor de edad y tu edad no es múltiplo de tres

// Y otro, escribiendo 21:

// Introduce tu edad: 21
// Eres mayor de edad y tu edad es múltiplo de tres

#include  <stdio.h>

int main(void)
{
  int edad;
  
  printf("\nIntroduce tu edad: ");
  scanf("%d", &edad);
  
  if (edad >= 18)
  {
    if (edad % 3 == 0)
    {
      printf("Eres mayor de edad y tu edad es múltiplo de tres.\n\n");
    }
    else
    {
      printf("Eres mayor de edad y tu edad no es múltiplo de tres.\n\n");
    }
  }
  else
  {
    printf("Eres menor de edad.\n\n");
  }
  
  return(0);
}

/*********************************************/


/*************** Ejercicio 1.4 ***************
// Escribe un programa que solicite al usuario el nombre 
// de un mes en minúsculas (enero, febrero, ..., diciembre)
// y responda con un mensaje indicando el número de días 
// del mes especificado. Si el usuario introduce un 
// nombre de mes incorrecto, el programa también le informará.

// Utiliza operadores lógicos para agrupar los meses con el 
// mismo número de días dentro de la misma condición.

// Este sería un ejemplo del programa:

// Introduce el nombre de un mes: febrero
// febrero tiene 28/29 días

// Otro ejemplo:

// Introduce el nombre de un mes: marzo
// marzo tiene 31 días

// Y otro:

// Introduce el nombre de un mes: abril
// abril tiene 30 días

#include  <stdio.h>
#include  <string.h>
#define   TAM 12

const char *meses30[] = 
{
  "febrero",
  "abril",
  "junio",
  "septiembre",
  "noviembre"
};

const char *meses31[] = 
{
  "enero",
  "marzo",
  "mayo",
  "julio",
  "agosto",
  "octubre",
  "diciembre"
};

int main(void)
{
  char mes[TAM];
  
  printf("\nIntroduce un mes: ");
  gets(mes);
  
  if (strcmp(mes, meses30[0]) == 0)
  {
    printf("\n%s tiene 28/29 dias.\n\n", mes);
  }
  else
  {
    for (int i = 1; i < TAM; i++)
    {
      if (strcmp(mes, meses30[i]) == 0)
      {
        printf("\n%s tiene 30 dias.\n\n", mes);
      }
      else if (strcmp(mes, meses31[i]) == 0)
      {
        printf("\n%s tiene 31 dias.\n\n", mes);
      }
      else
      {
        printf("\nEntrada erronea.\n\n");
      }
    }
  }
  return(0);
}

/*********************************************/


/*************** Ejercicio 1.5 ***************/
// Vamos a escribir un programa un poco más complejo,
// que lea del teclado dos fechas en forma de día,
// mes y año separados por espacios en blanco.
// El programa debe mostrar un mensaje indicando cuál 
// de las dos es anterior, o si ambas coinciden.

// Este sería un ejemplo del programa:

// Por favor, introduce la primera fecha: 11 3 1972
// Por favor, introduce la segunda fecha: 24 2 1989
// La fecha 11/3/1972 es anterior a 24/2/1989

// Otro ejemplo:

// Por favor, introduce la primera fecha: 12 3 456
// Por favor, introduce la segunda fecha: 12 3 456
// Las dos fechas son iguales

// Y otro:

// Por favor, introduce la primera fecha: 3 2 2000
// Por favor, introduce la segunda fecha: 1 1 2000
// La fecha 1/1/2000 es anterior a 3/2/2000

#include  <stdio.h>
#define   TAM 3

int main(void)
{
  printf("\nPor favor, introduce la primera fecha: ");
  scanf("%d %d %d", &fecha1[0], &fecha1[1], &fecha1[2]);
  
  printf("\nPor favor, introduce la segunda fecha: ");
  scanf("%d %d %d", &fecha2[0], &fecha2[1], &fecha2[2]);
  
  printf("\nLa fecha %d/%d/%d es anterior a %d/%d/%d\n\n",)
  
  
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


