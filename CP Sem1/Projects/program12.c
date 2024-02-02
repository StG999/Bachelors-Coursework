#include <stdio.h>

int pascal(int a, int b)
{
    if (a > 0 && b == 1)
    {
        return 1;
    }

    else if (a == b)
    {
        return 1;
    }
    else
    {
        return pascal(a - 1, b - 1) + pascal(a - 1, b);
    }
}
int main()
{
    int num;
    printf("how many rows of pascal triangle you wanted to see?\n");
    scanf("%d", &num);

    for (int i = 1; i < num + 1; i++)
    {

        for (int k = num - i; k > 0; k--)
        {
            printf("\t");
        }
        for (int j = 1; j < i + 1; j++)
        {

            printf("%d\t\t", pascal(i, j));
        }
        printf("\n");
    }

    return 0;
}