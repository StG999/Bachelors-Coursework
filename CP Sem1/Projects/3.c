#include <stdio.h>

int XOR(int a, int  b);

int main(void)
{
    int a = 0, b = 0;
    // INPUT (Do While loop can be removed if -ve inputs are acceptable)
    do
    {
        printf("a: ");
        scanf("%i", &a);
    }
    while(a < 0);

    do
    {
        printf("b: ");
        scanf("%i", &b);
    }
    while(a < 0);

    // OUTPUT
    printf("%d\n", XOR(a, b));
    printf("%d\n", a^b); //TO VERIFY THE PROGRAM
    return 0;
}

int XOR(int a, int b)
{
    int result = 0;
    result = (a | b) & ~(a & b);

    return result;
}