#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *insertAfterNode(struct node *prevNode, int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}
void display(struct node *head)
{
    struct node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d->", ptr->data);
        ptr = ptr->next;
    }
    if (ptr == NULL)
    {
        printf("NULL");
    }
}
struct node *deleteLastNode(struct node *head)
{
    struct node *ptr1 = head;
    struct node *ptr2 = head->next;
    while (ptr2->next != NULL)
    {
        ptr2 = ptr2->next;
        ptr1 = ptr1->next;
    }
    if (ptr2->next == NULL)
    {
        ptr1->next = NULL;
        free(ptr2);
    }
}
struct node *reverseLinkedList(struct node *head)
{
    struct node *prev = NULL;
    struct node *current = head;
    struct node *next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}
int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    struct node *second = (struct node *)malloc(sizeof(struct node));
    struct node *third = (struct node *)malloc(sizeof(struct node));
    struct node *fourth = (struct node *)malloc(sizeof(struct node));
    struct node *fifth = (struct node *)malloc(sizeof(struct node));
    head->data = 10;
    head->next = second;
    second->data = 20;
    second->next = third;
    third->data = 30;
    third->next = fourth;
    fourth->data = 40;
    fourth->next = fifth;
    fifth->data = 50;
    fifth->next = NULL;
    display(head);
    insertAfterNode(second, 25);
    printf("\nAfter inserting 25 after second node:\n");

    display(head);
    deleteLastNode(head);
    printf("\nAfter deleting the last node: \n");
    display(head);
    printf("\nAfter Reversing\n");

    head = reverseLinkedList(head);
    display(head);

    return 0;
}