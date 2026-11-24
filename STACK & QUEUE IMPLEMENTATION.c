
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *top = NULL;
struct Node *front = NULL;
struct Node *rear = NULL;

void push()
{
    struct Node *newnode;

    newnode = (struct Node*)malloc(sizeof(struct Node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->next = top;
    top = newnode;

    printf("Element pushed successfully\n");
}

void pop()
{
    struct Node *temp;

    if(top == NULL)
    {
        printf("Stack Underflow\n");
        return;
    }

    temp = top;
    printf("Deleted element: %d\n", temp->data);

    top = top->next;
    free(temp);
}

void displayStack()
{
    struct Node *temp = top;

    if(top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack: ");

    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

void enqueue()
{
    struct Node *newnode;

    newnode = (struct Node*)malloc(sizeof(struct Node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->next = NULL;

    if(front == NULL)
    {
        front = rear = newnode;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
    }

    printf("Element inserted successfully\n");
}

void dequeue()
{
    struct Node *temp;

    if(front == NULL)
    {
        printf("Queue Underflow\n");
        return;
    }

    temp = front;

    printf("Deleted element: %d\n", temp->data);

    front = front->next;

    if(front == NULL)
        rear = NULL;

    free(temp);
}

void displayQueue()
{
    struct Node *temp = front;

    if(front == NULL)
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue: ");

    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main()
{
    int choice;
     printf("\n----- MENU -----\n");
        printf("1. PUSH (Stack)\n");
        printf("2. POP (Stack)\n");
        printf("3. DISPLAY STACK\n");
        printf("4. ENQUEUE (Queue)\n");
        printf("5. DEQUEUE (Queue)\n");
        printf("6. DISPLAY QUEUE\n");
        printf("7. EXIT\n");


    do
    {

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                push();
                break;

            case 2:
                pop();
                break;

            case 3:
                displayStack();
                break;

            case 4:
                enqueue();
                break;

            case 5:
                dequeue();
                break;

            case 6:
                displayQueue();
                break;

            case 7:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    } while(choice != 7);

    return 0;
}
