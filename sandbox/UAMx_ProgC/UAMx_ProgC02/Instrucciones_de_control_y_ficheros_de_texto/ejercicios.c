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


/*************** Ejercicio 1.8 ***************
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


/**************** Prueba 1.1 ****************
// Declara una estructura llamada Fecha que contenga 
// tres miembros de tipo entero: dia, mes y anyo.

// Utiliza esa estructura en un programa que solicite
// la fecha de nacimiento de dos personas y las guarde
// en dos variables estructuradas.

// El programa ha de comparar las fechas e
// informar de los siguientes casos:

// Si ambos usuarios han nacido exactamente el mismo día.
// Si ambos usuarios comparten cumpleaños pero han nacido 
// en diferente año, cuántos años se llevan de diferencia.
// Si ambos usuarios no comparten cumpleaños.
// Los mensajes se han de mostrar tal y como aparecen
// en los siguientes ejemplos de ejecución y en el mismo 
// orden (variando solo según los datos introducidos por el usuario).

// Lo que sigue es un ejemplo de ejecución del programa:

// Introduce la fecha de nacimiento del primer usuario 
// separada por espacios: 17 2 1999
// Introduce la fecha de nacimiento del segundo usuario 
// separada por espacios: 17 2 1999
// ¡Felicidades! Ambos habéis nacido el mismo día.

// Lo que sigue es otro ejemplo de ejecución del programa:

// Introduce la fecha de nacimiento del primer usuario 
// separada por espacios: 17 2 1995
// Introduce la fecha de nacimiento del segundo usuario 
// separada por espacios: 17 2 1999
// Ambos cumplís años el mismo día. 
// Os lleváis -4 años de diferencia.

// Lo que sigue es otro ejemplo de ejecución del programa:

// Introduce la fecha de nacimiento del primer usuario 
// separada por espacios: 17 3 1999
// Introduce la fecha de nacimiento del segundo usuario 
// separada por espacios: 17 2 1999
// Vaya, no compartís cumpleaños.

#include  <stdio.h>
#include  <stdbool.h>

struct Fecha
{
  int dia;
  int mes;
  int anyo;
};

int main(void)
{
  struct Fecha fecha1, fecha2;
  int diferencia;
  bool mismoCumple     = false;
  bool mismoCumpleEdad = false;
  
  printf("\nIntroduce la fecha de nacimiento del "
         "primer usuario separada por espacios: ");
  scanf("%d %d %d", &fecha1.dia, &fecha1.mes, &fecha1.anyo);
  
  printf("\nIntroduce la fecha de nacimiento del "
         "segundo usuario separada por espacios: ");
  scanf("%d %d %d", &fecha2.dia, &fecha2.mes, &fecha2.anyo);
  
  if (fecha1.dia == fecha2.dia && fecha1.mes == fecha2.mes &&
      fecha1.anyo == fecha2.anyo)
  {
    mismoCumpleEdad = true;
  }
  else if (fecha1.dia == fecha2.dia && fecha1.mes == fecha2.mes)
  {
    mismoCumple = true;
    
    if (fecha1.anyo > fecha2.anyo)
    {
      diferencia = fecha1.anyo - fecha2.anyo;
    }
    else if (fecha1.anyo < fecha2.anyo)
    {
      diferencia = fecha2.anyo - fecha1.anyo;
    }
  }
  
  if (mismoCumpleEdad)
  {
    printf("\n¡Felicidades! Ambos habéis nacido el mismo día.\n\n");
  }
  else if (mismoCumple)
  {
    printf("\nAmbos cumplís años el mismo día. Os lleváis %d años "
           "de diferencia.\n\n", diferencia);
  }
  else
  {
    printf("\nVaya, no compartís cumpleaños.\n\n");
  }
  
  return(0);
}

/*********************************************/


/**************** Prueba 1.2 ****************
// El programa que debes escribir necesita un tipo de 
// dato estructurado que contenga tres miembros de tipo entero.

// El programa debe declarar una variable de este 
// tipo y solicitar al usuario tres números enteros, 
// que se deben guardar en los miembros de la variable estructurada.

// El programa ha de informar de cuál es el menor de los tres números.

// Los mensajes se han de mostrar tal y como aparecen 
// en los siguientes ejemplos de ejecución y en el mismo orden, 
// variando solo debido a los datos introducidos por el usuario.

// Lo que sigue es un ejemplo de ejecución:

// Introduce el primer número: 17
// Introduce el segundo número: 6
// Introduce el tercer número: 8
// El número 6 es el menor

// Lo que sigue es otro ejemplo de ejecución:

// Introduce el primer número: 2
// Introduce el segundo número: 2
// Introduce el tercer número: 4
// El número 2 es el menor

#include  <stdio.h>

struct Numeros
{
  int primer;
  int segundo;
  int tercer;
};

int main(void)
{
  struct Numeros numeros;
  int menor;
  
  printf("\nIntroduce el primer número: ");
  scanf("%d", &numeros.primer);
  
  printf("\nIntroduce el segundo número: ");
  scanf("%d", &numeros.segundo);
  
  printf("\nIntroduce el tercer número: ");
  scanf("%d", &numeros.tercer);
  
  if (numeros.primer <= numeros.segundo && numeros.primer <= numeros.tercer)
  {
    menor = numeros.primer;
  }
  else if (numeros.segundo <= numeros.primer && numeros.segundo <= numeros.tercer)
  {
    menor =  numeros.segundo;
  }
  else if (numeros.tercer <= numeros.primer && numeros.tercer <= numeros.segundo)
  {
    menor = numeros.tercer;
  }
  
  printf("\nEl número %d es el menor.\n\n", menor);
  
  return(0);
}

/*********************************************/


/*********************************************
// 2. El bucle while y do-while: while

#include  <stdio.h>

int main(void)
{
  int opcion;

  printf("\nMenú:\n  1. Empezar partida\n  2. Ajustes\n  3. Ayuda\n  4. Salir\n");
  printf("Selecciona una opción: "); 
  scanf("%d", &opcion);

  // if (opcion<1 || opcion>4)
  // {
  //   printf("\nOpción incorrecta. Inténtalo de nuevo: "); 
  //   scanf("%d", &opcion);
  // }
  
  while (opcion<1 || opcion>4) 
  {
    printf("\nOpción incorrecta. Inténtalo de nuevo: ");  
    scanf("%d", &opcion);
  }

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
    }
    
  return(0);
}

/*********************************************/


/*********************************************
// 2. El bucle while y do-while: while

#include  <stdio.h>

#define   DIM 3

int main(void)
{
  int i = 0;

    while(i < DIM)
    {
      printf("*******************\n");  
      i++;
    }
    
  return(0);
}

/*********************************************/


/*************** Ejercicio 2.1 ***************
// Escribe un programa que implemente el siguiente juego: 
// solicitará un número entero entre 0 y 9, que deberás 
// teclear sin mirar. Después el número desaparecerá de la
// pantalla (imprimiendo 10 saltos de línea, por ejemplo), 
// y después de preguntará por el número hasta que lo aciertes.

// Este sería un ejemplo de programa:

// Teclea la clave: 4

// ...10 líneas

// Adivina un número entre 0 y 9: 0
// Ese no es el número. Prueba otra vez: 1
// Ese no es el número. Prueba otra vez: 2
// Ese no es el número. Prueba otra vez: 3
// Ese no es el número. Prueba otra vez: 4
// ¡Número correcto!

#include  <stdio.h>
#define   DIM 10

int main(void)
{
  int clave;
  int numeroAdivinado;
  int i = 0;
  
  printf("\nTeclea la clave: ");
  scanf("%d", &clave);
 
  while (i < DIM)
  {
    printf("\n");
    i++;
  }
  
  printf("\nAdivina un número entre 0 y 9: ");
  scanf("%d", &numeroAdivinado);
  
  while (numeroAdivinado != clave)
  {
    printf("\nEse no es el número. Prueba otra vez: ");
    scanf("%d", &numeroAdivinado);
  }
  
  printf("\n¡Número correcto!\n\n");
  
  return(0);
}

/*********************************************/


/*************** Ejercicio 2.2 ***************
// Modifica el ejercicio anterior para mejorarlo haciendo
// que el programa te ayude en la búsqueda. Cada vez que 
// introduzcas un número, te indicará si es menor o mayor 
// que el que intentas adivinar. Además, para hacerlo 
// un poco más complejo, vamos a adivinar en el intervalo 0 - 99.

// Este sería un ejemplo de programa:

// Teclea la clave: 54

// ...10 líneas

// Adivina un número entre 0 y 99: 50
// Demasiado pequeño. Prueba otra vez: 75
// Demasiado grande. Prueba otra vez: 62
// Demasiado grande. Prueba otra vez: 56
// Demasiado grande. Prueba otra vez: 53
// Demasiado pequeño. Prueba otra vez: 54
// ¡Número correcto!

#include  <stdio.h>
#define   DIM 10

int main(void)
{
  int clave;
  int numeroAdivinado;
  int i = 0;
  
  printf("\nTeclea la clave: ");
  scanf("%d", &clave);
 
  while (i < DIM)
  {
    printf("\n");
    i++;
  }
  
  printf("\nAdivina un número entre 0 y 99: ");
  scanf("%d", &numeroAdivinado);
  
  while (numeroAdivinado != clave)
  {
    if (numeroAdivinado < clave)
    {
      printf("\nDemasiado pequeño. Prueba otra vez: ");
      scanf("%d", &numeroAdivinado);
    }
    else if (numeroAdivinado > clave)
    {
      printf("\nDemasiado grande. Prueba otra vez: ");
      scanf("%d", &numeroAdivinado);
    }
  }
  
  printf("\n¡Número correcto!\n\n");
  
  return(0);
}

/*********************************************/


/*********************************************
// 2. El bucle while y do-while: while

#include  <stdio.h>
#define   DIM 10

int main(void)
{
  int i = 0, suma = 0, total, tabla[DIM];

  printf("\n¿Cuántos números quieres sumar (entre 0 y %d)? ", DIM);
  scanf("%d", &total);

  while (i < total)
  {
    printf("Introduce un número: ");
    scanf("%d", &tabla[i]);
    suma += tabla[i];
    i++;
  }

  printf("\nLa suma de los %d números: ", total);

  i = 0;
  
  while (i < total)
  {
    printf("%d ", tabla[i]);
    i++;
  }

  printf("es %d.\n\n", suma);
  
  return(0);
}

/*********************************************/


/*************** Ejercicio 2.3 ***************
// Escribe un programa que inicialice en la declaración
// una tabla de enteros de tamaño 10 con los valores 
// que quieras. En nuestro ejemplo lo hemos hecho 
// con los números pares del 2 al 20.

// A continuación, el programa ha de solicitar al usuario
// que introduzca el número de valores que quiere que 
// se muestren por pantalla (del 1 al 10), 
// que se mostrarán después por pantalla.

// Esto sería un ejemplo del programa:

// ¿Cuántos elementos quieres mostrar por pantalla? 
// Elige un número entre 1 y 10: 4
// 2 4 6 8

// Y este, otro:

// ¿Cuántos elementos quieres mostrar por pantalla? 
// Elige un número entre 1 y 10: 7
// 2 4 6 8 10 12 14

#include  <stdio.h>

int main(void)
{
  int tabla[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
  int numero;
  int i = 0;
  
  printf("\n¿Cuántos elementos quieres mostrar por pantalla? \n"
        "Elige un número entre 1 y 10: ");
  scanf("%d", &numero);
  
  printf("\n");
  
  while (i < numero)
  {
    printf("%d ", tabla[i]);
    i++;
  }
  
  printf("\n\n");
  
  return(0);
}

/*********************************************/


/*********************************************
// 2. El bucle while y do-while: do-while

#include  <stdio.h>
#define   DIM 10

int main(void)
{
  int i=0, suma=0, total, tabla[DIM];

  do 
  {
    printf("\n¿Cuántos números quieres sumar (entre 0 y %d)? ", DIM);
    scanf("%d", &total);
  } while (total < 0 || total > DIM);

  while (i < total) 
  {
    printf("Introduce un número: ");
    scanf("%d", &tabla[i]);
    suma += tabla[i];
    i++;
  }

  printf("La suma de los %d números: ", total);

  i=0;
    
  while (i < total) 
  {
    printf("%d ", tabla[i]);
    i++;
  }

  printf("es %d.\n\n", suma);
  
  return(0);
}

/*********************************************/


/*************** Ejercicio 2.4 ***************
// Vamos a modificar el juego del ejercicio 2.3 paraque
// utilice un bucle do-while, en lugar de un bucle while.

// La salida del programa seguirá siendo la misma:
// Teclea la clave: 54

// ...10 líneas

// Adivina un número entre 0 y 99: 50
// Demasiado pequeño. Prueba otra vez: 75
// Demasiado grande. Prueba otra vez: 62
// Demasiado grande. Prueba otra vez: 56
// Demasiado grande. Prueba otra vez: 53
// Demasiado pequeño. Prueba otra vez: 54
// ¡Número correcto!

#include  <stdio.h>
#define   DIM 10

int main(void)
{
  int clave;
  int numeroAdivinado;
  int i = 0;
  
  printf("\nTeclea la clave: ");
  scanf("%d", &clave);
 
  while (i < DIM)
  {
    printf("\n");
    i++;
  }
  
  printf("\nAdivina un número entre 0 y 99: ");
  scanf("%d", &numeroAdivinado);
  
  do
  {
    if (numeroAdivinado < clave)
    {
      printf("\nDemasiado pequeño. Prueba otra vez: ");
      scanf("%d", &numeroAdivinado);
    }
    else if (numeroAdivinado > clave)
    {
      printf("\nDemasiado grande. Prueba otra vez: ");
      scanf("%d", &numeroAdivinado);
    }
    
  } while (numeroAdivinado != clave);
  
  printf("\n¡Número correcto!\n\n");
  
  return(0);
}

/*********************************************/


/*************** Ejercicio 2.5 ***************
// Vamos a modificar ahora el ejercicio 2.3 para que el 
// programa compruebe que el número introducido está
// comprendido entre 1 y 10. En caso contrario, 
// el programa informará de que el número introducido
// no es correcto y volverá a solicitar el número tantas
// veces como sea necesario, hasta que el número sea correcto. 
// Utiliza para esto un bucle do-while.

// Esto sería un ejemplo del programa:

// ¿Cuántos elementos quieres mostrar por pantalla?
// Elige un número entre 1 y 10: 42
// El número introducido no es correcto, vuelve a intentarlo: -4
// El número introducido no es correcto, vuelve a intentarlo: 4
// 2 4 6 8

// Y este, otro:

// ¿Cuántos elementos quieres mostrar por pantalla? 
// Elige un número entre 1 y 10: 7
// 2 4 6 8 10 12 14

#include  <stdio.h>
#define   DIM 10

int main(void)
{
  int tabla[DIM] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
  int numero;
  int i = 0;
  
  printf("\n¿Cuántos elementos quieres mostrar por pantalla? \n"
         "Elige un número entre 1 y 10: ");
  scanf("%d", &numero);
  
  printf("\n");
  
  do
  {
    if (numero < 0 || numero > DIM)
    {
      printf("\nEl número introducido no es correcto, vuelve a intentarlo: ");
      scanf("%d", &numero);
    }
    
    while (i < numero)
    {
      printf("%d ", tabla[i]);
      i++;
    }
      
  } while (numero < 0 || numero > DIM);
  
  printf("\n\n");
  
  return(0);
}

/*********************************************/


/*************** Ejercicio 2.6 ***************
// Vamos a escribir un programa bucles while y/o do-while,
// según consideres. Este programa tiene que solicite al 
// usuario cuántos números quiere leer por teclado (entre 2 y 10),
// leerlos y mostrar aquellos que sean menores al último introducido.

// Recuerda comprobar que el valor introducido por el usuario es correcto.

// Esto sería un ejemplo del programa:

// ¿Cuántos números quieres comparar? Elige un número entre 2 y 10: 11
// El número introducido no es correcto, vuelve a intentarlo: 4
// Introduce el número 1 de 4: 3
// Introduce el número 2 de 4: 7
// Introduce el número 3 de 4: 5
// Introduce el número 4 de 4: 6
// El número 5.00 es menor que el número 6.00
// El número 3.00 es menor que el número 6.00

// Y este, otro:

// ¿Cuántos números quieres comparar? Elige un número entre 2 y 10: 5
// Introduce el número 1 de 5: 5
// Introduce el número 2 de 5: 4
// Introduce el número 3 de 5: 3
// Introduce el número 4 de 5: 2
// Introduce el número 5 de 5: 1

#include  <stdio.h>
#define   DIM 10

int main(void)
{
  int i = 0;
  int numero;
  int tabla[DIM];
  
  printf("\n¿Cuántos números quieres comparar? Elige un número entre 2 y 10: ");
  scanf("%d", &numero);
  
  do
  {
    if (numero < 2 || numero > DIM)
    {
      printf("\nEl número introducido no es correcto, vuelve a intentarlo: ");
      scanf("%d", &numero);
    }
    
  } while (numero < 2 || numero > DIM);
  
  while (i < numero)
  {
    printf("\nIntroduce el número %d de %d: ", i+1, numero);
    scanf("%d", &tabla[i]);
    i++;
  }
  
  i = 0;
  
  while (i < numero)
  {
    if (tabla[i] < tabla[numero-1])
    {
      printf("\nEl número %d es menor que el número %d",
              tabla[i], tabla[numero-1]);
      i++;
    }
    else
    {
      i++;
    }
  }
  
  printf("\n\n");
  
  return(0);
}

/*********************************************/

/*************** Ejercicio 2.7 ***************
// Escribe un programa que solicite:

// Una cadena de caracteres en minúsculas. Puedes 
// considerar que el usuario siempre va a introducir
// una cadena en minúsculas y sin espacios.
// Un carácter en minúsculas
// Un carácter en mayúsculas
// Con dichos datos, el programa tendrá que mostrar:

// La cadena de caracteres en minúsculas, habiendo 
// cambiado el carácter en minúsculas introducido 
// por el usuario por el carácter en mayúsculas, si lo contiene.
// La cadena resultante, del revés.
// Recuerda que debes emplear bucles while y/o do-while,
// según consideres. Asimismo, es necesario realizar una
// comprobación de errores de los datos introducidos por el usuario.

// Esto sería un ejemplo del programa:

// Introduce una cadena de caracteres en minúsculas: 
// supercalifragilisticoespialidoso

// Introduce un carácter en minúculas: i
// Introduce un carácter en mayúsculas: W
// supercalWfragWlWstWcoespWalWdoso
// osodWlaWpseocWtsWlWgarfWlacrepus

// Y este, otro:

// Introduce una cadena de caracteres en minúsculas: sagas
// Introduce un carácter en minúsculas: 5
// Error, el carácter tiene que estar comprendido entre a y z. 
// Vuelve a intentarlo: F
// Error, el carácter tiene que estar comprendido entre a y z. 
// Vuelve a intentarlo: a
// Introduce un carácter en mayúsculas: 7
// Error, el carácter tiene que estar comprendido entre A y Z. 
// Vuelve a intentarlo: g
// Error, el carácter tiene que estar comprendido entre A y Z. 
// Vuelve a intentarlo: U
// sUgUs
// sUgUs

#include  <stdio.h>
#include  <string.h>
#include  <ctype.h>
#define   DIM 64

int main(void)
{
  int i = 0;
  char minuscula;
  char mayuscula;
  char cadena[DIM];
  
  printf("\nIntroduce una cadena de caracteres en minúsculas: ");
  scanf("%s", cadena);
  
  do
  {
    printf("\nIntroduce un carácter en minúsculas: ");
    scanf("\n%c", &minuscula);
  
    if (!(islower(minuscula)))
    {
      printf("\nError, el carácter tiene que estar comprendido entre a y z.\n"
             "Vuelve a intentarlo: ");
      scanf("\n%c", &minuscula);      
    }
  
  } while (!(islower(minuscula)));
  
  do
  {
    printf("\nIntroduce un carácter en mayúsculas: ");
    scanf("\n%c", &mayuscula);
  
    if (!(isupper(mayuscula)))
    {
      printf("\nError, el carácter tiene que estar comprendido entre A y Z.\n"
             "Vuelve a intentarlo: ");
      scanf("\n%c", &mayuscula);      
    }
  
  } while (!(isupper(mayuscula)));
  
  while (i < strlen(cadena))
  {
    if (cadena[i] == minuscula)
    {
      cadena[i] = mayuscula;
      i++;
    }
    i++;
  }
  
  printf("\n%s\n", cadena);
  
  while (i >= 0)
  {
    printf("%c", cadena[i]);
    i--;
  }
  
  printf("\n\n");
  
  return(0);
}

/*********************************************/


/**************** Prueba 2.1 ****************
// Escribe un programa en C que pida por teclado 
// dos palabras y las guarde en dos variables.
// A continuación crea y escriba en una nueva 
// variable una tercera palabra que tenga la 
// concatenación de las dos palabras introducidas, 
// pero la segunda con sus caracteres en orden inverso. 
// El programa ha de mostrar las palabras 
// originales y la nueva palabra por pantalla.

// Lo que sigue es un ejemplo de ejecución:

// Escribe la primera palabra: Certificado
// Escribe la segunda palabra: Profesional
// La palabra resultante de concatenar 
// Certificado y Profesional es: CertificadolanoiseforP

// Otro ejemplo:

// Escribe la primera palabra: Rick
// Escribe la segunda palabra: diculous
// La palabra resultante de concatenar 
// Rick y diculous es: Ricksuolucid

#include  <stdio.h>
#include  <string.h>
#define   DIM 64

int main(void)
{
  int  i;
  int  num = 0;
  int  tmp = 0;
  char palabra1[DIM];
  char palabra2[DIM];
  char palabra2reves[DIM];
  char resultado[DIM];
  
  printf("\nEscribe la primera palabra: ");
  scanf("%s", palabra1);
  
  printf("\nEscribe la segunda palabra: ");
  scanf("%s", palabra2);
  
  while (palabra2[num] != 0)
  {
    num++;
  }
  
  strcpy(palabra2reves, palabra2);
  
  while (i < num/2)
  {
    tmp = palabra2reves[i];
    palabra2reves[i] = palabra2reves[num - 1 - i];
    palabra2reves[num - 1 - i] = tmp;
    i++;
  }
  
  strcpy(resultado, palabra1);
  strcat(resultado, palabra2reves);
  
  printf("\nLa palabra resultante de concatenar %s y %s es: %s\n\n",
          palabra1, palabra2, resultado);
  
  return(0);
}

/*********************************************/


/**************** Prueba 2.2 ****************/
// Escribe un programa que lea números enteros del 
// teclado hasta que se lean 10 números o se introduzca 
// un 0, lo que ocurra antes. El programa guardará 
// dichos números en una tabla y los mostrará en orden
// inverso al que han sido introducidos.

// Para los bucles, emplea solo bucles while y/o do-while.

// Esto sería un ejemplo de ejecución:

// Introduzca un número entero (0 para terminar): 12
// Introduzca un número entero (0 para terminar): -6
// Introduzca un número entero (0 para terminar): 3
// Introduzca un número entero (0 para terminar): 0
// Los números tecleados son: 3 -6 12

// Otro ejemplo:

// Introduzca un número entero (0 para terminar): 0
// No se ha introducido ningún número.

// Un tercer ejemplo:

// Introduzca un número (0 para terminar): 3
// Introduzca un número (0 para terminar): 5
// Introduzca un número (0 para terminar): 9
// Introduzca un número (0 para terminar): -1
// Introduzca un número (0 para terminar): -5
// Introduzca un número (0 para terminar): 7
// Introduzca un número (0 para terminar): 8
// Introduzca un número (0 para terminar): 12
// Introduzca un número (0 para terminar): 17
// Introduzca un número (0 para terminar): 9
// Máximo de números alcanzado. Continuando...
// Los números tecleados son: 9 17 12 8 7 -5 -1 9 5 3

#include  <stdio.h>
#include  <string.h>
#define   DIM 10

int main(void)
{
  static int  i = 0;
  int  tabla[DIM];
  int  opcion;
  
  do  
  {
    if (i < DIM)
    {
      printf("\nIntroduzca un número entero (0 para terminar): ");
      scanf("%d", &opcion);
      
      tabla[i] = opcion;
      
      if (tabla[0] == 0)
      {
        printf("\nNo se ha introducido ningún número.\n\n");
        return(-1);
      }
      
    }
    else if (i >= DIM)
    {
      printf("\nMáximo de números alcanzado. Continuando...\n\n");
      tabla[i] = opcion;
      break;
    }
    i++;
    
  } while (opcion != 0 && i <= DIM);
  
  // if (i == 0)
  // {
  //   printf("\nNo se ha introducido ningún número.\n\n");
  //   return(-1);    
  // }
  // else
  // {
    printf("\nLos números tecleados son: ");
    
    --i;
    
    while (i >= 0)
    {
      printf("%d ", tabla[i]);
      i--;
    }
  // }
  
  printf("\n\n");
  
  return(0);
}


// #include  <stdio.h>
// #include  <string.h>
// #define   DIM 10

// int main(void)
// {
//   int  i = 0;
//   int  temp = 0;
//   int  suma = 0;
//   int  tabla[DIM];
//   int  opcion;
//   memset(tabla, 0, DIM);
  
//   do  
//   {
//     if (i < DIM)
//     {
//       printf("\nIntroduzca un número entero (0 para terminar): ");
//       scanf("%d", &opcion);
//       tabla[i] = opcion;  
//     }
//     else if (i >= DIM)
//     {
//       printf("\nMáximo de números alcanzado. Continuando...\n\n");
//       tabla[i] = opcion;
//       break;
//     }
//     i++;
    
//   } while (opcion != 0 && i <= DIM);
  
//   i -= 1;
//   temp = i;
  
//   while (tabla[temp-1] > 0)
//   {
//     if (tabla[temp] != 0)
//     {
//       suma += tabla[temp];
//       printf("\nSuma = %d\n", suma); // Debug...
//     }
//     temp--;
//   }
  
//   printf("\nSuma = %d\n", suma); // Debug...
//   printf("%d", sizeof(tabla / tabla[0]));
//   if (suma == 0)
//   {
//     printf("\nNo se ha introducido ningún número.\n\n");
//     return(-1);    
//   }
//   else
//   {
//     printf("\nLos números tecleados son: ");
    
//     while (i >= 0)
//     {
//       // if (tabla[i] == 0)
//       // {
//       //   printf("");
//       // }
//       // else
//       // {
//         printf("%d ", tabla[i]);
//         i--;
//       // }
//     }
    
//     printf("\n\n");
//   }
  
//   return(0);
// }

/*********************************************/


/*************** Ejercicio 0.0 ***************

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

