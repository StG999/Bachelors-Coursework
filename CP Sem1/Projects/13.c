#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    char fname1[50],ch;
    printf("Enter filename: ");
    scanf("%s", fname1);

    fp = fopen(fname1, "r");
    
    if (fp == NULL)
    {
        fp = fopen(fname1, "w");
        printf("\n%s file does not exist hence file created..", fname1);
    }
    
    while((ch=fgetc(fp))!=EOF)
    {
        printf("%c", ch);
    }
    
    fclose(fp);
    
    return 0;
}