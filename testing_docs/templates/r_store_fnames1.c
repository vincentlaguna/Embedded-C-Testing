#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>

#define SIZE 512

int main(void)
{
   DIR *directory;
   FILE *output;
   struct dirent *entry;
   char path[SIZE];
   const char filename[] = "filelist.txt";
   int x, r;
   // Open the output file (must do this first!) -> same directory
   output = fopen(filename, "w");
   if(output == NULL)
   {
      fprintf(stderr, "Unable to create file %s\n", filename);
      exit(1);
   }
   // Fetch path for the directory to read
   printf("Please enter the directory to be examined: ");
   fgets(path, SIZE, stdin);
   // Remove the newline
   for(x = 0; x < SIZE; x++)
   {
      
   }
   return(0);
}