#include <stdio.h>
#define MAX 100
int stack[MAX];
int top = -1;
int PUSH(int val)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow! Can't add more element\n");
        return 1;
    }
    else
    {
        top++;
        stack[top] = val;
    }
}
int POP()
{
    if (top == -1)
    {
        printf("Stack underflow! Can't pop element\n");
        return 1;
    }
    else
    {
        return stack[top--];
    }
}
void DisplayStack()
{
    if (top == -1)
    {
        printf("Stack UnderFLow! No element Present.\n");
    }
    else
    {
        printf("The elements in stack are:\n");

        for (int i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}
int main()
{
    int arr[10];
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < 10; i++)
        PUSH(arr[i]);
    printf("Array Pushed!\n");

    for (int i = 0; i < 10; i++)
    {
        POP();
    }
    printf("Array Popped!\n");
    for (int i = 0; i < 10; i++)
        PUSH(arr[i]);
    printf("Array reversed and Pushed!\n");
    DisplayStack();
    return 0;
}
