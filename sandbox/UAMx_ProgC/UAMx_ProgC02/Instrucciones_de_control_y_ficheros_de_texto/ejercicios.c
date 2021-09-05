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


/*************** Ejercicio 1.5 ***************
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
#define   MAYOR 1
#define   IGUAL 0
#define   MENOR -1

int main(void)
{
  int fecha1[TAM];
  int fecha2[TAM];
  int fecha1Res;
  
  printf("\nPor favor, introduce la primera fecha: ");
  scanf("%d %d %d", &fecha1[0], &fecha1[1], &fecha1[2]);
  
  printf("Por favor, introduce la segunda fecha: ");
  scanf("%d %d %d", &fecha2[0], &fecha2[1], &fecha2[2]);
  
  if (fecha1[2] > fecha2[2])
  {
    fecha1Res = MAYOR;
  }
  else if (fecha1[2] < fecha2[2])
  {
    fecha1Res = MENOR;
  }
  else if (fecha1[2] == fecha2[2])
  {
    if (fecha1[1] > fecha2[1])
    {
      fecha1Res = MAYOR;
    }
    else if (fecha1[1] < fecha2[1])
    {
      fecha1Res = MENOR;
    }
    else if (fecha1[1] == fecha2[1])
    {
      if (fecha1[0] > fecha2[0])
      {
        fecha1Res = MAYOR;
      }
      else if (fecha1[0] < fecha2[0])
      {
        fecha1Res = MENOR;
      }
      else if (fecha1[0] == fecha2[0])
      {
        fecha1Res = IGUAL;
      }
    }
  }
  
  if (fecha1Res == MAYOR)
  {
    printf("\nLa fecha %d/%d/%d es anterior a %d/%d/%d\n\n",
            fecha2[0], fecha2[1], fecha2[2],
            fecha1[0], fecha1[1], fecha1[2]);
  }
  else if (fecha1Res == MENOR)
  {
    printf("\nLa fecha %d/%d/%d es anterior a %d/%d/%d\n\n",
            fecha1[0], fecha1[1], fecha1[2],
            fecha2[0], fecha2[1], fecha2[2]);
  }
  else if (fecha1Res == IGUAL)
  {
    printf("\nLas dos fechas son iguales\n\n");
  }
  else
  {
    printf("\nLa entrade fue erronea.\n\n");
  }
  
  return(0);
}

/*********************************************/


/*********************************************
// La instruccion switch y las enumeraciones

#include  <stdio.h>

int main(void)
{
  int opcion;

  printf("\nMenú:\n  1. Empezar partida\n  2. Ajustes\n  3. Ayuda\n  4. Salir\n");
  printf("Selecciona una opción: "); 
  scanf("%d", &opcion);

  switch (opcion)
  {
    case 1:          
      printf("Has elegido comenzar la partida.\n\n");
      break;
    case 2:          
      printf("Aquí estará el código para mostrar los ajustes del juego.\n\n");
      break;
    case 3:          
      printf("Aquí estará el código para mostrar la ayuda.\n\n");
      break;
    case 4:          
      printf("¡Hasta luego!\n\n");
      break;
    default:
      printf("Opción incorrecta.\n\n");
      break;
    // case 3:
    //     printf("Ant-Man");
    //     break;
    // default:
    //     printf("Black Widow");
    //     break;
    // case 2:
    // case 1:
    //     printf("Captain America");
    //     break;
    // case 4 ... 6:
    //     printf("Doctor Strange");
    //     break;
    }
    
  return(0);
}

/*********************************************/


/*************** Ejercicio 1.6 ***************
// Escribe un conversor de euros a varias monedas mediante la 
// instrucción switch. El programa ha de solicitar una cantidad
// en euros, que será traducida a la moneda seleccionada.

// A continuación, el programa debe presentar por 
// pantalla un menú como el que sigue:

// Selecciona una opción:
// 1. Dólar
// 2. Yen japonés
// 3. Libra esterlina

// El usuario podrá introducir 1, 2 o 3 y la opción 
// se leerá como un número entero.

// Este sería un ejemplo del programa:

// Introduce una cantidad en euros: 100
// Selecciona una opción:
// 1. Dólar
// 2. Yen japonés
// 3. Libra esterlina
// 2
// 100.00 euros son 10289.20 yenes.

#include  <stdio.h>
#define   CONVERSION_DOLAR 1.18785
#define   CONVERSION_YEN   130.309
#define   CONVERSION_LIBRA 0.856971

int main(void)
{
  int opcion;
  double cantidad;
  
  printf("\nIntroduce una cantidad en Euros: ");
  scanf("%lf", &cantidad);
  
  printf("\nSelecciona una opción:\n\n1.Dólar\n2.Yen japonés\n3.Libra esterlina\n");
  scanf("%d", &opcion);
  
  switch (opcion)
  {
    case 1:
      printf("\n%.2lf Euros son %.2lf Dólares.\n\n",
              cantidad, cantidad * CONVERSION_DOLAR);
      break;
    case 2:
      printf("\n%.2lf Euros son %.2lf Yenes.\n\n",
              cantidad, cantidad * CONVERSION_YEN);
      break;
    case 3:
      printf("\n%.2lf Euros son %.2lf Libras.\n\n",
              cantidad, cantidad * CONVERSION_LIBRA);
      break;
    default:
      printf("\nEntrada erronea.\n\n");
  }
 
  return(0);
}

/*********************************************/


/*************** Ejercicio 1.7 ***************
// Modifica el ejercicio anterior para trabajar con caracteres
// en la instrucción switch. Ahora el menú será de la forma:

// Selecciona una opción:
// (D)ólar
// (Y)en japonés
// (L)ibra esterlina

// El usuario podrá introducir D, Y o L en mayúscula o 
// minúscula, informando si la opción introducida no es correcta.

// Este sería un ejemplo del programa:

// Introduce una cantidad en euros: 100
// Selecciona una opción:
// (D)ólar
// (Y)en japonés
// (L)ibra esterlina
// y
// 100.00 euros son 10289.20 yenes.

#include  <stdio.h>
#define   CONVERSION_DOLAR 1.18785
#define   CONVERSION_YEN   130.309
#define   CONVERSION_LIBRA 0.856971

int main(void)
{
  char opcion;
  double cantidad;
  
  printf("\nIntroduce una cantidad en Euros: ");
  scanf("%lf", &cantidad);
  
  printf("\nSelecciona una opción:\n\n(D)ólar\n(Y)en Japonés\n(L)ibra esterlina\n");
  scanf("\n%c", &opcion);
  
  switch (opcion)
  {
    case 'D':
    case 'd':
      printf("\n%.2lf Euros son %.2lf Dólares.\n\n",
              cantidad, cantidad * CONVERSION_DOLAR);
      break;
    case 'Y':
    case 'y':
      printf("\n%.2lf Euros son %.2lf Yenes.\n\n",
              cantidad, cantidad * CONVERSION_YEN);
      break;
    case 'L':
    case 'l':
      printf("\n%.2lf Euros son %.2lf Libras.\n\n",
              cantidad, cantidad * CONVERSION_LIBRA);
      break;
    default:
      printf("\nEntrada erronea.\n\n");
  }
 
  return(0);
}

/*********************************************/


/*********************************************
// Enumeraciones

#include  <stdio.h>

enum
{
  jugar = 1,
  ajustes,
  ayuda,
  salir
};

int main(void)
{
  int opcion;

  printf("\nMenú:\n  1. Empezar partida\n  2. Ajustes\n  3. Ayuda\n  4. Salir\n");
  printf("Selecciona una opción: "); 
  scanf("%d", &opcion);

  switch (opcion)
  {
    case jugar:          
      printf("Has elegido comenzar la partida.\n\n");
      break;
    case ajustes:          
      printf("Aquí estará el código para mostrar los ajustes del juego.\n\n");
      break;
    case ayuda:          
      printf("Aquí estará el código para mostrar la ayuda.\n\n");
      break;
    case salir:          
      printf("¡Hasta luego!\n\n");
      break;
    default:
      printf("Opción incorrecta.\n\n");
      break;
    }
    
  return(0);
}

/*********************************************/


/*************** Ejercicio 1.8 ***************/
// Modifica el conversor de moneda con la opción 
// numérica para utilizar una enumeración en el switch.

// La salida del programa seguirá siendo la misma:

// Introduce una cantidad en euros: 100
// Selecciona una opción:
// 1. Dólar
// 2. Yen japonés
// 3. Libra esterlina
// 2
// 100.00 euros son 10289.20 yenes.

#include  <stdio.h>
#define   CONVERSION_DOLAR 1.18785
#define   CONVERSION_YEN   130.309
#define   CONVERSION_LIBRA 0.856971

enum
{
  dolar = 1,
  yen,
  libra
};

int main(void)
{
  int opcion;
  double cantidad;
  
  printf("\nIntroduce una cantidad en Euros: ");
  scanf("%lf", &cantidad);
  
  printf("\nSelecciona una opción:\n\n1. Dólar\n2. Yen Japonés\n3. Libra Esterlina\n");
  scanf("%d", &opcion);
  
  switch (opcion)
  {
    case dolar:
      printf("\n%.2lf Euros son %.2lf Dólares.\n\n",
              cantidad, cantidad * CONVERSION_DOLAR);
      break;
    case yen:
      printf("\n%.2lf Euros son %.2lf Yenes.\n\n",
              cantidad, cantidad * CONVERSION_YEN);
      break;
    case libra:
      printf("\n%.2lf Euros son %.2lf Libras.\n\n",
              cantidad, cantidad * CONVERSION_LIBRA);
      break;
    default:
      printf("\nEntrada erronea.\n\n");
  }
 
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


