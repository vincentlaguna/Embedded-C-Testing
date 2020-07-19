#include <stdio.h>

int main(void)
{
    int i;
    char ch;
    
    for(i = 0, ch = 'A'; i < 4; i++, ch += 2 * i)
        printf("%c\n", ch);
    /*
    char ch;
    printf("Enter char -> ");
    scanf("%c", &ch);
    
    while((ch = getchar()) != '#')
    {
        if(ch == '\n')
            continue;
        printf("Step 1\n");
        if(ch == 'c')
            continue;
        else if(ch == 'b')
            break;
        else if(ch == 'h')
            goto laststep;
        printf("Step 2\n");
    laststep: printf("Step 3\n");
    }
    printf("Done\n");
    */
    return 0;
}