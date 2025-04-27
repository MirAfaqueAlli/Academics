#include <stdio.h>
#define MAX 5
int queue[MAX], front = -1, rear = -1;
void enqueue(int value)
{
    if ((rear + 1) % MAX == front)
    {
        printf("Queue is full. Can't add more element.\n");
        return;
    }
    if (front == -1)
    {
        front = 0, rear = 0;
    }
    else
    {
        rear = (rear + 1) % MAX;
    }
    queue[rear] = value;
    printf("Element inserted.\n");
}
void dequeue()
{
    if (front == -1)
    {
        printf("Queue is empty.\n");
        return;
    }
    printf("Element deleted.\n");
    if (front == rear)
    {
        front = -1, rear = -1;
    }
    else
    {

        front = (front + 1) % MAX;
    }
}
void display()
{
    if (front == -1)
    {
        printf("Queue is empty.\n");
        return;
    }
    for (int i = front;; i = (i + 1) % MAX)
    {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
    }

    printf("\n");
}
int main()
{
    int choice, value;

    while (1)
    {
        printf("1.Enqueue.\n2.Dequeue.\n3.DIsplay.\n4.Exit.\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:

            printf("Enter the number to insert: ");
            scanf("%d", &value);
            enqueue(value);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        default:
            printf("Invalid Choice! Try Again.\n");

            break;
        }
    }

    return 0;
}