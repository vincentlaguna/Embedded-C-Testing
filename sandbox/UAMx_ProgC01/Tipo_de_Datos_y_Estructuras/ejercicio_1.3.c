// Piensa en una serie que hayas visto...
// ¿Cuántas temporadas tiene? 3
// ¿Cuántos capítulos de media cada temporada? 10
// ¿Cuántos minutos duran aproximadamente los capítulos? 22
// ¿Y su intro? 0.5
// ¡En total has invertido unas 10.75 horas en ver la serie!
#include <stdio.h>

int main(void)
{
  int     temporadas;
  int     capitulos;
  int     duracion;
  double  intro;
  double  total;
  
  printf("\nPiensa en una serie que hayas visto...\n\n");
  printf("¿Cuántas temporadas tiene?\n");
  printf("Entre numero: ");
  scanf("%d", &temporadas);
  printf("¿Cuántos capítulos de media cada temporada?\n");
  printf("Entre numero: ");
  scanf("%d", &capitulos);
  printf("¿Cuántos minutos duran aproximadamente los capítulos?\n");
  printf("Entre numero: ");
  scanf("%lf", &duracion);
  printf("¿Y su intro?\n");
  printf("Entre numero: ");
  scanf("%lf", &intro);
  
  total = temporadas * capitulos * (duracion - intro) / 60;
  
  printf("\n¡En total has invertido unas %lf horas en ver la serie!\n", total);
  
  return(0);
}