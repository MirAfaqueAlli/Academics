#include <stdio.h>
#define SIZE 5
int queue[SIZE], front = -1, rear = -1;
void enqueue(int value)
{
    if ((rear + 1) % SIZE == front)
    {
        printf("Queue is full.\n");
        return;
    }
    if (front == -1)
    {
        front = rear = 0;
    }
    else
        rear = (rear + 1) % SIZE;
    queue[rear] = value;
    printf("%d insterted in the queue.\n", value);
}
void dequeue()
{
    if (front == -1)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("%d deleted from the queue.\n", queue[front]);
    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % SIZE;
    }
}
void display()
{
    if (front == -1)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue Elements: ");
    for (int i = front; i <= rear; i = (i + 1) % SIZE)
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
}
int main()
{
    int choice, elem;
    while (1)
    {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element to insert: ");
            scanf("%d", &elem);
            enqueue(elem);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            return 0;
        default:
            printf("Invalid Choice.\n");
            break;
        }
    }

    return 0;
}