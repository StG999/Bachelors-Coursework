#include <stdio.h>
void insert();
void delete ();
void display();
int q[50];
int last = -1;
int first = -1;
int main()
{
    int ans;
    while (1)
    {
        printf("1.Insert element to queue \n");
        printf("2.Delete element from queue \n");
        printf("3.Display all elements of queue \n");
        printf("4.Quit \n");
        printf("Enter your choice : \n");
        scanf("%d", &ans);
        switch (ans)
        {
        case 1:
            insert();
            break;
        case 2:
            delete ();
            break;
        case 3:
            display();
            break;
        case 4:
            goto end;
        default:
            printf("Please enter valid value!\n");
        }
        printf("\n\n");
    }
    end:
    printf("Quitting...");
    return 0;
}
void insert()
{
    int item;
    if (last == 49)
        printf("Queue Overflow \n");
    else
    {
        if (first == -1)
            first = 0;
        printf("Insert the element in queue : ");
        scanf("%d", &item);
        last+=1;
        q[last] = item;
    }
}
void delete ()
{
    if (first == -1 || first > last)
    {
        printf("Queue Underflow \n");
        return;
    }
    else
    {
        printf("Element deleted from queue is : %d\n", q[first]);
        first = first + 1;
    }
}
void display()
{
    int i;
    if (first == -1)
        printf("Queue is empty \n");
    else
    {
        printf("Queue is : \n");
        for (i = first; i <= last; i++)
            printf("%d ", q[i]);
        printf("\n");
    }
}