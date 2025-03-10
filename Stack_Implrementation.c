#include<stdio.h>
#define MAX 100
int stack[MAX];
int top = -1;
int PUSH(int stack[]){
    if (top==MAX-1)
    {
        printf("Stack Overflow! Can't add more element\n");
        return 1;        
    }
    else{
        top++;
        printf("Enter the element to add: \n");
        scanf("%d", &stack[top]);
        printf("%d pushed into the stack.\n\n", stack[top]);
        }
    }
int POP(int stack[]){
    if (top==-1)
    {
        printf("Stack underflow! Can't pop element\n");  
        return 1;      
    }
    else{
        int PopedElement = stack[top];
        stack[top] = 0;
        top--;
        printf("Top element popped.\n\n");
        
        return PopedElement;
    }
    }
void DisplayStack(int stack[]){
if (top==-1)
{
    printf("Stack UnderFLow! No element Present.\n");    
}
else{
    printf("The elements in stack are:\n");
    
    for (int i = top; i >=0; i--)
    {
        printf("%d\n", stack[i]);
        }
        printf("\n\n");
        
    }

    
}
int main(){
    int choice;
    while(1){
    printf("Top: %d\n", top);
    printf("Choose your option\n1. Push\n2. Pop\n3. Display Stack\n4. Exit\n");
    scanf("%d", &choice);
    
    switch (choice)
    {
    case 1:
        PUSH(stack);
        break;
    case 2:
        POP(stack);
        break;
    case 3:
        DisplayStack(stack);
        break;
    case 4:
        return 0;
    default:
    printf("Wrong Choice, Try again!\n");
    
        break;
    }
}
    return 0;
}