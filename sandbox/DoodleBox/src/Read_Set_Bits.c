/*********************************************/

#include <stdio.h>

int main(int argc, char **argv)
{
  puts("\n\t     ***** Hello World! *****\n");
  puts("\t<--- Reading and Setting Bits --->\n\n");
  
  int num, position, newNum, bitStatus;
  // Get Input from User
  printf("Enter any number: ");
  scanf("%d", &num);
  // Enter the bit position you want to set...
  printf("Enter the nth bit position to check and set (0-31): ");
  scanf("%d", &position); 
  // Right-shift num (n) number of times and perform bitwise & with 1
  bitStatus = (num >> position) & 1;
  puts("The %d bit is set to: %d\n", position, bitStatus);
  
  return(0);
}

/*********************************************/  

/*************** Ejercicio 3.5 ***************/

/*********************************************/

/*********************************************/  