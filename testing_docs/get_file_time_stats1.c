#include <stdio.h>
#include <sys/stat.h>
#include <time.h>

int main(void)
{
   const char filename[] = "mcpu_log.txt";
   struct stat fstat;
   
   stat(filename, &fstat);
   printf("%s is %ld bytes long\n", filename, fstat.st_size);
   printf("It was modified on %s", ctime(&fstat.st_mtime));
   
   return(0);
}