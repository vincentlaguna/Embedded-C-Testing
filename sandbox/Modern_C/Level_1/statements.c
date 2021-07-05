/******************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char **argv) 
{
  puts("Hello, World!");
  if (argc > 1)
  {
    while (true)
    {
      puts("Some programs never stop");    
    }
  }
  else
  {
    do
    {
      puts("...but this one does!");
    } while (false);
  }
  return EXIT_SUCCESS;
}

/******************************************/