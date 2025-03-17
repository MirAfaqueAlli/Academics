// Write a program for the coversion of infix expression to a postfix expression
// Steps:-
//     (i) Scan the symbols of the expression left to right and for each symbol, do the following,

//             a. If the symbol is an operand, print that symbol onto the screen.
//             b. If the symbol is a left paranthesis, push in onto the stack.
//             c. If the symbol is a right paranthesis, pop all the operators from the stack upto the first left paranthesis annd print them onto the screen.
//             d. Discard left and right paranthesis(In case of paranthesis).
//             e. If the symbol is an operator,
//                     i. If the precedence of the operators in the stack are greater than or equal to the current operator, then pop the previous operators out of the stack and print them onto the screen and push the current operator onto the stck.
//                     ii. Else push the current operator onto the stack.
#include <stdio.h>
#include <string.h>
#define MAX 100
char stack[MAX];
char infix[MAX], postfix[MAX];
int top = -1;
void push(char c)
{
    stack[++top] = c;
}
char pop()
{
    return stack[top--];
}
int precedence(char c)
{
    switch (c)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    default:
        return 0;
    }
}
int isEmpty()
{
    if (top == -1)
    {
        return 1;
    }
    else
        return 0;
}
int isFull()
{
    if (top == MAX - 1)
    {
        return 1;
    }
    else
        return 0;
}
void inToPos()
{
    int symbol, next, j = 0;
    for (int i = 0; i < strlen(infix); i++)
    {
        symbol = infix[i];
        switch (symbol)
        {
        case '(':
            push(symbol);
            break;
        case ')':
            next = pop();
            while (next != '(')
            {
                postfix[j++] = next;
            }
            break;
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
            while (!isEmpty() && precedence(stack[top]) >= precedence(symbol))
            {
                postfix[j++] = pop();
            }
            push(symbol);
            break;

        default:
            postfix[j++] = symbol;
            break;
        }
    }
    while (!isEmpty())
    {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}
int main()
{
    printf("Enter the infix expresion: ");
    gets(infix);
    inToPos();
    printf("The postfix expression is: %s", postfix);
    return 0;
}