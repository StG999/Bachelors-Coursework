#include<stdio.h>
int main()
{
    for (int i = 0 ; i<=10  ; i++){
        for(int a = 0 ; a < 10 - i ; a++){
            printf(" ");
        }

        for(int j = 1; j<=2*i-1 ; j++){
            int k = 2*i+1;
            if(j <= i){
                k >=11 ? k=k%10 : k-=0;
                printf("%d", k);
                k+=2;
            }
            else if(j>i){
                k-=4;
                k >=11 ? k=k%10 : k-=0;
                k == -1 ? k=9 : k-=0;
                printf("%d", k);
                k-=2;
            }
        }
        printf("\n");
    }
    return 0;
}