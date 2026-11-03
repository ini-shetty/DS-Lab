
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void insertFromFirst(struct Node** head, int value)
{
    struct Node* newNode =
        (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}

void insertFromEnd(struct Node** head, int value)
{
    struct Node* newNode =
        (struct Node*)malloc(sizeof(struct Node));

    struct Node* temp;

    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    temp = *head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

void insertAtPosition(struct Node** head, int value, int position)
{
    if (position < 0)
    {
        printf("Invalid position\n");
        return;
    }

    if (position == 0)
    {
        insertFromFirst(head, value);
        return;
    }

    struct Node* newNode =
        (struct Node*)malloc(sizeof(struct Node));

    struct Node* temp = *head;

    for (int i = 0; temp != NULL && i < position - 1; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Position out of range\n");
        free(newNode);
        return;
    }

    newNode->data = value;
    newNode->next = temp->next;
    temp->next = newNode;
}

void display(struct Node* head)
{
    struct Node* temp = head;

    if (temp == NULL)
    {
        printf("List is empty\n");
        return;
    }

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main()
{
    struct Node* head = NULL;
    int n, value, choice, position;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter data: ");
        scanf("%d", &value);
        insertFromEnd(&head, value);
    }


        printf("\n1. Insert at First");
        printf("\n2. Insert at End");
        printf("\n3. Insert at Specified Position");
        printf("\n4. Display");
        printf("\n5. Exit");
        while (1)
     {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter data: ");
                scanf("%d", &value);
                insertFromFirst(&head, value);
                break;

            case 2:
                printf("Enter data: ");
                scanf("%d", &value);
                insertFromEnd(&head, value);
                break;

            case 3:
                printf("Enter data: ");
                scanf("%d", &value);
                printf("Enter position (starting from 0): ");
                scanf("%d", &position);
                insertAtPosition(&head, value, position);
                break;

            case 4:
                display(head);
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
