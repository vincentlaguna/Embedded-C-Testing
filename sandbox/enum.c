#include<stdio.h>
  
enum {Jan, Feb, Mar, Apr, May, Jun, Jul, 
          Aug, Sep, Oct, Nov, Dec};
  
int main()
{
   int i;
   for (i=Jan; i<=Dec; i++)      
      printf("%d ", i);
      printf("\n");
        
   return 0;
}