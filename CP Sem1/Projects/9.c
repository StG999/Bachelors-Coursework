#include <stdio.h>

int main()
{
    int a;
    printf("How many employees are there in your company?\n");
    scanf("%d", &a);
    getchar();
    typedef struct employeedetails
    {
        char name[50];
        int age;
        char degree[30];
        float exp;
        struct address
        {
            
        char streetno[30];
        char city[30];
        char district[30];
        char state[30];

        };
    } ED;

    ED arr[a];
    for (int i = 0; i < a; i++)
    {
        printf("Enter the name of %d employee\n", i + 1);
        gets(arr[i].name);
        printf("Enter the age of %d employee\n", i + 1);
        scanf("%d", &arr[i].age);
        getchar();
        printf("Enter the degree of %d employee\n", i + 1);
        gets(arr[i].degree);
        printf("Enter the experience %d employee\n", i + 1);
        scanf("%f", &arr[i].exp);
        getchar();
        printf("Enter the streetno. of %d employee\n", i + 1);
        gets(arr[i].streetno);
        printf("Enter the city of %d employee\n", i + 1);
        gets(arr[i].city);
        printf("Enter the district of %d employee\n", i + 1);
        gets(arr[i].district);
        printf("Enter the state of %d employee\n", i + 1);
        gets(arr[i].state);
        printf("\n");
    }
    for (int i = 0; i < a; i++)
    {
        printf("the name of employee no.%d is : %s\n", i + 1, arr[i].name);
        printf("the age of employee no.%d is : %d\n", i + 1, arr[i].age);
        printf("the degree of employee no.%d is : %s\n", i + 1, arr[i].degree);
        printf("the experience of employee no.%d is : %f\n", i + 1, arr[i].exp);
        printf("the streetno. of employee no.%d is : %s\n", i + 1, arr[i].streetno);
        printf("the city of employee no.%d is : %s\n", i + 1, arr[i].city);
        printf("the district of employee no.%d is : %s\n", i + 1, arr[i].district);
        printf("the state of employee no.%d is : %s\n", i + 1, arr[i].state);
        printf("\n");
    }
    return 0;
}