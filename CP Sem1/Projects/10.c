#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *ptr;
typedef struct information
{
    char name[30];
    char street[30];
    char city[30];
    char state[30];
    char zipcode[30];

} info;

void add_mailing_address()
{
    // int c;
    // printf("size of dynamic mem: ");
    // scanf("%d", &c);

    ptr = (char *)malloc(144 * sizeof(char));
    info a;
    getchar();
    printf("Enter your name\n");
    gets(a.name);
    printf("Enter your street name\n");
    gets(a.street);
    printf("Enter your city\n");
    gets(a.city);
    printf("Enter your state\n");
    gets(a.state);
    printf("Enter your zipcode\n");
    gets(a.zipcode);
}
void delete_mailing_address()
{
    free(ptr);
    printf("done\n");
}
int main()
{
    char str[4];
    printf("Do you want to add your mailing address?\n");
    scanf("%s", &str);
   
    if (strcmp(str,"yes")==0)
    {
        add_mailing_address();
        char string[4];
        printf("Do you want to delete the mailing address?\n");
        scanf("%s", &string);
        if (strcmp(string,"yes")==0)
        {
            delete_mailing_address();
        }
        else if ( strcmp(string,"no")==0)
        {
            printf("ok\n");
        }
        else
        {
            printf("wrong input\n");
        }
    }
    else if ( strcmp(str,"no") ==0)
    {
        printf("ok\n");
    }
    else
    {
        printf("wrong input\n");
    }

    return 0;
}