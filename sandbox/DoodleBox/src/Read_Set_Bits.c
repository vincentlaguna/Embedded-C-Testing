/********* Reading and Setting Bits *********/

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
  // Right-shift num (n) position times and perform bitwise & with 1
  bitStatus = (num >> position) & 1;
  printf("\nThe %d bit is set to: %d\n", position, bitStatus);
  // Left-shift 1, position times and perform bitwise | with num
  newNum = (1 << position) | num;
  puts("Bit is set successfully.");
  
  printf("\nNumber before setting the %d bit: %d (in decimal)\n",
          position, num);
  printf("Number after setting the %d bit: %d (in decimal)\n\n",
          position, newNum);
          
  return(0);
}

/*********************************************/  


/*********************************************/  