#include <stdio.h>

int main(void)
{
    int n[31], m, arr[3][31];

    printf("m: ");
    scanf("%d", &m);

    for(int i = 0; i < m; i++)
    {
        printf("n%d: ",i+1);
        scanf("%d", &arr[i][0]);
    }

    for(int i = 0; i < m; i++)
    {
        for(int j = 1; j <= arr[i][0]; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    for(int i = 0; i < m; i++)
    {
        for(int j = 1; j <= arr[i][0]; j++)
        {
            printf("%d", arr[i][j]);
        }

        printf("\n");
    }

    return 0;
}