#include <stdio.h>
#include <string.h>

int main()
{
    int num1, num2;
    printf("Enter the operation you wanted to operate\n 1) AND \n 2) OR \n 3) XOR \n 4) NOT \n");
    char str[5];
    scanf("%s", &str);
    if (strcmp(str, "AND") == 0)
    {
        printf("Enter 1st number\n");
        scanf("%d", &num1);
        printf("Enter 2nd number\n");
        scanf("%d", &num2);
        printf("the AND operation on these two  a&b is : %d", num1 & num2);
    }
    else if (strcmp(str, "OR") == 0)
    {
        printf("Enter 1st number\n");
        scanf("%d", &num1);
        printf("Enter 2nd number\n");
        scanf("%d", &num2);
        printf("the OR operation on these two  a|b is : %d", num1 | num2);
    }
    else if (strcmp(str, "XOR") == 0)
    {
        printf("Enter 1st number\n");
        scanf("%d", &num1);
        printf("Enter 2nd number\n");
        scanf("%d", &num2);
        printf("the XOR operation on these two  a^b is : %d", num1 ^ num2);
    }
    else if (strcmp(str, "NOT") == 0)
    {
        printf("Enter 1st number\n");
        scanf("%d", &num1);
        printf("Enter 2nd number\n");
        scanf("%d", &num2);
        printf("the NOT operation on these two  ~a and ~b is : %d and %d", ~num1 , ~num2);
    }else{
        printf("Wrong input\n");
    }

    return 0;
}