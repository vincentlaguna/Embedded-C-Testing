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


/*************** Ejercicio 1.1 ***************/
Escribe un programa con una función que 
solicite la base y la altura de un triángulo
y muestre por pantalla su área.

La función main se encargará únicamente de 
llamar a esta función, y no declarará ninguna
variable ni tendrá ninguna otra instrucción.

Este sería un ejemplo del programa:

Introduce la base del triángulo: 12
Introduce la altura del triángulo: 7
El área del triángulo de base
12 y altura 7 es 42.00.

Y otro:

Introduce la base del triángulo: 37
Introduce la altura del triángulo: 10
El área del triángulo de base
37 y altura 10 es 185.00.

#include  <stdio.h>

int main(void)
{
  int base;
  int altura;
  double area;
  
  printf("\nIntroduce la base del triángulo: ");
  scanf("%d", &base);
  printf("\nIntroduce la altura del triángulo: ");
  printf("El área del triángulo de base %d y altura %d es %lf\n",
          );
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