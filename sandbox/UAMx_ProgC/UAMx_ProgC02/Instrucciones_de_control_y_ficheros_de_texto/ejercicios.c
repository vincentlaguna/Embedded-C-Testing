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


