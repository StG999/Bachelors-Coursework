#include <stdio.h>
#include <string.h>

int main()
{
    char *s;
    gets(s);

    for(int i = strlen(s); i >= 0; i--)
    {
        printf("%c", s[i]);
    }
}