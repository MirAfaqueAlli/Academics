#include<stdio.h>
#define MAX 100
void insertElement(int arr[], int *n, int position, int element){
    if (position<0 || position > *n)
    {
        printf("Invalid Position\n");
        return;        
    }
    for (int i = *n; i > position; i--)
    {
        arr[i]= arr[i-1];
    }
    arr[position] = element;
    (*n)++; 
    }
void deleteElement(int arr[], int *n, int position){
    if (position<0 || position >= *n)
    {
        printf("Invalid position\n");
        return;
    }
    for (int i = position; i < *n-1; i++)
    {
        arr[i] = arr[i+1];
    }
    (*n)--;
    }
void printArray(int arr[], int n){
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);        
    }
    printf("\n");
    
}
int main(){
    int arr[MAX], n, choice, position, element;
    printf("Enter the number of elements of the Array: ");
    scanf("%d", &n);
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    while (1)
    {
        printf("Menu\n");
        printf("1. Insert Element\n");
        printf("2. Delete Element\n");
        printf("3. Display Array\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter posiiton to insert(0-based index): ");
            scanf("%d", &position);
            printf("Enter the element to insert: ");
            scanf("%d", &element);
            insertElement(arr, &n, position, element);         
            break;
        case 2:
            printf("Enter position to delete(0-based index): ");
            scanf("%d", &position);
            deleteElement(arr, &n, position);
            break;
        case 3:
            printf("Array: ");
            printArray(arr, n);
            break;
        case 4:
            return 0;           
        default:
            printf("Invalid Choice\n");
            
        }
    }
    
    
    
    
    return 0;
}