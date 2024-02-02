#include <stdio.h>

int main()
{
    char *s;

    gets(s);

    int i = 0, counter = 0;
    do
    {
        counter++;
        i++;
    } while (s[i] != '\0' || s[i] == ' ');

    printf("%d", counter);
    
}