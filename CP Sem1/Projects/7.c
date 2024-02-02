#include <stdio.h>

int main()
{
    int n;
    printf("n: ");
    scanf("%d", &n);

    int arr[n];


    int age = 0, AGE = 0;
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &*(arr+i));
    }

    for(int i = 0; i < n; i++)
    {
        age += *(arr+i);
    }

    printf("Avg age of employees: %.2f", (float) age/n);
    
    return 0;
}