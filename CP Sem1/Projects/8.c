#include <stdio.h>

int queue[20];
int *front = queue;
int *back = queue;

int enqueue(int data)
{

    if (*back == 20 - 1)
    {
        return (-1);
    }

    else
    {

        *back = data;
        back++;
        return (1);
    }
}

void dequeue(int data)
{
    if (back == queue)
    {
        printf("Queue is full \n");
    }

    else
    {
        printf("%d is deleted\n", *front);
        for (int i = 0; i < back - front; i++)
        {
            *(front + i) = *(front + 1 + i);
        }
        back--;
    }
}

int main()
{
    int data;

    int num, response;
    printf("\n 1.Enqueue  ");
    printf("\n 2.Dequeue  ");
    printf("\n 3.Print queue");
    while (1)
    {
        printf("Choice: ");
        scanf("%d", &num);
        switch (num)
        {
        case 1: // insertion
            printf("Enter Element: ");
            scanf("%d", &data);

            response = enqueue(data);

            if (response == -1)
            {
            }
            else
            {
                printf("%d is inserted\n", data);
            }

            break;
        case 2: // deletion

            dequeue(data);

            break;
        case 3: // display
            if (front == back)
            {
                printf("Queue is empty \n");
            }
            else
            {
                printf("Queue=> \n");
                for (int i = 0; i < back - front; i++)
                {
                    printf("%d.%d\n", i + 1, queue[i]);
                }
            }

            break;
        case 4:
            return 0;
        default:
            printf("Invalid input");
            break;
        }
    }
}