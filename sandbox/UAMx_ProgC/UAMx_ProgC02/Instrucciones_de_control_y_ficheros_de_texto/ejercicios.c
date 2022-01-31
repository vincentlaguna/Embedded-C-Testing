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


/**************** Prueba 2.2 ****************
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
  
  putchar('\n');
  
  do  
  {
    if (i < DIM)
    {
      printf("Introduzca un número entero (0 para terminar): ");
      scanf("%d", &opcion);
      
      tabla[i] = opcion;
      
      if (tabla[0] == 0)
      {
        printf("No se ha introducido ningún número.\n\n");
        return(-1);
      }
      
    }
    else if (i >= DIM)
    {
      printf("Máximo de números alcanzado. Continuando...\n");
      
      if (opcion != 0)
      {
        tabla[i] = opcion;
        break;  
      }
      else
      {
        break;
      }
    }
    i++;
    
  } while (opcion != 0 && i <= DIM);
  
  printf("Los números tecleados son: ");
  
  i--;
    
  while (i >= 0)
  {
    if (tabla[i] == 0)
    {
      putchar(' ');
    }
    else
    {
      printf("%d ", tabla[i]);
    }
    
    i--;
  }
  
  printf("\n\n");
  
  return(0);
}

/*********************************************/


/*************** Ejercicio 3.1 ***************
// Haz un programa que muestre la tabla de multiplicar 
// de un número (entre 1 y 9) introducido por el usuario.

// Esto sería un ejemplo del programa:

// Introduce un número entre 1 y 9: 5
// La tabla del 5 es:
// 5 por 1 es 5
// 5 por 2 es 10
// 5 por 3 es 15
// 5 por 4 es 20
// 5 por 5 es 25
// 5 por 6 es 30
// 5 por 7 es 35
// 5 por 8 es 40
// 5 por 9 es 45
// 5 por 10 es 50

// Y este, otro:

// Introduce un número entre 1 y 9: 9
// La tabla del 9 es:
// 9 por 1 es 9
// 9 por 2 es 18
// 9 por 3 es 27
// 9 por 4 es 36
// 9 por 5 es 45
// 9 por 6 es 54
// 9 por 7 es 63
// 9 por 8 es 72
// 9 por 9 es 81
// 9 por 10 es 90


#include  <stdio.h>

#define   DIM 10

int main(void)
{
  
  int i;
  int numero;
  
  printf("\nIntroduce un número entre 1 y 9: ");
  scanf("%d", &numero);
  printf("\nLa tabla del %d es:\n", numero);
  
  
  for (i = 1; i <= DIM; i++)
  {
    printf("%d por %d es: %d\n", numero, i, numero * i);
  }
  putchar('\n');
  
  return(0);
}

/*********************************************/


/*************** Ejercicio 3.2 ***************
// Escribe un programa que solicite por teclado una cadena de 
// caracteres sin espacios y muestre por pantalla el tamaño de 
// la cadena y la posición intermedia. A continuación, guardará
// en otra cadena la segunda mitad de la cadena original 
// (esto es, desde la posición intermedia hasta el final) 
// y la mostrará por pantalla.

// Para este programa, puedes suponer que el usuario siempre
// va a introducir una cadena sin espacios y que su tamaño 
// nunca va a superar al que hayas establecido.

// Esto sería un ejemplo:

// Introduce una cadena de caracteres: wubalubadubdub
// La cadena camino tiene una longitud de
// 14 caracteres y la mitad es la posición 7.
// La segunda mitad de la cadena wubalubadubdub es adubdub.

// Y este, otro:

// Introduce una cadena de caracteres: supercalifragilisticoespialidoso
// La cadena camino tiene una longitud de 32 
// caracteres y la mitad es la posición 16.
// La segunda mitad de la cadena 
// supercalifragilisticoespialidoso es sticoespialidoso.

#include  <stdio.h>
#include  <string.h>

#define   DIM 64

int main(void)
{
  
  int   i;
  int   longitud;
  int   mitad;
  char  palabra[DIM];
  static char  palabra1[DIM];
  
  printf("\nIntroduce una cadena de caracteres: ");
  gets(palabra);
  longitud = strlen(palabra);
  mitad  = longitud / 2;
  printf("\nLa cadena %s tiene una longitud de %d "
         "caracteres y la mitad es la posicion %d.\n",
          palabra, longitud, mitad);
         
  printf("\nLa segunda mitad de la cadena %s es ", palabra);
  
  for (i = mitad; i <= longitud-1; i++)
  {
    printf("%c", palabra[i]);
  }

  
  puts(".\n");
  
  return(0);
}

/*********************************************/


/*********************************************

#include  <stdio.h>
#include  <stdlib.h>
#include  <math.h> // Link -lm when compiling (GCC)

// double sqrt(double num)
// {
//   for (double i = 2.00; i <= num; i++)
//     if ((i * i) == num)
//       return i;
// }

int main(void)
{

  int i, num, esPrimo;

  printf("\nIntroduce un número entero: ");
  scanf("%d", &num);

  for (i=2; i <= sqrt(num) && esPrimo == 1; i++)
    if (num%i == 0)
    {
      // esPrimo = 0;
      break;
    }
    
  if (esPrimo)
    printf("\n%d es primo.\n\n", num);
  else
    printf("\n%d no es primo\n\n", num);

  return(0);
}

/*********************************************/


/*************** Ejercicio 3.3 ***************
// Escribe un programa que utilice un bucle para 
// leer hasta 10 números enteros del teclado 
// o que pare de solicitar números si se introduce 0 
// (utiliza la instrucción break para esta situación).

// El programa sumará únicamente los números que sean 
// positivos, los negativos no se considerarán para 
// la suma. Antes de terminar el programa mostrará 
// la suma total obtenida, indicando además cuántos 
// números se han leído en total (sin contar el 0)
// y cuántos de ellos eran negativos.

// Esto sería un ejemplo del programa:

// Introduce un número: 4
// Introduce un número: -2
// Introduce un número: 5
// Introduce un número: -6
// Introduce un número: -11
// Introduce un número: 0
// Se han leído un total de 5 números, 
// de los cuales 3 eran negativos.
// La suma de los 2 valores positivos leídos es: 9.

// Y este, otro:

// Introduce un número: 10
// Introduce un número: -9
// Introduce un número: 8
// Introduce un número: -7
// Introduce un número: 6
// Introduce un número: -5
// Introduce un número: 4
// Introduce un número: -3
// Introduce un número: 2
// Introduce un número: -1
// Se han leído un total de 10 números, 
// de los cuales 5 eran negativos.
// La suma de los 5 valores positivos leídos es: 30.

#include  <stdio.h>

#define   DIM 10

int main(void)
{
  
  int i, j;
  int cadena[DIM];
  static int suma = 0;
  int total = 0;
  int negativos = 0;
  static int cuentaPos = 0;
  static int positivos[DIM];
  
  putchar('\n');
  
  for (i = 0; i <= DIM; i++)
  {
    printf("Introduce un número: ");
    scanf("%d", &cadena[i]);
    
    if (cadena[i] < 0)
    {
      negativos++;
      total++;
    }
    else if (cadena[i] > 0)
    {
      positivos[i] = cadena[i];
      suma += positivos[i];
      cuentaPos++;
      total++;
    }
    else
      break;
  }

  printf("\nSe han leído un total de %d números, " 
         "de los cuales %d eran negativos. "
         "La suma de los %d valores positivos "
         "leídos es: %d.\n\n", 
          total, negativos, cuentaPos, suma);
          
  return(0);
}

/*********************************************/


/*************** Ejercicio 3.4 ***************
// Vamos a modificar la prueba 2.2 para utilizar 
// bucles for en vez de while. Recuerda, 
// el programa lee números enteros del teclado
// hasta que se lean 10 números o se introduzca
// un 0, lo que ocurra antes, guardando dichos
// números en una tabla y mostrándolos en 
// orden inverso al que han sido introducidos.

// Este sería un ejemplo de programa:

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
  int     tabla[DIM];
  int     opcion;
  static  int i;
  
  putchar('\n');
  
  for (i = 0; i < DIM; i++)
  {
    printf("Introduzca un número entero (0 para terminar): ");
    scanf("%d", &opcion);
    
    tabla[i] = opcion;
    
    if (tabla[0] == 0)
    {
      printf("No se ha introducido ningún número.\n\n");
      return(-1);
    }
    else if (tabla[i] == 0)
      break;
  }
  
  if (i == DIM)
    printf("Máximo de números alcanzado. Continuando...\n");
  
  printf("Los números tecleados son: ");
  
  
  for (; i >= 0; i--)
  {
    if (tabla[i] == 0)
      putchar(' ');
    else
      printf("%d ", tabla[i]);
  }

  printf("\n\n");
  
  return(0);
}

/*********************************************/


/*************** Ejercicio 3.5 ***************
// Si alguna vez te has preguntado cómo se 
// representan los números decimales en binario, 
// en este ejercicio vamos a crear un programa que 
// lo lleve a cabo. Pero no pienses que es tan 
// difícil que se necesita un ordenador, 
// simplemente con papel y boli podrías calcularlo.

// Los pasos que seguimos para calcular un número
// binario son dividir el número en base 10 por 2. 
// De dicha operación, utilizamos el cociente como
// nuevo divisor y el resto nos lo guardamos, 
// pues formará parte del número binario. 
// Seguimos dividiendo los cocientes resultante 
// por 2 hasta que obtengamos un 1, siendo el 
// último resto el correspondiente con el primer 
// número de la cifra binaria. Puedes consultar 
// un ejemplo en esta página de educalab.

// Ahora te toca escribir un programa que lea por 
// teclado un número entero positivo en base 10 y 
// lo convierta a binario. La conversión se 
// realizará sobre una tabla de enteros, 
// guardando el número binario en orden inverso 
// pero mostrándolo en orden correcto.

// Como condición para tu programa, es necesario 
// que utilices bucles for cuando necesites 
// recorrer alguna tabla de tu código.

// Esto sería un ejemplo del programa:

// Introduce un entero positivo: 5
// El número convertido a binario es: 101

// Y este, otro:

// Introduce un entero positivo: 23
// El número convertido a binario es: 10111

#include  <stdio.h>

#define   DIM 16
#define   DIVISOR 2

int main(void)
{
  int i;
  int j;
  int numero;
  int resultado[DIM];
  
  printf("\nIntroduce un entero positivo: ");
  scanf("%d", &numero);
  
  for (i = DIM; i >= 0; i--)
  {
    if (numero % 2 == 0)
    {
      resultado[i] = 0;
      numero /= DIVISOR;
    }
    else
    {
      resultado[i] = 1;
      numero /= DIVISOR;
    }
  }
  
  printf("\nEl número convertido a binario es: ");
  
  for (i = 0; i <= DIM; i++)
  {
    if (resultado[i] == 1)
    {
      j = i;
      break;
    }
  }
      
  for (; j <= DIM; j++)
    printf("%d", resultado[j]);
    
  printf("\n\n");
  
  return(0);
}

/*********************************************/


/*************** Ejercicio 3.6 ***************
// Utiliza bucles anidados para imprimir las tablas
// de multiplicar de los números del 1 al 9.

// Esta sería la salida del programa:

// La tabla del 1 es:
// 1 por 1 es 1
// 1 por 2 es 2
// 1 por 3 es 3
// 1 por 4 es 4
// 1 por 5 es 5
// 1 por 6 es 6
// 1 por 7 es 7
// 1 por 8 es 8
// 1 por 9 es 9
// 1 por 10 es 10

// [Resto de tablas...]

// La tabla del 9 es:
// 9 por 1 es 9
// 9 por 2 es 18
// 9 por 3 es 27
// 9 por 4 es 36
// 9 por 5 es 45
// 9 por 6 es 54
// 9 por 7 es 63
// 9 por 8 es 72
// 9 por 9 es 81
// 9 por 10 es 90

#include  <stdio.h>

#define   DIM 10

int main(void)
{
  int i, j;
  
  for (i = 1; i < DIM; i++)
  {
    printf("\nLa tabla del %d es: \n", i);
    
    for (j = 1; j <= DIM; j++)
    {
      printf("%d por %d es %d\n", i, j, i * j);
    }
  }
  
  putchar('\n');
  
  return(0);
}

/*********************************************/


/*************** Ejercicio 3.7 ***************
// Vamos a modificarel ejercicio anterior (2.6) 
// para imprimir las tablas de multiplicar de los 
// números del 1 al 9 desde el 1 hasta el 
// número la que corresponda la tabla.

// Esta sería la salida del programa:

// La tabla del 1 hasta el número 1 es:
// 1 por 1 es 1

// La tabla del 2 hasta el número 2 es:
// 2 por 1 es 2
// 2 por 2 es 4

// La tabla del 3 hasta el número 3 es:
// 3 por 1 es 3
// 3 por 2 es 6
// 3 por 3 es 9

// [Resto de tablas...]

// La tabla del 9 hasta el número 9 es:
// 9 por 1 es 9
// 9 por 2 es 18
// 9 por 3 es 27
// 9 por 4 es 36
// 9 por 5 es 45
// 9 por 6 es 54
// 9 por 7 es 63
// 9 por 8 es 72
// 9 por 9 es 81

#include  <stdio.h>

#define   DIM 10

int main(void)
{
  int i, j;
  
  for (i = 1; i < DIM; i++)
  {
    printf("\nLa tabla del %d es: \n", i);
    
    for (j = 1; j <= i; j++)
    {
      printf("%d por %d es %d\n", i, j, i * j);
    }
  }
  
  putchar('\n');
  
  return(0);
}

/*********************************************/


/*********************************************
// Bluces Anidados
#include  <stdio.h>

#define   FIL 2
#define   COL 3

int main(void)
{
  int i, j;
  int matriz[FIL][COL] = 
  {
    {1,4,2},
    {3,5,9}
  };
  
  for (i = 0; i < FIL; i++)
  {
    for (j = 0; j < COL; j++)
    {
      printf("%d ", matriz[0][0]);
    }
    printf("\n");
  }
  
  return(0);

}

/*********************************************/


/*************** Ejercicio 3.8 ***************
// Escribe un programa que muestre, utilizando
// bucles anidados, la suma de dos matrices
// 3x3 de números enteros.

// Habiendo inicializado en la 
// declaración las matrices como:

// int a[3][3]={{1,2,3},{4,5,6},{7,8,9}};
// int b[3][3]={0,1,2,4,2,3,1,4,5};

// Esto sería el resultado del programa:

// 1   3   5
// 8   7   9
// 8  12  14

#include  <stdio.h>

#define   DIM 3

int main(void)
{
  int i, j;
  
  int a[DIM][DIM] =
  {
    {1,2,3},
    {4,5,6},
    {7,8,9}
    
  };

  int b[DIM][DIM] =
  {
    {0,1,2},
    {4,2,3},
    {1,4,5}
  };
  
  printf("\n");
  
  for (i = 0; i < DIM; i++)
  {
    for (j = 0; j < DIM; j++)
    {
      printf("%d  ", (a[i][j] + b[i][j]));
    }
    printf("\n");
  }

  printf("\n");
  
  return(0);
}

/*********************************************/


/**************** Prueba 3.1 *****************
// Escribe un programa en C que solicite 
// exactamente por teclado tantos números como 
// se especifiquen en una macro 
// (del tamaño que consideres) y guárdalos en 
// una tabla del tamaño de la macro.

// A continuación, por cada número introducido,
// el programa mostrará cuántos de los números 
// introducidos después son mayores que él.

// El programa ha de ser genérico para cualquier 
// valor de la macro. Si por ejemplo, 
// se cambiara el valor a 7, funcionaría 
// exactamente igual con siete números sin hacer 
// ninguna otra modificación en el código.

// Lo que sigue es un ejemplo de ejecución
// con una macro definida con 5:

// Introduce el número 1: 2
// Introduce el número 2: 7
// Introduce el número 3: 1
// Introduce el número 4: 4
// Introduce el número 5: 5
// El número 2 es menor que otros 3 números posteriores.
// El número 7 es menor que otros 0 números posteriores.
// El número 1 es menor que otros 2 números posteriores.
// El número 4 es menor que otros 1 números posteriores.
// El número 5 es menor que otros 0 números posteriores.
// Otro ejemplo:

// Introduce el número 1: 3
// Introduce el número 2: 12
// Introduce el número 3: 9
// Introduce el número 4: 4
// Introduce el número 5: 8
// Introduce el número 6: 1
// Introduce el número 7: 7
// El número 3 es menor que otros 5 números posteriores.
// El número 12 es menor que otros 0 números posteriores.
// El número 9 es menor que otros 0 números posteriores.
// El número 4 es menor que otros 2 números posteriores.
// El número 8 es menor que otros 0 números posteriores.
// El número 1 es menor que otros 1 números posteriores.
// El número 7 es menor que otros 0 números posteriores.

#include  <stdio.h>
#define   DIM 7

int main(void)
{
  int i, j, x;
  int numeros[DIM];
  int resultados[DIM] = {0};
  printf("\n");
  for (i = 0; i < DIM; i++)
  {
    printf("Introduce el número %d: ", i+1);
    scanf("%d", &numeros[i]);
  }
  for (i = 0; i < DIM; ++i)
  {
    for (j = 0; j < DIM; ++j)
    {
      if (numeros[i] < numeros[j])
      {
        resultados[i]++;
      }
      else if (numeros[i] == numeros[j])
      {
        resultados[i] = 0;
      }
    }
  }
  for (i = 0; i < DIM; i++)
  {
    printf("El número %d es menor que otros %d números posteriores\n",
            numeros[i], resultados[i]);
  }
  printf("\n");
  return(0);
}

/*********************************************/


/**************** Prueba 3.2 *****************
// Escribe un programa en C que solicite por 
// teclado una cadena de caracteres y guárdala en
// una variable del tamaño 128 (utiliza macros).

// Para simplificar, puedes asumir que el usuario va
// a introducir el carácter '_' en lugar de espacios.

// A continuación, para cada carácter de la cadena, 
// el programa mostrará por pantalla todas las 
// vocales minúsculas anteriores a dicho carácter.

// Lo que sigue es un ejemplo de ejecución:

// Escribe una cadena de caracteres: Hola_mundo
// las vocales anteriores al caracter H son:
// las vocales anteriores al caracter o son:
// las vocales anteriores al caracter l son: o
// las vocales anteriores al caracter a son: o
// las vocales anteriores al caracter _ son: o a
// las vocales anteriores al caracter m son: o a
// las vocales anteriores al caracter u son: o a
// las vocales anteriores al caracter n son: o a u
// las vocales anteriores al caracter d son: o a u
// las vocales anteriores al caracter o son: o a u

// Otro ejemplo:

// Escribe una cadena de caracteres: Yo_soy_tu_padre
// Las vocales anteriores al caracter Y son:                          
// Las vocales anteriores al caracter o son:                          
// Las vocales anteriores al caracter _ son: o                        
// Las vocales anteriores al caracter s son: o                        
// Las vocales anteriores al caracter o son: o                        
// Las vocales anteriores al caracter y son: o o                      
// Las vocales anteriores al caracter _ son: o o                      
// Las vocales anteriores al caracter t son: o o                      
// Las vocales anteriores al caracter u son: o o                      
// Las vocales anteriores al caracter _ son: o o u                    
// Las vocales anteriores al caracter p son: o o u                    
// Las vocales anteriores al caracter a son: o o u                    
// Las vocales anteriores al caracter d son: o o u a                  
// Las vocales anteriores al caracter r son: o o u a                  
// Las vocales anteriores al caracter e son: o o u a

#include  <stdio.h>
#include  <string.h>

#define   TAM  128
#define   TAMV 5

int main(void)
{
  int i, j, x;
  int tam;
  static int contador = 0;
  char cadena[TAM] = {'\0'};
  char cadenaV[TAM] = {'\0'};
  char vocales[] = {'a', 'e', 'i', 'o', 'u'};
  
  printf("\nEscribe una cadena de caracteres: ");
  scanf("%s", cadena);
  
  tam = strlen(cadena);
  
  putchar('\n');

  for (i = 0; i < tam; ++i)
  {
    printf("Las vocales anteriores al caracter %c son: ", cadena[i]);
    if (!(i <= 0))
    {
      for (x = 0; x < strlen(cadenaV); ++x)
      {
        printf("%c ", cadenaV[x]);
      }
    }
    for (j = 0; j < TAMV; ++j)
    {
      if (!(i <= 0))
      {
        if (cadena[i] == vocales[j])
        {
          cadenaV[contador] = vocales[j];
          contador++;
        }
      }
    }
    putchar('\n');
  }
  putchar('\n'); 
  return(0);
}

/*********************************************/


/*********************************************
// 4. Archivos de Texto

#include  <stdio.h>

int main(void)
{
  FILE    *ficha;
  char    dni[10];
  int     modelo, i;
  double  nota, media;

  ficha = fopen("notas.txt", "r");

  if (ficha == NULL)
  {
    printf("Error abriendo el archivo.\n");
    return (-1);
  }

  for (i = 0, media = 0.0; fscanf(ficha, "%s", dni) == 1; i++)    
  {
    fscanf(ficha, "%d", &modelo);
    fscanf(ficha, "%lf", &nota);
    media += nota;
  }

  printf("\nLa nota media es = %.2lf\n\n", media / i);

  fclose(ficha);

  return(0);  
}

/*********************************************/


/*************** Ejercicio 4.1 ***************
// Escribe un programa que lea este archivo 
// de texto, que contiene los resultados de las 
// calificaciones de un examen tipo test. 
// Cada línea se compone de: identificador del 
// estudiante, modelo, número de aciertos, 
// número de fallos, número de respuestas 
// en blanco y calificación.

// Tras la lectura, tendrá que calcular por 
// separado la nota media de los 
// estudiantes del modelo 1 y del modelo 2.

// Según el fichero notas.txt especificado, 
// esta sería la salida del programa:

// La nota media del modelo 1 es: 7.235
// La nota media del modelo 2 es: 7.170

#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>

typedef struct 
{
  // Datos
  int estudiante;
  int modelo;
  int aciertos;
  int fallos;
  int blancos;
  double calificacion;

} Notas;


int main(void)
{
  FILE  *ficha;
  Notas *notas;

  int    i;
  double media1;
  double media2;
  static int contador1, contador2 = 0;

  notas = (Notas *)malloc(sizeof(Notas));
  memset(notas, 0, sizeof(Notas));


  ficha = fopen("notas1.txt", "r");

  if (ficha == NULL)
  {
    printf("Error abriendo el archivo.\n");
    return (-1);
  }

  for (i = 0; fscanf(ficha, "%d", &notas->estudiante) == 1; i++)    
  {
    fscanf(ficha, "%d", &notas->modelo);
    fscanf(ficha, "%d", &notas->aciertos);
    fscanf(ficha, "%d", &notas->fallos);
    fscanf(ficha, "%d", &notas->blancos);
    fscanf(ficha, "%lf", &notas->calificacion);    
    
    if (notas->modelo == 1)
    {
      media1 += notas->calificacion;
      contador1++;
    }
    else if (notas->modelo == 2)
    {
      media2 += notas->calificacion;
      contador2++;
    }
    
  }


  printf("\nLa nota media del modelo 1 es = %.3lf\n",
          media1 / contador1);
  printf("La nota media del modelo 2 es = %.3lf\n\n",
          media2 / contador2);

  fclose(ficha);

  return(0);
}

/*********************************************/


/*********************************************
// 4. Escribiendo a una ficha

#include  <stdio.h>

#define   NUM_ESTUD 3
#define   MAX_DNI   10

typedef struct 
{
  // Datos
  char    dni[10];
  int     modelo;
  double  nota;

} Notas;

int main(void)
{
  FILE  *ficha;
  Notas  notas[NUM_ESTUD] = 
  {
    { "96545675Z", 1, 4.34 },
    { "96345645D", 1, 7.2 },
    { "94236532G", 2, 6.56 }
  };

  int    i;

  ficha = fopen("escrito.txt", "w");

  if (ficha == NULL)
  {
    printf("Error abriendo el archivo.\n");
    return (-1);
  }

  for (i = 0; i < NUM_ESTUD; i++)    
  {
    fprintf(ficha, "%s %d %.2lf\n",
            notas[i].dni, notas[i].modelo, notas[i].nota);
  }

  fclose(ficha);

  return(0);
}

/*********************************************/


/*************** Ejercicio 4.2 ***************
// Escribe un programa que lea el archivo de 
// calificaciones y genere un nuevo archivo 
// llamado listado.txt que contenga una línea
// por estudiante con la siguiente información: 
// DNI, calificación numérica y 
// calificación alfabética.

// La calificación alfabética será:

// Suspenso si la nota es menor que 5.
// Aprobado si la nota es mayor o igual que 5 y 
// menor que 7.
// Notable si la nota es mayor o igual que 7 y 
// menor que 9.
// Sobresaliente si la nota es mayor o igual que
// 9 y menor que 10.
// Matrícula si la nota es igual a 10.
// Las dos primeras filas del archivo generado
// salida serán:

// 02289512 8.095 notable
// 02667819 3.810 suspenso

#include  <stdio.h>

#define   TAM        256
#define   TAM_NOMBRE 32

typedef   struct 
{
  // Datos
  int     estudiante;
  int     modelo;
  int     aciertos;
  int     fallos;
  int     blancos;
  double  calificacion;

} Notas;

static const char *const calificacion[] =
{
  "Suspenso",
  "Aprobado",
  "Notable",
  "Sobresaliente",
  "Matrícula"
};

enum
{
  Suspenso,
  Aprobado,
  Notable,
  Sobresaliente,
  Matricula
};

int main(void)
{
  FILE     *fEntrada, *fListado;
  Notas    notas[TAM];
  char     entrada[TAM_NOMBRE] = "calificaciones.txt";
  char     listado[TAM_NOMBRE] = "listado.txt";
  int      i, j;
  int      nota = 0;

  if ((fEntrada = fopen(entrada, "r")) == NULL)
  {
    printf("Error abriendo el archivo %s.\n", entrada);
    return (-1);
  }

  if ((fListado = fopen(listado, "w")) == NULL)
  {
    printf("Error abriendo el archivo %s.\n", listado);
    return (-1);
  }


  for (i = 0; fscanf(fEntrada, "%d", &notas[i].estudiante) == 1; i++)    
  {
    fscanf(fEntrada, "%d", &notas[i].modelo);
    fscanf(fEntrada, "%d", &notas[i].aciertos);
    fscanf(fEntrada, "%d", &notas[i].fallos);
    fscanf(fEntrada, "%d", &notas[i].blancos);
    fscanf(fEntrada, "%lf", &notas[i].calificacion);
    nota = (int)notas[i].calificacion;

    if (nota < 5) 
      fprintf(fListado, "%d %.3lf %s\n",
              notas[i].estudiante, notas[i].calificacion,
              *(calificacion + Suspenso));

    else if ((nota >= 5) && (nota < 7))
      fprintf(fListado, "%d %.3lf %s\n",
              notas[i].estudiante, notas[i].calificacion,
              *(calificacion + Aprobado));

    else if ((nota >= 7) && (nota < 9))
      fprintf(fListado, "%d %.3lf %s\n",
              notas[i].estudiante, notas[i].calificacion,
              *(calificacion + Notable));

    else if ((nota >= 9) && (nota < 10))
      fprintf(fListado, "%d %.3lf %s\n",
              notas[i].estudiante, notas[i].calificacion,
              *(calificacion + Sobresaliente));

    else if (nota == 10)
      fprintf(fListado, "%d %.3lf %s\n",
              notas[i].estudiante, notas[i].calificacion,
              *(calificacion + Matricula));
    else
      printf("Error.");
  }

  fclose(fListado);
  fclose(fEntrada);

  return(0);
}

/*********************************************/


/*************** Ejercicio 4.3 ***************
// Escribe un programa que utilice los datos 
// generados en el fichero listado.txt,
// que has creado en el ejercicio anterior, 
// para calcular la nota media.

// Esta se guardará al final de ese mismo
// fichero, listado.txt, sin borrar el 
// contenido que ya tiene:

// [Información previa]
// La nota media es: 7.20

#include  <stdio.h>

#define   TAM        256
#define   TAM_NOMBRE 32

typedef   struct 
{
  // Datos
  int     estudiante;
  int     modelo;
  int     aciertos;
  int     fallos;
  int     blancos;
  double  calificacion;

} Notas;

int main(void)
{
  FILE     *fEntrada, *fListado;
  Notas    notas[TAM];
  char     entrada[TAM_NOMBRE] = "calificaciones.txt";
  char     listado[TAM_NOMBRE] = "listado.txt";
  int      i;
  double   media, mediaFinal;

  if ((fEntrada = fopen(entrada, "r")) == NULL)
  {
    printf("Error abriendo el archivo %s.\n", entrada);
    return (-1);
  }

  if ((fListado = fopen(listado, "a")) == NULL)
  {
    printf("Error abriendo el archivo %s.\n", listado);
    return (-1);
  }


  for (i = 0; fscanf(fEntrada, "%d", &notas[i].estudiante) == 1; i++)    
  {
    fscanf(fEntrada, "%d", &notas[i].modelo);
    fscanf(fEntrada, "%d", &notas[i].aciertos);
    fscanf(fEntrada, "%d", &notas[i].fallos);
    fscanf(fEntrada, "%d", &notas[i].blancos);
    fscanf(fEntrada, "%lf", &notas[i].calificacion);
    media += notas[i].calificacion;
  }

  mediaFinal = media / i;

  fprintf(fListado, "La Nota Media es: %.2lf\n\n", mediaFinal);

  fclose(fListado);
  fclose(fEntrada);

  return(0);
}

/*********************************************/


/*************** Ejercicio 4.4 ***************
// Partiendo de un fichero compuesto por un 
// número indeterminado de filas de 3 columnas, 
// cada una de ellas formada por
// una cadena y 2 enteros:

// Elena 25 43
// Juan 5 8
// Sonia 2 1
// Julia 3 17

// Escribe un programa que solicite el nombre 
// del archivo con dichos datos y una letra 
// inicial. A continuación, ha de leer los datos
// del fichero (teniendo en cuenta que el fichero 
// puede tener cualquier número de líneas) 
// y escribir al final del mismo cuántos nombres 
// empiezan por la letra solicitada. 
// El programa acabará informando si el resultado 
// se ha escrito correctamente en el fichero 
// o si este no se ha podido abrir.

// Este es un ejemplo de ejecución basado en los 
// datos anteriores (Elena, Juan, Sonia, Julia), 
// que hemos guardado en datos.txt:

// Teclea el nombre del archivo: datas.txt
// Teclea una inicial: J
// Error: no se pudo abrir el fichero datas.txt.

// Y otro:

// Teclea el nombre del archivo: datos.txt
// Teclea una inicial: J
// El resultado se ha guardado correctamente 
// al final del fichero datos.txt

// En este segundo ejemplo, el fichero datos.txt 
// habrá quedado de la forma:

// Elena 25 43
// Juan 5 8
// Sonia 2 1
// Julia 3 17
// Hay 2 nombres que empiezan por la inicial J.

#include  <stdio.h>
#include  <string.h>

#define   TAM        256
#define   TAM_CAD    32


typedef struct 
{
  // Datos
  char    nombre[TAM_CAD];
  int     num;
  int     num1;

} Notas;

int main(void)
{
  FILE    *fFicha;
  int     i;
  static int contador;    
  char    inicial;
  static  Notas notas[TAM];
  char    ficha[TAM_CAD];

  printf("\nTeclea el nombre del archivo: ");
  gets(ficha);

  if ((fFicha = fopen(ficha, "r")) == NULL)
  {
    printf("Error: no se pudo abrir el fichero %s.\n", ficha);
    return (-1);
  }

  printf("Teclea una inicial: ");
  scanf("%c", &inicial);
  

 for (i = 0; fscanf(fFicha, "%s", notas[i].nombre) == 1; i++)    
  {
    fscanf(fFicha, "%d", &notas[i].num);
    fscanf(fFicha, "%d", &notas[i].num1);
  }

  if ((fFicha = fopen(ficha, "a")) == NULL)
  {
    printf("Error: no se pudo abrir el fichero %s.\n", ficha);
    return (-1);
  }

  while (i > 0)
  {

    if (notas[i].nombre[0] == inicial)
    {
      // fprintf(fFicha, "%c ", notas[i].nombre[0]);
      contador++;
      i--;
    }
    i--;
  }
  
  fprintf(fFicha, "Hay %d nombres que empiezan por la inicial %c.\n", contador, inicial);

  printf("El resultado se ha guardado correctamente al final del fichero %s\n", ficha);
  
  fclose(fFicha);

  return(0);
}

/*********************************************/


/**************** Prueba 4.1 *****************
// Partiendo de un fichero compuesto por un número
// indeterminado de filas de 3 columnas, 
// cada una de ellas formada por una cadena 
// y 2 enteros, como el que sigue:

// Elena 5 3
// Juan 24 8
// Sonia 12 1

// Haz un programa principal que solicite el 
// nombre del archivo con los datos de entrada, 
// otro nombre para el archivo que se va a crear 
// con los datos de salida y un número entero.

// El programa debe crear un fichero de texto con
// los nombres de las personas cuya suma de la 
// segunda y tercera columnas se encuentra por 
// debajo del valor númerico introducido.

// El programa acabará mostrando un mensaje 
// indicando si se ha podido guardar el resultado o 
// si ha habido algún problema al abrir los ficheros.

// Lo que sigue son varios ejemplos de ejecución 
// (para estos ejemplos el nombre correcto del 
// archivo de entrada es datos.txt):

// Teclea el nombre del archivo de entrada: datis.txt
// Teclea el nombre del archivo de salida: nombres.txt
// Teclea el valor del límite: 25
// Error: no se pudo abrir el fichero de entrada.

// Lo que sigue es otro ejemplo de ejecución:

// Teclea el nombre del archivo de entrada: datos.txt
// Teclea el nombre del archivo de salida: nombres.txt
// Teclea el valor del límite: 25
// Se ha creado correctamente el fichero nombres.txt 
// con los resultados

// Para este últiimo caso, y basándose en el fichero 
// puesto como ejemplo al principio del enunciado, 
// nombres.txt contendrá los siguientes datos:

// Elena
// Sonia

// El programa ha de funcionar igual con cualquier 
// fichero que pueda tener cualquier número de líneas.

// NOTA: Si abres el fichero resultante desde el Bloc 
// de notas de Windows es probable que veas toda la 
// información en la misma línea. Para poder verlo 
// correctamente, utiliza otro editor de 
// texto como WordPad.

#include  <stdio.h>
#include  <string.h>

#define   TAM        256
#define   TAM_CAD    32


typedef struct 
{
  // Datos
  char    nombre[TAM_CAD];
  int     num;
  int     num1;

} Notas;

int main(void)
{
  FILE        *fFichaE;
  FILE        *fFichaS;
  int         i;   
  char        fichaE[TAM_CAD];
  char        fichaS[TAM_CAD];
  static      Notas notas[TAM];
  static int  limite;
  static int  contador;

  printf("\nTeclea el nombre del archivo: ");
  gets(fichaE);

  if ((fFichaE = fopen(fichaE, "r")) == NULL)
  {
    printf("Error: no se pudo abrir el fichero %s.\n", fichaE);
    return (-1);
  }

  printf("\nTeclea el nombre del archivo de salida: ");
  gets(fichaS);

  if ((fFichaS = fopen(fichaS, "w")) == NULL)
  {
    printf("Error: no se pudo abrir el fichero %s.\n", fichaS);
    return (-1);
  } 

  printf("\nTeclea el valor del límite: ");
  scanf("%d", &limite);
  

 for (i = 0; fscanf(fFichaE, "%s", notas[i].nombre) == 1; i++)    
  {
    fscanf(fFichaE, "%d", &notas[i].num);
    fscanf(fFichaE, "%d", &notas[i].num1);

    if (((notas[i].num) + (notas[i].num1)) < limite)
    {
      fprintf(fFichaS, "%s\n", notas[i].nombre);
    }
  }

  printf("\nSe ha creado correctamente el fichero nombres.txt con los resultados\n");
  
  fclose(fFichaE);
  fclose(fFichaS);

  return(0);
}

/*********************************************/


/**************** Prueba 4.2 *****************/
// Partiendo de un fichero compuesto por un 
// número indeterminado de filas de 5 columnas, 
// cada una de ellas formada por 2 enteros, 
// seguidos de un número real y otros dos enteros, 
// como el que sigue:

// 25 43 3.4 5 8
// 12 3 -1.2 12 3
// 2 7 1.3 8 4

// El programa ha de solicitar el nombre del 
// archivo con los datos, así como un valor entero. 
// A continuación debe calcular la media de los 
// valores de la segunda columna para los que la 
// cuarta columna es mayor que el entero
// introducido por teclado.

// Por ejemplo, si se introduce el valor 5,
// se calculará (3 + 7) / 2, es decir, 5.

// Finalmente, debe mostrar el resultado del cálculo.

// Lo que sigue son varios ejemplos de ejecución
// (para estos ejemplos, el nombre correcto
// del archivo es datos.txt):

// Teclea el nombre del archivo: datos.txt
// Teclea un número entero: 5
// La media de la segunda columna con 
// el límite igual a 5 es: 5.00

// Lo que sigue es otro ejemplo de ejecución:

// Teclea el nombre del archivo: datos.txt
// Teclea un número entero: 12
// La media de la segunda columna con 
// el límite igual a 12 es: 0.00

// Lo que sigue es otro ejemplo de ejecución:

// Teclea el nombre del archivo: datas.txt
// Teclea un número entero: 12
// Error: no se pudo abrir el fichero datas.txt


#include  <stdio.h>
#include  <string.h>

#define   TAM        256
#define   TAM_CAD    32

typedef struct 
{
  // Datos
  int     ent_0; 
  int     ent_1;
  int     ent_2;
  int     ent_3;
  double  real; 

} Numeros;

int main(void)
{
  FILE        *fFichaE;
  int         i;   
  char        fichaE[TAM_CAD];
  static      Numeros nums[TAM];
  static int  limite;
  static double media;
  // static int  contador;

  printf("\nTeclea el nombre del archivo: ");
  gets(fichaE);

  if ((fFichaE = fopen(fichaE, "r")) == NULL)
  {
    printf("Error: no se pudo abrir el fichero %s.\n", fichaE);
    return (-1);
  }

  printf("\nTeclea un número entero: ");
  scanf("%d", &limite);
  

 for (i = 0; fscanf(fFichaE, "%d", &nums[i].ent_0) == 1; i++)    
  {
    fscanf(fFichaE, "%d", &nums[i].ent_1);
    fscanf(fFichaE, "%lf", &nums[i].real);
    fscanf(fFichaE, "%d", &nums[i].ent_2);
    fscanf(fFichaE, "%d", &nums[i].ent_3);

    if (((nums[i].ent_0) + (nums[i].ent_1)) < limite)
    {
      for (int j = i; j > 0; j--)
      {
        printf("%d %d %.2lf %d %d\n", nums[j].ent_0, nums[j].ent_1,
                nums[j].real, nums[j].ent_2, nums[j].ent_3);
      }
    }
  }

  printf("\nLa media de la segunda columna con el límite igual a %d es: %.2lf\n", limite, media);
  
  fclose(fFichaE);

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
    printf("\nFound %s.\n\n", tmp->name);
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

  if (hash_table[index] != NULL)
  {
    return false;
  }

  hash_table[index] = person;

  return true;

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

  if (hash_table[index] != NULL && strncmp(hash_table[index]->name, person, TABLE_SIZE) == 0)
  {
    return hash_table[index];
  }
  else
  {
    return NULL;
  }
}

Person  *ht_delete(char *person)
{

  int index = hash(person);

  if (hash_table[index] != NULL && strncmp(hash_table[index]->name, person, TABLE_SIZE) == 0)
  {
    hash_table[index] = NULL;
  }
  else
  {
    return NULL;
  }
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

#include  <stdio.h>

int main(void)
{
 
  return(0);
}

/*********************************************/


/*********************************************
// Debugging **argv example 0
#include  <stdio.h>

int main(int argc, char **argv)
{
  printf("\n");

  int i;
  // Iterate over array of args
  for (i = 0; i < argc; i++)
  {
    printf("arg %d is %s\n", i, argv[i]);
  }
  // Deferencing each string arg (*argv)
  // via pointer to the pointer to the start
  // of the array of args (**argv)
  printf("\n\n");

  for (i = 0; i < argc; i++)
  {
    printf("arg %d is %s\n", i, *argv);
    argv++;
  }

  printf("\n");

  return(0);
}

/*********************************************/


/*********************************************
// Debugging **argv example 0
#include  <stdio.h>

struct 
{
  int ***p2p2p2Int;
  int  **p2p2Int;
  int   *p2Int;
  int    Int;
} p;

int main(int argc, char **argv)
{
  
  p.p2p2p2Int = &p.p2p2Int;
  p.p2p2Int   = &p.p2Int;
  p.p2Int     = &p.Int;
  p.Int       = 0x55555555;
   
  return(0);
}

/*********************************************/
