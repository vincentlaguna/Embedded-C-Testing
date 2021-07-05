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
  scanf("%lf", &dolares);
   
  euros = dolares * 0.859;
  printf("%.2lf dólares son %.2lf euros.\n", euros, dolares);
   
  return 0;
}

/*********************************************/

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

/*************** Ejercicio 1.4 ***************/

/*********************************************/ 

/*************** Ejercicio 1.3 ***************/

/*********************************************/  

/*************** Ejercicio 1.3 ***************/

/*********************************************/  

/*************** Ejercicio 1.3 ***************/

/*********************************************/  