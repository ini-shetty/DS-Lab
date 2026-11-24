
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node* create()
{
    struct Node *head = NULL;
    struct Node *temp, *newnode;
    int n, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for(i = 1; i <= n; i++)
    {
        newnode = (struct Node*)malloc(sizeof(struct Node));

        printf("Enter data: ");
        scanf("%d", &newnode->data);

        newnode->next = NULL;

        if(head == NULL)
        {
            head = newnode;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }

    return head;
}

void display(struct Node *head)
{
    struct Node *temp = head;
    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

void sortList(struct Node *head)
{
    struct Node *temp, *current;
    int swap;

    if(head == NULL)
        return;

    for(temp = head; temp->next != NULL; temp = temp->next)
    {
        for(current = temp->next; current != NULL;
            current = current->next)
        {
            if(temp->data > current->data)
            {
                swap = temp->data;
                temp->data = current->data;
                current->data = swap;
            }
        }
    }

    printf("List sorted successfully\n");
}

struct Node* reverseList(struct Node *head)
{
    struct Node *prev = NULL;
    struct Node *current = head;
    struct Node *next;

    while(current != NULL)
    {
        next = current->next;

        current->next = prev;

        prev = current;
        current = next;
    }

    return prev;
}

struct Node* concatenate(struct Node *head1,struct Node *head2)
{
    struct Node *temp;

    if(head1 == NULL)
        return head2;

    if(head2 == NULL)
        return head1;

    temp = head1;

    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = head2;

    return head1;
}

int main()
{
    struct Node *head1 = NULL, *head2 = NULL;
    int choice;

    printf("Create First Linked List\n");
    head1 = create();

     printf("\n----- MENU -----\n");
     printf("1. Sort Linked List\n");
     printf("2. Reverse Linked List\n");
     printf("3. Concatenate Two Linked Lists\n");
     printf("4. Display Linked List\n");
     printf("5. Exit\n");

    do
    {

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                sortList(head1);
                display(head1);
                break;

            case 2:
                head1 = reverseList(head1);
                printf("Reversed List:\n");
                display(head1);
                break;

            case 3:
                printf("Create Second Linked List\n");
                head2 = create();

                head1 = concatenate(head1, head2);
                head2 = NULL;

                printf("After Concatenation:\n");
                display(head1);
                break;

            case 4:
                display(head1);
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid Choice\n");
        }

    } while(choice != 5);

    return 0;
}
