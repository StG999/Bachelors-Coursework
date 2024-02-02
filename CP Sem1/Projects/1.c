#include <stdio.h>

int main(void)
{
    int a;

    printf("a: ");
    scanf("%d", &a);

    // printf("b: ");
    // scanf("%d", &b);

    printf("right shifted output: %d\n", a << 1);
    printf("left shifted output: %d", a >> 1);
    
    return 0;
}