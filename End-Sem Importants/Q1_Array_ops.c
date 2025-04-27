#include <stdio.h>
#define MAX 100
void insert(int arr[], int *size, int position, int element)
{
    if (*size >= MAX)
    {
        printf("Array is full! Can't add more elements.\n");
        return;
    }
    if (position < 0 || position > *size)
    {
        printf("Invalid position given.\n");
        return;
    }
    for (int i = *size; i > position; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[position] = element;
    (*size)++;
}
void delete(int arr[], int *size, int position)
{
    if (*size == 0)
    {
        printf("Array is empty. Can't delete.\n");
        return;
    }
    if (position < 0 || position >= *size)
    {
        printf("Invalid position given.\n");
        return;
    }
    for (int i = position; i < *size-1; i++)
    {
        arr[i] = arr[i + 1];
    }
    (*size)--;
}
void display(int arr[], int size)
{
    if (size == 0)
    {
        printf("Array is empty. Can't delete.\n");
        return;
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            printf("%d ", arr[i]);
        }

        printf("\n");
    }
}
int main()
{
    int arr[MAX];
    int size = 0;
    int choice, position, element;
    printf("Enter the size of array: ");
    scanf("%d", &size);
    printf("Enter elements:\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    do
    {
        printf("\nMenu\n1. Insert.\n2. Delete\n3. Display\n4. Exit\n Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter element to insert: ");
            scanf("%d", &element);
            printf("Enter position to insert: ");
            scanf("%d", &position);
            insert(arr, &size, position, element);
            printf("Element inserted\n");
            
            break;
        case 2:
            printf("Enter position to delete: ");
            scanf("%d", &position);
            delete (arr, &size, position);
            printf("Element deleted\n");
            
            break;
        case 3:
            display(arr, size);
            break;
        case 4:
            printf("Exiting program...\n");
            return 0;

        default:
            printf("Invalid Choice! Try again.\n");

            break;
        }

    } while (1);

    return 0;
}