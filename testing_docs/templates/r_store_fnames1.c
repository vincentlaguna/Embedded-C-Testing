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
      if(path[x] == '\n')
      {
         path[x] = '\0';
         break;
      }
   }
   // Change the directories supplied by the user
   r = chdir(path);
   // If this function fails -> likely invalid pathname by user input
   if(r != 0)
   {
      printf("Unable to change to %s\n", path);
      fclose(output); // Don't forget this part! Secure the file's data
      return(1);
   }
   // Open the directory
   
   return(0);
}