#include <stdio.h>
#include <stdlib.h>

int main(void)
{
   FILE *proc;
   int c;
   // Open the process
   //proc = popen("ver", "r"); // WIN
   proc = popen("uname", "r"); // LIN
   if(proc == NULL)
   {
      fprintf(stderr, "Unable to create process\n");
      exit(1);
   }
   // Read from the process
   while((c = fgetc(proc)) != EOF)
   {
      putchar(c);
   }
   pclose(proc); // Close the process
   
   return(0);
}