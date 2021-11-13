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


/*************** Ejercicio 1.3 ***************/

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