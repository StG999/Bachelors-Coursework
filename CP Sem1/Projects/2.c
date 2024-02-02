#include <stdio.h>

int main(void)
{
    int a, b;
    
    printf("a: ");
    scanf("%d", &a);

    printf("b: ");
    scanf("%d", &b);

    if(b == 0)
    {
        return 1;
    }

    printf("quotient: %.1f\n", (float) a/b);

    return 0;
}