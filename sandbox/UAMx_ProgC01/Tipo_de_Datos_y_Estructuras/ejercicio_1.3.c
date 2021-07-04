// Piensa en una serie que hayas visto...
// ¿Cuántas temporadas tiene? 3
// ¿Cuántos capítulos de media cada temporada? 10
// ¿Cuántos minutos duran aproximadamente los capítulos? 22
// ¿Y su intro? 0.5
// ¡En total has invertido unas 10.75 horas en ver la serie!
#include <stdio.h>

int main(void)
{
  int   numDeTemporadas;
  int   numDeCapitulos;
  float numDeMinutos;
  float numDeIntro;
  float total;
  
  printf("Piensa en una serie que hayas visto...\n");
  printf("¿Cuántas temporadas tiene?\n");
  printf("Entre numero: ");
  scanf("%d", &numDeTemporadas);
  printf("¿Cuántos capítulos de media cada temporada?\n");
  printf("Entre numero: ");
  scanf("%d", &numDeCapitulos);
  printf("¿Cuántos minutos duran aproximadamente los capítulos?\n");
  printf("Entre numero: ");
  scanf("%lf", &numDeMinutos);
  printf("¿Y su intro?\n");
  printf("Entre numero: ");
  scanf("%lf", &numDeIntro);
  
  total = numDeTemporadas * numDeCapitulos
}