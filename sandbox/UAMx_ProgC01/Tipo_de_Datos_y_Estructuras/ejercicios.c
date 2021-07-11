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


/**************** Prueba 2.1 ****************/
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


/*********************************************/  



/*********************************************/

/*************** Ejercicio 2.7 ***************/

/*********************************************/  

/*************** Ejercicio 2.8 ***************/

/*********************************************/  

/*********************************************/

/*********************************************/  