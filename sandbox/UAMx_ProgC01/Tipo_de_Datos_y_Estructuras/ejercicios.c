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

int main() 
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

int main() {
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

int main() {
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


/*************** Ejercicio 2.2 ***************/
// Modifica ahora el programa anterior para que no inicialice el valor de las variables al declararlas, 
// sino que se soliciten al usuario de una en una y después las muestre por pantalla.
// Recuerda, hemos definido los siguientes atributos: sexo (M/F), CP, HP, peso, altura y caramelos.

#include <stdio.h>

int main() 
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


/*********************************************/

/*********************************************/  

/*************** Ejercicio 2.3 ***************/

/*********************************************/  

/*************** Ejercicio 1.3 ***************/

/*********************************************/  

/*********************************************/

/*********************************************/  