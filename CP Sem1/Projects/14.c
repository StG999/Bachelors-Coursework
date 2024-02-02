#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    
    fp = fopen(argv[1], "w");
    if(fp == NULL)
    {
        return 1;
    }

    printf("input: ");
    char *s;
    gets(s);

    for(int i = 0; s[i] != '$'; i++)
    {
        fputc(s[i] ,fp);
    }

    fclose(fp);

    return 0;
}   